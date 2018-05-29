/*
Exercise 11.3: Write your own version of the word-counting program.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> count_words;
    string word;
    while (cin >> word)
        ++count_words[word];
    for (const auto &w : count_words)
        cout << w.first << " occurs " << w.second << " times." << endl;
    return 0;
}
