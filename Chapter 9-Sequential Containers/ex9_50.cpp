/*
Exercise 9.50: Write a program to process a vector<string>s whose
elements represent integral values. Produce the sum of all the elements in
that vector. Change the program so that it sums of strings that represent
floating-point values.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec_int = {"12", "-3", "03", "100"};
    vector<string> vec_flo = {"12.31", "3.21", "-3.21", "01.00"};
    
    int sumi = 0;
    for (auto i : vec_int)
        sumi += stoi(i);
        
    float sumf = 0.0;
    for (auto i : vec_flo)
        sumf += stof(i);
        
    cout << "sum of all the elements in vec_int is: " << sumi << endl;
    cout << "sum of all the elements in vec_flo is: " << sumf << endl;
    
    return 1;
}
