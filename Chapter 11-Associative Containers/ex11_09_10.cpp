/*
Exercise 11.9: Define a map that associates words with a list of line
numbers on which the word might occur.
Exercise 11.10: Could we define a map from vector<int>::iterator to
int? What about from list<int>::iterator to int? In each case, if
not, why not?
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility> // std::pair, std::make_pair
#include <map>
#include <math.h>

using namespace std;

int main()
{
    // ex11_09
    map<string, list<int>> m;
    m["Hong"] = {1, 2, 3};
    
    for (auto i : m)
        cout << i.first << " " << i.second.back() << endl;
        
    // ex11_10
    // define new maps are ok for both cases
    map<vector<int>::iterator, int> m1;
    map<list<int>::iterator, int> m2;
    
    // initialization of m1 is successful
    vector<int> t1;
    m1.insert(pair<vector<int>::iterator, int>(t1.begin(), 0));
    
    // initialization of m2 fails
    // because no match for ‘operator<’ in __x < __y
    list<int> l1;
    m2.insert(pair<list<int>::iterator, int>(l1.begin(), 0));
   
    return 0;
}
