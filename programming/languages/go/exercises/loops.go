package main

import "fmt"

//
// for loop examples in go
//

func main() {

    // simple nested for loops
    for i := 0; i < 5; i++ {
        fmt.Printf("h")
        for j := 0; j <= i; j++ {
            fmt.Printf("i")
        }
        fmt.Printf("\n")
    }

    // using range 
    var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}
    for i, v := range pow {
        fmt.Printf("2**%d = %d\n", i, v)
    }

    // while loop 
    var value int = 3
    for value > 0 {
        fmt.Printf("%d", value)
        value--
    }

    // forever loop
    for {
        fmt.Printf("hi ")
    }
}
