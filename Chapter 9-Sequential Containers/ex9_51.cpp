/*
Exercise 9.51: Write a class that has three unsigned members
representing year, month, and day. Write a constructor that takes a string
representing a date. Your constructor should handle a variety of date
formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.
*/

/*
This is the solution on https://github.com/Mooophy/Cpp-Primer/blob/master/ch09/ex9_51.cpp.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class My_date {
    private:
        unsigned year, month, day;
    public:
        My_date(const string &s) {
            unsigned tag, format;
            tag = format = 0;
            
            // 1/1/1900
            if (s.find_first_of("/") != string::npos)
                format = 0x01;
            // January 1, 1900 or Jan 1, 1900
            if ((s.find_first_of(",") != string::npos) && (s.find_first_of(",") >= 4))
                format = 0x10;
            else { // Jan 1 1900
                if ((s.find_first_of(" ") != string::npos) && (s.find_first_of(" ") >= 3)) {
                    format = 0x10;
                    tag = 1;
                }
            }
        }
}
