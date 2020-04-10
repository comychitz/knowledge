# java
General notes about the Java programming language

## notes from "Effective Java - Joshua Bloch"

### general programming
* prefer primitive types to boxed primitives
    * a boxed primitive is simply a primitive value that has been wrapped into
      an object, so that they can have the behavior of an object.
    * differences between primitive & boxed primitive
        * primitives have values, where boxed primitives have identities and
          values (which are distinct)
        * primitive types only have fully functional values, but a boxed
          primitive has one nonfunctional value, `null`.
        * primitives are generally more time- and space-efficient
    * `==` operator on boxed primitives is almost always wrong, it does identity
      comparison, not value comparison.
* beware the performance of string concatenation
    * use the append() method instead when adding to a string when performance
      is important.
* refer to objects by their interfaces
* prefer interfaces to reflection
* use native methods judiciously
* optimize judiciously

### exceptions
* use exceptions only for exceptional conditions
    * don't use for ordinary control flow
* use checked exceptions for recoverable conditions and runtime exceptions for
  programming errors
    * Java provides three kinds of throwables: checked exceptions, runtime
      exceptions and errors.
    * all the unchecked throwables you implement shoudl subclass
      RuntimeExcpetion
* avoid unncessary use of checked exceptions
* favor the use fo standard exceptions
* throw exceptions appropriate to the abstraction
    * higher layers should catch lower-leverl exceptions and, int heir place,
      throw exceptions that can be explained in terms of the higher-level
      abstraction.
* doucment all exceptions thrown by each method
* include failure-capture information in detail messages
* strive for failure atomicity


## general notes


