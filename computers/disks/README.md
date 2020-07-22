# disks
notes about disks, including concepts and tools used to manage them

# helpful utilities & commands
## disk utilities
* `fdisk` - tool for manipulating disk partition table
* `mkfs.ext4` (`mke2fs`) - create ext* file system
* `df` - report file system disk usage

## formatting disks
```
sudo fdisk /dev/sda1
```
```
d // to delete partitions
```
```
n // to create new partitions
```
```
w // write/sync changes to the disk
```

## checking disk health
```
sudo e2fsck -c /dev/sda1
```
or, can use *badblocks*, but *backblocks* man page recommends to use e2fsck


