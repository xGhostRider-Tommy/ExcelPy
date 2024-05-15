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
		// pCell non eliminata perche' lo fa gia' il garbage collector di python
	}

	Cell* ptr()
	{
		return pCell;
	}

	void set(py::object cell)
	{
		//delete pCell;
		pCell = cell.cast<Cell*>();
	}

	bool KeepAlive()
	{
		return pKeepAlive;
	}
};
#endif