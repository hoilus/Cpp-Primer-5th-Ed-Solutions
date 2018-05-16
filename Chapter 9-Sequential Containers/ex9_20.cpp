/*
Exercise 9.20: Write a program to copy elements from a list<int> into
two deques. The even-valued elements should go into one deque and the
odd ones into the other.
*/

#include <iostream>
#include <string>
#include <list>
#include <deque>

using namespace std;

int main(void) {

list<int> lst = {1, 3, 4, 10, 2837, 42, 51, 289};
deque<int> dq_for_even;
deque<int> dq_for_odd;
for (auto iter = lst.cbegin(); iter != lst.cend(); ++iter) {
  if ((*iter) % 2 == 0)
    dq_for_even.push_back(*iter);
  else
    dq_for_odd.push_back(*iter);
}

for (auto iter = dq_for_even.cbegin(); iter != dq_for_even.cend(); ++iter)
  cout << *iter << endl;
for (auto iter = dq_for_odd.cbegin(); iter != dq_for_odd.cend(); ++iter)
  cout << *iter << endl;
  
return 0;

}
