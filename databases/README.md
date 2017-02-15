#Databases
Some notes regarding database management systems.

##General Notes
* advantages of a DBMS include: data independence, efficient data access, data integrity and security, data administration, concurrent access and crash recovery, reduced application development time
* schema is a description of data in terms of a data model. example: Students(sid: string, name: string, login: string, age: integer, gpa: real) is a schema.
* a relation can be though of as a set of records. Each row of a relation (i.e. students relation) is a record transactions and locks
* Write-ahead log idea is the concept of writing a log before performing a read/write.
* time to recover from a crash can be reduced by periodically forcing some information to disk; this periodic operation is called a checkpoint
* Replacement Sort: the idea is to repeatedly pick the tuple in the current set with the smallest k value that is still greater than the largest k value in he output buffer. The chosen tuple must satisfy the condition that its k value be greater than or equal to the largest k value currently in the output bugger. When all tuples in the input buffer have been consumed in this manner, the next page of the file is read in. Of course, the output buffer is written out when it is full, thereby extending the current run (which is gradually built up on disk). When every tuple in the current set is smaller than the largest tuple in the output buffer, the output buffer is written out and becomes the last page in the current run. We then start a new run and continue the cycle of writing tuples from the input buffer to the current set to  the output buffer. This will produce runs of 2B pages long, on average.
* Disc access time = seek time + rotational delay + transfer time

##Storage & Indexing
* cost of io operations dominates the cost of typical database operations
* file of records. scan on files allows us to step through all records one at a time
* an index is a data structure that organizes data records on disk to optimize certain kinds of retrieval operations
* the term data entry is used to refer to the records stored in an index file
* a data entry with search key value k, denoted as k*, contains enough information to locate one or more data records with search key value k. 
* there are three main alternatives for what to store as a data entry in an index:
    1. a data entry k* is an actual data record (with search key value k)
    2. a data entry is a <k, rid> pair, where rid is the record id of a data record with search key value k
    3. a data entry is a <k, rid-list> pair, where rid-list is a list of record ids of data record with search key value k.
* when a file is organized so that the ordering of data records is the same as or close to the ordering of data entries in some index, we say that the index is clustered. An index that uses alternative 1 is clustered. Alternatives 2 and 3 can be a clustered index only if the data records are sorted on the search key field. Files are rarely kept sorted since its expensive, so in practice a clustered index is an index that uses 1; the other two are unclustered.
* an index on a set of fields that includes the primary key is called a primary index; other indexes are called secondary indexes.
* hashed-based indexing and tree based indexing
* Dense index: an index record appears for every search key value in file. This record contains search key value and a pointer to the actual record.
* Sparse index: index records are created only for some of the records. to locate a record we find the index record with the largest search key values less than or 
	equal to the search key value we are looking for. we start at that record pointer to by the index record, and proceed along the pointers in the file (that is, 
	sequentially) until we find the desired record.
* RAID Levels:
  * Level 0 - (nonredundant) data striping, 
  * Level 1 - Mirrored, 
  * Level 0+1 - Striping and Mirroring, 
  * Level 2: Error-correcting Codes, 
  * Level 3: Bit-Interleaved Parity, 
  * Level 4: Block-Interleaved Parity, 
  * Level 5: Block-Interleaved Distributed Parity, 
  * Level 6: P+Q Redundancy

##Papers
###Graefe paper: Modern B-Tree Techniques
* binary trees are used for in memory data and B-trees for on disk data. B-trees are good for on disk data because they can match the node size to the page size. B-trees are indexes optimized for pages environments. B-trees are balanced, with a uniform path length in root-to-leaf searches. This guarantees uniformly efficient search. B+ trees are different from traditional B-trees because they only stored user data in the leaves. if a b-tree contains N records and L records per leaf, the B-tree required N/L leaf nodes. The average number of children per parent is F, the number of branch levels is logF(N/L). often more than 99% of nodes in a B-tree are leaf nodes. B-trees vs Hash indexes: hash indexes should save IO costs due to a single IO per look-up whereas B-trees require a complete root-to-leaf traversal for each search. B-trees have advantages over hash indexes with respect to index creation, range predicates, sorted retrieval, phantom protection in concurrency control. The strongest argument for B-trees over hashed indexes pertain to multi-field indexes and to nonuniform distributions of key values. B-tree indexes are ubiquitous, whereas hash indexes are not, even though has indexes promise exact-match look up with direct address calculation in the hash directory and a single IO. page/node size is access time x transfer bandwidth. normalized keys - implementations of B-trees transform keys into a binary string such that simply binary comparisons suffice to sort the records during index creation and to guide a search in the B-tree to the correct record. duplicate keys are not desirable in B-trees because they lead to ambiguities especially when navigating from a primary to secondary index or during a deletion.

###Litwin paper - Linear Hashing
* if the hashing function is dynamically modified in the course of insertions or deletions we call it a virtual hashing function. 
* linear hashing is an algorithm that uses only a few bytes of core suffice now for a file of any size. for any number of insertions or deletions, the load of a file may therefore be high and record may be found, in general, in one access. a dynamic hashing function uses splits to reassign addresses to records.
* splits are performed iff a collision occurs are called uncontrolled. Splits are called controlled if they also depend on other conditions or are performed even if there is no collision.  A useful control is called load control. This is where a split is performed when a collision occurs, but only if the load factor is superior to some threshold. the inverse of splitting is grouping. if allocation is contiguous then linear hashing is almost as simple and fast as classical hashing
* if the bucket capacity is greater than 10 records, then almost any record is found in one access. vs trees linear hashing has simpler algorithms for search, for insertion and especially for deletion. also the case for concurrency control since only the key and the pointer must be locked, instead of a path in the tree.

###Stonebraker paper: Operating System Support for Database Management
* Summary: Several operating system services are examined with a view toward their applicability to support of database management functions. These services include buffer pool management; the file system; scheduling, process management, and interprocess communication; and consistency control.
* In order of an OS provided buffer pool manager to be attractive, the access overhead must be cut to a few hundred instructions (system call instructions). 
* Database access in INGRES is a combination of: 1) sequential access to blocks which will not be rereferenced 2) sequential access to blocks which will be cyclically rereferenced 3) random access to blocks which will not be rereferenced again 4) random access to blocks for which there is a nonzero probability of rereference.
* There is no way for an OS to implement the correct prefetch strategy
* DBMSs need to provide recovery from hard and soft crashes. The way a DBMS does this is through an intentions list. When the intentions list is complete, a commit flag is set. The last step of a transaction is to process the intentions list making the actual updates. During recovery from a crash the commit flag is examined. If it is set, the DBMS recovery utility processes the intentions list to correctly install the changes made by updates in progress at the time of the crash. If it is not set, the utility removes the intentions list, thereby backing out of the transaction. The page on which the commit flag exists must be forced to disk after all pages in the intentions list. The service required from an OS buffer manager is a selected force out which would push the intentions list and the commit flag to disk in the proper order.
* DBMSs want a record management system, which is not efficient when contribute on top of a character array object. 
* The simplest way to organize a multiuser database system is to have one OS process per user. The alternative organization is to allocate one run-time database process which acts as a server. The design of most operating systems strongly favors the first approach. Either way, both the server and per process model seem unattractive. 
* Most operating systems provide locking for files, but not many provide finer locks such as those on records and pages.
* DBMS prefers small efficient operating systems with only desired services. Real-time OSs are the only ones that get close to this ideal
