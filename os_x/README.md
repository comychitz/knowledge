# os x (now macos) tips & tricks
* get the current active interface:
  ```route get default | sed -n -e 's/^.*interface: //p'```
* similar tool to ldd: ```otool -L```
