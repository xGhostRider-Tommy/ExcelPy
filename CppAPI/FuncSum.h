#include "pch.h"
#ifndef FUNCSUM_H
#define FUNCSUM_H

#include "FuncCell.h"
#include <vector>

class FuncSum: public FuncCell
{
public:
	FuncSum(py::list cells): FuncCell(cells)
	{
		
	}

	~FuncSum()
	{
		
	}

	double get()
	{
		double sum = 0;

		for (int i = 0; i < pCells.size(); i++)
		{
			sum = sum + pCells[i]->get();
		}
		
		return sum;
	}
	
};
#endif // !FUNCSUM_H