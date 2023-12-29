#include "linelist.h"

void LineList::load(Elem* elem, string expression)
{
    if(expression[0] == '(')
    {
        int count = 1;
        elem->R = 0;
        expression.erase(expression.begin());
        elem->level = new Elem;
        this->load(elem->level, expression);
        do
        {
            if(expression[0] == ')') --count;
            if(expression[0] == '(') ++count;
            expression.erase(expression.begin());
        }
        while(count != 0);
        if(expression[0] == ')' or expression.size() == 0)
        {
            elem->next = NULL;
        }
        else
        {
            elem->next = new Elem;
            this->load(elem->next, expression);
        }
    }
    else
    {
        elem->R = 1;
        elem->atom = expression[0];

        expression.erase(expression.begin());
        if(expression[0] == ')')
        {
            elem->next = NULL;
        }
        else
        {
            elem->next = new Elem;
            this->load(elem->next, expression);
        }
    }
}

Elem* LineList::head(Elem* elem)
{
    return elem->level->level;
}
Elem* LineList::tail(Elem* elem)
{
    return elem->level->next;
}
