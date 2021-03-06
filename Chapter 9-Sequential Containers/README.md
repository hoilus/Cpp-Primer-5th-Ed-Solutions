# Chapter 9. Sequential Containers

## Exercise 9.1: 
> #### Which is the most appropriate—a vector, a deque, or a list—for the following program tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not. 
> #### (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll see in the next chapter that associative containers are better suited to this problem. 
> #### (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front. 
> #### (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

## Answer:
#### (a) list. Insertion (not at the end) in vector takes O(n), while insertion in list takes O(m), where n is the list or vector size and m is the insertion element numbers.
#### (b) deque. Insertion and remove at either end of the deque is a fast operation, comparable to adding an element to a list or forward_list. On the other hand, inserting or removing elements other than at the back may be slow.
#### (c) vector. no need to add or remove elements. The list and forward_list containers are designed for fast add and remove of elements in any position of the container. However, they do not support random excess to elements. The memory overhead for these two containers are oftern substantial. 

## Exercise 9.2: 
> #### Define a list that holds elements that are deques that hold ints

## Answer:
```
#include <list>
#include <deque>
#include <iostream>
using namespace std;
list<deque<int>> list_hold_deques_of_ints;
```

## Exercise 9.3: 
> #### What are the constraints on the iterators that form iterator ranges?

## Answer:
#### end must not precede begin in the same container.

## Exercise 9.4: 
> #### Write a function that takes a pair of iterators to a vector<int> and an int value. Look for that value in the range and return a bool indicating whether it was found.

## Answer:
```
// from https://github.com/Mooophy/Cpp-Primer
auto contains(vector<int>::const_iterator first, vector<int>::const_iterator last, int value) {
    for(; first != last; ++first)
        if(*first == value) return true;
    return false;
}
```

## Exercise 9.5: 
> #### Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the
element is not found.

## Answer:
```
// from https://github.com/Mooophy/Cpp-Primer
auto contains(vector<int>::const_iterator first, vector<int>::const_iterator last, int value) {
    for(; first != last; ++first)
        if(*first == value) return first;
    return last;
}
```

## Exercise 9.6: 
> #### What is wrong with the following program? How might you correct it?
```
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

## Answer:
```
...
while (iter1 != iter2) /* ... */
```
#### operator < is not implemented in list, because list is a doubly linked list, whose memory is not necessarily continuous.

## Exercise 9.7: 
> #### What type should be used as the index into a vector of ints?

## Answer:
```
vector<int>::size_type;
```

## Exercise 9.8: 
> #### What type should be used to read elements in a list of strings? To write them?

## Answer:
```
list<string>::const_iterator; // for reading
list<strig>::iterator; // for writing
```

## Exercise 9.9: 
> #### What is the difference between the begin and cbegin functions?

## Answer:
begin returns a nonconstant iterator that refers the first element in the container. 
cbegin returns a constant iterator that refers the first element in the container.

## Exercise 9.10: 
> #### What are the types of the following four objects?

## Answer:
```
vector<int> v1;  // v1 is a vector container holding integer elements
const vector<int> v2;  // v2 is a constant vector container holding integer elements
auto it1 = v1.begin(), it2 = v2.begin();  // it1 is vector<int>::iterator
                                          // it2 is vector<int>::const_iterator
auto it3 = v1.cbegin(), it4 = v2.cbegin();  // it3 is vector<int>::const_iterator
                                            // it4 is vector<int>::const_iterator
```

## Exercise 9.11: 
> #### Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.

## Answer:
```
- vector<int> sam0; // 0
- vector<int> sam1 = {1, 2, 3};
- vector<int> sam2(3, 10); // three int elements, each initialized to 10
- vector<int> sam21(3); // three 0 elements
- vector<int> sam3(sam1); // copy vector sam1 to sam3
- vector<double> sam4(sam2.begin(), sam2.end()); // copy via a pair of iterators, and convert element type
```

## Exercise 9.12: 
> #### Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

## Answer:
#### Copying container directly requires both have the same container and element type.
#### Copying through iterators do not require same container or element type. 

## Exercise 9.13: 
> #### How would you initialize a vector<double> from a list<int>? From a vector<int>? Write code to check your answers.
    
## Answer:
```
#include <iostream>
#include <vector>
#include <array>
#include <list>

