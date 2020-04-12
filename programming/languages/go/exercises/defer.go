package main

import "fmt"

//
// the defer statement defers the execution of a function until the surrounding
// function returns
//

func main() {

    // when multiple defer statements are called, each is placed onto a stack
    defer fmt.Printf("world!\n")
    defer fmt.Printf(", ")
    fmt.Printf("hello")

}
