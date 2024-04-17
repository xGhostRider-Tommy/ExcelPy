#ifndef EXCELCELL_H
#define EXCELCELL_H

#include "Cell.h"

class ExcelCell
{
private:
	Cell* pCell;
	bool pKeepAlive;
	
public:
	ExcelCell(py::object cell, bool isReferenced)
	{
		pKeepAlive = isReferenced;
		set(cell);
	}

	ExcelCell(py::object cell)
	{
		pKeepAlive = false;
		set(cell);
	}

	~ExcelCell()
	{
		delete pCell;
	}

	Cell* ptr()
	{
		return pCell;
	}

	void set(py::object cell)
	{
		pCell = cell.cast<Cell*>();
	}

	bool KeepAlive()
	{
		return pKeepAlive;
	}
};
#endif