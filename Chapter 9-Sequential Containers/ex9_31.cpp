/*
Exercise 9.31: The program on page 354 to remove even-valued elements
and duplicate odd ones will not work on a list or forward_list. Why?
Revise the program so that it works on these types as well.
*/

#include <iostream>
#include <forward_list>
#include <string>
#include <vector>
#include <list>

using namespace std;

// silly loop to remove even-valued elements and insert a duplicate of odd-valued elements
void rem_ins_vector(vector<int>& list) {
    auto iter = list.begin(); // call begin, not cbegin because we're changing vi
    while (iter != list.end()) {
        if (*iter % 2) {
            iter = list.insert(iter, *iter); // duplicate the current element
            iter += 2; // advance past this element and the one inserted before it
        } else
            iter = list.erase(iter); // remove even elements
 // don't advance the iterator; iter denotes the element after the one we erased
    }
}

void rem_ins_list(list<int>& lst) {
    auto iter = lst.begin(); 
    while (iter != lst.end()) {
        if (*iter % 2) {
            iter = lst.insert(iter, *iter); 
            ++iter;
            ++iter;
        } else
            iter = lst.erase(iter); 
    }
}

void rem_ins_forward_list(forward_list<int>& forlst) {
    auto prev = forlst.before_begin();
    auto iter = forlst.begin(); 
    while (iter != forlst.end()) {
        if (*iter % 2) {
            iter = forlst.insert_after(iter, *iter); 
            prev = iter;
            ++iter;
        } else
            iter = forlst.erase_after(prev); // remove the element after iter points to.
                                            // return an iterator to the element after the one deleted.
    }
}

int main(void) {
//    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
//    rem_ins_vector(vi);
//    list<int> vi = {0,1,2,3,4,5,6,7,8,9};
//    rem_ins_list(vi);
    forward_list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    rem_ins_forward_list(vi);
    for (auto i : vi)
        cout << i << endl;

    return 0;
}
