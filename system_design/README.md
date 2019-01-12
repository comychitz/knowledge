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
* Database partitioning
    * Horizontal partitioning - put different rows into different tables.
        database shards are horizontal partitions of data. each of multiple
        shards is held on a separate database server to help load balance. like
        vertical partitioning is to normalization, database sharding is to
        horizontal partitioning - it goes further than just horizontal
        partitioning.
        * main disadvantage is the increased complexity in all aspects of
            interaction and maintainability of the database
    * [Wikipedia - Shard](https://en.wikipedia.org/wiki/Shard_(database_architecture))
    * Vertical partitioning - create tables with fewer columns - similar to
        normalizing approach. but vertional partitioning goes further on
        normalized data. For example, we might store more used vertical
        partitions on a different device, and less used tables in another
        device. 

## references
* https://www.hiredintech.com/classrooms/system-design/lesson/60 
