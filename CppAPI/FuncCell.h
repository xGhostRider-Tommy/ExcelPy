#include "pch.h"
#ifndef FUNCCELL_H
#define FUNCCELL_H

#include <pybind11/pybind11.h>
#include "Cell.h"
#include <vector>

namespace py = pybind11;


class FuncCell: public Cell
{
protected: // anche i figli di FuncCell possono accedere alla variabile (quello che c'e' sotto)
	std::vector<Cell*> pCells; // vector = lista pyton che contiene delle celle (TUTTE le celle)

public: // tutti possono accedere alla funzione sottostante 
	FuncCell(py::list cells) // costruttore
	{
		auto tLista = cells.cast<std::vector<Cell*>>();

		/*for (int i = 0; i < cells.size(); ++i)
		{
			pCells[i] 
		}*/
		printf("idk");

	}

	~FuncCell() // distruttore
	{
		pCells.clear();
	}
};
#endif // !FUNCCELL_H