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
		// cella vuota
	}

	~Cell() // distruttore
	{

	}

	virtual double get() // funzione che da il valore della cella (valore = testo numerico contenuto nella cella)
	{
		return 0; // perchè è vuota, quindi è zero
	}

	virtual std::string getString() // quello che vedo nella barra della funzione (se scrivo valore è anche quello che vedo, se funzione no) 
	{
		return "";
	}

	virtual std::string getDisplay() // quello che vedo nella cella
	{
		return getString();
	}

	virtual bool Error()
	{
		return false;
	}

};
#endif // !CELL_H