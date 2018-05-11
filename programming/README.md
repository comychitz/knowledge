# programming essentials
## remember to always...
* optimize for the reader, not the writer(!)
* be consistent(!)
* keep it simple, stupid(!)
* if unit testing is difficult, revisit your design/implementation

## object oriented
* SOLID Priciples of Obect Oriented Design
  * Single Responsibility 
  * Open-Closed - open for extension, closed for modification
  * Liskov Substitution - a subclass shall be able to be replaced for its parent without breaking the program
  * Interface Segregation - many specific interfaces is better than one do-it-all interface
  * Dependency Inversion - program toward abstractions, not implementations (because they vary, abstractions should not)

## general notes
* syntax vs semantics
    * syntax is the grammar
    * semantics is the meaning
    * a statement can be syntatically valid, but the semantics can not be.
* memory barrier
  * is a type of barrier instruction that causes a CPI or compiler to enforce
      ordering constraint on memory operations.
  * Typically, this means that operations issued prior to the barrier are
      guaranteed to be performed before operatiosn issued after the barrier
  * https://en.wikipedia.org/wiki/Memory_barrier
* toolchain
  * general definition: a set of tools, usually used sequentially (hence, a
    chain), to perform some complex software task. A simple example is a
    toolchain that contains system libraries, tools for building, a debugger,
    and other related tools - like the GNU toolchain - for building software
    programs on Unix/Linux systems.
  * https://en.wikipedia.org/wiki/GNU_toolchain
* idempotence: the property of certain operations in mathematics and computer science, that can be applied multiple times without changing the result beyond the initial application [idempotence - wikipedia](https://en.wikipedia.org/wiki/Idempotence)
* serialization
  * has two contexts: 1) serializing access (i.e. with a mutex) 2) serializing
    data (translating from one form to another; for example, to store in a DB)
* late vs early binding
  * making a run-time decision about which instance method to call is known as
    dynamic or late binding. 
  * when the compiler selects the correct overloaded method at compile time by
    comparing the method's signatures is known as static or early binding.
  * in polymorphism, the actual method that will be called is not determined by
    the compiler. The compiler determines if a method can be called (i.e. is it
    legal?), while the run-time environment determines how it will be called
    (i.e. which overriden form should be used?)
* static/dynamic and strong/weak typing
  * good wiki article: https://en.wikipedia.org/wiki/Type_system
  * Static/Dynamic typing is about when type information is aquired (Either at
    compiletime or at runtime)
  * static type checking is the process of verifying the
    type safety of a program based on analysis of a program's text (source
    code).
  * dynamic type checking is the process of verifying the type
    safety of a program at runtime. Implementations of dynamically type-checked
    languages generally associate each runtime object with a type tag (i.e., a
    reference to a type) containing its type information. This runtime type
    information (RTTI) can also be used to implement dynamic dispatch, late
    binding, downcasting, reflection, and similar features.
  * Strong/Weak typing is about how strictly types are distinguished (e.g. whether
    the language tries to do implicit conversion from strings to numbers).
  * https://en.wikipedia.org/wiki/Strong_and_weak_typing
  * These terms do not have a precise definition, but in general, a strongly typed
    language is more likely to generate an error or refuse to compile if the
    argument passed to a function does not closely match the expected type. On the
    other hand, a weakly typed language may produce unpredictable results or may
    perform implicit type conversion.
