from EditCell import ParseValue, tk, ttk, CppAPI


global cellsXNumber
global cellsYNumber
global displayTable
global root
global currentFormula
global table
global currentCell


def Reload():
    print("Reloading")
    global cellsXNumber
    global cellsYNumber
    global displayTable
    global table

    for y in range(0, cellsYNumber):
        for x in range(0, cellsXNumber):
            
            displayTable[y][x].config(
                text = table[y][x].ptr().get(),
                command = (
                    lambda x = x, y = y: currentFormula.set(CellPressed(x, y))
                )
            )

def ChangeValue():
    global currentCell
    global table
    global currentFormula

    print("ChangeValue")
    print(currentFormula.get())
    if (currentCell == None):
        print(currentCell)
        return
    else:
        currentCell.set(ParseValue(table, currentFormula.get()))
        Reload()

def CellPressed(x, y):
    global currentCell
    global table

    print("CellPressed")
    currentCell = table[y][x]
    print(currentCell)
    return table[y][x].ptr().getString()


            

cellsXNumber = 3
cellsYNumber = 3
displayTable = []
table = []
currentCell = None
root = tk.Tk()
currentFormula = tk.StringVar()
formulaBar = tk.Entry(root, textvariable=currentFormula)

formulaBar.grid(row=0, column=0)


idk = tk.Button(root, text="ChangeValue", command=ChangeValue)
idk.place(x=100, y = 10)




for y in range(0, cellsYNumber):
    table.append([]);
    for x in range(0, cellsXNumber):
        table[y].append(CppAPI.ExcelCell(CppAPI.DoubleCell(1)))


for y in range(0, cellsYNumber):
    displayTable.append([])
    for x in range(0, cellsXNumber):
        button = tk.Button(root, text="", height=1, width=8)
        button.place(x=x*65,y=y*25+25)
        
        displayTable[y].append(button)

Reload()


root.state("zoomed") 



root.mainloop()