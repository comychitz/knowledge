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

## design patterns
* observer (aka listener) pattern
  * the subject maintains a list of observers and notifies them (via calling one their methods) of state changes. this is common in event-driven programming.
* strategy pattern [wikiArticle](https://en.wikipedia.org/wiki/Strategy_pattern)
  * a behavorial pattern that enables an algorithm's behavior to be selected at runtime
* template method pattern [wikiArticle](https://en.wikipedia.org/wiki/Template_method_pattern)
  * a behavioral design pattern that defines the program skeleton of an algorithm in an operation, deferring some steps to subclasses. 
* bridge pattern [wikiArticle](https://en.wikipedia.org/wiki/Bridge_pattern)
  * decouple an abtraction from its implementation


## software development
* the waterfall model
  * analysis of specification
  * program design
  * implementation
  * testing & debugging
  * maintenance
