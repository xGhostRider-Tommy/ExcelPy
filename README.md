# Welcome to ExcelPy!

Ciao! Questo e' un progetto per scuola. Abbiamo deciso di ricreare una versione semplificata di Excel. Abbiamo deciso di scrivere una libreria in **C++** per il funzionamento usando **pybind11** chiamata **CppAPI** e poi in **python** l'interfaccia grafica e l'interazione con l'utente


# Run

## Requirements
- Almeno **Python 3.12.3** o successivi
- **Pybind11**
  > sul cmd eseguire:
  > `pip install pybind11`

## Running
Scaricare `ExcelPy.zip` ed eseguire `ExcelPy\ExcelPy.py`

# Compile CppAPI

## Requirements
- Almeno **Python 3.12.3** o successivi installati su **all users** con i **developer tools** installati sia su **python** che su **visual studio**
- **Pybind11** installati su **all users**
  > sul cmd come amministratore eseguire:
  > `pip install pybind11`

**IMPORTANTE**: L'installazione di python, con le relative dipendenze e' su `C:\Programs Files\Python`, se lo si ha installato in un altra directory cambiare le dipendenze a quella
PS: Python se e' installato su **all users** di solito vien salvato in `C:\Programs Files\Python%VERSIONE%`. Dove `%VERSIONE%` e' la versione di Python (Es. Python 3.12.x sara' installato in `C:\Programs Files\Python312` e python 3.11.x su `C:\Programs Files\Python311`).
Stessa cosa per **Pybind11**.

## Compiling
Scaricare `ExcelPy.zip` e aprire il file `*.sln` con visual studio e **applicare le dipendenze** corrette in base all'installazione di Python e Pybind11 corrente nelle proprieta' di **CppAPI**.
Le dipendenze da cambiare sono le seguenti:
- `C/C++\Generale\Directory di inclusione aggiuntive\`
- `Linker\Generale\Directory librerie aggiuntive`
