package main

import "testing"

//
//  simple unit test example to verify fibonacci number
//

func fibonacci(i int) int {
    if(i == 0) {
        return 0;
    } else if(i == 1 || i == 2) {
        return 1;
    }
    return fibonacci(i-1)+fibonacci(i-2);
}

func TestFibonacci(t *testing.T) {
    var result int = fibonacci(2)
    if(result != 1) {
        t.Error("Expected 1 got ", result)
    }
    result = fibonacci(5)
    if(result != 5) {
        t.Error("Expected 5 got ", result)
    }
    result = fibonacci(10)
    if(result != 55) {
        t.Error("Expected 55 got ", result)
    }

}
