/*
Exercise 9.49: A letter has an ascender if, as with d or f, part of the letter
extends above the middle of the line. A letter has a descender if, as with p or
g, part of the letter extends below the line. Write a program that reads a file
containing words and reports the longest word that contains neither
ascenders nor descenders
*/

#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    string str = {"aceimnorsuvwxz"};
    string my_letter("");
    string curr, longest;
    while (getline(cin, curr)) {
        my_letter.append(curr);
        if (curr.substr(0,curr.size()-1).find_first_not_of(str) == string::npos) // exclude space at the end of curr.
            longest = (longest.size() < curr.size() ? curr : longest);
    }
    cout << my_letter << endl;
    cout << "************" << endl;
    cout << longest << endl;
    
    return 1;
}
