/*
Exercise 11.33: Implement your own version of the word-transformation
program.
*/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = buildMap(map_file); // store the transformations
    string text;                        // hold each line from the input
    while (getline(input, text)) {      // read a line of input
        istringstream stream(text);     // read each word
        string word;
        bool firstword = true;          // controls whether a space is printed
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";            // print a space between words
            // transform returns its first argument or its transformation
            cout << transform(word, trans_map); // print the output
        }
        cout << '\n';                   // done with this line of input
    }
}

map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;      // holds the transformations
    string key;                         // a word to transform
    string value;                       // phrase to use instead
    // read the first word into key and the rest of the line into value
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)           // check that there is a transformation
            trans_map[key] = value.substr(1); // skip leading space
        else
            throw runtime_error("no role for " + key);
    
    return trans_map;
}

int main()
{
    multimap<string, string> author_works = {{"Princeton", "Textbook"}, {"Hong", "Book1"}, {"Hong", "Action2"}, {"Zuo", "Book"}};
    
    //11.31
    //string auth = "Hong";
    string auth = "ING";
    if (author_works.find(auth) != author_works.end())
        author_works.erase(auth);
    
    //11.32
    //multiset can only be sorted by its key, cannot sorted by val.
    //sort(author_works.begin(), author_works.end());
    map<string, multiset<string>> map_for_order;
    for (const auto &w : author_works)
        map_for_order[w.first].insert(w.second);
    for (const auto &w : map_for_order) {
        cout << w.first << "  ";
        for (const auto &books : w.second)
            cout << books << "  ";
        cout << '\n';
    }
    return 0;
}
