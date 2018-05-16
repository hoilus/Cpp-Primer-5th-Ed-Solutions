/*
Exercise 9.22: Assuming iv is a vector of ints, what is wrong with the
following program? How might you correct the problem(s)?
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void) {

vector<int> iv{1, 3, 2, 6, 5, 1, 3, 1};
int some_val = 3;
vector<int>::iterator iter = iv.begin();
auto mid = [&]{ return iv.begin() + iv.size()/2; };
while (iter != mid()) {
  if (*iter == some_val) 
    ++(iter = iv.insert(iter, 2 * some_val));
  ++iter;
}
for (auto iter = iv.cbegin(); iter != iv.cend(); ++iter)
  cout << *iter << endl;
  
return 0;
}
