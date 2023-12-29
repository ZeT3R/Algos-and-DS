#include "tree.h"
#include <iostream>

using namespace std;

Tree::Tree()
{
    root = new Elem;
}

void Tree::load(string expression)
{
    this->load(this->root, expression);
}

void Tree::load(Tree::Elem* elem, string expression)
{
    if(expression.size() == 1)
    {
        elem->inf = expression[0];
        elem->left = NULL;
        elem->right = NULL;
        return;
    }

    int brackets_count = 0;
    int i = 1;

    while((expression[i] != '+' and expression[i] != '-' and expression[i] != '*' and expression[i] != '/') or brackets_count != 0)
    {
        brackets_count += expression[i] == '(';
        brackets_count -= expression[i] == ')';

        ++i;
    }

    elem->left = new Elem;
    elem->right = new Elem;

    elem->inf = expression[i];

    string buffer = "";

    for(int j = 1; j < i; ++j)
    {
        buffer += expression[j];
    }

    this->load(elem->left, buffer);

    buffer = "";

    for(int j = i + 1; j < expression.size() - 1; ++j)
    {
        buffer += expression[j];
    }

    this->load(elem->right, buffer);
}

void Tree::print_LNR()
{
    this->print_LNR(this->root);
    cout << endl;
}

void Tree::print_LNR(Tree::Elem* elem)
{
    if(elem->left != NULL)
    {
        cout << '(';
        this->print_LNR(elem->left);
    }
    cout << elem->inf;
    if(elem->right != NULL)
    {
        this->print_LNR(elem->right);
        cout << ')';
    }
}

void Tree::print_LRN()
{
    this->print_LRN(this->root);
    cout << endl;
}

void Tree::print_LRN(Tree::Elem* elem)
{
    if(elem->left != NULL)
    {
        this->print_LRN(elem->left);
    }
    if(elem->right != NULL)
    {
        this->print_LRN(elem->right);
    }
    cout << elem->inf;
}

