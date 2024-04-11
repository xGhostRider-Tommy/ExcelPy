from libs import CppAPI # libreria = insieme delle funzioni di C++

rigaIDK = [CppAPI.Cell(), CppAPI.Cell(), CppAPI.Cell()]
func = CppAPI.FuncCell([rigaIDK[0], rigaIDK[1], rigaIDK[2]])
print(func.get())
input()