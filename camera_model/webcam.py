import cv2
import os

img = cv2.imread("algarismo.png")
file= open("pipe_data.txt", "w")

grayFrame = cv2.resize(img, [28,28])
grayFrame = cv2.cvtColor(grayFrame, cv2.COLOR_BGR2GRAY)

dados=str(grayFrame);
dados=dados.replace("\n","")
dados=dados.replace("[","")
dados=dados.replace("]","")
dados=dados.replace("  "," ")
dados=dados.replace("  "," ")
file.write(dados)

file.close()
