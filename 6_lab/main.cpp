#include <iostream>
#include "linelist.h"

using namespace std;

int main()
{

    LineList l;

    string s = "((d-(a+b))*e)";

    l.load(s);

    l.head();
    cout << endl;
    l.tail();
     cout << endl;

    return 0;
}
