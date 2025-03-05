# setup.py
from setuptools import setup, Extension

setup(
    name='my_extensions',
    version='0.1',
    ext_modules=[
        Extension('hello_func', ['src/hello_func.cpp']),
        Extension('hello_class', ['src/hello_class.cpp'])
    ]
)
