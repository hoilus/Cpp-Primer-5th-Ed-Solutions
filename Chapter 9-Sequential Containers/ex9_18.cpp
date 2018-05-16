/*
Exercise 9.18: Write a program to read a sequence of strings from the
standard input into a deque. Use iterators to write a loop to print the
elements in the deque.
*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void) {

deque <string> sts;
string word;
while (cin >> word)
  sts.push_back(word);
for (auto iter = sts.cbegin(); iter != sts.cend(); ++iter)
  cout << *iter << endl;
return 0;

}
