#include "linelist.h"

LineList::LineList()
{
    front = new Elem;
}

void LineList::load(Tree t)
{
    this->load(this->front, t.root);
}

void LineList::load(LineList::Elem* l, Tree::Elem *t)
{
    Elem* cur = l;

    if(t->left->inf == '+' or t->left->inf == '-' or t->left->inf == '*' or t->left->inf == '/')
    {
        cur->R = 0;
        cur->atom = '\0';
        cur->level = new Elem;
        this->load(cur->level, t->left);
    }
    else
    {
        cur->R = 1;
        cur->level = NULL;
        cur->atom = t->left->inf;
    }

    cur->next = new Elem;
    cur = cur->next;
    cur->R = 1;
    cur->level = NULL;
    cur->atom = t->inf;

    cur->next = new Elem;
    cur = cur->next;

    if(t->right->inf == '+' or t->right->inf == '-' or t->right->inf == '*' or t->right->inf == '/')
    {
        cur->R = 0;
        cur->atom = '\0';
        cur->level = new Elem;
        this->load(cur->level, t->right);
    }
    else
    {
        cur->R = 1;
        cur->level = NULL;
        cur->atom = t->right->inf;
    }

    cur->next = NULL;
}

void LineList::print()
{
    cout << '(';
    this->print(this->front);
    cout << ')';
}

void LineList::print(LineList::Elem* elem)
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
    }
    if(elem->next != NULL)
    {
        this->print(elem->next);
    }
}
