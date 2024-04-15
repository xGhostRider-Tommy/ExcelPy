#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "Cell.h"

class StringCell : public Cell
{
private:
	std::string pValue;

public:
	StringCell(std::string pyValore)
	{
		pValue = pyValore;
	}

	~StringCell()
	{
		
	}

	std::string getString() override
	{
		return pValue;
	}
};
#endif // !STRINGCELL_H