using namespace std;

int main()
{
list<int> list1(10, 1); // list size 10, all elements are 1
vector<double> vec1(list1.begin(), list1.end()); // copy through iterators
for (auto i : list1) cout << i << "  ";
cout << endl;
for (auto j : vec1) cout << j << "  ";
cout << endl;

vector<int> vec2 = {1, 2, 3, 4, 5};
vector<double> vec3(vec2.begin(), vec2.end());
for (auto i : vec2) cout << i << "  ";
cout << endl;
for (auto j : vec3) cout << j << "  ";
cout << endl;

return 0;
}
```

## Exercise 9.14: 
> #### Write a program to assign the elements from a list of char* pointers to C-style character strings to a vector of strings

## Answer:
```
list<const char*> ltmp = {"absd", "nmks"};
vector<string> vec;
vec.assign(ltmp.begin(), ltmp.end());
for (auto elem : vec) cout << elem << "  ";
cout << endl;
return 0;
```
    
## Exercise 9.15: 
> #### Write a program to determine whether two vector<int>s are equal.
    
## Answer:
```
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2(5, 1);
    vector<int> vec3 = {1, 2, 3, 4, 5};
    cout << (vec1 == vec2 ? "true" : "false") << endl;
    cout << (vec1 == vec3 ? "true" : "false") << endl;
```

## Exercise 9.16: 
> #### Repeat the previous program, but compare elements in a list<int> to a vector<int>.

## Answer:
```
    vector<int> vec2(5, 1);
    list<int> lis1 = {1, 1, 1, 1, 1};
    cout << (vector<int>(lis1.begin(), lis1.end()) == vec2 ? "true" : "false") << endl;
```

## Exercise 9.17: 
> #### Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2? 
> #### if (c1 < c2)

## Answer:
- Both element type of c1 and c2 support < operator.
- All containers except the unordered associative containers.

## [Exercise 9.18](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_18.cpp)

## [Exercise 9.19](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_19.cpp)

## [Exercise 9.20](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_20.cpp)

## [Exercise 9.21](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_21.cpp)

## Exercise 9.22: 
> #### Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?
```
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
while (iter != mid)
 if (*iter == some_val) iv.insert(iter, 2 * some_val);
```

## Answer:
- Endless loop since iter never change, thus iter will not equal to mid for ever.
- mid will be invalid after insertion
- see my solutions [here](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_22.cpp).

## Exercise 9.23: 
> ####  In the first program in this section on page 346, what would the values of val, val2, val3, and val4 be if c.size() is 1?

## Answer:
#### They are the same and equal to the first element in c.

## [Exercise 9.24](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_24.cpp)

## Exercise 9.25: 
> ####  In the program on page 349 that erased a range of elements, what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the off-the-end iterator?

## Answer:
- nothing happens if elem1 and elem2 are equal.
- if elem2 is off-the-end, the code will delete all the elements from elem1 to the end.
- if both elem1 and elem2 are off-the-end, nothing will happen.

## [Exercise 9.26](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_26.cpp)

## [Exercise 9.27](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_27.cpp)

## Exercise 9.28: 
> ####  Write a function that takes a forward_list<string> and two additional string arguments. The function should find the first string and insert the second immediately following the first. If the first string is not found, then insert the second string at the end of the list.
    
## Answer:
```
void insert_str(forward_list<string>& list, string const& to_find, string const& to_insert) {
  auto prev = list.before_begin();
  auto curr = list.begin();
  while (curr != list.end()) {
    if (*curr == to_find) {
      list.insert_after(curr, to_insert);
      return;
    }
    else {
      prev = curr;
      ++curr;
    }
  }
  list.insert_after(prev, to_insert);
}
```

## Exercise 9.29: 
> ####  Given that vec holds 25 elements, what does vec.resize(100) do? What if we next wrote vec.resize(10)?
    
## Answer:
#### vec.resize(100) will extend the orignal vec to size of 100, and all the added elements are zero.
#### after we next wrote vec.resize(100), vec only keep the first 10 elements.

## Exercise 9.30: 
> ####  What, if any, restrictions does using the version of resize that takes a single argument place on the element type?
    
## Answer:
#### If the container holds elements of a class type and resize adds elements, we must supply an initializer or the element type must have a default constructor.

## Exercise 9.31: 
> ####  The program on page 354 to remove even-valued elements and duplicate odd ones will not work on a list or forward_list. Why? Revise the program so that it works on these types as well.
    
## Answer:
```
iter += 2; // list and forward_list are linked lists, therefore, iterator can only increase continuously.
```
#### check the revised code [here](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_31.cpp).

## Exercise 9.32: 
> ####  In the program onpage 354 would it be legal to write the call to insert as follows? If not, why not?
```
iter = vi.insert(iter, *iter++); // segmentation fault.
```

## Answer:
#### Because "The order of evaluation of arguments is unspecified." As a result, after entering function insert, iter could be its original value or original value + 1 or even anything else, depending on how compiler implemented. (the original answer is [here](https://github.com/Mooophy/Cpp-Primer/blob/master/ch09/ex9_32.cpp))

## Exercise 9.33: 
> #### In the final example in this section what would happen if we did not assign the result of insert to begin? Write a program that omits this assignment to see if your expectation was correct.
```
vi.insert(begin, 42); // crashed. invalid pointer.
```

## Exercise 9.34: 
> #### Assuming vi is a container of ints that includes even and odd values, predict the behavior of the following loop. After you’ve analyzed this loop, write a program to test whether your expectations were correct.
```
iter = vi.begin();
while (iter != vi.end())
 if (*iter % 2) 
   iter = vi.insert(iter, *iter); 
 ++iter;
