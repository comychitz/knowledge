# cloud computing
some notes about computing in the *cloud*.

## general notes
* the NIST's definition of cloud computing identifies 5 characteristics:
    * On-demand self-service
    * Broad network access
    * Resource pooling
    * Rapid elasticity
    * Measured service
* service-oriented architecture
    * Infrastructure as a Service (IaaS)
        * provides virtual hardware from a provider with adjustable
            configuration/scalability
        * example, Amazon's EC2
    * Software as a Service (SaaS)
        * "on-demand software" that is licensed on a subscription basis and is
            centralized
        * has a very lightweight client, usually interface through one's browser
    * Platform as a Service (PaaS)
        * in between IaaS and Saas
        * with PaaS, server management is handled by the provider whereas in
            IaaS the user still needs to manage their server
    * Database as a Service (DaaS)
        * example, Amazon's RDS

## aws
* amazon web services
* benefits:
    * prevent large capital expenses at the beginning or IT resources
    * scalability
    * no need to guess how much resources you need
    * quickly get up to speed and developing your product(s)
* aws by category:
    * core services
    * platform services
    * development and operations services
* aws regions
    * availability zone within regions
    * can use for replication/redundancy
    * each region is made up of two or more availability zones
    * edge locations
* AWS marketplace
* hypervisor
    * aws uses a hypervisor running on the host machines to allow multiple operating
        systems to run on the same computer
    * hypervisor manages virtualization at the hardware level while containers
        manage virtualization at the operating system level
    * two main types:
        * native/bare metal hypervisor - hypervisor runs directly on
            hardware
        * hosted hypervisor - hypervisor runs on top of an OS
    * [wikiArticle](https://en.wikipedia.org/wiki/Hypervisor)
    * [KVM - Kernel-based Virtual Machine](https://en.wikipedia.org/wiki/Kernel-based_Virtual_Machine)

### dynamo db
* a primary key in DDB is either a partition key or a partition + sort key (aka composite key)
  * the primary key has to be unique (whether composite or not)
* A GSI (Global Secondary Index) can be defined to support more access patterns
  * GSIs are eventually consistent. they are updated as the table changes
  * the primary key of a GSI is not required to be unique
  * because GSIs take up storage, it is best to minimize the number of them.
* data is replicated to three availability zones in the region
* cost (https://aws.amazon.com/dynamodb/pricing/)
  * 1/2 Read Capacity Unit (RCU) = 4KB data read (eventually consistent)
    * strong consistent read of 4KB = 1 RCUs
    * strong consistent transaction read of 4KB = 2 RCUs
  * 1 Write Capacity Unit (WCU) = 1KB data write
    * transaction write of 1KB = 2 write units
  * checkout the cost calculator to project monthly costs
    * https://calculator.s3.amazonaws.com/index.html
* good videos to watch
  * https://www.youtube.com/watch?v=6yqfmXiZTlM

### ec2
* elastic compute cloud
* resizable compute capacity
    * can shut it down and restart with modifications if needed
* scale capacity
* pay for capacity that you actually use
* supports Windows or Linux
* amazon machine image (ami)
    * template for root volume that define the os, apps, etc.
    * lifecycle: launch -> pending, running -> stopping -> stopped, running ->
        shutting-down -> terminated (instance destroyed)
    * when its stopped you stop paying, but you can restart it and the instance
        is still alive
* instance types
    * there are many different types of instances that are optimized for
        different types of workloads (ex. need lots of memory, need high CPU
        speed, etc.)
* ec2 instance store
    * storage device that is directly attached to the machine you are running on
    * ebs is usually a network storage device
    * nothing is persisted in an instance store after the instance is shut down

### ebs
* elastic block store
* persistent block storage volumes that offer consistent and low-latency
    performance
* stored data is automatically replicated within its AZ
* make sure to keep in mind the kind of ebs type you choose matches the ec2
    instance you run.

## references & videos
* [wikiArticle - Cloud Computing](https://en.wikipedia.org/wiki/Cloud_computing)
* https://www.youtube.com/watch?v=r4YIdn2eTm4&feature=youtu.be
* https://www.youtube.com/watch?v=ybcV0sJ_T_I
* [youtube - AWS Lambda](https://www.youtube.com/watch?v=eOBq__h4OJ4&feature=youtu.be)
* [youtube - AWS IoT](https://www.youtube.com/watch?v=WAp6FHbhYCk&feature=youtu.be)
* [docs.amazon.com - AWS IoT](https://docs.aws.amazon.com/iot/latest/developerguide/aws-iot-how-it-works.html)
