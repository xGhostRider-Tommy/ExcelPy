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
		.def(py::init<py::object, bool>(), py::keep_alive<1, 2>())
		.def("ptr", &ExcelCell::ptr)
		.def("set", &ExcelCell::set, py::keep_alive<1, 2>());

	py::class_<Cell>(m, "Cell")
		.def(py::init<>())
		.def("getString", &Cell::getString)
		.def("get", &Cell::getDisplay);

	py::class_<DoubleCell, Cell>(m, "DoubleCell")
		.def(py::init<double>())
		.def("getString", &DoubleCell::getString)
		.def("get", &DoubleCell::getDisplay);

	py::class_<FuncCell, Cell>(m, "FuncCell")
		.def(py::init<py::list, std::string>(), py::keep_alive<1, 2>())
		.def("getString", &FuncCell::getString)
		.def("get", &FuncCell::getDisplay);

	py::class_<StringCell, Cell>(m, "StringCell")
		.def(py::init<std::string>())
		.def("getString", &StringCell::getString)
		.def("get", &StringCell::getDisplay);


#ifdef VERSION_INFO
	m.attr("__version__") = VERSION_INFO;
#else
	m.attr("__version__") = "dev";
#endif
}