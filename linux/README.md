# Linux
Some, hopefully useful, Linux-related notes.

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


## Notes
### general 
* reading from the man pages
   * if there is more than one entry for the command/api 
    we can look at all the man pages by running
              man -a <command/api>
      if it says to checkout <command/api>(3) man page
      then run:
              man 3 <command/api>
      the different levels of man pages are:
              1 User Command
              2 System Calls
              3 C Library Functions
              4 Devices and Special Files
              5 File Formats and Conventions
              6 Games et. Al.
              7 Miscellanea
              8 System Administation tools and Deamons
      use man -l <command/api> to list all the different
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
- what it should contain:
  - The name of the program
  - Every non-optional command-line argument your program takes
  - Every optional command-line argument your program takes
  - Any extra descriptive material that the user should know about.
- optionals: 
  Optional arguments should always be surrounded by square brackets. Do not use
  square brackets for any other purpose in usage messages. Don't use anything
  but square brackets for this purpose. Square brackets mean that an argument is
  optional, always.
  Optional "flags" (arguments that change the way the program works) should
  start with a dash. Very often (but not always) they will have a name which is
  a dash followed by a single letter, which identifies what it is. Here's an
  example, which is a greatly simplified version of the usage message for the
  Unix  ls  program which lists files:
    usage: ls [-a] [-F]
  This program is called  ls   and can be called with no arguments, with one
  optional argument ( ls -a  or  ls -F ) or with two optional arguments ( ls -a
  -F ). In this particular case, the  -a  optional argument says to list hidden
  files as well as normal ones, and  -F  changes the way the output of the
  program is formatted.
  Note that each optional argument gets its own set of square brackets.
  If an optional "flag" argument itself has arguments, put them inside the
  square brackets. For instance:
    usage: chess [-strength r]
        -strength r: playing strength in approximate rating (800-3000)
                     (default strength is 2200)
  might represent a chess program that can either play with its default strength
  (when invoked with no command-line arguments) or with some other strength if
  the optional argument is used. Note the extra explanatory text that goes after
  the usage statement itself. This program could be invoked like this:
    % chess
    (where  %  is the prompt) or like this:
    % chess -strength 2600
    but not like this:
    % chess -strength
  because that wouldn't make sense (the strength isn't specified).
- If your program has multiple arguments of the same type on the command line
  (e.g. it takes a series of numbers between 1 and 10 of arbitrary length, but
  at least one of them), put any non-optional arguments as normal arguments in
  the usage message (normally this will be the first one of the arguments) and
  put the rest in square brackets. Since there are arbitrary numbers of
  arguments, you can use ellipses ( ... ) to indicate that any number of
  arguments can follow. For instance: 
      usage: average n1 [n2 ...]
        n1, n2, etc.: numbers between 1 and 10
        Maximum length of the list: 100
- You shouldn't hard-code the program name into your program's source code. It
  won't make any difference in how it's displayed, but if you change the name of
  your program and don't change your usage message the usage message will be
  invalid. Instead, you should write your code so that the program name gets
  inserted into the usage message before printing. In C, the program name is
  argv[0]  (the first element of the  argv  array) whereas in python it's
  sys.argv[0] .
- <b>DON'T USE CARROTS (< >) in your usage statments!!</b>
- Some programs (e.g. C track lab 2) use the less-than ( < ) and greater-than ( >
) symbols to perform Unix file redirection on the command line. The less-than
symbol means that input from a file will look to the program like it's input to
the terminal, and the greater-than symbol means that output to the terminal is
actually redirected to a file. If this is done, it is a good idea to indicate
this in the usage message (though many, many programs don't do this). For
instance:
    usage: myprog  < input_file  > output_file
- This says that the program ( myprog ) takes its input from the file  input_file
using input file redirection (remember to put the  <  symbol before the file
name!) and puts its output into the file  output_file  using output file
redirection.
- Note that this also explains why you don't want to use the less-than ( < ) or
greater-than ( > ) characters as angle brackets around a command-line argument
name; a user might think you meant input/output redirection.
- If you need to explain in detail what a particular command-line argument
  means, do it on the lines following the first line. Don't feel that you have
  to cram the entire usage message on one line. For instance, this is bad:
    usage: myprog infile (the input file) outfile (the output file)
- it should instead look like this:
    usage: myprog infile outfile
      infile:  the input file
      outfile: the output file
