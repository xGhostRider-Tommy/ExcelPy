#include "pch.h"
#ifndef FUNCCELL_H
#define FUNCCELL_H

#include "Cell.h"

class FuncCell: public Cell
{
protected: // anche i figli di FuncCell possono accedere alla variabile (quello che c'e' sotto)
	std::vector<Cell*> pCells; // vector = lista pyton che contiene delle celle (TUTTE le celle)

public: // tutti possono accedere alla funzione sottostante 
	FuncCell(py::list pyCells) // costruttore
	{
		for (int i = 0; i < pyCells.size(); i++)
		{
			pCells.push_back(py::cast<Cell*>(pyCells[i]));
		}
	}

	~FuncCell() // distruttore
	{
		pCells.clear();
	}
};
#endif // !FUNCCELL_H