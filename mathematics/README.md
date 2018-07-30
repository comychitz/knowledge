# mathematics
*"the Queen of the Sciences" - Carl Friedrich Gauss*

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
    * most commonly used to compute the total amount of ways to arrand n
        distinct objects. `n!`
    * often appears in the denominator of a formala when ordering is to be
        ignored
    * 0! = 1.
        * there is only one permutation of zero objects

