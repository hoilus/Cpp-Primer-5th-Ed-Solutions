/*
Exercise 9.45: Write a funtion that takes a string representing a name
and two other strings representing a prefix, such as “Mr.” or “Ms.” and a
suffix, such as “Jr.” or “III”. Using iterators and the insert and append
functions, generate and return a new string with the suffix and prefix
added to the given name.
*/

#include <iostream>
#include <iterator>
#include <string>
#include <cstddef>

using namespace std;

string full_name(string& s, string const& prefix, string const& suffix) {
    s.insert(s.begin(), prefix.cbegin(), prefix.cend());
    return s.append(suffix);
}

int main()
{
    string name = {"Jessica"};
    cout << full_name(name, "Ms.", ", I.") << endl;
    
    return 1;
}
