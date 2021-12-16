#include <iostream>
#include "hash.h"
using namespace std;

int main() {
    HashMap<int> m;
    m.insert("abc", 1);
    m.insert("def", 2);
    m.insert("ghi", 3);
    cout << "Size" << m.size() << endl;
    cout << "Value" << m.getValue("def") << endl;
    cout << m.removeKey("ghi");
}