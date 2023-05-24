#include <Python.h>
#include <fileutils.h>
#include <modsupport.h>
#include <object.h>
#include <pylifecycle.h>
#include <pythonrun.h>

static PyObject * 
greet_name(PyObject *self, PyObject *args) {
    const char *name;

    if (!PyArg_ParseTuple(args, "s", &name)) {
            return NULL;
    }

    printf("Hello %s\n", name);

    Py_RETURN_NONE;
}

static PyObject * 
print_objcount(PyObject *self, PyObject *args) {
    PyObject *theObject = NULL;
    if (!PyArg_ParseTuple(args, "O", &theObject)) {
            printf("I failed and I don't know why or how\n");
            Py_RETURN_NONE;
    }
    uintmax_t i = theObject->ob_refcnt;
    printf("%ul\n", i);
    Py_RETURN_NONE;
}

static PyObject * 
test_is_immortal(PyObject *self, PyObject *args) {
    Py_RETURN_NONE;
}

static PyMethodDef GreetMethods[] = {
    {"greet", greet_name, METH_VARARGS, "Greet an entity."},
    {"test", print_objcount, METH_VARARGS, "eh"},
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
