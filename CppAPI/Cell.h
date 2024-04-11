#ifndef CELL_H
#define CELL_H // impedisce di definire la classe 2 volte

#include "pch.h" // per far funzionare la libreria

class Cell // definiamo la classe
{
public:
	Cell() // costruttore
	{
		
	}

	virtual ~Cell() // distruttore
	{

	}

	virtual double get() // funzione che da il valore della cella (valore = testo numerico contenuto nella cella)
	{
		return 0; // perchè è vuota, quindi è zero
	}

};
#endif // !CELL_H