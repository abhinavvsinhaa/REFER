#include <iostream>
#include "refer/refer.h"
using namespace std;

int main()
{
    Array<int> s;
    s.push_back(10);
    s.push_back(100);
    s.push_back(1000);
    s.push_back(1000);

    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";

    return 0;
}