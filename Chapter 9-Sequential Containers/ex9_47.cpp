/*
Exercise 9.47: Write a program that finds each numeric character and then
each alphabetic character in the string "ab2c3d7R4E6". Write two
versions of the program. The first should use find_first_of, and the
second find_first_not_of.
*/

#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    string str = {"ab2c3d7R4E6"};
    string letters = {"abcdefghijklmnopqrszuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string numbers = {"0123456789"};
    string::size_type po = 0;
    while ((po = str.find_first_of(numbers, po)) != string::npos) {
        cout << "find number at index: " << po << " and the element is " << str[po] << endl;
        ++po;
    }
    po = 0;
    while ((po = str.find_first_of(letters, po)) != string::npos) {
        cout << "find letters at index: " << po << " and the element is " << str[po] << endl;
        ++po;
    }
    
    for (po = 0; (po = str.find_first_not_of(letters, po)) != string::npos; ++po)
        cout << "find number at index: " << po << " and the element is " << str[po] << endl;
    for (po = 0; (po = str.find_first_not_of(numbers, po)) != string::npos; ++po)
        cout << "find letters at index: " << po << " and the element is " << str[po] << endl;
    return 1;
}
