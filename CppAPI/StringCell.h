#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "Cell.h"

class StringCell : public Cell
{
private:
	char* pValore;

public:
	StringCell(char* valore)
	{
		pValore = valore;
	}

	~StringCell()
	{
		
	}

	char* getString()
	{
		return pValore;
	}
};
#endif // !STRINGCELL_H