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

## [Exercise 11.3](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2011-Associative%20Containers/ex11_03.cpp)

> #### It is interesting to see the map element is fetched in a sorted way.
```
here is the input:
this 
is
a
sample
letter
for
testing
Exercise
9.49.
add
one
more
word.
```
```
here is the output:
9.49. occurs 1 times.
Exercise occurs 1 times.
a occurs 1 times.
add occurs 1 times.
for occurs 1 times.
is occurs 1 times.
letter occurs 1 times.
more occurs 1 times.
one occurs 1 times.
sample occurs 1 times.
testing occurs 1 times.
this occurs 1 times.
word. occurs 1 times.
```
