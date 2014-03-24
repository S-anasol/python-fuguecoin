#include <Python.h>

#include "fugue.h"

static PyObject *fugue_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    fugue_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    fugue_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef FugueMethods[] = {
    { "getPoWHash", fugue_getpowhash, METH_VARARGS, "Returns the proof of work hash using fugue hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef FugueModule = {
    PyModuleDef_HEAD_INIT,
    "fugue_hash",
    "...",
    -1,
    FugueMethods
};

PyMODINIT_FUNC PyInit_fugue_hash(void) {
    return PyModule_Create(&FugueModule);
}

#else

PyMODINIT_FUNC initfugue_hash(void) {
    (void) Py_InitModule("fugue_hash", FugueMethods);
}
#endif
