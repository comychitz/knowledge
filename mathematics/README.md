# mathematics
*"the Queen of the Sciences" - Carl Friedrich Gauss*

## why prime numbers are so important
To mathematicians, prime numbers are equivalent to atoms - they can't be broken
down to any smaller piece. Other natural numbers that can be broken down, known
as *composites*, have been proven to have a *prime factorization*. In other
words, they can be composed of only prime numbers - this is known as the
*Fundamental thereom of arithmetic*. 

There are many applications that make use of prime numbers in science and
engineering, which is why unlocking the key to producing and/or verifying prime
numbers is an important open problem in the world of mathematics. 

Moreover, prime numbers have also shown to have interesting properties, such as:
* (TODO)

## why log?
Why is the *logarithm* function so important and frequently used in engineering?
Well, there are many answers to that question, but let's try and breakdown why
*log* is so powerful and also show some practical applications of it.

*log* is the inverse function to exponentiation. In other words, taking the
logarithm of a value `x` results in the exponent that is required to apply to
the base of the logarithm to result with x.
```
logb(x) = y  b^y = x
```

Logarithms have many applications in science and engineering. Logarithms were
first introduced by John Napier in the 1700s to offer the ability to more easily
perform computations using slide rules and log tables. However, the modern day
notion of logarithms stems from Leonhard Euler's discovery linking them to
exponential function.

Logarithmic scales and graphs are often used when data sets need to be visually
presented, especially when the data covers a large range of values or contain
exponential laws or power laws (these will show up as straight lines). This is
helpful when viewing the data as it allows readers to see trends that aren't
visible when viewing on a linear scale.

[[Logarithm (Wikipedia)](https://en.wikipedia.org/wiki/Logarithm)]

## number theory
* A branch of mathematics that studies integers. 

## permutations & combinations
"A combination lock should really be called a permutation lock" :) 

* permutations 
    * are for lists (order matters)
    * possibilities of picking k out of n total items:
        `P(n,k) = n! / (n-k)!`
    * in programming, can solve permutation of a string by the following
        algorithm:
        * use recursion(!)
        * base case is when string is empty or size 1
        * then, insert the outter char in every spot of a permutation of the
            substring
* combinations 
    * are for groups (order doesn't matter)
    `C(n,k) = P(n,k) / k! = n! / (n-k)!k!`
    
* *Combinations are always less than permutations* 

* factorial
    * most commonly used to compute the total amount of ways to arrange n
        distinct objects. `n!`
    * often appears in the denominator of a formala when ordering is to be
        ignored
    * 0! = 1.
        * there is only one permutation of zero objects

## series
* consecutive integers sum: `n(n+1)/2` ([proof](https://math.stackexchange.com/questions/2260/proof-for-formula-for-sum-of-sequence-123-ldotsn))

### fibonacci
* `F(n) = F(n-1) + F(n-2)`
* Binet's formula: `((1+sqrt(5))^n - (1-sqrt(5))^n)/(sqrt(5)*2^n)`

### arithmetic progression
* a sequence of numbers where the diffrenec between any two consecutive numbers
    is constant.
* sum can be calculated as: `n(a+b)/2` where a is the first number of the series
    and b is the last

### geometic progression
* a sequnece of numbers where the ration between any two consecutive numbers is
    constant
* sum can be calculated as: `bk - a / k - 1` where a is the first number, b is
    the last number and k is the ration between consecutive numbers

### harmonic series
* `1 + 1/2 + 1/3 + 1/4 ... + 1/n`
* upper bound of sum is `log(n) + 1` (log base 2)
