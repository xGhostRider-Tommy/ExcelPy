from libs import CppAPI # libreria = insieme delle funzioni di C++

b = CppAPI.DoubleCell(2)
a = CppAPI.ExcelCell(b)
print(a.ptr().get())
input()