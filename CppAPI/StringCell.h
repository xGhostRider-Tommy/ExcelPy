#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "Cell.h"

class StringCell : public Cell
{
private:
	char* pValore;

public:
	StringCell(char* pyValore, int size)
	{
		pValore = new char[size];

		for (int i = 0; i < size; i++)
		{
			pValore[i] = pyValore[i];
		}
	}

	~StringCell()
	{
		delete pValore;
	}

	char* getString()
	{
		return pValore;
	}
};
#endif // !STRINGCELL_H