* [opaque pointer](https://en.wikipedia.org/wiki/Opaque_pointer)
  * a special case of an opaque data type, a dataype decalred to be a pointer 
    to a record or data structure of some unspecified type
  * "Opaque pointers are a way to hide the implementation details of an
    interface from ordinary clients, so that the implementation may be changed
    without the need to recompile the modules using it. This benefits the
    programmer as well since a simple interface can be created, and most
    details can be hidden in another file.[1] This is important for providing
    binary code compatibility through different versions of a shared library,
    for example."
  * "This technique is described in Design Patterns as the Bridge pattern. It is
    sometimes referred to as "handle classes",[2] the "Pimpl idiom" (for
    "pointer to implementation idiom"),[3] "Compiler firewall idiom",[4]
    "d-pointer" or "Cheshire Cat", especially among the C++ community."
* distributed systems:
    - a collection of independent computers that appears to its users as a single cohenerent system
* declaration vs definition
    * a declaration introduces an identifier and describes its type, be it a
        type, object, or function.
        * a declaration is what the compiler needs
    * a definition actually instantiates/implements the identifier.
        * definition is what the linker needs
    * in C++, the standard considers `struct x;` to be a declaration and `stuct
        x {};` to be a definition.
    * [stackoverflow question](https://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa)
* closures
    * [WikiArticle](https://en.wikipedia.org/wiki/Closure_(computer_programming))
    * a closure is a record storing a function together with an environment
    * "a technique for implementing lexically scoped name binding in a language
        with first-class functions."

## type systems
* [Types and Programming Languages - B.Pierce - MIT Press](https://www.asc.ohio-state.edu/pollard.4/type/books/pierce-tpl.pdf)

## design patterns
* observer (aka listener) pattern
  * the subject maintains a list of observers and notifies them (via calling one their methods) of state changes. this is common in event-driven programming.
  * push-based vs pull-based observers
* strategy pattern [wikiArticle](https://en.wikipedia.org/wiki/Strategy_pattern)
  * a behavorial pattern that enables an algorithm's behavior to be selected at runtime
* template method pattern [wikiArticle](https://en.wikipedia.org/wiki/Template_method_pattern)
  * a behavioral design pattern that defines the program skeleton of an algorithm in an operation, deferring some steps to subclasses. 
* bridge pattern [wikiArticle](https://en.wikipedia.org/wiki/Bridge_pattern)
  * decouple an abtraction from its implementation
* decorator pattern [wikiArticle](https://en.wikipedia.org/wiki/Decorator_pattern)
  * A decorator makes it possible to add or alter behavior of an interface at run-time 
* proxy pattern
  * provides a one-to-one forwarding interface to another class: calling FunctionA() in the proxy class will cause it to call FunctionA() in the original class.
  * is useful to modify the behavior of the original class while still preserving its interface. 
  * this is particularlly useful if the original class in a third-party library and hence not easily modifiable directly.
* adapter pattern
  * translates the interface for one class into a compatible but different interface
* facade pattern
  * defines a higher-level interface that makes the underlying subsystem easier to use
  * is a way to structure your API into subsystems to reduce complexity and in turn make the API easier to use
  * think of it as an example of a multicomponent wrapper

## algorithms 
* complete search
    * general method to solve almost *any* algorithm problem
    * generate all possible solutions to the problem using brute force, and then
        select the best solution or count the number of solutions, depending on
        the problem.
* greedy algorithm 
    * constructs a solution to the problem by always making a choice that looks
        the best at the moment.
* dynamic programming
    * combines the correctness of complete search and the efficiency of greedy
        algorithms. 
    * it can be applied if the problem can be divded into overlapping problems
        that can be solved independently.
    * there are two uses for dynamic programming
        * finding an optimal solution
        * counting the number of solutions
* (reference: [Competetive Programmer's Handbook](https://cses.fi/book.pdf))


## interesting problems
* [the travelling salesman problem](https://en.wikipedia.org/wiki/Travelling_salesman_problem)
* [the produce-consumer problem](https://en.wikipedia.org/wiki/Producer–consumer_problem)
  * usually solved using 2 semaphores
    * the consumer must wait for the producer to produce something if the queue is empty
    * the producer must wait for the consumer to consume something if the queue is full

## software development
* [agile](https://en.wikipedia.org/wiki/Agile_software_development)
  * [agile manifesto](http://agilemanifesto.org)
    * "We are uncovering better ways of developing software by doing it and helping others do it. Through this work we have come to value:
        * Individuals and interactions over process and tools
        * Working software over comprehensive documentation
        * Customer collaboration over contract negotiation
        * Repsonding to change over following a plan
      That is, while there is value in the items on the right, we value the items on the left more."
  * the 12 principles:
    1. Customer satisfaction by early and continuous delivery of valuable software
    2. Welcome changing requirements, even in late development
    3. Working software is delivered frequently (weeks rather than months)
    4. Close, daily cooperation between business people and developers
    5. Projects are built around motivated individuals, who should be trusted
    6. Face-to-face conversation is the best form of communication (co-location)
    7. Working software is the primary measure of progress
    8. Sustainable development, able to maintain a constant pace
    9. Continuous attention to technical excellence and good design
    10. Simplicity—the art of maximizing the amount of work not done—is essential
    11. Best architectures, requirements, and designs emerge from self-organizing teams
    12. Regularly, the team reflects on how to become more effective, and adjusts accordingly
* the waterfall model
  * analysis of specification
  * program design
  * implementation
  * testing & debugging
  * maintenance

