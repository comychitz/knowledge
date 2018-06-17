# awk
Learning *awk* has been encouraged to me by several collegues, friends and even
authors of some posts on Hackernews. Since my daily job deals with text on the
command line ubiquitiously, I'd thought I'd take a shot and learn a little bit
about *awk*.

## resources
* [WikiArticle](https://en.wikipedia.org/wiki/AWK)
* [Why you should know just a little Awk](https://gregable.com/2010/09/why-you-should-know-just-little-awk.html)

## general notes
* awk stands for Aho, Weinberger, Kernighan
    * the designers of the language
* it is a data-driven scripting language for manipulating streams of text
* very commonly available on Linux-based systems

## using awk
* awk programs starting with `{` and end with `}` 
* when reading text, it automatically delimits fields based on whitespaces and
    is available $1, $2, $3, tec.
    * ex. `echo "hello, my name is cameron" | awk '{ print $1 }' // prints hello`
* The NF is a keyword for number of fields
    * ex. `echo "hello, my name is cameron" | awk '{ print $(NF) }' // prints cameron`
* use the FS keyword to specify your own field separator
    * ex. `echo "hello, my name is cameron" | awk 'BEGIN{FS=","}{ print $2 }' // prints my name is cameron`
* using logic 
    * can use simple if statements to conditionally output matches for a field
    * ex. `awk '{if ($(NF-2) == "200") {print $0}}' logs.txt`
* variables automatically persist through multiple ines
    * ex. `awk '{a+=$(NF-2); print "Total so far:", a}' logs.txt`

