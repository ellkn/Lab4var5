#include <iostream>
#include "List.h"
using namespace std;
int main()
{
    List<int> a;
    a.insertLast(1);
    a.insertFirst(2);
    a.insertLast(3);
    a.print() const;
    return 0;
}
