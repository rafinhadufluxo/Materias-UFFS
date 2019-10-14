import cv2
import numpy as np
from matplotlib import pyplot as plt

#Este trabalho visa comparar os resultados de uma limiarizacao de Otsu implementada pelo aluno e a implementada pelo Opencv.

img = cv2.imread('ncage.jpg',0)
diff = cv2.imread('ncage.jpg',0)
ret2,th2 = cv2.threshold(img,0,255,cv2.THRESH_OTSU)
cv2.imshow('OTSU-OPENCV', th2)
height, width = img.shape
histo = cv2.calcHist([img],[0],None, [256], [0,256])

b = 0
hist = []
for a in histo:
	hist.append(a[0])

s = height*width
p = [x / s for x in hist]

min_v = 999999
index = 0

#formula de Otsu
for a in range(1, 255):
	Wb = 0
	Ub = 0
	for b in range(0, a):
		Wb += p[b]
		Ub += b*hist[b]
	Ub /= sum(hist[0:a])
	V1 = 0
	for b in range(0, a):
		V1 += ((b - Ub)**2) * hist[b]
	V1 /= sum(hist[0:a])

	Wf = 0
	Uf = 0
	for b in range(a, 255):
		Wf += p[b]
		Uf += b*hist[b]
	aux = sum(hist[a:255])
	if(aux == 0):
		continue
	Uf = Uf/aux
	V2 = 0
	for b in range(a, 256):
		V2 += ((b - Uf)**2) * hist[b]
	V2 /= sum(hist[a:256])

	fin = Wb*V1 + Wf*V2

	if(fin <= min_v):
		min_v = fin
		index = a

#threshold encontrado
print('OSTU-IMPLEMENTADO: '+ str(index))
print('OSTU-OPENCV: '+ str(ret2))
imgaux = img

#limiarizacao
for x in range(0,width):
	for y in range(0,height):
		if img[y,x] < index:
			img[y,x] = 0
		else:
			img[y,x] = 255

#calculo de diferenca das imagens
for x in range(0,width):
	for y in range(0,height):
		if img[y,x] == th2[y,x]:
			diff[y,x] = 255
		else:
			diff[y,x] = 0


cv2.imshow('OTSU-IMPLEMENTADO',img)
cv2.imshow('Diferenca dos dois na imagem - Pixeis pretos sao a diferenca',diff)
cv2.waitKey(0)
cv2.destroyAllWindows()
