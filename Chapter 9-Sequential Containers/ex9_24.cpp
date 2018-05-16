/*
Write a program that fetches the first element in a vector
using at, the subscript operator, front, and begin. Test your program on
an empty vector.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
vector<int> lst{1};
cout << lst.at(0) << endl;
cout << lst[0] << endl;
cout << lst.front() << endl;
cout << *(--lst.end()) << endl;
cout << "***********" << endl;

vector<int> lst1;
cout << lst1.at(0) << endl; // terminate called after throwing an instance of 'std::out_of_range'
cout << lst1[0] << endl; // Segmentation fault
cout << lst1.front() << endl; // Segmentation fault
cout << *(--lst1.end()) << endl; // Segmentation fault
return 0;
}
