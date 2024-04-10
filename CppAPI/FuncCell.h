#include "pch.h"
#ifndef FUNCCELL_H
#define FUNCCELL_H

#include <pybind11/pybind11.h>
#include "Cell.h"
#include <vector>

namespace py = pybind11;


class FuncCell: public Cell
{
protected:
	std::vector<Cell*> pCells;

public:
	FuncCell(py::list cells)
	{
		for (int i = 0; i < cells.size(); i++)
		{
			pCells[i] = py::cast<Cell*>(cells[i]);
		}
	}

	~FuncCell()
	{
		pCells.clear();
	}
};
#endif // !FUNCCELL_H