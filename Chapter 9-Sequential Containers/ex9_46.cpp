/*
Exercise 9.46: Rewrite the previous exercise using a position and length to
manage the strings. This time use only the insert function.
*/

#include <iostream>
#include <iterator>
#include <string>
#include <cstddef>

using namespace std;

string full_name(string& s, string const& prefix, string const& suffix) {
    s.insert(0, prefix);
    return s.insert(s.size(), suffix);
}

int main()
{
    string name = {"Jessica"};
    cout << full_name(name, "Ms.", ", I.") << endl;
    
    return 1;
}
