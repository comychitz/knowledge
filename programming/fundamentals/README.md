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
- [References](#references)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>

## algorithms overview
* divide and conquer
* greedy algorithm
* dynamic programming
* five algorithm approaches
    * exemplify
    * pattern matching
    * simplify and generalize
    * base case and build
    * data structure brainstorm

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

## o notation
Big O notation, also called asymptotic notation, is a mathematical notation that
describes the limiting behavior of a function. It is used to analyze algorithms
as input size grows. The letter O is used because the growth rate of a function
is referred to as the *order of the function*.

The precise use of asymptotic notation is abused because big O notation isn't
completely accurate in all contexts. Technically, Big O gives the upper
asymptotic bound, Big Omega gives the lower bound, and Big Theta gives both.

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

## arrays
* Dynamic vs static arrays

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

## heap
A heap is a special-purpose tree structure that satisfies the heap property:
    * *if P is a parent of C, then the value of P must be greater or equal to (in
    a max heap) than the value of C.*

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

## sorting
Ordering elements in a list.

| Name | Best | Average | Worst | Space | Stable | Notes |
|---|---|---|---|---|---|---|
| Quicksort | O(nlog(n)) | O(nlog(n)) | O(n^2) | O(n) | depends on implementation | 
| Mergesort | O(nlog(n)) | O(nlog(n)) | O(nlog(n)) | O(n) | yes |
| Heapsort | O(nlog(n)) (distinct keys) O(n) (equal keys) | O(nlog(n)) | O(nlog(n)) | O(1) | No |

*a sorting algorithm is said to be stable if two objects with equal keys appear
in the output in the same order they were in the input*

## dynamic programming
Dynamic programming is thought to be as the opposite approach that recursion
takes. Recursion is a top-down approach while dynamic programming is bottom-up.
Although dynamic programming uses recursion, it often solves a problem by
calculating all possibilities and then choosing the best one. Along with this,
*memoization* is used to improve efficiency, by storing values already calculated
previously.

### references
* [MIT OpenCourseWare - Dynamic Programming w/Eric Demaine](https://www.youtube.com/watch?v=OQ5jsbhAv_M)

### memoization
* memoize - came from the idea of writing down your subproblem solutions on a
    memopad. to memoize is to write down on memopad, in other words, remember.

### bottom-up approach
* exactly same computation as the memoized version
* performing a topological sort of subproblem dependency DAG
* can usually

DP = recursion + memoization + guessing
* memoize (remember) + re-use solutions to subproblems that help solve the
    problem
* time = # subproblems * time/subproblem
    * or, more precisely the sum of all subproblems
    * for fibonacci implemented using dynamic programming, n is the number of
        subproblems and the time per subproblem is constant (O(1))

The two key attributes of a dynamic programming problem are:
* optimal substructure
* overlapping sub-problems

7 steps to solve a dynamic programming problem ([DP tutorial](http://blog.refdash.com/dynamic-programming-tutorial-example/))
* recognize a DP problem
* identify problem variables
* clearly express the recurrence relation
* identify the base cases
* decide if you want to implement it iteratively or recursively
* add memoization
* determine time complexity

Common problems solved using dynamic programming
* fibonacci number
* shortest path problem
* the knapsack problem
* egg dropping problem

# threads & locks
* deadlock
    * occurs if and only if all the *Coffman conditions* are tru:
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

## References
* [Tree (Data Structure) - Wikipedia](https://en.wikipedia.org/wiki/Tree_(data_structure))
* [Know Thy Complexities!](http://bigocheatsheet.com)
* [Data Structures Reference - InterviewCake](https://www.interviewcake.com/data-structures-reference)
