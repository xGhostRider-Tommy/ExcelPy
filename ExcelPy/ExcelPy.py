from libs import CppAPI # libreria = insieme delle funzioni di C++

b1 = CppAPI.DoubleCell(3)
b2 = CppAPI.ExcelCell(b1)
b = CppAPI.FuncCell([CppAPI.ExcelCell(CppAPI.DoubleCell(2), True), b2], "sum")



a = CppAPI.ExcelCell(b)
print(a.ptr().get())
input()