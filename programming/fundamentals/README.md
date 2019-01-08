# data structures & algorithms
Practice coding data structures and algorithms in C++.

- [algorithms overview](#algorithms-overview)
- [bit manipulation](#bit-manipulation)
- [o notation](#o-notation)
- [arrays](#arrays)
- [hash sets & tables](#hash-sets---tables)
- [linked lists](#linked-lists)
- [trees](#trees)
  * [tree properties](#tree-properties)
  * [tree traversal](#tree-traversal)
  * [binary search trees](#binary-search-trees)
- [heap](#heap)
  * [insertion](#insertion)
  * [deletion of root](#deletion-of-root)
- [graphs](#graphs)
  * [problems](#problems)
- [searching](#searching)
  * [binary search](#binary-search)
- [sorting](#sorting)
- [dynamic programming](#dynamic-programming)
- [threads and locks](#threads-and-locks)
- [hard problems](#hard-problems)
- [map reduce](#map-reduce)
- [References](#references)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>

## practice 
* [HackerRank](https://www.hackerrank.com/dashboard)
* [LeetCode](https://leetcode.com/problemset/all/)
* Cracking the Coding Interview - G. McDowell

## to learn/review
* algorithms review
    * designing algorithms
    * complexity analysis 
* mathematics
    * fundamentals(!)
    * prime numbers
    * probability
    * number theory
    * combinatorics
* database & sql basics
    * structured data
    * normalized vs denormalized
    * relational (sql) vs noSql
    * different database types
    * sql db indexes
    * sql, noSql, graphql
* security basics
    * public key crypto (RSA)
* networking basics
    * REST
    * OSI Model
    * streaming & up/down-loading

## algorithms overview
### divide and conquer
* **divide** the problem into a number of subproblems that are smaller
    instances of the same problem.
* **conquer** the subproblems by solving them recursively. If the subproblem
    sizes are small enough, however, just solve the subproblems in a
    straightforward manner.
* **combine** the solutions to the subporblems into the solution for the
    original problem.
* running time of divide-and-conquer algorithms can be represented using a
    *recurrence equation*, or *recurrence*. it often will help to build a
    recursion tree as well.
* examples
    * merge sort
    * maximum sub-array problem 
        * this can also be solved using Kadane's alg. in O(n) time
        * solved in O(nlog(n)) using divide and conquer
        * solved simply by iterating over every subarray in O(n^3) time

### greedy algorithms
* at each step, make a *greedy* decision on what to do next.

### dynamic programming
Dynamic programming is thought to be as the opposite approach that recursion
takes. Recursion is a top-down approach while dynamic programming is bottom-up.
Although dynamic programming uses recursion, it often solves a problem by
calculating all possibilities and then choosing the best one. Along with this,
*memoization* is used to improve efficiency, by storing values already calculated
previously.
DP = recursion + memoization + guessing
* memoize (remember) + re-use solutions to subproblems that help solve the
    problem
* time = # subproblems * time/subproblem
    * or, more precisely the sum of all subproblems
    * for fibonacci implemented using dynamic programming, n is the number of
        subproblems and the time per subproblem is constant (O(1))
* The two key attributes of a dynamic programming problem are:
    * optimal substructure
    * overlapping sub-problems
* references
    * [MIT OpenCourseWare - Dynamic Programming w/Eric Demaine](https://www.youtube.com/watch?v=OQ5jsbhAv_M)
* memoization
    * memoize - came from the idea of writing down your subproblem solutions on a
        memopad. to memoize is to write down on memopad, in other words, remember.
* bottom-up approach
    * exactly same computation as the memoized version
    * performing a topological sort of subproblem dependency DAG
    * can usually
* bottom-up vs top-down
    * bottom-up approach is breaking down a problem to a simple case (like a
        list with one element); or traversing to the leaves of a solution tree
        and working our way up. one key here is that we can use the solution of
        one case off of the previous case(s).
    * top-down approach is like memoization - define problem recursively and
        solve from top level downwards, caching results as you go.
    * [StackOverFlow Q/A](https://stackoverflow.com/questions/6164629/dynamic-programming-and-memoization-bottom-up-vs-top-down-approaches)
* 7 steps to solve a dynamic programming problem ([DP tutorial](http://blog.refdash.com/dynamic-programming-tutorial-example/))
    * recognize a DP problem
    * identify problem variables
    * clearly express the recurrence relation
    * identify the base cases
    * decide if you want to implement it iteratively or recursively
    * add memoization
    * determine time complexity
* Common problems solved using dynamic programming
    * fibonacci number
    * shortest path problem
    * the knapsack problem
    * egg dropping problem
    * edit distance problem
    * coin change problem

### five algorithm approaches
* exemplify
* pattern matching
* simplify and generalize
* base case and build
* data structure brainstorm

### [top 10 algorithm problems](https://www.geeksforgeeks.org/top-10-algorithms-in-interview-questions/)
* graphs
* linked lists
* dynamic programming
* sorting & searching
* trees & binary search trees
* number theory
* bit manipulation
* strings & arrays

### famous algorithms
*[15 important algorithms](https://interestingengineering.com/15-of-the-most-important-algorithms-that-helped-define-mathematics-computing-and-physics)*
* Euclid's algorithm for GCD
* PageRank
* Monte Carlo Method
* Kalman Filter
* QR algorithms for computing eigenvalues

## o notation
Big O notation, also called asymptotic notation, is a mathematical notation that
describes the limiting behavior of a function. It is used to analyze algorithms
as input size grows. The letter O is used because the growth rate of a function
is referred to as the *order of the function*.

The precise use of asymptotic notation is abused because big O notation isn't
completely accurate in all contexts. Technically, Big O gives the upper
asymptotic bound, Big Omega gives the lower bound, and Big Theta gives both.
* Θ-notation bounds a function to within constant factors.
* *O*-notation gives an upper bound for a function to within a constant factor.
* Ω-notation gives a lower bound for a function to within a constant factor.

"When we look at input size large enough to make only the order of growth of the
running time relevant, we are studying the *asymptotic* efficiency of
algorithms. That is, we are concerned with how the running time of an algorithm
increases with the size of the input *in the limit*, as the size of the input
increases without bound. **Usually, an algorithm that is asymptotically more
efficient will be the best choice for all but very small inputs.**"

| Notation | Name | Notes |
|---|---|---|
| O(1) | constant | 
| O(log n) | logarithmic |
| O(n) | linear |
| O(n log(n)) | linearithmic, loglinear, or quasilinear |
| O(n^2) | quadratic | 
| O(n^c) | polynomial |
| O(c^n) | exponential | where c > 1 
| O(n!) | factorial | 

### recursive runtime
* Recursive runtime of an algorithm will generall be: `O(branches^depth)`

### amortized analysis
Amortized analysis is used to analyze algorithms where an operation that doesn't
occur often is costly. For example, a dynamic array insertion takes O(1) time,
however, if the array is at its capacity *c*, adding c+1 elements causes it to
resize itself, which takes O(n) time. But if we analyze this using the
**aggregate method**, we can show that the amortized cost of insertion is O(1). 
`(nO(1) + O(n)) / (n + 1) = O(1)`

In addition to aggregate analysis, there is the **acounting method** and the
**potential method**.

## bit manipulation
* xor operation
    * tell whether two bits are unequal
    * it is an optional bit-flipper (the deciding input chooses whether to
        invert the data input)
    * it tells whether this is an odd number of 1 bits (A^B^C^D^E is true iff an
        odd number of the variables are true)
* tips and tricks
    * when doing additions, try and notice when one of the operands are 2^n,
        becuase we can just perform shifting if needed
* getting/clearing/setting bits in a number
    * getting a bit
        ```c++
           int mask = 1 << i; 
           return ((num&mask) != 0);
        ```
    * setting a bit
        ```c++
           int mask = 1 << i;
           return num | mask;
        ```
    * clearing a bit
        * opposite of setting a bit
        ```c++
           int mask = ~(1 << i);
           return num & mask;
        ```
    * clear bits MSB to i (inclusive)
        ```c++
           int mask = (1<<i)-1;
           return num & mask;
        ```
    * clear bits 0 to i (inclusive)
        ```c++
           int mask = (-1<<i);
           return num & mask;
        ```
 * Two's complement
  * To calculate the negative of K: `-K = concat(1, 2^(N-1) - K`
  * Or, flip all bits, then add 1 to the result.
    * One's complement is the same, just don't add 1 to the result.
  * When adding two numbers using two's complement results in an extra bit
      needed, we simply drop it.

## tips and tricks
### swapping two integers
* can swap two integers without temporary variable in the following ways:
```c++
int x = 10, y = 5;
x = x + y; // 15
y = x - y; // 10
x = x - y; // 5
// shorthand could be x=(x+y)-(y=x);
```
*can apply same method using multiply and divide*
* using xor
    * this method works because the result of xor-ing two numbers has the bits
        set for wherever the bits between the two numbers are unequal
```c++
int x = 10, y = 5;
x = x ^ y;
y = x ^ y;
x = x ^ y;
```

## arrays
* Dynamic vs static arrays

## inversions
* counting inversions is a common problem with arrays
* an inversion is when: `a[i] > b[j]` and `i < j`
* the number of inversions indicates how much work is needed to sort the array
* swapping a pair of consecutive elements that are in the wrong order removes
    exactly one inversion from the array. if a sorting algorithm can only swap
    consecutive elements, each swap removes at most one invesions, and the time
    complexity of the agorithm is at least O(n^2)
* counting invesions can be done using
    * simple nested for loop (O(n^2))
    * merge sort (O(nlog(n)))
    * BIT (binary indexed tree, aka Fenwick tree) (O(nlog(n)))

## hash sets & tables
* constant O(1) lookups & inserts (O(n) worst case, in case underlying array
    needs to be resized).

### hashing function
* the result of a hashing function for a hash table should be the index of the
    array the value is to be placed into. ideally, collisions should be as
    limited as possible

## linked lists
Linked lists is a data structure to typically keep an unordered sequence of
items. Insertion & deletion are *constant* time. All other operations are linear
with respect to the number of elements.

When solving problems with linked lists, there are several tricks to keep in
mind:
* recursion
* copying a node into another
* two runners; one fast, one slow
    * can be used to find loops in corrupted linked lists

## trees
Trees are ubiquitous in computer science/programming. They are a powerful data
structure for keeping track of ordered data and searching said data. There many
types of trees, each offering specific benefits. Some commonly used trees are:
* binary search trees
* heaps
* B-Trees & T-Trees
* Binary Tries

Trees are used for the purposes of:
* manipulating hierarchical data
* storing data to allow for efficent searching
* manipulating sorted lists of data

Some example applications where trees are used:
* Storing data in structures like maps and sets
* File system hierarchy
* Databases
* Router-tables

Common operations performed on trees:
* enumerating the tree or a section of it
* searching
* add/deleting an item to a specific position
* pruning: removing a section
* grafting: adding a section
* find the root for any node
* finding the lowest common ancestor of two nodes

### tree properties
* balanced vs unbalanced
* sorted vs unsorted
* full binary tree
    * a tree that all nodes besides last level has two children
* complete binary tree
    * a tree that has all levels but last filled, and the last level has nodes
        from the left populated
* tree symmetry
*

### tree traversal
* depth-first search
* breadth-first search
    * typical solution involves a queue
* in-order, pre-order, post-order traversal

### binary search trees
* rule for a binary search tree:
    * *for every node, the left child must be less or equal and the right
    child must be greater*
* all operations of a binary search tree are `O(log(n))`
* balanced binary search trees are efficient for performing operations because
    the time taken to perform an operation (ex. search) is directly
    proportional to the height of the tree.
* if a binary tree isn't balanced, and keys are added to the tree in sorted
    order, the tree will effectively become a linked list, with a height of n.
* traversals
    * depth first traversals: 
        * In Order - left, root, right
            * use case: gives ascending order of elements 
        * Pre Order - root, left, right
            * use case: create a copy of the tree
            * use case: get prefix expression of an expression tree
        * Post Order - left, right, root
            * use case: used to delete thre tree.
            * get postfix expression of an expression tree
* if we perform in-order traversal on a binary search tree, the result should be
    an ordered list of the elements
* self-balancing binary search trees:
    * AVL tree
    * B-tree
    * Red-black tree

#### red-black tree
* Operations: search, insert, remove (all O(log(n)))
* Criteria of the tree
    1. a node is either red or black
    2. the root and leaves (NULL) are black
    3. if a node is red, then its children are black
        * note that its ok for black nodes to have black children
    4. all paths from a node to its NULL descendents contain the same number of
       black nodes
        * when couting black nodes, we exclude the starting nodes color



### binary indexed tree
* [Wikipedia Article - Fenwick Tree](https://en.wikipedia.org/wiki/Fenwick_tree)
* A Fenwick tree or binary indexed tree is a data structure that can efficiently
    update elements and calculate prefix sums in a table of numbers.
    
### tries
* Tries, also referred to as a digital tree, radix tree or prefix tree is a kind of search tree. No node in the tree stores a value, instead the position of a node determines what key a node is associate with. All descendents of a node have a common prefix, with the root node having the empty value. 
* Tries are useful when you want to check if a string/value you are building is going to be valid. For example, if we had all words in the dictionary in a trie, we can easily check if a string we are building is going to be a legit word.

* radix/PATRICIA tree
    * a compressed version of a trie - rather than storing a character at each
        node, it stores several together when applicable. 
    * see [this stackoverflow q/q](https://stackoverflow.com/questions/14708134/what-is-the-difference-between-trie-and-radix-trie-data-structures)
    * [Wikipedia Article](https://en.wikipedia.org/wiki/Radix_tree)

## heap
A heap is a special-purpose tree structure that satisfies the heap property:
* if P is a parent of C, then the value of P must be greater or equal to (in a max heap) than the value of C.

A heap can be implemented using a tree as its underlying strucutre, but more
commonly implemented as an array since pointers are not required between
elements. In a binary heap that is implemented using an array the children of a
node can be calculated using `2n+1` and `2n+2`.

Heaps are commonly used to implemented priority queues.

### insertion
When adding a node to a heap, append to the end of the heap first, then
*sift-up* until the heap property is satisfied again. 
To *sift-up* simply compare the current node with its parent, if the heap
property is not satisfied, then swap the nodes. Repeat until property is
satisfied. Insertion time complexity is `O(log(n))`.

### deletion of root
A common operation is to pop the top of the heap, thus potentially causing the
heap property to become unsatisfied. To become a heap again, the last node is
placed at the top of the tree and sifted down until no longer needed. Deletion
time complexity is `O(log(n))`.

## graphs
A graph is mathematical structure used to model pairwise relations between
objects.  Graphs are a set of vertices and edges, where edges connect two
vertices together, typically carrying a weight. 

Operations:
* adjacent
* neighbors
* add/remove vertex/edge
* get edge/vertex value

Representations:
* adjacency list
    * slow to remove vertices and edges, because it needs to find all vertices
        or edges
* adjacency matric
    * slow to add or remove vertices, because matrix must be resized/copied
* Incidence matrix
    * slow to add or remove vertices and edges because matrics must be
        resized/copied
* *Adjacency lists are generally preferred because they efficiently represent
sparse graphs. An adjacency matrix is preferred if the graph is dense, that is
the number of edges |E | is close to the number of vertices squared, |V |2, or
if one must be able to quickly look up if there is an edge connecting two
vertices*

Properties of graphs:
* directed or undirected
* cyclic or acyclic graph

Classes of graphs:
* regular graph
* complete graph
* bipartite graph
* connected graph
* cycle graph
* tree

Problems that graphs data structures are used:
* enumeration
* graph coloring
* route problems
* network flow
* visibility problems
* covering problems

### problems
* traveling salesman problem
* dijkstra's shortest path 

## searching
Searching problems are ubiquitous in computer science. Storing values and
searching through them later is a common technique that aids in solving various
problems. There are many searching algorithms, some inefficient, but we'll keep
our focus on the better ones.

### binary search
* performs search on a sorted array in logarithmic time (average and worst case)
* O(log n) time complexity
* O(1) space complexity
* In C++ use the `lower_bound` and `upper_bound` functions to find the index in
    the array

## sorting
Ordering elements in a list.
* see Array Sorting Algorithms table on this page --> [bigocheetsheet.com](http://bigocheatsheet.com)

| Name | Best | Average | Worst | Space | Stable | Notes |
|---|---|---|---|---|---|---|
| Insertion Sort | O(n^2) | O(n^2) | O(n^2) | O(1) | yes | 
| Counting Sort | - | Θ(k + n) | Θ(k + n) | O(k) | yes |
| Radix Sort | Ω(n+k) | Θ(n+k) | O(n+k) | O(n+k) | - | uses a stable sort sub-alg.
| Quicksort | O(nlog(n)) | O(nlog(n)) | O(n^2) | O(n) | depends on implementation | 
| Mergesort | O(nlog(n)) | O(nlog(n)) | O(nlog(n)) | O(n) | yes |
| Heapsort | O(nlog(n)) (distinct keys) O(n) (equal keys) | O(nlog(n)) | O(nlog(n)) | O(1) | No |

*a sorting algorithm is said to be stable if two objects with equal keys appear
in the output in the same order they were in the input*

### sorting in linear time
* comparison sorting algorithms:
    * *the sorted order they determine is based only on comparisons between the
        input elements*
    * these types of algorithms run in O(nlog(n)) time.
* counting sort
* radix sort
* bucket sort

### simple sorting algos
* selection sort
    * find the min, replace with element at front. find the second min, replace
        with element at second. repeat. `O(n^2)`
* bubble sort
    * swap adjacent element until condition is met. `O(n^2)`

### radix sort
```
for i = 1 to d // d = number of digits
    use a stable sort to sort array A on digit i
```
* radix sort correct sorts numbers in Θ(d(n+k)) time if the stable sort takes
    Θ(n+k) time

# threads and locks
* deadlock
    * occurs if and only if all the *Coffman conditions* are true:
        * mutual exclusion: at least one resource must be held in a
            non-shareable mode. Otherwise, the processes would not be prevented
            from using the resource when necessary. Only one process can use the
            resource at any given time.
        * hold & wait (or resource holding): a process is currently holding at
            least one resource and requesting additional resource which are
            being held by other processes
        * no preemption: a resource can be released only voluntarily by the
            process holding it.
            * preemption is the act of interrupting a task being carried out by
                a computer system, without requiring its coorperation, and with
                the intention of resuming the task at a later time. context
                switches are a perfect example of preemption where a higher
                priveleged scheduler, which has the power to preempt, or
                interrupt tasks on the system.
        * circular wait: each proces must be waiting for a resource which is
            being held by another process, which in turn is waiting for the
            first process to release the resource.
* preventing deadlock
    * prevent one of the mentioned conditions from happening
    * the most common is to prevent the circular wait condition from occuring

# hard problems 
[A short guide to hard problems](https://www.quantamagazine.org/a-short-guide-to-hard-problems-20180716/)

| Label | Name | Description |
|---|---|---|
| P | Polynomial Time | Anything that a classic computer can solve in n^c time |
| BPP | Bounded-error Probabalistic Polynomial Time | Problems that can be quickly solved by algorithms that include a bit of randomness |
| BQP | Bounded-error Quantum Polynomial Time | All problems that are easy for a quantum computer to solve |
| NP | Non-deterministic Polynomail Time | A hard problem that can only be verified in polynomial time, no good solution exists yet |
| PH | Polynomial Heirarchy | A generalization of NP; all problems of NP when adding more complexity |
| PSPACE | Polynomial Space | Problems that can be solved with reasonable amount of memory |
| EXPTIME | Exponential Time | All problems that can be solved in an exp. amount of time by a classical computer |

# map reduce
* a programming model for processing big data sets with a parallel, distruted
    algorithm on a cluster.
* map reduce systems are a specialization of the split-apply-combine strategy
* inspired by the map & reduce functions in functional programming, but not used
    in the same exact way.

## traditional map, filter & reduce
* map 
    * a function that applies the same function to all objects of a list and
        returns the resulting list
    ```javascript
    const numbers = [2,4,8,10];
    const halves = numbers.map(x => x/2);
    // halves is [1,2,4,5]
    ```
* filter
    * same concept as map, except items that only pass the filter are returned
        in the resulting list
* reduce
    * reduce applies a function against an accumulator and each element in the
        array (from left to right) to reduce it to a single value
    ```javascript
    const total = [0, 1, 2, 3].reduce((sum, value) => sum + value, 1);
    // total is 7
    ```

## References
* [Tree (Data Structure) - Wikipedia](https://en.wikipedia.org/wiki/Tree_(data_structure))
* [Know Thy Complexities!](http://bigocheatsheet.com)
* [Data Structures Reference - InterviewCake](https://www.interviewcake.com/data-structures-reference)
