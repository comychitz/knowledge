# cloud computing
some notes about computing in the cloud.

## general notes
* the NIST's definition of cloud computing identifies 5 characteristics:
    * On-demand self-service
    * Broad network access
    * Resource pooling
    * Rapid elasticity
    * Measured service
* service-oriented architecture
    * Infrastructure as a Service (IaaS)
    * Platform as a Service (PaaS)
    * Software as a Service (SaaS)

## aws
* amazon web services
* benefits:
    * prevent large capital expenses at the beginning or IT resources
    * scalibility
    * no need to guess how much resources you need
    * quickly get up to speed and developing your product(s)
* aws by category:
    * core services
    * platform services
    * development and operations services
* aws regions
    * availibility zone within regions
    * can use for replication/redundancy
    * each region is made up of two or more availability zones
    * edge locations
* AWS marketplace

### ec2
* elastic compute cloud
* resizable compute capacity
    * can shut it down and restart with modifications if needed
* scale capacity
* pay for capacity that you actually use
* supports Windows or Linux
* amazon machine image (ami)
    * template for root valome that define the os, apps, etc.
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
