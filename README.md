# tiny-py-cpp

A tiny Python and C++ interfacing code example.

Run the following commands:

```shell
python setup.py install
python main.py
```

Following is the Python implementation of the C++ files as a reference:

```py
# For hello_func.cpp
def hello_world():
    print("Hello, world!")
```

```py
# For hello_class.cpp
class Hello:
    def __init__(self, name):
        self.name = name

    def hello():
        print(f"Hello, {self.name}!")

    @staticmethod
    def hello_world():
        print("Hello, world!")
```
