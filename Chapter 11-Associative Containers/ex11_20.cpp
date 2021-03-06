/*
Exercise 11.20: Rewrite the word-counting program from § 11.1 (p. 421) to
use insert instead of subscripting. Which program do you think is easier to
write and read? Explain your reasoning.
*/

#include <iostream>

using namespace std;

int main() {
    
    // rewrite the following part using insert
    /* 
    // count the number of times each word occurs in the input
    map<string, size_t> word_count; // empty map from string to size_t
    string word;
    while (cin >> word)
    ++word_count[word]; // fetch and increment the counter for word
    for (const auto &w : word_count) // for each element in the map
    // print the results
    cout << w.first << " occurs " << w.second
    << ((w.second > 1) ? " times" : " time") << endl;
    */
    
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        auto iter = word_count.insert({word, 1});
        if (!iter.second)
            ++((iter.first)->second);
    }
    for (const auto &w : word_count)
        cout << w.first << " occurs" << w.second 
        << ((w.second > 1) ? " times" : " time") << endl;
    
    
    return 0;
    
}
