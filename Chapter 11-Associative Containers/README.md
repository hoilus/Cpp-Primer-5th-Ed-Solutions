# Chapter 11. Associative Containers

## Exercise 11.1: 
> #### Describe the differences between a map and a vector.

## Answer:
- Elements in a map are key-value pairs. The values are stored and efficiently retrieved by a key.
- Elements in a vector are stored and accessed sequentially by their position in the container.

## Exercise 11.2: 
> #### Give an example of when each of list, vector, deque, map, and set might be most useful.

## Answer:
- List is a doubly-linked list. It allows constant time insert and erase operations anywhere within the sequence, with storage management handled automatically. Unlike vectors and deques, fast random access to list elements is not supported.
- A vector is a sequence container that supports random access iterators. In addition, it supports (amortized) constant time insert and erase operations at the end; insert and erase in the middle take linear time.
- Double ended queues are sequence containers with the feature of expansion and contraction on both the ends. They are similar to vectors, but are more efficient in case of insertion and deletion of elements at the end, and also the beginning. __*Unlike vectors, contiguous storage allocation may not be guaranteed. SO, capacity() and reserve() are not required for deque as the expansion doesn't involve copying all the elements to the new memory. data() doesn't exist for deque either as deuqe doesn't guarantee contiguous memory.*__
- Map is an associative container, and is a collection of key-value pairs. So define a __*Dictionary*__ using map is a good example.
- Set is an associative container which simply collect keys. So a good example is __* a business might define a set named bad_checks to hold the names of individuals who have written bad checks. Before accepting a check, that business would query bad_checks to see whether the customer’s name was present.*__

## [Exercise 11.3](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%209-Sequential%20Containers/ex9_24.cpp)