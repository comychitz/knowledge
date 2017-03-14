#emacs basics & notes
some notes for using emacs

## evil-org-mode keys
see -> https://github.com/edwtjo/evil-org-mode

to export something:
* ctrl-c ctrl-e (requires ox-md)

to run a terminal emulator in emacs
* M-x term to run 

to fill paragraph/line wrap
* M-q

to use the iedit feature:
* hit ctrl-; on a word, and then when you edit it, all other instances of the word is also being edited at the same time

##basic controls  
  * ctrl-h t for help/tutorial in emacs
  * ctrl-x ctrl-c to exit
  * ctrl-x ctrl-s to save
  * ctrl-x u undo
  * ESC x lineNum to go to line number
  * ctrl-k to join/delete line
  * ctrl-j to insert a new line
  * ctrl-x ctrl-f to open a file
  * ctrl-x ctrl-w to write a file with a filename
  * crtl-d to delete current character
  * M-f move forward one word
  * M-b move backward one word
  * ctrl-v scroll a page down
  * M-v scroll a page up
  * M-< move to the top of the buffer
  * M-> move to the end of the buffer

##searching/replacing:
  * ctrl-s incremental search forward
  * ctrl-r incremental search backward
  * ESC x replace-string
  
##buffer managemenet:
  * ctrl-x b select another buffer
  * ctrl-x ctrl-b list all buffers
  * ctrl-x 1 get rid of buffer list
  * ctrl-x k kill a buffer
  
##window movement:
  * ctrl-x 0 dismiss this window
  * ctrl-x 1 dismiss all other windows
  * ctrl-x 2 split window in two horizontally
  * ctrl-x o switch cursor to other window

##org mode
  * use stars to make bullets/tree entries
  * use Ctrl-c ctrl-t to toggle TODO state
  * use Ctrl-c ctrl-d to set deadline timestamp
  * tab to cycle through visibility
  * shift tab to cycle through visibility of an entire tree
  * M-enter to create a new bullet entry
  * ctrl-c ctrl-x ctrl-i makes a clock in entry
  * ctrl-c ctrl-x ctrl-o clocks out
  * ctrl-c ctrl-x ctrl-r generates a report
  * ctrl-c ctrl-x ctrl-u updates a report
  * ctrl-c ctrl-x ctrl-j jump to latest
  * ctrl-u ctrl-c ctrl-x ctrl-j show recent tasks & jump to them
  * ctrl-u ctrl-c ctrl-x ctrl-j i shows the most recently interrupted task
  * use shift and up/down arrow to adjust time, use shift left/right arrow to adjust day
  * use meta left/right arrows to change the depth of a subtree 
  * use meta up/down arrows to change the index of the subtree

Note: M = meta (which is alt/option or escape)
