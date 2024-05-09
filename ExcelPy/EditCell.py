from libs import CppAPI # libreria = insieme delle funzioni di C++
import tkinter as tk
from tkinter import ttk


def ParseValue(table, value):
    try:
        parsedValue = float(value)
    except:
        parsedValue = ParseFunction(table, value)
        if (parsedValue == None):
            return ParseString(table, value)
        else:
            return parsedValue
        
    return CppAPI.DoubleCell(parsedValue)
            


def ParseFunction(table, value):
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