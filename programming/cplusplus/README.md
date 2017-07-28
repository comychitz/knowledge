# C++ Notes
Some of my personal notes on the C++ language - regarding features, coding style, etc. In no way is this a complete set of notes, if anything it barely touches the surface. But hopefully it'll grow to be a great reference.


## References
* Style notes mostly stolen from the [Google C++ Syle Guide](https://google.github.io/styleguide/cppguide.html). 
* A Tour of C++ by Bjarne Stroustrup


## Style Notes
* optimize for the reader not the writer!
* don't forget about the header guard in header files (#ifndef...)
* don't do work in the constructors that can result in a crash, it's better to safely exit
* "In some cases it may be useful to make a unittest class a friend of the class it tests."
* "We do not use C++ exceptions."
* "Use C++-style casts like ```static_cast<float>(double_value)```, or brace initialization for conversion of arithmetic types like ```int64 y = int64{1} << 42```."
* When possible, use inline functions instead of macros. If using macros, follow these rules:
   * don't define macros in a .h file.
   * #define macros right before you use them, and #undef them right after.
   * Do not just #undef an existing macro before replacing it with your own; instead, pick a name that's likely to be unique.
   * Try not to use macros that expand to unbalanced C++ constructs, or at least document that behavior well.
   * Prefer not using ## to generate function/class/variable names.
* the 'auto' type:
   * auto is permitted, for local variables only. 
   * use it to help shorten/make a statement more readable( i.e. ```sparse_hash_map<string, int>::iterator iter = m.find(val); ---> auto iter = m.find(val);```
   * the rules for brace-initialization and auto in C++ has not be completely implemented for all compilers, thus need to be cautious using auto sometimes
   * do not use auto for file-scope or namespace-scope variables, or for class members. Never initialize an auto-typed variable with a braced initializer list.
* In C++03, aggregate types (arrays and structs with no constructor) could be initialized with braced initializer lists.
* Never assign a braced-init-list to an auto local variable


## Language Notes (and related programming notes)
* member object variables are able to be constructed with arguments from the constructor itself, but it has to be in the initialization list.
* as in all object oriented code should be, we want high cohesion but low coupling of our modules/classes
* declaring a variable in a global un-named namespace is the C++ way of doing static functions. Everything in the anonymous namespace gets mangled with a compile-generated string, and those functions are only accessible by other functions in the same translation unit
* l-values and r-values
  * l-values are expressions that appear on the left or on the right hand side of an assignment (ex. a = b; // a and b are both l-values)
  * r-values are expressions that can only appear on the right side of an expression (ex. a * b is an rvalue )
* an abstract type is a type that completely insulates a user from implementation details (i.e. a class with all virtual functions, an interface for something)
* ```= 0``` syntax after a virtual function definition means that classes derived from the abstract/virtual class must define the function
* ```const``` after a member function declaration means that function can not modify any class members.
* Inherited classes do not inherit constructors or deconstructors; you need those for each class.
* By declaring a member function as ```static```, you make it independent of any particular object of the class. 
* A static member function can only access static data member, other static member functions and any other functions from outside the class. 
* There are five situations in which an object is copied or moved:
    * As the source of an assignment
    * As an object initializer
    * As a function argument
    * As a function return value
    * As an exception
* Copying and moving containers/essesntial operations on classes:
```
  class X { 
  public:
    X(Sometype);               // ‘‘ordinary constructor’’: create an object
    X();                       // default constructor
    X(const X&);               // copy constructor. can [en|dis]able w/ = delete|default
    X(X&&);                    // move constructor. can [en|dis]able w/ = delete|default
    X& operator=(const X&);    // copy assignment: clean up target and copy. can [en|dis]able w/ = delete|default
    X& operator=(X&&);         // move assignemtn: clean up target and move. can [en|dis]able w/ = delete|default
    ̃X();                      // destructor: clean up
  };
```
* static_cast does type checking at compile time. although, it is referenced that it does no type checking.
* dynamic_cast does type checking at compile time and at run time. if the objects aren't related dynamic_cast returns 0.
* remember that all instances of a class share a single static member of a class
* encapsulation is the term used for the act of hiding the implementation details of an object from its user
* a forward declaration is a declaration of an identifier (denoting an entity such as a type, a variable, a constant, or a function) for which the programmer has not yet given a complete definition.

## Miscellaneous
* use the c++ linter that enforces the Google C++ style code can be found [here](https://raw.githubusercontent.com/google/styleguide/gh-pages/cpplint/cpplint.py)
