/*
Exercise 9.27: Write a program to find and remove the odd-valued
elements in a forward_list<int>.
*/

#include <iostream>
#include <forward_list>

using namespace std;

auto remove_odd(forward_list<int>& flist) {
  auto prev = flist.before_begin();
  auto curr = flist.begin();
  while (curr != flist.end()) {
    if (*curr % 2 == 0)
      curr = flist.erase_after(prev);
    else {
      prev = curr;
      ++curr;
    }
  }
}

int main(void) {
  forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  remove_odd(flst);
  for (auto i : flst)
    cout << i << endl;
  return 0;
}
