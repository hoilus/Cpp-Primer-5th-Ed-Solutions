/*
Exercise 9.21: Explain how the loop from page 345 that used the return
from insert to add elements to a list would work if we inserted into a
vector instead.
*/

#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <vector>

using namespace std;

int main(void) {

vector<string> lst;
vector<string> lst2;
string word;
auto iter = lst.begin();
while (cin >> word) {
  iter = lst.insert(iter, word); // same as calling push_front
//  lst2.push_front(word); // push_front not work on vector
}

for (auto iter = lst.begin(); iter != lst.cend(); ++iter)
  cout << *iter << endl;

return 0;

}
