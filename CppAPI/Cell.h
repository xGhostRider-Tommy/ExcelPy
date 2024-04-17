#ifndef CELL_H
#define CELL_H // impedisce di definire la classe 2 volte

#include "pch.h" // per far funzionare la libreria
#include <vector>
#include <string>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


namespace py = pybind11;

class Cell // definiamo la classe
{
public:
	Cell() // costruttore
	{
		
	}

	~Cell() // distruttore
	{

	}

	virtual double get() // funzione che da il valore della cella (valore = testo numerico contenuto nella cella)
	{
		return 0; // perchè è vuota, quindi è zero
	}

	virtual std::string getString()
	{
		return "";
	}

	virtual std::string getDisplay()
	{
		return getString();
	}

};
#endif // !CELL_H