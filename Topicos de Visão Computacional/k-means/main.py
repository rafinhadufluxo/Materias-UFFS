import numpy as np
import cv2

#codigo adaptado de https://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials/py_ml/py_kmeans/py_kmeans_opencv/py_kmeans_opencv.html

def rescale_frame(frame, percent=75):
    width = int(frame.shape[1] * percent/ 100)
    height = int(frame.shape[0] * percent/ 100)
    dim = (width, height)
    return cv2.resize(frame, dim, interpolation =cv2.INTER_AREA)

img = cv2.imread('img2.jpg')

kernel = np.ones((5,5),np.float32)/25
img = cv2.bilateralFilter(img,9,50,50)
img = cv2.dilate(img, kernel, iterations = 1)
img = cv2.erode(img, kernel, iterations = 1)
cv2.imshow('Imagem tratada', rescale_frame(img, 40))

Z = img.reshape((-1,3))

# convert to np.float32
Z = np.float32(Z)

# define criteria, number of clusters(K) and apply kmeans()
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0)
K = 2
ret,label,center=cv2.kmeans(Z,K,None,criteria,10,cv2.KMEANS_RANDOM_CENTERS)

# Now convert back into uint8, and make original image
center = np.uint8(center)
res = center[label.flatten()]
res2 = res.reshape((img.shape))

res2 = rescale_frame(res2, 40)

cv2.imwrite('images/Resultado3-K-'+str(K)+'.jpg', res2) 

cv2.imshow('Resultado',res2)
cv2.waitKey(0)
cv2.destroyAllWindows()
