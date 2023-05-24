#include <Python.h>
#include <fileutils.h>
#include <import.h>
#include <modsupport.h>
#include <object.h>
#include <pylifecycle.h>
#include <pystate.h>
#include <pythonrun.h>
#include <unicodeobject.h>

static PyObject *
greet_name(PyObject *self, PyObject *args) {
    const char *name;

    if (!PyArg_ParseTuple(args, "s", &name)) {
            return NULL;
    }

    //PyObject_Print(self, stdout, 0);

    printf("Hello %s", name);

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

int main(int argc, char *argv[]) {
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error, can't decode arg\n");
        exit(1);
    }

    if (PyImport_AppendInittab("greet", PyInit_greet) == -1) {
        fprintf(stderr, "failed extending modules table");
        exit(1);
    }

    Py_SetProgramName(program);
    Py_Initialize();

    PyObject *pmodule = PyImport_ImportModule("greet");
    if (!pmodule) {
        PyErr_Print();
        fprintf(stderr, "couldn't do the thing");
    }
    PyRun_SimpleString("greet()");



    if (Py_FinalizeEx() < 0) {
        exit(120);
    }

    //PyObject *s = Py_BuildValue("s", "testing building a python string");



    PyMem_RawFree(program);
    
    return 0;
}
