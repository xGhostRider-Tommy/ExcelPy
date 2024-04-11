#include "pch.h"
#ifndef DOUBLECELL_H
#define DOUBLECELL_H

#include "Cell.h" // include Cell (padre)

class DoubleCell : public Cell // definisce la classe e suo padre
{
private: //solo la cella puo' accedere a pValore (es. 3,76)
	double pValore;  // double e' un numero decimale (il corrispospondente a float di python)

public: //chiunque puo' accedere a questa funzione (tutto quello che c'e' sotto)
	DoubleCell(double valore) // costruttore
	{
		pValore = valore;
	}

	~DoubleCell() // distruttore
	{

	}

	double get() override // ritorna il pValore
	{
		return pValore;
	}
};
#endif // !DOUBLECELL_H