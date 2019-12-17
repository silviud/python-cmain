#include <Python.h>

static PyObject *cmain_addList(PyObject *self, PyObject *args){

    PyObject * listObj;

    if(!PyArg_ParseTuple(args, "O", &listObj))
        return NULL;

    long length = PyList_Size(listObj);

    long i, sum =0;

    for(i = 0; i < length; i++){
        //get an element out of the list - the element is also a python objects
        PyObject* temp = PyList_GetItem(listObj, i);
        //we know that object represents an integer - so convert it into C long
        long elem = PyLong_AsLong(temp);
        sum += elem;
    }

    return Py_BuildValue("i", sum);

}


//This is the docstring that corresponds to our 'add' function.
static char cmain_docs[] =
    "addList( ): add all elements of the list\n";


static PyMethodDef cmain_funcs[] = {
    {"addList", (PyCFunction)cmain_addList, METH_VARARGS, cmain_docs},
    {NULL, NULL, 0, NULL} /* sentinel */
};


static struct PyModuleDef cmainmodule = {
    PyModuleDef_HEAD_INIT,
    "cmain",   /* name of module */
    cmain_docs, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    cmain_funcs
};


PyMODINIT_FUNC PyInit_cmain(void){
    return PyModule_Create(&cmainmodule);
}
