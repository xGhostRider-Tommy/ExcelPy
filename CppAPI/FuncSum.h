#include "pch.h"
#ifndef FUNCSUM_H
#define FUNCSUM_H

#include "FuncCell.h"
#include <vector>

class FuncSum: public FuncCell // FuncSum eredita da FuncCell che eredita da Cell. Sum e' una cella 
{
public:
	FuncSum(py::list cells): FuncCell(cells) // costruttore
	{
		
	}

	~FuncSum() // distruttore
	{
		
	}

	double get() // ha gia' pCells (lista)
	{
		double sum = 0;

		for (int i = 0; i < pCells.size(); i++)
		{
			sum = sum + pCells[i]->get();
		}
		
		return sum; //da come risultato la somma
	}
	
};
#endif // !FUNCSUM_H