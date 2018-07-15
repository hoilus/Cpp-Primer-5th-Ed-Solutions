/*
Exercise 11.7: Define a map for which the key is the family’s last name and
the value is a vector of the children’s names. Write code to add new
families and to add new children to an existing family.
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void addFaml(map<string, vector<string>> &mapfam, string newfam, vector<string> childs) {
    if (mapfam.find(newfam) != mapfam.end()) {
        mapfam[newfam].insert(mapfam[newfam].end(), childs.begin(), childs.end());
    }
    else
        mapfam[newfam] = childs;
}

int main()
{
    map<string, vector<string>> mapfam;
    addFaml(mapfam, "Hong", {"Jessica", "Evan"});
    addFaml(mapfam, "Zuo", {"AAA1", "BBBBBB1", "CCCCCC"});
    for (const auto &w : mapfam)
        cout << w.first << " occurs " << w.second[0] << endl;
    
    return 0;
}
