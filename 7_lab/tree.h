#ifndef TREE_H
#define TREE_H

#include <string>

using namespace std;

class Tree
{
public:
    struct Elem
    {
        Elem* left;
        Elem* right;

        char inf;
    };

    Tree();

    void load(string expression);

    void print_LRN();
    void print_LNR();

    Elem* root;

private:
    void load(Tree::Elem* elem, string expression);
    void print_LRN(Tree::Elem* elem);
    void print_LNR(Tree::Elem* elem);
};



#endif // TREE_H
