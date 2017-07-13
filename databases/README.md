# Databases
Some notes regarding database management systems.

## General Notes
* advantages of a DBMS include: data independence, efficient data access, data integrity and security, data administration, concurrent access and crash recovery, reduced application development time
* schema is a description of data in terms of a data model. example: Students(sid: string, name: string, login: string, age: integer, gpa: real) is a schema.
* a relation can be though of as a set of records. Each row of a relation (i.e. students relation) is a record transactions and locks
* Write-ahead log idea is the concept of writing a log before performing a read/write.
* time to recover from a crash can be reduced by periodically forcing some information to disk; this periodic operation is called a checkpoint
* Replacement Sort: the idea is to repeatedly pick the tuple in the current set with the smallest k value that is still greater than the largest k value in he output buffer. The chosen tuple must satisfy the condition that its k value be greater than or equal to the largest k value currently in the output bugger. When all tuples in the input buffer have been consumed in this manner, the next page of the file is read in. Of course, the output buffer is written out when it is full, thereby extending the current run (which is gradually built up on disk). When every tuple in the current set is smaller than the largest tuple in the output buffer, the output buffer is written out and becomes the last page in the current run. We then start a new run and continue the cycle of writing tuples from the input buffer to the current set to  the output buffer. This will produce runs of 2B pages long, on average.
* Disc access time = seek time + rotational delay + transfer time
* RAID Levels:
  * Level 0 - (nonredundant) data striping, 
  * Level 1 - Mirrored, 
  * Level 0+1 - Striping and Mirroring, 
  * Level 2: Error-correcting Codes, 
  * Level 3: Bit-Interleaved Parity, 
  * Level 4: Block-Interleaved Parity, 
  * Level 5: Block-Interleaved Distributed Parity, 
  * Level 6: P+Q Redundancy
* conjunction is ADD. selection conditions are first converted to be in conductive normal form. ex. (something V something) ^ (something V something)
* projection (or DISTINCT in the SQL query) removes duplicates
  * sorting approach - sort then remove duplicates, or remove duplicates while sorting
  * algorithm: 1. scan R and produce a set of tuples that contain only the desired attributes, 2. Sort this set of tuples using the combination of all its attributes as the key sorting, 3. San the sorted result, comparing adjacent tuples, and discard duplicates
  * hashing - hash to create partitions, load partitions into memory one at a time, build an in-memory hash structure and eliminate duplicates within it
