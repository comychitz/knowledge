# python
A slow work in progres...

## references
* [python.org](https://www.python.org/)
  * https://docs.python.org/2/tutorial/

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
