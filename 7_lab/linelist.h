#ifndef LINELIST_H
#define LINELIST_H

#include <iostream>

#include "tree.h"

using namespace std;

class LineList
{
public:
    struct Elem
    {
        Elem* next;
        int R;
        union
        {
            Elem* level;
            char atom;
        };
    };

    LineList();

    void load(Tree t);
    void print();

    Elem* front;

private:

    void load(LineList::Elem* l, Tree::Elem* t);
    void print(LineList::Elem* l);
};

#endif // LINELIST_H
