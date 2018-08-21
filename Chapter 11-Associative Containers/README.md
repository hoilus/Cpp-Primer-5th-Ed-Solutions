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

## [Exercise 11.4](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2011-Associative%20Containers/ex11_04.cpp)

## Exercise 11.5: 
> #### Explain the difference between a map and a set. When might you use one or the other?

## Answer:
- Elements in a map are key-value pairs, while elements in a set only store keys.

## Exercise 11.6: 
> #### Explain the difference between a set and a list. When might you use one or the other?

## Answer:
- Set has unique keys, while elements in list can have the same content.

## [Exercise 11.7](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2011-Associative%20Containers/ex11_07.cpp)

## [Exercise 11.9 and 11.10](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2011-Associative%20Containers/ex11_09_10.cpp)

## [Exercise 11.12 and 11.13](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2011-Associative%20Containers/ex11_12_13.cpp)

## [Exercise 11.14](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2011-Associative%20Containers/ex11_14.cpp)

## Exercise 11.15: 
> #### What are the mapped_type, key_type, and value_type of a map from int to vector<int>?

## Answer:
- mapped_type: vector<int>
- key_type: int
- value_type: pair<const int, vector<int>>
  
  ## Exercise 11.16: 
> #### Using a map iterator write an expression that assigns a value to an element.

## Answer:
- map<string, string> word_count = {{"dictionary", "xxx"}};
- auto map_it = word_count.begin();
- map_it->second = "a book to look for explanations";

  ## Exercise 11.17: 
> #### Assuming c is a multiset of strings and v is a vector of strings, explain the following calls. Indicate whether each call is legal:

```
copy(v.begin(), v.end(), inserter(c, c.end())); // legal
copy(v.begin(), v.end(), back_inserter(c)); // illegal, no `push_back` in `set`
copy(c.begin(), c.end(), inserter(v, v.end())); // legal
copy(c.begin(), c.end(), back_inserter(v)); // legal
```

 ## Exercise 11.18: 
> #### Write the type of map_it from the loop on page 430 without using auto or decltype.

## Answer:
- map<const string, int>::iterator

## [Exercise 11.20](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2011-Associative%20Containers/ex11_20.cpp)

## Answer:
- Directly fetch map element is easier to write and read than using insert. Because the latter method returns a pair for the containers with unique keys.

 ## Exercise 11.21: 
> #### Exercise 11.21: Assuming word_count is a map from string to size_t and word is a string, explain the following loop:

```
while (cin >> word) // read in word string
  ++word_count.insert({word, 0}).first->second;
// if word does not exist in word_count map, insert the key-value pair {word, 0} firstly, then increase the value to 1;
// if word exists in word_count map, insert will not happen, but increase the value of the corresponding key by 1.
```

## Exercise 11.22: 
> #### Given a map<string, vector<int>>, write the types used as an argument and as the return value for the version of insert that inserts one element.
  
## Answer:
- argument: pair<string, vector<int>>
- return: pair<map<string, vector<int>>::iterator, bool>
  
## [Exercise 11.23](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2011-Associative%20Containers/ex11_23.cpp)
  
## Exercise 11.24: 
> #### What does the following program do?
  
```
map<int, int> m; // 
m[0] = 1; // add key-value pair {0, 1} into map
```
 
## Exercise 11.25: 
> #### Contrast the following program with the one in the previous exercise
  
```
vector<int> v;
v[0] = 1; // error
```

## Exercise 11.26: 
> #### What type can be used to subscript a map? What type does the subscript operator return? Give a concrete example—that is, define a map and then write the types that can be used to subscript the map and the type that would be returned from the subscript operator.
  
## Answer:
- Not Yet Answered!!

## Exercise 11.27: 
> #### What kinds of problems would you use count to solve? When might you use find instead?
  
## Answer:
- count will loop over the whole multi-container.
- find will return if it finds the first mathcing element. 

## Exercise 11.28: 
> #### Define and initialize a variable to hold the result of calling find on a map from string to vector of int.
  
## Answer:
```
string element("Hong");
map<string, vector<int>>::iterator itr = word_count.find(element);
```

## Exercise 11.29: 
> #### What do upper_bound, lower_bound, and equal_range return when you pass them a key that is not in the container?
  
## Answer:
- if the key is not in the contianer, upper_bound and lower_bound returns the equal iterator at which the key can be inserted without disrupting the order.
- equal-range will return a pair of iterators, in which the begin and end iterator are equal. And both can be used to insert the key.

## Exercise 11.30: 
> #### Explain the meaning of the operand pos.first->second used in the output expression of the final program in this section.
  
## Answer:
- the first iterator in the returned pair of iterators by equal_bound, and then fetch the value of the iterator in the map.

## [Exercise 11.31 & 32](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2011-Associative%20Containers/ex11_31_32.cpp)

## [Exercise 11.33](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2011-Associative%20Containers/ex11_33.cpp)

## Exercise 11.34: 
> #### What would happen if we used the subscript operator instead of find in the transform function?
  
## Answer:
- If the code has been changed like below:
```
const string &
    transform(const string &s, const map<string, string> &m) {
    return m[s];
}
```
The above code won't compile because the subscript operator will insert an element if s does not exist in map. However, map is const.
