/*
Exercise 9.41: Write a program that initializes a string from a
vector<char>.
*/

#include <iostream>
#include <iterator>
#include <string>
#include <cstddef>

using namespace std;

auto repl_with(string& s, string const& oldVal, string const& newVal) {
    for (auto itr = s.begin(); itr <= s.end() - oldVal.size();) {
        string tmp = string{itr, itr + oldVal.size()};
        if (oldVal == tmp) {
            itr = s.erase(itr, itr + oldVal.size());
            itr = s.insert(itr, newVal.cbegin(), newVal.cend());
            itr += newVal.size();
        } else
            ++itr;
    }
}

int main()
{
    string s = {"here is a str samp, wit abbr words."};
    repl_with(s, "samp", "sample");
    repl_with(s, "wit", "with");
    cout << s << endl;
    
    return 1;
}
