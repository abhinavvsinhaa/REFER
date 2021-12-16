#include <string>
using namespace std;

template<typename V>
class MapNode {
public:
    string key;
    V value;
    MapNode<V>* next;

    MapNode(const string& k, V val) {
        this->key = k;
        this->value = val;
        next = NULL;
    }

    ~MapNode() {
        delete next;
    }
};

template<typename V>
class HashMap {
    MapNode<V>** buckets;
    int count, bucketSize;

    int hashString(string key) {
        int hashCode = 0, currentCoeff = 1;
        for (int i = key.length(); i >= 0; i--) {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % bucketSize;
            currentCoeff *= 31;
            currentCoeff = currentCoeff % bucketSize;
        }
        return hashCode % bucketSize;
    }

    void rehash() {
        //create a copy of original bucket with size bucketSize
        MapNode<V>** temp = buckets;
        //initialize bucket with NULL, and size 2*bucketSize
        buckets = new MapNode<V>*[2 * bucketSize];
        for (int i = 0; i < 2*bucketSize; i++) {
            buckets[i] = NULL;
        }

        //update the essentials
        int oldBucketSize = bucketSize;
        bucketSize = 2 * bucketSize;
        count = 0;

        //copy the nodes from copy array into new bucket array
        //by calling the insert function on new bucket array
        //which will calculate the hash code according the new bucket array size
        for (int i = 0; i < oldBucketSize; i++) {
            MapNode<V>* head = temp[i];
            while (head != NULL) {
                insert(head->key, head->value);
                head = head->next;
            }
        }

        //deleting the copy of previous array
        for (int i = 0; i < oldBucketSize; i++) {
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }

public:
    HashMap() {
        count = 0;
        bucketSize = 5;
        buckets = new MapNode<V>*[bucketSize];
        for (int i = 0; i < bucketSize; i++) {
            buckets[i] = NULL;
        }
    }

    int size() {
        return count;
    }

    //Get key's value function
    V getValue(string key) {
        int index = hashString(key);
        MapNode<V>* head = buckets[index];
        while (head != NULL) {
            if (head->key == key) return head->value;
            head = head->next;
        }

        return -1;
    }

    //Remove key function
    V removeKey(string key) {
        int index = hashString(key);
        MapNode<V>* head = buckets[index];
        MapNode<V>* prev = NULL;
        if (head->key == key) {
            V value = head->value;
            head = head->next;
            buckets[index] = head;
            return value;
        }
        else {
            while (head != NULL) {
                if (head->key == key) {
                    prev->next = head->next;

                    //delete the node and return that node's value
                    V value = head->value;
                    head->next = NULL;
                    delete head;
                    count--;
                    return value;
                }
                prev = head;
                head = head->next;
            }
        }

        return -1;
    }

    //Insert Function
    void insert(string key, V value) {
        int index = hashString(key);
        MapNode<V>* head = buckets[index];
        //if the key exists, update its value
        while (head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        //if we don't find the key, insert a new key
        head = buckets[index];
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;
        buckets[index] = node;
        //update total entries in the map
        count++;

        int loadFactor = count/bucketSize;
        if (loadFactor > 0.7) {
            rehash();
        }
    }

    ~HashMap() {
        for (int i = 0; i < bucketSize; i++) {
            delete buckets[i];
        }
        delete [] buckets;
    }
};

/*
Time Complexity
Let's assume total entries in the map - n
Let's assume bucket size - b
Load factor (load on each bucket index) - n/b
Time complexity - O(n/b)
Ideally should be n/b < 0.7

Time complexity to calculate hashcode - O(l) (l: length of the word)
Suppose if we have 10^5 entries in the map, then O(l) can be neglected and taken as constant

Rehashing - if the load factor is >= 0.7
then we will increase the bucket size by 2*bucketSize,
and rehash all the nodes into our new array which have double size
*/
