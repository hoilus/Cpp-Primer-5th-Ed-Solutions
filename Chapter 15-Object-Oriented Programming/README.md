# Chapter 15. Object-Oriented Programming

## Exercise 15.1: 
> #### What is a virtual member?

## Answer:
- A virtual member in a base class expects its derived class define its own version. In particular base classes ordinarily should define a virtual destructor, even if it does no work.

## Exercise 15.2: 
> #### How does the protected access specifier differ from private?

## Answer:
- Protected member can be accessed by base class, derived class, and friend class.
- Private member can be accessed by base and friend class.

## [Exercise 15.3](https://github.com/hoilus/Cpp-Primer-5th-Ed-Solutions/blob/master/Chapter%2015-Object-Oriented%20Programming/ex15p1_main.cpp)

## Exercise 15.4: 
> #### Which of the following declarations, if any, are incorrect? Explain why.

```
class Base { ... };
(a) class Derived : public Derived { ... }; // wrong, class cannot derive from its own
(b) class Derived : private Base { ... }; // wrong, this is a definition not declaration
(c) class Derived : public Base; // wrong, declaration does not need list
```
