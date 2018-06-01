/*
Exercise 11.4: Extend your program to ignore case and punctuation. For
example, “example.” “example,” and “Example” should all increment the same
counter.
*/

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

auto strip(string &str) {
    for (auto &ch : str) ch = tolower(ch);
    str.erase(remove_if(str.begin(), str.end(), ::ispunct), str.end());
    return str;
}

int main()
{
    map<string, int> count_words;
    string word;
    while (cin >> word)
        ++count_words[strip(word)];
    for (const auto &w : count_words)
        cout << w.first << " occurs " << w.second << " times." << endl;
    
    return 0;
}
