from libs import CppAPI # libreria = insieme delle funzioni di C++
import tkinter as tk
from tkinter import ttk


cellsXNumber = 3
cellsYNumber = 3
root = tk.Tk()
table = []



for y in range(0, cellsYNumber):
    table.append([]);
    for x in range(0, cellsXNumber):
        table[y].append(CppAPI.ExcelCell(CppAPI.Cell()))

for y in range(0, cellsYNumber):
    for x in range(0, cellsXNumber):
        cell = tk.Entry(root, text = "")
        cell.grid(row = y, column = x)
        cell.insert(tk.END, table[y][x].ptr().get())
        




root.mainloop()