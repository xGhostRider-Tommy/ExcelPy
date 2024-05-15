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
	std::string pFormula;
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
		double subtraction = pCells[0]->ptr()->get();

		for (int i = 0; i < pCells.size() - 1; i++)
		{
			subtraction = subtraction - pCells[i + 1]->ptr()->get();
		}
		return subtraction;
	}

	double pMultiplication()
	{
		double multiplication = 1;

		for (int i = 0; i < pCells.size(); i++)
		{
			multiplication = multiplication * pCells[i]->ptr()->get();
		}
		return multiplication;
	}

	double pDivision()
	{
		pError = false;

		if (pCells.size() >= 2 && pCells[1]->ptr()->get() != 0)
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
	FuncCell(py::list pyCells, std::string function, std::string formula) // costruttore
	{
		pFunction = function;
		pFormula = formula;
		pError = false;

		for (int i = 0; i < pyCells.size(); i++)
		{
			pCells.push_back(pyCells[i].cast<ExcelCell*>());
		}
	}

	~FuncCell() // distruttore
	{
		pCells.clear();
	}

	double get() override
	{
		if (pFunction == "sum") return pSum();
		else if (pFunction == "subtraction") return pSubtraction();
		else if (pFunction == "multiplication") return pMultiplication();
		else if (pFunction == "division") return pDivision();
		else if (pFunction == "avarage") return pAvarage();

		else return Cell::get();
	}

	std::string getString() override
	{
		return pFormula;
	}

	std::string getDisplay() override
	{
		double value = get();

		if (pError)
		{
			return "Error!";
		}
		else
		{
			return std::to_string(value);
		}
	}

};
#endif // !FUNCCELL_H