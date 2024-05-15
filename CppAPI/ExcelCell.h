#ifndef EXCELCELL_H
#define EXCELCELL_H

#include "Cell.h"

class ExcelCell
{
private:
	Cell* pCell;
	
public:
	ExcelCell(py::object cell)
	{
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
		pCell = cell.cast<Cell*>();
	}
};
#endif