from EditCell import ParseValue, tk, ttk, CppAPI


global cellsXNumber
global cellsYNumber
global displayTable
global root
global currentFormula
global table
global currentCell
global addY
global addX


def Reload():
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

def UpdateValue():
    global currentCell
    global table
    global currentFormula

    print(currentFormula.get())
    if (currentCell == None):
        return
    else:
        currentCell.set(ParseValue(table, currentFormula.get()))
        Reload()

def CellPressed(x, y):
    global currentCell
    global table

    currentCell = table[y][x]
    return table[y][x].ptr().getString()

def UpdateTable():
    global cellsYNumber
    global cellsXNumber
    global table
    global displayTable

    for y in range(0, cellsYNumber):
        if (len(displayTable) <= y):
            displayTable.append([])
        
        for x in range(0, cellsXNumber):
            if (len(displayTable[y]) <= x):
                button = tk.Button(root, text="", height=1, width=10)
                button.place(x = x*80, y = (y+2)*25)
        
                displayTable[y].append(button)
            displayTable[y][x].config(command=None)
                
        while (len(displayTable[y]) != cellsXNumber):
            displayTable[y][-1].destroy()
            displayTable[y].pop()
            
    while (len(displayTable) != cellsYNumber):
        for element in displayTable[-1]:
            element.destroy()
        
        displayTable.pop()
        

    for y in range(0, cellsYNumber):
        if (len(table) <= y):
            table.append([]);
        
        for x in range(0, cellsXNumber):
            if (len(table[y]) <= x):
                table[y].append(CppAPI.ExcelCell(CppAPI.DoubleCell(1)))
        
        while (len(table[y]) != cellsXNumber):
            table[y].pop()
    
    while (len(table) != cellsYNumber):
        table.pop()
    

    addX.place(x = (cellsXNumber + 1)*65, y = 50)
    addY.place(x = 0, y = (cellsYNumber+2)*25)
    
    removeX.place(x = (cellsXNumber + 1)*65, y = 75)
    removeY.place(x = 40, y = (cellsYNumber+2)*25)
    
    Reload()

def AddX():
    global cellsXNumber
    cellsXNumber += 1
    
    UpdateTable()
    
def AddY():
    global cellsYNumber
    cellsYNumber += 1
    
    UpdateTable()

    
def RemoveX():
    global cellsXNumber
    cellsXNumber -= 1
    
    UpdateTable()
    
def RemoveY():
    global cellsYNumber
    cellsYNumber -= 1
    
    UpdateTable()


cellsXNumber = 3
cellsYNumber = 3
displayTable = []
table = []
currentCell = None
root = tk.Tk()

currentFormula = tk.StringVar()
formulaBar = tk.Entry(root, textvariable=currentFormula)
formulaBar.grid(row=0, column=0)

updateButton = tk.Button(root, text="Update Value", command=UpdateValue)
updateButton.place(x = 150, y = 0)

addX = tk.Button(root, text="+", command=AddX, height=1, width=4)
addY = tk.Button(root, text="+", command=AddY, height=1, width=4)

removeX = tk.Button(root, text="-", command=RemoveX, height=1, width=4)
removeY = tk.Button(root, text="-", command=RemoveY, height=1, width=4)

UpdateTable()

root.state("zoomed")
root.mainloop()