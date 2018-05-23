/*
Exercise 9.52: Use a stack to process parenthesized expressions. When
you see an open parenthesis, note that it was seen. When you see a close
parenthesis after an open parenthesis, pop elements down to and including
the open parenthesis off the stack. push a value onto the stack to
indicate that a parenthesized expression was replaced.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    string paren_exp = "(()()))()";
    char tmps = '1';
    paren_exp[0] = char(1);
    
    cout << "the original parenthesized expression is: " << paren_exp << endl;
    stack<int> paren_ind;
    int indx = 0;
    for (auto i : paren_exp) {
        if (i == '(')
            paren_ind.push(indx);
        if ((i == ')') and !paren_ind.empty()) {
            int tmp = paren_ind.top();
            paren_ind.pop();
            paren_exp[indx] = (char)tmp;
            paren_exp[tmp] = (char)tmp;
        }
        ++indx;
    }
    cout << "the effective parenthesized expression is: " << paren_exp << endl;
    return 0;
}
