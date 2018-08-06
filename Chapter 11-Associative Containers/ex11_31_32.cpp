/*
Exercise 11.31: Write a program that defines a multimap of authors and
their works. Use find to find an element in the multimap and erase that
element. Be sure your program works correctly if the element you look for is
not in the map.

Exercise 11.32: Using the multimap from the previous exercise, write a
program to print the list of authors and their works alphabetically.
*/


#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

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
