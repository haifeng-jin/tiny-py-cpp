from setuptools import setup, Extension
from setuptools import find_packages

# Define the C++ extension
extension = Extension(
    name="tiny_project.ops",  # The compiled module will be tiny_project.ops
    sources=["tiny_project/ops.cpp"],  # Use ops.cpp instead of example.cpp
    language="c++"
)

setup(
    name="tiny_project",
    version="0.1",
    packages=find_packages(),  # Ensures package structure is recognized
    ext_modules=[extension]
)

