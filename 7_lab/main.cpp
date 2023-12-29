#include <iostream>
#include "tree.h"
#include "linelist.h"

using namespace std;

int main()
{
    Tree t;

    t.load("((a+b)/c)");

    t.print_LNR();
    t.print_LRN();

    LineList l;

    l.load(t);

    l.print();
    return 0;
}
