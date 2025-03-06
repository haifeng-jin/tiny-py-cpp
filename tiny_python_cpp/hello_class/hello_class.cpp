#include <Python.h>
#include <iostream>
#include "hello_class.h"

// Define the attributes of the Python class.
typedef struct {
    PyObject_HEAD
    PyObject* name;
} HelloObject;

// Constructor of the Hello class
static int Hello_init(HelloObject* self, PyObject* args, PyObject* kwds) {
    const char* name;
    if (!PyArg_ParseTuple(args, "s", &name)) {
        return -1;
    }
    self->name = PyUnicode_FromString(name);
    if (self->name == NULL) {
        return -1;
    }
    return 0;
}

// Destructor of the Hello class
static void Hello_dealloc(HelloObject* self) {
    Py_XDECREF(self->name);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

// Print the hello with the name attribute
static PyObject* Hello_hello(HelloObject* self) {
    PyObject* format_string = PyUnicode_FromString("Hello, %s!");
    if (format_string == NULL) {
        return NULL;
    }
    PyObject* formatted_string = PyUnicode_Format(format_string, PyTuple_Pack(1, self->name));
    Py_DECREF(format_string);
    if (formatted_string == NULL) {
        return NULL;
    }

    const char* result = PyUnicode_AsUTF8(formatted_string);
    if (result == NULL) {
        Py_DECREF(formatted_string);
        return NULL;
    }

    std::cout << result << std::endl;
    Py_DECREF(formatted_string);
    Py_RETURN_NONE;
}

// Static method hello_world()
static PyObject* Hello_hello_world(PyTypeObject* type) {
    std::cout << "Hello, world!" << std::endl;
    Py_RETURN_NONE;
}

// The methods in the class.
static PyMethodDef HelloMethods[] = {
    {"hello", (PyCFunction)Hello_hello, METH_NOARGS, "Prints a greeting with the instance's name."},
    {"hello_world", (PyCFunction)Hello_hello_world, METH_NOARGS | METH_STATIC, "Prints 'Hello, world!'"},
    {NULL, NULL, 0, NULL} // Sentinel value ending the table
};

static PyTypeObject HelloType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "hello_class.Hello", // tp_name
    sizeof(HelloObject), // tp_basicsize
    0, // tp_itemsize
    (destructor)Hello_dealloc, // tp_dealloc
    0, // tp_vectorcall_offset
    0, // tp_getattr
    0, // tp_setattr
    0, // tp_as_async
    0, // tp_repr
    0, // tp_as_number
    0, // tp_as_sequence
    0, // tp_as_mapping
    0, // tp_hash
    0, // tp_call
    0, // tp_str
    0, // tp_getattro
    0, // tp_setattro
    0, // tp_as_buffer
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, // tp_flags
    "Hello objects", // tp_doc
    0, // tp_traverse
    0, // tp_clear
    0, // tp_richcompare
    0, // tp_weaklistoffset
    0, // tp_iter
    0, // tp_iternext
    HelloMethods, // tp_methods
    0, // tp_members
    0, // tp_getset
    0, // tp_base
    0, // tp_dict
    0, // tp_descr_get
    0, // tp_descr_set
    0, // tp_dictoffset
    (initproc)Hello_init, // tp_init
    PyType_GenericAlloc, // tp_alloc
    PyType_GenericNew, // tp_new
};

static struct PyModuleDef helloclassmodule = {
    PyModuleDef_HEAD_INIT,
    "hello_class", // Module name
    "A module that defines a Hello class.", // Module docstring
    -1, // Size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_hello_class(void) {
    PyObject* m;
    if (PyType_Ready(&HelloType) < 0) {
        return NULL;
    }
    m = PyModule_Create(&helloclassmodule);
    if (m == NULL) {
        return NULL;
    }
    Py_INCREF(&HelloType);
    if (PyModule_AddObject(m, "Hello", (PyObject*)&HelloType) < 0) {
        Py_DECREF(&HelloType);
        Py_DECREF(m);
        return NULL;
    }
    return m;
}
