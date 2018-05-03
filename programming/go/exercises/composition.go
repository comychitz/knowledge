package main

import "fmt"

//
// simple exercise that shows composition & polymorphism
//

type Greeter interface {
    Greet()
}

type Person struct {
    age int
    name string
}

func (p *Person) Greet() {
    fmt.Printf("Hello, my name is %s\n", p.name)
}

func (p *Person) Introduce() {
    fmt.Printf("I'm %d years old and have one sibling, Bob.\n", p.age)
}

type Employee struct {
    Person
    salary int
}

func (e *Employee) ShareSalary() {
    fmt.Printf("My salary is: $%d\n", e.salary)
}

func DoGreeting(g Greeter) {
    g.Greet()
}

func main() {
    alice := &Employee {
        Person{ 30, "Alice" },
        60000,
    }

    DoGreeting(alice)
    alice.Introduce()
    alice.ShareSalary()
}
