template <typename T>
class LinkedList
{
private:
    T data;
    LinkedList<T> *head;

public:
    LinkedList(T data)
    {
        this->data = data;
        head = NULL;
    }

    LinkedList(T data, LinkedList<T> *ptr)
    {
        this->data = data;
        head = ptr;
    }

    ~LinkedList()
    {
        delete head;
    }
};