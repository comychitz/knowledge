# Linux
Some (hopefully useful) Linux-related notes.

## Useful commands
* find
  * find . -name "*.o" -exec rm {} \;
  * find . -name "unittest.log" -exec rm {} \;
  * find . -name "tmp" -type d |xargs rm -rf
  * find ./ -type f -exec sed -i -e 's/apple/orange/g' {} \;
* remount something: mount -o remount,rw /path/to/filesystem/to/remount
* tcpdump
    * listening on a UDP socket: tcpdump -lu -vvXX port <portnum>
* convert csv to json
    * python -c "import csv,json;print json.dumps(list(csv.reader(open('csv_file.csv'))))"
* info coreutils 
  * is like an intense manual for all the GNU coreutils
* df -h - disk free space stats
* du - disk usage of files and directories
* fdisk - to create partitions for a mounted drive such as USB drive, etc.
* mkfs - to create a file system on a mounted drive
* get CPU info
    *  cat /proc/cpuinfo or try uname with options
* /proc/<pid>/cmdline
    * this file will contain how the process got called via the command line

## Notes
### general 
* reading from the man pages
   * if there is more than one entry for the command/api 
    we can look at all the man pages by running:
              man -a <command/api>
   * use man -l <command/api> to list all the different
   sections the command/api is in, along with a brief
   description
* directory permissions
  * Directory permissions in linux differ than regular file permissions:
    * the write bit allows the affected user to create, rename,
      or delete files within the directory, as well as modify
      the directory's attributes.
    * the read bit allows the affected user to list the files
      within the directory
    * the execute bit allows the affected user to enter the 
      directory, and access files and directories inside
    * the stick bit states that files and directories within
      that directory may only be deleted or renamed by their
      owner (or root)
* chroot command
  * the chroot command is for creating a change root directory.
    to set up a "jail" area i did the following:
    * logged in as root user
    * created a jail
    * copied command binaries i need (/bin/*) to the jail
    * copied the libraries needed (i just did cp -r /lib/*) 
      to the jail
    * to be in the chroot environment run "sudo chroot jail"
      (no need to be logged in as root user when the 
      jail has been all set up)
### getopt
* An option character in this string can be followed by a colon (‘:’) to indicate
that it takes a required argument. If an option character is followed by two
colons (‘::’), its argument is optional; this is a GNU extension.
### writing usage statements
- reference: http://courses.cms.caltech.edu/cs11/material/general/usage.html
- use brackets ([]) to indicate optional arguments
- just right an argument name if it is mandatory, with no punctuation, and
  following the snake_case formatting
- typical example:
      usage: myprog arg1 arg2
- <b>DON'T USE CARROTS (< >) in your usage statments!!</b>
- what it should contain:
  - The name of the program
  - Every non-optional command-line argument your program takes
  - Every optional command-line argument your program takes
  - Any extra descriptive material that the user should know about.