```

## Answer:
#### Infinite loop will start when the first even value is reached.
#### Another '++iter' needs to be added into if, and then the loop will realize inserting even numbers in front of the original even value.
#### check the revised code [here](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_34.cpp).

## Exercise 9.35: 
> #### Explain the difference between a vector’s capacity and its size.

## Answer:
- vector's capacity: how many spots the vector has pre-located for storing elements.
- vector's size: how many elements the vector has stored.
- vector's size is always not larger than capacity.

## Exercise 9.36: 
> #### Can a container have a capacity less than its size?

## Answer:
#### No.

## Exercise 9.37: 
> #### Why don’t list or array have a capacity member?

## Answer:
- capacity member requires element memory is continuous and can be resized.
- list is a doubly linked list, memory is not necessarily continous.
- array has fixed size.

## Exercise 9.38: 
> #### Write a program to explore how vectors grow in the library you use.

## Answer:
```
    vector<string> vec1;
    string buffer;
    while(cin >> buffer) {
        vec1.push_back(buffer);
        cout << "vec1's size is " << vec1.size() << " ." << endl;
        cout << "vec1's capacity is " << vec1.capacity() << " ." << endl;
    }
```

## Exercise 9.39: 
> #### Explain what the following program fragment does:
```
vector<string> svec;
svec.reserve(1024); // pre-allocate 1024 spots to save the elements.
string word;
while (cin >> word) // read in words
 svec.push_back(word); // svec's capacity will automatically increase if the number of read in words is larger than 1024.
svec.resize(svec.size()+svec.size()/2);
// resize() will add another svec.size()/2 elements initiated of " " to svec. 
// if this exceeds capacity, it will also automatically increase to accomodate the new elements.
```

## Exercise 9.40: 
> #### If the program in the previous exercise reads 256 words, what is its likely capacity after it is resized? What if it reads 512? 1,000? 1,048?

## Answer:
- words     capacity after resized
-  256                      1024
-  512                      1024
- 1000                      2000
- 1048                      2048

## [Exercise 9.41](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_41.cpp)

## Exercise 9.42:
> #### Given that you want to read a character at a time into a string, and you know that you need to read at least 100 characters, how might you improve the performance of your program?

## Answer:
- string.reserve(128); // allocate enough space

## [Exercise 9.43](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_43.cpp)

## [Exercise 9.44](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_44.cpp)

## [Exercise 9.45](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_45.cpp)

## [Exercise 9.46](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_46.cpp)

## [Exercise 9.47](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_47.cpp)

## Exercise 9.48:
> #### Given the definitions of name and numbers on page 365, what does numbers.find(name) return?

## Answer:
#### string::npos

## [Exercise 9.49](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_49.cpp)

## [Exercise 9.50](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_50.cpp)

## [Exercise 9.51](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_51.cpp)

## [Exercise 9.52](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_52.cpp)
