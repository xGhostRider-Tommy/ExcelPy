import glob
from token import COMMA
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

a = [CppAPI.ExcelCell(CppAPI.DoubleCell(1))]
a[0] = "hdahuiasd"
a.pop()

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
    
    print("cellsYNumber: " + str(cellsYNumber) + "\n")
    print("len table: " + str(len(table)))
    print("y: " + str(y))
    while (len(table) != cellsYNumber):
        for i in range(0, len(table[-1])):
            table[-1].pop()
        table.pop()
        print("len table: " + str(len(table)))
        print("y: " + str(y))
    print("lets go")
        


    
        


    addX.place(x = cellsXNumber*65, y = 25)
    addY.place(x = 0, y = (cellsYNumber+2)*25)
    
    removeX.place(x = (cellsXNumber)*65, y = 25)
    removeY.place(x = 40, y = (cellsYNumber+2)*25)
    
    print("\n\n\n\n\n\n\n\n")
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