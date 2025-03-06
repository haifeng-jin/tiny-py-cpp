# setup.py
from setuptools import setup, find_packages, Extension
import os

def get_cpp_files(directory):
    cpp_files = []
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith('.cpp'):
                cpp_files.append(os.path.join(root, file))
    return cpp_files

setup(
    name='tiny-python-cpp',
    version='0.1',
    ext_modules=[
        Extension('hello_func', get_cpp_files(os.path.join('tiny_python_cpp', 'hello_func'))),
        Extension('hello_class', get_cpp_files(os.path.join('tiny_python_cpp', 'hello_class')))
    ],
    packages=find_packages(),
)
