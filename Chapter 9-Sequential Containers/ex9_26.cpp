/*
Exercise 9.26: Using the following definition of ia, copy ia into a vector
and into a list. Use the single-iterator form of erase to remove the
elements with odd values from your list and the even values from your
vector.
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(void) {
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
vector<int> vect1(ia, end(ia));
list<int> lst1(vect1.begin(), vect1.end());

auto iter1 = vect1.begin();
while (iter1 != vect1.end())
  if (*iter1 % 2 == 0)
    iter1 = vect1.erase(iter1);
  else
    ++iter1;
    
auto iter2 = lst1.begin();
while (iter2 != lst1.end())
  if (*iter2 % 2 == 0)
    ++iter2;
  else
    iter2 = lst1.erase(iter2);
    
for (auto i : vect1)
  cout << i << endl;
cout<< "******" << endl;
for (auto i : lst1)
  cout << i << endl;
  
return 0;
}
