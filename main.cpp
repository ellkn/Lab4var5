#include <iostream>
#include "List.h"
using namespace std;
int main()
{
    List<int> a;
    a.insertLast(2);
    a.insertFirst(1);
    a.insertLast(3);
    a.print();
    a.deleteAtPos(2); //нумерация с 0, поэтому последння - это 2
    a.print();
    a.clear();
    a.print();
    a.insertFirst(22);
    a.insertLast(5);
    a.insertLast(2020);
    a.isContains(1);
    a.print();
    a.deleteLast();
    a.getFirst();
    a.getLast();
    a.print();

    return 0;
}
