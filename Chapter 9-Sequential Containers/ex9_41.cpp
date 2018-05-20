/*
Exercise 9.41: Write a program that initializes a string from a
vector<char>.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    vector<char> vec1{'p', 'l', 'e', 'a', 's', 'e'};
    string str(vec1.cbegin(), vec1.cend());
    cout << str << endl;
    return 0;
}
