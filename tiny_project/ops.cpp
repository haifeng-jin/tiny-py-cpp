#include <Python.h>

// A simple function that adds two numbers
static PyObject* add(PyObject* self, PyObject* args) {
    double a, b;
    if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return NULL;
    }
    return Py_BuildValue("d", a + b);
}

// Method definitions
static PyMethodDef OpsMethods[] = {
    {"add", add, METH_VARARGS, "Adds two numbers"},
    {NULL, NULL, 0, NULL}  // Sentinel
};

// Module definition
static struct PyModuleDef opsmodule = {
    PyModuleDef_HEAD_INIT,
    "ops",
    "A minimal C++ extension module",
    -1,
    OpsMethods
};

// Module initialization function
PyMODINIT_FUNC PyInit_ops(void) {
    return PyModule_Create(&opsmodule);
}

