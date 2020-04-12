# system design

Let's talk about how different types of systems can be designed, along with
techniques and technologies used to build them.

## general notes
* VPS vs Web-Hosting
* Vertical Scaling
    * Add more/faster/state-of-the-art hardware
    * Bounded by single-machine constraints
* Horizontal Scaling
    * Distribute between many different slower machines
* Load Balancing
    * all servers do the same
    * each server has a dedicated responsibility
    * round robin
    * can be software or hardware
    * active vs passive load balancer roles
* Caching
    * memcached
    * Redis
* Replication
    * Master - Slave(s) setup
    * Master - Master setup, each master has their own slave(s)
    * With master slave replication all writes are done on the master and all
        reads can be done from the slave(s).
* Normalized vs Denormalized DBs
    * normalized databases are designed to minimize redundancy
    * denormalized databases are design to optimize read time
* Database partitioning
    * Horizontal partitioning - put different rows into different tables.
        database shards are horizontal partitions of data. each of multiple
        shards is held on a separate database server to help load balance. like
        vertical partitioning is to normalization, database sharding is to
        horizontal partitioning - it goes further than just horizontal
        partitioning by allowing partitions (shards) to be distributed amongst
        multiple servers
        * main disadvantage is the increased complexity in all aspects of
            interaction and maintainability of the database
    * [Wikipedia - Shard](https://en.wikipedia.org/wiki/Shard_(database_architecture))
    * Vertical partitioning - create tables with fewer columns - similar to
        normalizing approach. but vertical partitioning goes further on
        normalized data. For example, we might store more used vertical
        partitions on a different device, and less used tables in another
        device.
* ACID database transactions
    * [Wikipedia - ACID](https://en.wikipedia.org/wiki/ACID_(computer_science))
    * atomicity
        * a transaction (even if multiple statements) either succeeds complete
            or fails completed
    * consistency
        * the requirement that any database transaction should only change
            affected data in allowed ways. in other words, any data written to
            the database must be valid according to the rules (constraints,
            cascades, triggers)
    * isolation
        * ensures that concurrent execution of transactions leaves the database
            in the same state that would have been if executed sequentially
    * durability
        * guarantees that if a transaction is committed, it will stay committed
            even if system failure

## relational vs non-relational database
* relational database use cases
    * when the data your storing is clearly structured and defined - and also
        has the tendency not to change
    * requires up-front investment to figure out how the data is going to be
        stored in the db
    * they are safer, supporting the ACID requirements
    * more popular and standardized - everyone knows SQL
    * responds well to vertical scaling - not horizontal (though some now
        support it, but it is a complex thing to setup in comparison to
        non-relational dbs)
* non-relational database use cases
    * data format/definition is constantly changing
    * scalability is a hard requirement - non-relational databases support
        horizontal scaling and sharding much better
    * stale reads are a problem in non-relational dbs
* non-relational database types
    * column-oriented
    * document-oriented
    * key-value
    * graph

## references
* https://www.hiredintech.com/classrooms/system-design/lesson/60
