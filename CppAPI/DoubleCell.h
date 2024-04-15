#include "pch.h"
#ifndef DOUBLECELL_H
#define DOUBLECELL_H

#include "Cell.h" // include Cell (padre)

class DoubleCell : public Cell // definisce la classe e suo padre
{
private: //solo la cella puo' accedere a pValore (es. 3,76)
	double pValue;  // double e' un numero decimale (il corrispospondente a float di python)

public: //chiunque puo' accedere a questa funzione (tutto quello che c'e' sotto)
	DoubleCell(double valore) // costruttore
	{
		pValue = valore;
	}

	~DoubleCell() // distruttore
	{

	}

	double get() override // ritorna il pValore
	{
		return pValue;
	}

	std::string getString() override
	{
		return std::to_string(pValue);
	}
};
#endif // !DOUBLECELL_H