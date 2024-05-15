#include "pch.h"
#ifndef DOUBLECELL_H
#define DOUBLECELL_H

#include "Cell.h" // include Cell (padre)

class DoubleCell : public Cell // definisce la classe e suo padre. double cell per valori decimali
{
private: // solo la cella puo' accedere a pValore (es. 3,76)
	double pValue; // double e' un numero decimale (il corrispospondente a float di python)

public: // chiunque puo' accedere a questa funzione (tutto quello che c'e' sotto)
	DoubleCell(double value) // costruttore
	{
		pValue = value;
	}

	~DoubleCell() // distruttore
	{
		
	}

	double get() override // ritorna il pValore
	{
		return pValue; // non ti ridà 2+2 ma 4
	}

	std::string getString() override
	{
		return std::to_string(pValue);
	}
};
#endif // !DOUBLECELL_H