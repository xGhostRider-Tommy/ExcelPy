#include "pch.h"
#ifndef DOUBLECELL_H
#define DOUBLECELL_H

#include "Cell.h"

class DoubleCell : public Cell
{
private:
	double pValore;

public:
	DoubleCell(double valore)
	{
		pValore = valore;
	}

	~DoubleCell()
	{

	}

	double get() override
	{
		return pValore;
	}
};
#endif // !DOUBLECELL_H