import numpy as np
import cv2
#funcao que faz a supressao dos nao maximos - funcao baseada na funcao de https://github.com/FienSoP/canny_edge_detector
def non_max_suppression(img, D):
        M, N = img.shape
        Z = cv2.imread('image.jpg', 0)
        angle = D * 180. / np.pi
        angle[angle < 0] += 180


        for i in range(1,M-1):
            for j in range(1,N-1):
                try:
                    q = 255
                    r = 255

                   #angle 0
                    if (0 <= angle[i,j] < 22.5) or (157.5 <= angle[i,j] <= 180):
                        q = img[i, j+1]
                        r = img[i, j-1]
                    #angle 45
                    elif (22.5 <= angle[i,j] < 67.5):
                        q = img[i+1, j-1]
                        r = img[i-1, j+1]
                    #angle 90
                    elif (67.5 <= angle[i,j] < 112.5):
                        q = img[i+1, j]
                        r = img[i-1, j]
                    #angle 135
                    elif (112.5 <= angle[i,j] < 157.5):
                        q = img[i-1, j-1]
                        r = img[i+1, j+1]

                    if (img[i,j] >= q) and (img[i,j] >= r):
                        Z[i,j] = img[i,j]
                    else:
                        Z[i,j] = 0


                except IndexError as e:
                    pass

        return Z

#funcao de threshold binario
def threshold(img):
    th, dst = cv2.threshold(img, 42, 255, cv2.THRESH_BINARY)
    return dst

#funcao de hysteresis, adaptada de https://github.com/FienSoP/canny_edge_detector
def hysteresis(img, weak = 25, strong = 100):
    M, N = img.shape
    for i in range(1, M-1):
        for j in range(1, N-1):
            if (img[i,j] == weak):
                try:
                    if ((img[i+1, j-1] == strong) or (img[i+1, j] == strong) or (img[i+1, j+1] == strong)
                        or (img[i, j-1] == strong) or (img[i, j+1] == strong)
                        or (img[i-1, j-1] == strong) or (img[i-1, j] == strong) or (img[i-1, j+1] == strong)):
                        img[i, j] = strong
                    else:
                        img[i, j] = 0
                except IndexError as e:
                    pass
    return img


imga = cv2.imread('image.jpg', 0)
blur = cv2.GaussianBlur(imga,(5,5),0)

gradientx = cv2.convertScaleAbs(cv2.Sobel(blur, cv2.CV_64F,1,0,ksize=3))
gradienty = cv2.convertScaleAbs(cv2.Sobel(blur, cv2.CV_64F,0,1,ksize=3))
gradients = cv2.addWeighted(gradientx, 0.5, gradienty, 0.5, 0);

theta = np.arctan2(gradienty, gradientx)
z = non_max_suppression(gradients, theta)
thresh = threshold(z)
hyst = hysteresis(thresh)

cv2.imshow('imagem original', imga)
cv2.imshow('final', hyst)

edges = cv2.Canny(imga,100,200)
cv2.imshow('canny opencv', edges)

cv2.waitKey(0)
cv2.destroyAllWindows()
