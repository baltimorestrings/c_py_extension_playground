#define PY_SSIZE_T_CLEAN
#include <Python.h>


static PyObject * 
greet_name(PyObject *self, PyObject *args) {
    Py_RETURN_NONE;
}

static PyMethodDef GreetMethods[] = {
    {"greet", greet_name, METH_VARARGS, "Greet an entity."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef greet = {
    PyModuleDef_HEAD_INIT,
    "greet", // name of module
    "",
    -1,      // -1 means we keep state in global vars
    GreetMethods
};

PyMODINIT_FUNC PyInit_greet(void) {
    return PyModule_Create(&greet);
}
