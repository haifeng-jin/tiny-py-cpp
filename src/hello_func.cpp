#include <Python.h>
#include <iostream>

static PyObject* hello_func_hello_world(PyObject* self, PyObject* args) {
    // This function corresponds to the Python function hello_world()
    std::cout << "Hello, world!" << std::endl;
    Py_RETURN_NONE; // Return None in Python
}

static PyMethodDef HelloFuncMethods[] = {
    {"hello_world", hello_func_hello_world, METH_NOARGS, "Prints 'Hello, world!'"},
    {NULL, NULL, 0, NULL} // Sentinel value ending the table
};

static struct PyModuleDef hellofuncmodule = {
    PyModuleDef_HEAD_INIT,
    "hello_func", // Module name
    "A module that prints hello world.", // Module docstring
    -1, // Size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    HelloFuncMethods
};

PyMODINIT_FUNC PyInit_hello_func(void) {
    return PyModule_Create(&hellofuncmodule);
}
