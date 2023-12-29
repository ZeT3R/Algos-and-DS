#ifndef LINELIST_H
#define LINELIST_H

#include <string>
#include <iostream>

using namespace std;

struct Elem
{
    Elem* next = NULL;
    int R;
    union
    {
        Elem* level;
        char atom;
    };
};

class LineList
{
public:
    void load(string expression)
    {
        this->load(this->front, expression);
    }
    void head()
    {
        this->print(this->head(this->front));
    }
    void tail()
    {
        this->print(this->tail(this->front));
    }

    void print()
    {
        this->print(this->front);
    }

private:
    Elem* front;

    void load(Elem* elem, string expression);

    Elem* head(Elem* elem);
    Elem* tail(Elem* elem);

    void print(const Elem* elem)
    {
        if(elem->R == 0)
        {
            cout << '(';
            this->print(elem->level);
            cout << ')';
        }
        else
        {
            cout << elem->atom;
            if(elem->next != NULL)
            {
                this->print(elem->next);
            }
        }
    }
};

#endif // LINELIST_H
