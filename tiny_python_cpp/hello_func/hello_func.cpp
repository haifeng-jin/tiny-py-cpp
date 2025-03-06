#include <Python.h>
#include <iostream>
#include "hello_func.h"

// This function prints the hello world
static PyObject* hello_func_hello_world(PyObject* self, PyObject* args) {
    // This function corresponds to the Python function hello_world()
    std::cout << "Hello, world!" << std::endl;
    Py_RETURN_NONE; // Return None in Python
}

// A list of methods in the module.
static PyMethodDef HelloFuncMethods[] = {
    {
        "hello_world",         // The name of the function as it will be seen in Python.
        hello_func_hello_world, // The C function pointer that implements the Python function.
        METH_NOARGS,           // The calling convention: METH_NOARGS indicates the function takes no arguments.
        "Prints 'Hello, world!'" // The docstring for the Python function.
    },
    {NULL, NULL, 0, NULL} // Sentinel value ending the table
};

// This is a struct contains all the info about the module.
static struct PyModuleDef hellofuncmodule = {
    PyModuleDef_HEAD_INIT,
    "hello_func", // Module name
    "A module that prints hello world.", // Module docstring
    -1, // Size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    HelloFuncMethods // The methods in the module
};

// This function initializes the Python module.
// The function signature has to be:
// PyMODINIT_FUNC PyInit_<module_name>(void)
PyMODINIT_FUNC PyInit_hello_func(void) {
    return PyModule_Create(&hellofuncmodule);
}
