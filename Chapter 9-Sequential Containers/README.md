#Chapter 9. Sequential Containers

Exercise 9.1: Which is the most appropriate—a vector, a deque, or a
list—for the following program tasks? Explain the rationale for your choice.
If there is no reason to prefer one or another container, explain why not.
(a) Read a fixed number of words, inserting them in the container
alphabetically as they are entered. We’ll see in the next chapter that
associative containers are better suited to this problem.
(b) Read an unknown number of words. Always insert new words at the
back. Remove the next value from the front.
(c) Read an unknown number of integers from a file. Sort the numbers and
then print them to standard output.

Answer:
(a) list. Insertion (not at the end) in vector takes O(n), while insertion in list takes O(m), where n is the list or vector size and m is the insertion element numbers.
(b) deque. Insertion and remove at either end of the deque is a fast operation, comparable to adding an element to a list or forward_list. On the other hand, inserting or removing elements other than at the back may be slow.
(c) vector. no need to add or remove elements. The list and forward_list containers are designed for fast add and remove of elements in any position of the container. However, they do not support random excess to elements. The memory overhead for these two containers are oftern substantial. 

Exercise 9.2: Define a list that holds elements that are deques that hold ints

Answer:
#include <list>
#include <deque>
  #include <iostream>
using namespace std;
list<deque<int>> list_hold_deques_of_ints;
