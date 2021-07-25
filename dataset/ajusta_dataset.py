import os


dataset= open("MNIST_train.txt", "r")
file= open("dataset.txt", "a")
entradas= open("entradas.txt", "a")
saidas= open("saidas.txt", "a")

dados=dataset.readline()

while dados:
    dados=dados.replace(',', ' ')
    file.write(dados)
    dados=dataset.readline()

file.close()
dataset.close()

file= open("dataset.txt", "r")

linha=file.readline()
while linha:
    dados=linha.split()
    for j in range(10):
        if(j==int(dados[0])):
            saidas.write("1 ")
        else:
            saidas.write("0 ")
    saidas.write("\n") 

    for k in range(len(dados)-1):
        entradas.write(str((float(dados[k+1]))/255)+" ")
    entradas.write("\n")

    linha=file.readline()

file.close()
entradas.close()
saidas.close()
