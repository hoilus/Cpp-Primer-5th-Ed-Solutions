/*
Exercise 11.7: Define a map for which the key is the family’s last name and
the value is a vector of the children’s names. Write code to add new
families and to add new children to an existing family.

Exercise 11.14: Extend the map of children to their family name that you
wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a
pair that holds a child’s name and birthday.
*/

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>

using namespace std;

void addFaml(map<string, vector<pair<string,string>>> &mapfam, string newfam, vector<pair<string, string>> childs) {
    if (mapfam.find(newfam) != mapfam.end()) {
        mapfam[newfam].insert(mapfam[newfam].end(), childs.begin(), childs.end());
    }
    else
        mapfam[newfam] = childs;
}

int main()
{
    map<string, vector<pair<string, string>>> mapfam;
    addFaml(mapfam, "Hong", {{"Jessica", "Mar-01-2012"}, {"Evan", "Dec-07-2016"}});
    addFaml(mapfam, "Zuo", {{"AAA1", "01-01-01"}, {"BBBBBB1", "02-02-02"}, {"CCCCCC", "03-03-03"}});
    addFaml(mapfam, "Hong", {{"Chuqing", "11-11-11"}, {"Chuming", "12-12-12"}});
    for (const auto &w : mapfam)
        cout << w.first << " family has " << w.second.size() << ((w.second.size() > 1) ? " children" : "child") << endl;
        
    for (const auto &w : mapfam) {
        cout << w.first << "'s family children informations are: ";
        for (int j = 0; j < w.second.size(); j++)
            cout << "  " << w.second[j].first << " born in " << w.second[j].second;
        cout << endl;
    }
    
    return 0;
}
