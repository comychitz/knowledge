# Vim Shortcuts

#### Two good visual images:
* https://cdn.shopify.com/s/files/1/0165/4168/files/preview.png
* http://www.viemu.com/vi-vim-cheat-sheet.gif

For my vim configuration, see https://github.com/comychitz/dotfiles/tree/master/vim

Movement | Description 
--- | ---
h|Move left
j|Move down 
k|Move up 
l|Move right
$|Move to end of line 
0|Move to beginning of line (including whitespace) 
^|Move to first character on line 
gg|Move to first line of file 
G|Move to last line of file 
w|Move forward to next word, with cursor on <span>first</span> character (use W to jump by whitespace only) 
b|Move backward to next word, with cursor on <span>first</span> character (use B to jump by whitespace only) 
e|Move forward to next word, with cursor on <span>last</span> character (use E to jump by whitespace only) 
ge|Move backwards to next word, with cursor on <span>last</span> character (use gE to jump by whitespace only) 
(|Move to beginning of previous sentence. Use ) to go to next sentence 
{ |    	 	Move to beginning of previous paragraph. Use } to go to next paragraph 
+ |    		Move forward to the first character on the next line
-  |       Move backwards to the first character on the previous line
``<C>``+u|   	Move up by half a page 
``<C>``+d |  	Move down by half a page 
H|         Move cursor to <span>header</span> (top) line of current visible window
M |        Move cursor to <span>middle</span> line of current visible window 
L  |       Move cursor to <span>last</span> line of current visible window 
fc  |      Move cursor to next occurrence of character c on the current line. Use Fcto move backwards
tc   |     Move cursor till next character c on the current line. Use Tc to move backward
ma    |   	Set a marker at cursor position to come back to later. a can be any character you choose
`a    |    Move cursor to exact position of the marker you set with ma 
'a     |   Move cursor to the first character of the line marked with ma 
%       |  Move cursor to next brace, bracket or comment paired to the current cursor location 

Search | Desc 
--- | ---
*     |      	Search forward for word under cursor                                                                                                      
#       |     	Search backwards for word under cursor 
/word   |  	Search forward for word. Accepts regular expressions to search 
?word   | 	Search backwards for word. Accepts regular expressions to search
n       |     	Repeat the last / or ? command
N       |    	Repeat the last / or ? command in the opposite direction

Deletion | Desc 
--- | ---
x    |      	Delete character forward (under cursor). use xdo delete backwards (before cursor)
r    |       	Replace single character under cursor, and remain in normal mode 
s    |       	Delete character under cursor, then switch to insert mode 
d    |       	Delete in direction of movement m. For m, you can also use wb, or any other variation
dd   |     	Delete entire current line 
D    |     	Delete until end of line

Yank and Put | Desc
--- | ---
y        |  	Yank (copy) highlighted test
yy	|	Yank current line
p	|	Put (paste) yanked text below current line. P to put above current line
J	|	Join current line with the next line. Use gJ to exclude join-position space

Normal to Insert Mode | Desc
--- | ---
i	|	Enter insert mode to the left of the cursor
a	|	Enter insert mode to the right of the cursor
I	|	Enter insert mode at first character of current line
A	|	Enter insert mode at last character of current line
o	|	Insert line below current line and enter insert mode
O		Insert line above current lien and enter insert mode
cm	|	Delete (change) the character or word (w) in motion m, then enter insert mode
cc	|	Delete current line and enter insert mode (unlike dd which leaves you in normal mode)
C	|	Delete (change) from cursor to end of line, enter insert mode

Visual Mode | Desc
--- | ---
v	|	Enter visual mode and highlight characters
V	|	Enter visual mode and highlight lines
``<C>``+v	|	Enter visual block mode and highlight exactly where the cursor moves
o	|	Switch cursor from first and last character of highlight block while in visual mode
vat	|	Highlight all text up to and including the parent element
vit	|	Highlight all text up to the parent element, excluding the element
vac	|	Highlight all text including the pair marked with c (like va<, va’, or va”)

Window Management | Desc
--- | ---
``<C>``+w s	| Split current window horizontally
``<C>``+w v|	Split current window vertically
``<C>``+w c|Close current window
``<C>``+w m	|Move to window according to motion
``<C>``+w o	|Maximize current window (note: this overwrites your current window configuration)

Miscellaneous | Desc
--- | ---
u	|	Undo
U	|	Undo all changes on current line
``<C>``+r	|	Redo
.	|	Repeat last change or delete
;	|	Repeat last f, t, F, or T command
,	|	Repeat last f, t, F, or T command in opposite direction
gg=G	|	Format HTML. Make sure FileType is set to html with :setf html
``<C>``+n	|	Press after typing part of a word. It scrolls down the list of all previous used words
``<C>``+p	|	Press after typing part of a word. It scrolls up the list of all previous used words
``	|	Jump between the last two line jump positions
[[	|	Goes to top of function
gg=G 	|	Autoindent all lines in file (gg goes to top, = is the indent command, G applies it to all lines)

```
Control: <C> Command: <D> Shift: <S> Option/Alt: <A> Carriage Return: <CR>
```
