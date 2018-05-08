package main

import "fmt"

/**
 * higher order function that declares a function that multiplies the input by a
 * constant value
 */
func multiply(m int) func(int) int {
    return func(x int) int {
        return x*m
    }
}

func main() {

    doubleValue := multiply(2)
    tripleValue := multiply(3)

    fmt.Printf("%d doubled is: %d\n", 3, doubleValue(3))
    fmt.Printf("%d tripled is: %d\n", 3, tripleValue(3))
}
