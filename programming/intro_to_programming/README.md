# introduction to programming
A brief introduction to computer programming.

## what is programming?
Before we talk about what programming is, we need to understand what a computer
is. Computers are programmable machines. In other words, they are machines that
follow a set of instructions to do *something*. That *something* can be as
simple as adding two numbers or as difficult as classifying a set of images and
their contents. Computers come in all shapes and sizes, each having their own
purpose and responsibilities. The computers we use everyday are general purpose
computers, built to carry out everyday tasks such as writing documents, creating 
presentations, accessing the internet, and so on. 

There are three basic components that make a computer, the central processing 
unit (CPU), memory, and input/output (I/O). The CPU is the brain of the
computer, it is responsible for executing the instructions (programs) we tell it
to perform. While it is executing these complex instructions, it needs to keep
track of what it is doing, and that's where memory comes into play. A computer
stores intermediate values (state) in memory to reference later, as needed.
There are different types of memory, which we will not cover here. Lastly,
there is I/O, which is how a computer interacts with the outside world. We
humans typically interact with our computers (i.e. give input) via our mouse 
and keyboard, which in turn causes output (i.e. text on the screen). 

Now, a computer doesn't understand English or Japanese or any human language, a
computer only understands 1s and 0s, or bits (bit = binary digit). When we write
computer programs we don't write a file that contains a bunch of bits, that
would be very tedious and time consuming. We instead write programs in a
programming language - a language that was constructed for the sole purpose of
communicating to a computer a set of instructions to perform. This allows humans
to create programs in an efficient manner, abstracting the low level details of
the computer from the programmer. There are hundreds, maybe thousands, of
programming languages in existence today. Some are easy to learn, some much more
difficult. Some are very general purpose while others have a single purpose. As
we have studied computers and made discoveries in this area, new programming
languages have been developed to exploit new methods and paradigms of
programming.

So what is programming? There is much, much more to cover, but in simple terms
programming is the act of writing a set of instructions (aka programs) for a
computer to execute.

## an example program
Let's dive in and start writing a simple program. For the purposes of this
introduction we will be using the C++ programming language, a powerful,
general-purpose programming language widely used in practice today. 

### functions
A program is made of many tiny units we call functions. A program function is
conceptually the same as a mathematical function. Take y = f(x) as an example. 
The function f takes as input a value, x, and returns a different value, y. 
Let's take a look at an example function in C++.
```c++
int doubleValue(int x) 
{
  int y = x*2;
  return y;
}
```
Let's take this line by line. The first line is declaring a function named
doubleValue, which takes in an integer value we're calling x and returns another
integer value (int stands for integer). As you can guess, this function's
purpose is to double the value given and return its result. The second line is
an open curly bracket used to indicate the start of the function body. The body
of the function is where we perform all the *hard work*. Within the body we have
lines of code, separated by semi-colons (;), executing code to fulfill the
functions purpose.  The third line declares a new variable y, which is assigned
the value of x multiplied by 2. The last statement of the body is typically a
return statement, which outputs (returns) the result of all of our *hard work*.
Finally, we have a close curly bracket, indicating the end of the body, and the
end of this function.

### the main function


```c++
int main()
{
  int x = 3;
  int y = doubleValue(x);

  std::cout << "The value: " << x << " doubled is: " << y << std::endl;

  return 0;
}
```

### coding style
Even though it is quite early in your programming endeavors, it is well worth
quickly talking about coding style. In the C++ programming language there is no
restriction on how the code is organized in regards to white spaces. For
example, we could write our doubleValue function in the following ways:
```c++
int doubleValue(int x) { int y = x*2; return y; }
```
or
```c++
int 
doubleValue(int x)
{
int y = 
x*2;
return y;
}
```
These are both valid in the C++ language. However, as you can tell, our first
implementation of doubleValue is much more readable. This is why style is
important, you always want to make sure your programs are easy to read, because
you never know who is going to be reading them. There is no restriction on
style, however, it is best to adhere to community guidelines and to keep things
consistent. My general style rules in programming are: 1) "be consistent!", 
2) "optimize for the reader, not the writer!".

