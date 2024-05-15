from EditCell import ParseValue, tk, ttk, CppAPI # importa le funzioni di EditCell, tk, CppAPI


global cellsXNumber
global cellsYNumber
global displayTable
global root
global currentFormula
global table
global currentCell
global addY
global addX
# aggiungo le variabili globali al programma 

def Reload(): # ricarica i valori scritti nelle celle
    global cellsXNumber
    global cellsYNumber
    global displayTable
    global table
# definendo le variabili globali
    
    for y in range(0, cellsYNumber): # scorre i valori dentro a display table
        for x in range(0, cellsXNumber):
            
            displayTable[y][x].config( # modifica quel bottone
                text = table[y][x].ptr().get(), # modifica il testo dentro al bottone
                command = (
                    lambda x = x, y = y: currentFormula.set(CellPressed(x, y)) # quando crei una cella devi aggiornare la barra sopra (currentFormula)
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

    currentCell = table[y][x] # quando premi il pulsante si aggiorna la currentCell
    return table[y][x].ptr().getString()

def UpdateTable(): # scorre fra le celle e se vede r.58 la refresha
    global cellsYNumber
    global cellsXNumber
    global table
    global displayTable

    for y in range(0, cellsYNumber): # scorre nelle y e cerca colonne che devono essere aggiunte
        if (len(displayTable) <= y): # vede se le y sono abbastanza
            displayTable.append([]) # aggiunge una lista vuota (colonna)
        
        for x in range(0, cellsXNumber):
            if (len(displayTable[y]) <= x):
                button = tk.Button(root, text="", height=1, width=10) # crea il bottone
                button.place(x = x*80, y = (y+2)*25)
        
                displayTable[y].append(button) # aggiungo il bottone 
            displayTable[y][x].config(command=None) # dico che la funzione è nulla perchè la aggiungo dopo
                
        while (len(displayTable[y]) != cellsXNumber): # scorre nelle y e cerca colonne che devono essere rimosse
            displayTable[y][-1].destroy() # i bottoni/celle vengono distrutti
            displayTable[y].pop() # elimina la lista nella lista di liste
            
    while (len(displayTable) != cellsYNumber): # stessa roba ma per le x
        for element in displayTable[-1]:
            element.destroy()
        
        displayTable.pop()
        

    for y in range(0, cellsYNumber): # stessa cosa ma per table (lista oggetti), displaytable e' la lista dei bottoni
        if (len(table) <= y):
            table.append([]);
        
        for x in range(0, cellsXNumber):
            if (len(table[y]) <= x):
                table[y].append(CppAPI.ExcelCell(CppAPI.DoubleCell(1)))
        
        while (len(table[y]) != cellsXNumber):
            table[y].pop()
    
    while (len(table) != cellsYNumber):
        table.pop() # l'oggetto viene eliminato da button, il bottone no
    

    addX.place(x = (cellsXNumber + 1)*65, y = 50) # operazioni che calcolano la nuova posizione del bottone
    addY.place(x = 0, y = (cellsYNumber+2)*25)
    
    removeX.place(x = (cellsXNumber + 1)*65, y = 75)
    removeY.place(x = 40, y = (cellsYNumber+2)*25)
    
    Reload()

def AddX():
    global cellsXNumber
    cellsXNumber += 1 # aumenta o diminuisce il numero di celle
    
    UpdateTable() # chiama la funzione update table
    
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


cellsXNumber = 3 # definisce quante caselle ci saranno all'inizio della compilazione del programma 
cellsYNumber = 3
displayTable = [] # lista dei bottoni (bottoni -> celle che vengono letti bottoni per essere cliccabili)
table = [] # lista di tutti i puntatori delle celle (lista di tutti gli ExcelCell)
currentCell = None # la barra di funzione è vuota
root = tk.Tk() # crea finestra

currentFormula = tk.StringVar() # tutto quello che è scritto nella barra in alto viene visualizzata quando chiamo currentFormula, le do un "nome"
formulaBar = tk.Entry(root, textvariable=currentFormula) # definisce la barra in se, non ciò che contiene
formulaBar.grid(row=0, column=0) # dice dove la mette

updateButton = tk.Button(root, text="Update Value", command=UpdateValue) # crei il bottone del refresh (in excel non si aggiorna fino a quando non premi invio, è la stessa cosa)
updateButton.place(x = 150, y = 0) # dice dove la mette

addX = tk.Button(root, text="+", command=AddX, height=1, width=4) # bottone con il più /meno, sopra/sotto
addY = tk.Button(root, text="+", command=AddY, height=1, width=4)

removeX = tk.Button(root, text="-", command=RemoveX, height=1, width=4)
removeY = tk.Button(root, text="-", command=RemoveY, height=1, width=4)

UpdateTable() #funzione che aggiorna

root.state("zoomed")
root.mainloop()
