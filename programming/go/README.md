# go
Learning the go programming language through consistent practice and reading the
outstanding golang.org documentation.

## getting started
Note: Development environment: MacOS & vim
``` 
brew install go
```
``` 
go get golang.org/x/tour/gotour
```

## references
* https://golang.org
* [Go Wiki](https://github.com/golang/go/wiki)
* [Go for C++ Programmers](https://github.com/golang/go/wiki/GoForCPPProgrammers)
* The Go Programming Language - by Donovan & Kernighan
    * ISBN: 978-0134190440
* [Object Oriented Programming in Go](https://www.ardanlabs.com/blog/2013/07/object-oriented-programming-in-go.html)
* [Wikipedia Article](https://en.wikipedia.org/wiki/Go_(programming_language))


## general notes
* It is a compiled, statically typed language with garbage collection, limited structural typing,
    memory safety features and CSP-style (communicating sequential processes) concurrent programming 
    features added.
* go approaches object-oriented features in a unique way
    * there are no classes, thus no class-based inheritance. 
        * related: [composition over inheritance](https://en.wikipedia.org/wiki/Composition_over_inheritance)
    * composition through type embedding
    * interface satisfaction is done implicitly
        * interfaces are satisfied by simply implementing the method in the
            interface, without specifying the interface anywhere
* reflection
    * in general, reflection in a programming is the ability of a program to
        examine its own structure, particularly though types; its a form of
        metaprogramming
    * [Laws of Reflection in Go](https://blog.golang.org/laws-of-reflection)
* pointers
    * go has pointers, similar to C/C++
    * there is no pointer arithmetic in Go
* slices
    * slices are a flexible view of an array, think of it like a reference to an 
        array (it can modify the contents of an array)
    * they are dynamically-sized
    * slice is formed by specifying low and high indexes of an array
        * for example, a[1:3] creates a slice accessing elements 1 thru 3
    * A slice literal is like an array literal without the length.


## creating a project
* https://golang.org/doc/code.html
* go workspace
    * all of your go code can be located in a single space, pointed to by GOPATH
    * the top level of your GOPATH should have these directories
        * bin
        * pkg
        * src
    * you can keep all of your projects within src: src/project_name
* compile programs or libraries using:
    ```
    go build
    ```
* compile and install your own packages (libraries) to GOPATH/pkg using:
    ```
    go install
    ```
* compile and run executable using :
    ```
    go run main.go
    ```

## unit testing
* go has a built-in package "testing"
* internal unit testing
    * for unit testing internals of your package, it is best practice to create
        a separate file for unit tests, but that are part of your package.
    * this allows you to check internal values/function validity 
* external unit testing
    * for testing the exposed code/interfaces of your package, it is best
        practice to create a separate package for your unit tests that imports
        the package you are testing. 
    * this approach really exercises example usage of your package, and may even
        uncover things that you didn't see when you developed the package, such
        as difficulties in using the APIs, etc.
* good unit testing references:
    * https://medium.com/@matryer/5-simple-tips-and-tricks-for-writing-unit-tests-in-golang-619653f90742
    * https://golang.org/pkg/testing/
    * golang end to end testing
        * github.com/adrianwit/golang-e2e-testing
        * github.com/viant/endly

