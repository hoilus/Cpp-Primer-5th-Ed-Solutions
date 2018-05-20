/*
Exercise 9.44: Rewrite the previous function using an index and replace.
*/

#include <iostream>
#include <iterator>
#include <string>
#include <cstddef>

using namespace std;

auto repl_with(string& s, string const& oldVal, string const& newVal) {
    for (auto indx = 0; indx <= s.size() - oldVal.size();) {
        string tmp = s.substr(indx, oldVal.size());
        if (oldVal == tmp) {
            s.replace(indx, oldVal.size(), newVal);
            indx += newVal.size();
        } else
            ++indx;
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
