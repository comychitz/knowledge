# system design
Notes and practice problems for handing systems design problems.


## Example Problems
* Given a (typically) long URL, how would you design a service that would
    generate a shorter and unique alias for it.

    - Approach
        - input is URL -> output is short URL
        - need to create a unique identifier for input URL
            - can simply create UUIDs for URLS
            - or can hash URLs
