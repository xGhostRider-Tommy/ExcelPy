#include "pch.h"
#include <pybind11/pybind11.h>
#include "DoubleCell.h"
#include "StringCell.h"
#include "FuncCell.h"
#include "FuncSum.h"

namespace py = pybind11;


int test(int a)
{
	return a + 1;
}

PYBIND11_MODULE(CppAPI, m)
{
	m.def("test", &test, "idk");

	py::class_<Cell>(m, "Cell")
		.def(py::init<>())
		.def("get", &Cell::get);
	py::class_<DoubleCell, Cell>(m, "DoubleCell")
		.def(py::init<double>())
		.def("get", &DoubleCell::get);
	py::class_<FuncCell, Cell>(m, "FuncCell")
		.def(py::init<py::list>())
		.def("get", &FuncCell::get);

#ifdef VERSION_INFO
	m.attr("__version__") = VERSION_INFO;
#else
	m.attr("__version__") = "dev";
#endif
}