* statistics in catalogs: # tuples, and # pages for each relation. # distinct key values and # pages for each index. index height,low/high key values for each tree index. updated periodically, not after every single change
* reduction factor (RF) associate with term reflects the impact of the term in reducing result size. Result cardinality = Max # tuples * product of all RF’s
* Relational Operators: Others
  * Approaches to conjunctive selections: 1. Find the most selective path, retrieve tuples using it, and apply an remaining (“residual”) terms that don’t match the index 2. Intersection of Ridlists (if we have 2 or more matching indexes that use ridlists - or keylists - in the leaves): get sets of rids of data records using each matching index, intersect these sets of rids, retrieve those records and apply any remaining terms
  * The projection operations
    * an approach based on sorting: modify pass 0 of external sort to eliminate unwanted fields, modify merging passes to eliminate duplicates, Cost: In pass 0, read original relation (size M), write out same number of smaller tuples. In merging passes, fewer tuples written out in each pass. Using Reserves example, 1000 input pages become 250 after Pass 0 if 0.25 size ratio.
    * based on hashing. 2 phases: partitioning phase: read R using one input buffer. for each tuple, discard unwanted fields and do hash h1(whole tuple_ to pick one of B-1 output buffers. results is B-1 partitions (of tuples w/o unwanted fields). 2 tuples in different partitions are sure to be distinct; duplicate elimination phase: for each partition, read it and build an in-memory hash table using hash h2 (<> h1) on all fields, discarding duplicates; cost: for partition, read R, write out each tuple, but with fewer fields. Less data read in next phase
* BigData and MapReduce
  * map - processes one input key/value pair and produces a set of intermediate key/value pairs
  * reduce - combines intermediate value for one particular key. Produces a set of merged output values (usually one)
  word count example:
  ```C
reduce(String key, Iterator values):
	// key: a word
	// values: a list of counts
	int result = 0;
	for each v in values:
		result += ParseInt(v);		Emit(AsString(result))

map(String key, String value):
	// key: document name
	// value: document contents
	for each word w in value:
		EmitIntermediate(w,”1”)
  ```
* Column Stores
  * 3 benefits: read efficiency, compression efficiency, sorting & indexing efficiency
  * storage layout: columnar storage, header/ID elimination, compression, multiple sort orders. 
  * execution engine: column operators, avoid decompression, late materialization, vectored operations
  * applications: data warehousing (high end, mid end/mass market, personal analytics), data mining, Google bigTable, RDF (triple store) (semantic web data management), scientific datasets, information retrieval
  * no fundamental differences between row and column stores. can not efficiently simulate column-stores with row-stores
  * on disk layout vs execution layout. mixed layout schemes (fractured mirrors, PAX, clotho, data morphing)
  * crucial columnar techniques: storage, compression, late vs early materialization, execution (vectorized in-cache execution, exploiting SIMD)
* Spatial Indexes
  * Finding which ones overlap Q: Start at root; If current node is non-leaf, for each entry <E, ptr>, if box E overlaps Q, search subtree identified by ptr; If current node is leaf, for each entry <E, rid>, if E overlaps Q, rid identifies an object that might overlap Q
  * Insert Entry <B,ptr>
    * Start at root and go down to “best-fit” leaf L. Go to child whose box needs least enlargement to cover B; resolve ties by going to smallest area child
    * If best-fit leaf L has space, insert entry and stop. Otherwise split L into L1 and L2 - Adjust entry for L in its parents so that the box now covers (only) L1. Add an entry (in the parent node of L) for L2.
    * Splitting: Redistribute so as to minimize area of L1 plus area of L2
  * Deletions consists of searching for the entry to be deleted, removing it, and if the node becomes under-full, deleting the node and then re-inserting the remaining entries.
* Query Optimization I
  * Enumeration of alternative plans
    * Two main cases:
      * single-relation plans
      * multiple-relation plans
    * For queries over a single relation, queries consist of a combination of selects, projects, and aggregate ops:
      * each available access path (file scan / index) is considered, and the one with the least estimated cost is chosen.
      * the different operations are essentially carried out together (e.g., if an index is used for a selection, projection is done for each retrieved tuple, and the resulting tuples are pipeline into the aggregate computation)
  * Cost estimates for single-relation plans
    * Index I on primary key matches selection: Cost is Height(I) + 1 for a B+ tree, about 1.2 + 1 for hash
    * Clustered index I matching one or more selects: (NPages(I) + NTuples(R)) * product of RF’s of matching selects
    * Sequential scan of file:  NPages(R)
  * Multiple Relations
    * fundamental decision in System R: only left-deep join trees are considered. they allow us to generate all fully pipeline plans. not all left-deep trees are fully pipelined
    * Enumeration of Left-deep plans
      * left deep plans differ only in the order of relations, the access method for each relation, and the join method chosen for each join.
      * Enumerated using N passes (if N relations joined):
        * Pass 1: find best 1-relation plan for each relation
        * Pass 2: find best way to join result of each 1-relation plan (As outer) to another relations (all 2-relation plans)
        * Pass N: find best way to join result of a (N-1)-relation plan (as outer) to the N’ th relations (All N-relation plans)
      * for each subset of relations, retain only:
        * cheapest plan overall, plus cheapest plan for each interesting order of the tuples
  * Note on interesting orders:
    * a given data order is deemed “interesting” if it has the potential to save work later on
      * ordering on join attribute(s), GROUP BY attribute(s), DISTINCT attribute(S), ORDER BY attribute(S)
  * Cost estimation for multi-relation plans
    * Consider the query block to the right:
    * Maximum # tuples in result is the product of the cardinalities of relations in the FROM clause
    * Reduction factor (RF) associated with each term reflects the impact of the term in reducing result size. Result cardinality = mAx # tuples * product of all RF’s 
    * multi-relation plans are built up by joining one new relation at a time
      * cost of join method, plus estimation of join cardinality, gives us both a cost estimate and a result size estimate
  * System R recap
    * Single relation queries:
      * all access paths considered, cheapest chosen
      * Issues selections that match index, weather index key has all needed fields or provides tuples in an interesting order
    * Multiple relation queries:
      * All single-relation plans are first enumerated
      * selections/projections considered as early as possible
      * Next, for each 1-relation plan, all ways of ******* another relation (as inner) are considered
      * Next , for each 2 relation plan that is ****, all ways of joining one more relations (as inner) are considered, etc.
      * At each level, for each subset of relations only the best plan for each interesting order of tuples is retained

* Query Optimization II
  * stats kept in catalogs:
    * For each relation R: cardinality of R (|R|), avg R-tuple width, and # of pages in R (||R||) - pick an 2 to know all 3 (given the page size)
    * For each indexed attribute of R: number of distinct values |πA(R)|, range of values (low and high values), number of index leaf pages, number of index level (if B+ tree)


## Storage & Indexing
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
* Sparse index: index records are created only for some of the records. to locate a record we find the index record with the largest search key values less than or equal to the search key value we are looking for. we start at that record pointer to by the index record, and proceed along the pointers in the file (that is, sequentially) until we find the desired record.
* a tree index matches (a conjunction of) terms that involve only attributes in a prefix of the search key. e.g. tree index on <a,b,c> matches the selection a=5 AND b=3, and a=5 and b>6, but not b=3
* a hash index matches (a conjunction of) terms that has a term attribute = value for every attribute in the search key of the index. e.g. hash index on <a,b,c> matches a=5 AND b=3 AND c=5, bu not b=3, or a=5, pr a>5 AND b=3 AND c=5.

## Parallel Database Systems
* Reasons for success: Set oriented processing, natural pipelining (relational operators/trees), inexpensive hardware can do the trick, users/app-programmers don’t need to think in parallel. speed-up and scale-up (increase in data and hardware should result in constant time). shared memory (SMP) vs shared disk vs shared nothing (network). 
* different types of parallel DBMS: intra-operator parallelism - get all machines working together to compute a given operation (scan, sort, or join), inter-operator parallelism - each operator may run concurrently on a different site (exploits pipelining), inter-query parallelism - completely different queries run on different sites
* partitioning - shared nothing benefits from good partitioning: range - good for equijoins, exact-match queries, and range queries; hash - good for equijoins, exact match queries; round robin - good to spread load
* parallel scans/selects: scan in parallel and merge; selection may not require all sites for range or hash partitioning, but always does for round robin; indexes can be constructed on each partition; secondary indexes: become troublesome in the face of partitioning; can partition them via base table key; can partition by secondary key ranges; Teradata’s solution: partition non-unique indices by base table key. partition unique indices by secondary key
* broadcast join - send the tuples of the outer relation to all sites with a partition of the inner relation. In parallel, join the outer relation with each partition of the inner relation using Index NL Join
* Parallel sorting: scan in parallel, range partition as you go; as tuples arrive, perform “local” sorting; resulting data is sorted and range-partitioned (i.e. spread across system in known way); just one potential problem: Skew! ; solution: “sample” the data at the outset to determine good range partitioning points
* complex plans: allow for pipeline-parallelism, but sorts and hashes necessarily block the pipeline; partitioned parallelism achieved via bushy trees; parallel query optimization
  * common approach: 2 phases: pick best sequential plan (System R algorithm); then pick degree of parallelism based on current system parameters
  * “Bind” operators to processors: Take query tree, “decorate” it with site assignment as in previous picture
* Cost estimates for single-relation plans
  * Index I on primary key matches selection: Cost is Height(I) + 1 for a B+ tree, about 1.2 + 1 for hash
  * Clustered index I matching one or more selects: (NPages(I) + NTuples(R)) * product of RF’s of matching selects
  *  Sequential scan of file:  NPages(R)
* stats kept in catalogs:
  * For each relation R: cardinality of R (|R|), avg R-tuple width, and # of pages in R (||R||) - pick an 2 to know all 3 (given the page size)
  *  For each indexed attribute of R: number of distinct values |πA(R)|, range of values (low and high values), number of index leaf pages, number of index level (if B+ tree)
* a given data order is deemed “interesting” if it has the potential to save work later on
  * ordering on join attribute(s), GROUP BY attribute(s), DISTINCT attribute(S), ORDER BY attribute(S)


## Papers
### Graefe paper: Modern B-Tree Techniques
* binary trees are used for in memory data and B-trees for on disk data. 
* B-trees are good for on disk data because they can match the node size to the page size. 
* B-trees are indexes optimized for pages environments. 
* B-trees are balanced, with a uniform path length in root-to-leaf searches. This guarantees uniformly efficient search. 
* B+ trees are different from traditional B-trees because they only stored user data in the leaves. 
* if a b-tree contains N records and L records per leaf, the B-tree required N/L leaf nodes. 
* The average number of children per parent is F, the number of branch levels is logF(N/L). often more than 99% of nodes in a B-tree are leaf nodes. 
* B-trees vs Hash indexes: hash indexes should save IO costs due to a single IO per look-up whereas B-trees require a complete root-to-leaf traversal for each search. 
* B-trees have advantages over hash indexes with respect to index creation, range predicates, sorted retrieval, phantom protection in concurrency control. 
* The strongest argument for B-trees over hashed indexes pertain to multi-field indexes and to nonuniform distributions of key values. 
* B-tree indexes are ubiquitous, whereas hash indexes are not, even though has indexes promise exact-match look up with direct address calculation in the hash directory and a single IO. 
* page/node size is access time x transfer bandwidth. 
* normalized keys - implementations of B-trees transform keys into a binary string such that simply binary comparisons suffice to sort the records during index creation and to guide a search in the B-tree to the correct record. 
* duplicate keys are not desirable in B-trees because they lead to ambiguities especially when navigating from a primary to secondary index or during a deletion.

### Litwin paper - Linear Hashing
* if the hashing function is dynamically modified in the course of insertions or deletions we call it a virtual hashing function. 
* linear hashing is an algorithm that uses only a few bytes of core suffice now for a file of any size. for any number of insertions or deletions, the load of a file may therefore be high and record may be found, in general, in one access. a dynamic hashing function uses splits to reassign addresses to records.
* splits are performed iff a collision occurs are called uncontrolled. Splits are called controlled if they also depend on other conditions or are performed even if there is no collision.  A useful control is called load control. This is where a split is performed when a collision occurs, but only if the load factor is superior to some threshold. the inverse of splitting is grouping. if allocation is contiguous then linear hashing is almost as simple and fast as classical hashing
* if the bucket capacity is greater than 10 records, then almost any record is found in one access. vs trees linear hashing has simpler algorithms for search, for insertion and especially for deletion. also the case for concurrency control since only the key and the pointer must be locked, instead of a path in the tree.

### Stonebraker paper: Operating System Support for Database Management
* Summary: Several operating system services are examined with a view toward their applicability to support of database management functions. These services include buffer pool management; the file system; scheduling, process management, and interprocess communication; and consistency control.
* In order of an OS provided buffer pool manager to be attractive, the access overhead must be cut to a few hundred instructions (system call instructions). 
* Database access in INGRES is a combination of: 1) sequential access to blocks which will not be rereferenced 2) sequential access to blocks which will be cyclically rereferenced 3) random access to blocks which will not be rereferenced again 4) random access to blocks for which there is a nonzero probability of rereference.
* There is no way for an OS to implement the correct prefetch strategy
* DBMSs need to provide recovery from hard and soft crashes. The way a DBMS does this is through an intentions list. When the intentions list is complete, a commit flag is set. The last step of a transaction is to process the intentions list making the actual updates. During recovery from a crash the commit flag is examined. If it is set, the DBMS recovery utility processes the intentions list to correctly install the changes made by updates in progress at the time of the crash. If it is not set, the utility removes the intentions list, thereby backing out of the transaction. The page on which the commit flag exists must be forced to disk after all pages in the intentions list. The service required from an OS buffer manager is a selected force out which would push the intentions list and the commit flag to disk in the proper order.
* DBMSs want a record management system, which is not efficient when contribute on top of a character array object. 
* The simplest way to organize a multiuser database system is to have one OS process per user. The alternative organization is to allocate one run-time database process which acts as a server. The design of most operating systems strongly favors the first approach. Either way, both the server and per process model seem unattractive. 
* Most operating systems provide locking for files, but not many provide finer locks such as those on records and pages.
* DBMS prefers small efficient operating systems with only desired services. Real-time OSs are the only ones that get close to this ideal

