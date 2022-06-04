import os


entradas= open("entradas.txt", "a")
saidas= open("saidas.txt", "a")

for i in range(2000):
    entradas.write("0 0\n")
    saidas.write("0\n")

    entradas.write("0 1\n")
    saidas.write("1\n")

    entradas.write("1 0\n")
    saidas.write("1\n")

    entradas.write("1 1\n")
    saidas.write("0\n")

entradas.close()
saidas.close()
