/*
Exercise 11.31: Write a program that defines a multimap of authors and
their works. Use find to find an element in the multimap and erase that
element. Be sure your program works correctly if the element you look for is
not in the map.
*/


#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    multimap<string, string> author_works = {{"Hong", "Book1"}, {"Hong", "Book2"}, {"Zuo", "Book"}};
    
    //string auth = "Hong";
    string auth = "ING";
    if (author_works.find(auth) != author_works.end())
        author_works.erase(auth);
        
    for (const auto &w : author_works)
        cout << w.first << "  " << w.second << "\n";

    return 0;
}
