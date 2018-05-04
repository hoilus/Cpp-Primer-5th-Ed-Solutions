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