### AsterixDB paper
* well suited for application like web data warehousing, social data storage and analysis, and other use cases related to Big Data. AsterixDB has a flexible NoSQL style data model; a query language that supports a wide range of queries; a scalable runtime; partitioned LSM-based data storage and indexing (including B+-tree, R-tree and text indexes)
* key features desired: 1) a flexible, semistructured data model for use cases ranging from “schema first” to “schema never” 2) a full query language with at least the power of SQL 3) an efficient parallel query runtime 4) support for data management and automatic indexing 5) support for a wide range of query sizes, with processing cost proportional to the task at hand 6) support for continuous data ingestion 7) the ability to scale gracefully in order to manage and query large volumes of data by using large clusters 8) support for today’s common “Big Data data types” (e.g. textural, temporal and spatial data)
* open vs closed data types - open datatypes are allowed to have additional content, beyond what the type specifies, as long as they at least contain the information prescribed by the datatype definition.
* each AsterixDB dataset is stored and indexed as a B+ tree key on primary key; secondary indexes point to indexed data by its primary key
* offers external data adaptors to access local files that reside on the Node Controller of an AsterixDB cluster and to access data residing in HDFS. 
* Data fees are a built-in mechanism to allow new data to be continuous ingest into one or more Datasets from external sources, incrementally populating the Datasets and their associated indexes.
* query language for AsterixSB is Asterix Query language. It is an expression language (1+1 is allowed, etc). FLWR = for-let-where-order-by-return
* Hyracks is the runtime layer whose responsibility is to accept and manage data-parallel computations requested either by one of the layers above it in the Asterix software stack or potentially by direct end-users of Hyracks.
* supports record-level transactions across multiple LSM indexes in a Dataset. Concurrency control in AsterixDB is based on 2PL


