/*
Exercise 11.12: Write a program to read a sequence of strings and ints,
storing each into a pair. Store the pairs in a vector.
Exercise 11.13: There are at least three ways to create the pairs in the
program for the previous exercise. Write three versions of that program,
creating the pairs in each way. Explain which form you think is easiest to
write and understand, and why.
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
    vector<string> sts = {"May-01", "Jun-10", "Dec-30"};
    vector<int> ins = {501, 610, 1230, 0123};
    vector<pair<string, int>> prs;
    for (int i = 0; i < min(sts.size(), ins.size()); i++) {
        // version 1
        // prs.push_back({sts[i], ins[i]});
        // version 2
        // prs.push_back(make_pair(sts[i], ins[i]));
        // version 3
        prs.push_back(pair<string, int>(sts[i], ins[i]));
        cout << prs[i].first << " " << prs[i].second << endl;
    }
    
    return 0;
}
