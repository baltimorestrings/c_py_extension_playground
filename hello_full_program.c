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

    printf("Hello %s\n", name);

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

    // MANUALLY IMPORT MODULE (not needed if we build extension module
    PyObject *pmodule = PyImport_ImportModule("greet");
    if (!pmodule) {
        PyErr_Print();
        fprintf(stderr, "couldn't do the thing");
    } else {
        fprintf(stdout, "successfully manually imported lib: ");
        PyObject_Print(pmodule, stdout, 0);
        fprintf(stdout, "\n");
    }

    // MANUAL CALL
    PyObject * tuple_str = Py_BuildValue("(s)", "test string");
    greet_name(pmodule, tuple_str);
    uintmax_t i = _Py_IMMORTAL_REFCNT;


    // why doesn't this work when we've confirmed import and below works
    // PyRun_SimpleString("greet.greet('ari')");
    PyRun_SimpleString("import greet; greet.greet('hello')");

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    PyMem_RawFree(program);
    
    return 0;
}
