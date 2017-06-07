# python
A slow work in progres...

### references
* [wikiArticle](https://en.wikipedia.org/wiki/Python_(programming_language)) 
* http://www.ics.uci.edu/~brgallar/week9_3.html

# about 
* first releaed in 1991
* it is an interpreted language
  * [stackoverflow: Is Python interpreted or compiled or both?](https://stackoverflow.com/questions/6889747/is-python-interpreted-or-compiled-or-bot)
  * [is python interpreted or compiled?](https://softwareengineering.stackexchange.com/questions/24558/is-python-interpreted-or-compiled)
* indentation is used to delimit code blocks
* dynamic type system
   * uses duck typing
      * "Duck typing is concerned with establishing the suitability of an object for some purpose. With normal typing, suitability is assumed to be determined by an object's type only. In duck typing, an object's suitability is determined by the presence of certain methods and properties (with appropriate meaning), rather than the actual type of the object" - [wikiArticle](https://en.wikipedia.org/wiki/Duck_typing)
* automatic memory management
* programming paradigms:
  * object-oriented & structured
  * imperitave
  * functional programming
  * procedural styles
* handy standard library(!)
* CPython is the default and most used implementation (40+ platforms!)
* The Zen of Python (PEP 20)
  * Beautiful is better than ugly
  * Explicit is better than implicit
  * Simple is better than complex
  * Complex is better than complicated
  * Readability counts

## references
* [python.org](https://www.python.org/)
  * https://docs.python.org/2/tutorial/
  *  https://docs.python.org/3/tutorial/

## notes
* interfaces in python
```python
import abc

class MyABC(object):
""" Abstract Base Class Definition"""
  __metaclass__ = abc.ABCMeta

@abc.abstractmethod
def do_something(self, value):
  """Required method"""

@abc.abstractproperty
def some_property(self):
  """Required property"""

# in python3 it would be...
class MyABC(metaclass=abc.ABCMeta):
  ...
```
* tuples vs arrays
  * arrays are of the same type, tuples allow a mix of types
* python uses decorators
  * https://wiki.python.org/moin/PythonDecorators
* with 
  * (from Python 2.5) encloses a code block within a context manager (for example, acquiring a lock before the block of code is run and releasing the lock afterwards, or opening a file and then closing it), allowing Resource Acquisition Is Initialization (RAII)-like behavior
* assert [condition]
```python
>>> assert True
>>> assert False
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AssertionError
```
