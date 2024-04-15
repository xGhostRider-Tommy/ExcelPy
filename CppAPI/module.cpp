#include "pch.h"
#include <pybind11/pybind11.h> // include python
#include "Cell.h"
#include "ExcelCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FuncCell.h"

namespace py = pybind11;


int test(int a)
{
	return a + 1;
}

PYBIND11_MODULE(CppAPI, m) // importazione da/a python
{
	m.def("test", &test, "idk");

	py::class_<ExcelCell>(m, "ExcelCell")
		.def(py::init<py::object>())
		.def("ptr", &ExcelCell::ptr)
		.def("set", &ExcelCell::set);
	py::class_<Cell>(m, "Cell") // fixare garbage collector 
		.def(py::init<>())
		.def("get", &Cell::get);
	// bisogna fixare il garbage collector fatto male di python per i puntatori
	// creati e riferiti solo nei parametri del costruttore e non visibili a python
	py::class_<DoubleCell, Cell>(m, "DoubleCell")
		.def(py::init<double>())
		.def("get", &DoubleCell::get);
	py::class_<FuncCell, Cell>(m, "FuncCell")
		.def(py::init<py::list, std::string>())
		.def("get", &FuncCell::get);
	py::class_<StringCell, Cell>(m, "StringCell")
		.def(py::init<std::string>())
		.def("get", &StringCell::get)
		.def("getString", &StringCell::getString);

#ifdef VERSION_INFO
	m.attr("__version__") = VERSION_INFO;
#else
	m.attr("__version__") = "dev";
#endif
}