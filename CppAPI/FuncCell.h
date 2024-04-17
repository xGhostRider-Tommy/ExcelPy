#include "pch.h"
#ifndef FUNCCELL_H
#define FUNCCELL_H

#include "Cell.h"
#include "ExcelCell.h"

class FuncCell: public Cell
{
private:
	std::vector<ExcelCell*> pCells; // lista pyton che contiene delle celle (TUTTE le celle)
	std::string pFunction;
	bool pError; // potrei mettere una stringa o un numero per i tipi di errori


	double pSum()
	{
		double sum = 0;

		for (int i = 0; i < pCells.size(); i++)
		{
			sum = sum + pCells[i]->ptr()->get();
		}
		return sum;
	}

	double pSubtraction()
	{
		double subtraction = 0;

		for (int i = 0; i < pCells.size(); i++)
		{
			subtraction = subtraction - pCells[i]->ptr()->get();
		}
		return subtraction;
	}

	double pMultiplication()
	{
		double multiplication = 1;

		for (int i = 0; i < pCells.size(); i++)
		{
			multiplication = multiplication + pCells[i]->ptr()->get();
		}
		return multiplication;
	}

	double pDivision()
	{
		if (pCells.size() == 2)
		{
			return pCells[0]->ptr()->get() / pCells[1]->ptr()->get();
		}
		else
		{
			pError = true;
			return Cell::get();
		}
	}

	double pAvarage()
	{
		double sum = pSum();
		
		if (pCells.size() > 0)
		{
			return sum / pCells.size();
		}
		else
		{
			pError = true;
			return Cell::get();
		}
	}

public: // tutti possono accedere alla funzione sottostante
	FuncCell(py::list pyCells, std::string function) // costruttore
	{
		pFunction = function;
		pError = false;

		for (int i = 0; i < pyCells.size(); i++)
		{
			pCells.push_back(pyCells[i].cast<ExcelCell*>());
		}
	}

	~FuncCell() // distruttore
	{
		for (int i = 0; i < pCells.size(); i++)
		{
			if (!pCells[i]->KeepAlive())
			{
				delete pCells[i];
				pCells.erase(pCells.begin() + i);
			}
		}
		pCells.clear();
	}

	bool Error() // da rivedere il nome
	{
		return pError;
	}

	double get() override
	{
		pError = false;

		if (pFunction == "sum") return pSum();
		else if (pFunction == "subtraction") return pSubtraction();
		else if (pFunction == "multiplication") return pMultiplication();
		else if (pFunction == "division") return pDivision();
		else if (pFunction == "avarage") return pAvarage();

		else return Cell::get();
	}

	std::string getString() override
	{
		return pFunction; // ridare formula (DA FARE)
	}

	std::string getDisplay() override
	{
		return std::to_string(get());
	}
};
#endif // !FUNCCELL_H