/*
Exercise 9.19: Rewrite the program from the previous exercise to use a
list. List the changes you needed to make.
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void) {

list <string> sts;
string word;
while (cin >> word)
  sts.push_back(word);
for (auto iter = sts.cbegin(); iter != sts.cend(); ++iter)
  cout << *iter << endl;
return 0;

}
