from libs import CppAPI # libreria = insieme delle funzioni di C++
import tkinter as tk
from tkinter import ttk


def ParseValue(table, value): # funzione che viene chiamata da ExcelPy.py
    try:
        parsedValue = float(value) # se l'elemento e' un numero crea una DoubleCell con quel valore
    except:
        parsedValue = ParseFunction(table, value) # se non riesci chiama ParseFunction()
        if (parsedValue == None):
            return ParseString(table, value)
        else:
            return parsedValue
        
    return CppAPI.DoubleCell(parsedValue)
            


def ParseFunction(table, value): # prova a valutarlo come una funzione
    cells = []
    tPos = []

    if (len(value) != 0):
        parsedValue = value[1:].split(';')
        
        if (value[0] == '='):
            for element in parsedValue[1:]:
                tPos = element.split('_')

                if (len(tPos) == 2):
                    try:
                        x = int(tPos[0])
                        y = int(tPos[1])
                    except:
                        return None
                    cells.append(table[y][x])
            
                else:
                    cell = CppAPI.ExcelCell(ParseValue(table, element))
                
                    if (cell == None):
                        return None
                    else:
                        cells.append(cell)
        
            return CppAPI.FuncCell(cells, parsedValue[0], value)

        else:
            return None
    else:
        return None
              


def ParseString(table, value):
    if (value == ""):
        cell = CppAPI.Cell()
    else:
        cell = CppAPI.StringCell(value)

    return cell