import numpy as np
import cv2

#trabalho que busca encontrar um objeto em movimento por meio do watershed do opencv

#leitura do video
vid = cv2.VideoCapture('vid.mp4')

#itens para morfologia
kernel = np.ones((3,3),np.uint8)

#itens para a media corrida
ret, frame = vid.read()
grayFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
avg = grayFrame

frame_width = int(vid.get(3))
frame_height = int(vid.get(4))

# criacao dos arquivos para salvar
out  = cv2.VideoWriter('outColorido.avi',cv2.VideoWriter_fourcc('M','J','P','G'), 30, (frame_width,frame_height))

#funcao de rescale do video para exibicao
def rescale_frame(frame, percent=75):
    width = int(frame.shape[1] * percent/ 100)
    height = int(frame.shape[0] * percent/ 100)
    dim = (width, height)
    return cv2.resize(frame, dim, interpolation =cv2.INTER_AREA)

#primeira leitura para obtencao do bg
while(True):
    #leitura do frame
    ret, frame = vid.read()

    if(not ret):
        break

    #transformacao em cinza
    grayFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    #acumulo da media
    avg = cv2.addWeighted(avg, 0.7, grayFrame, 0.3, 0)

#criacao do threshold que define o background
ret, thresh = cv2.threshold(avg,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
kernel = np.ones((2,2),np.uint8)
closing = cv2.morphologyEx(thresh,cv2.MORPH_CLOSE,kernel, iterations = 2)
#dilatando o background com o threshold e remocao de ruido
avg = cv2.dilate(closing, kernel, iterations = 3)

#lendo novamente o video para executar o watershed
vid = cv2.VideoCapture('vid.mp4')

i = 0
while(True):
    #leitura do frame
    ret, frame = vid.read()

    if(not ret):
        break

    #até a realizacao do watershed, uma parte desse codigo foi adaptada de https://www.bogotobogo.com/python/OpenCV_Python/python_opencv3_Image_Watershed_Algorithm_Marker_Based_Segmentation.php
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(gray,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

    #remocao de ruido
    kernel = np.ones((2,2),np.uint8)
    closing = cv2.morphologyEx(thresh,cv2.MORPH_CLOSE,kernel, iterations = 2)

    # background certo do frame
    sure_bg = cv2.dilate(closing,kernel,iterations=3)

    #remocao do background ja encontrado, para deixar apenas o corredor
    sure_bg = cv2.absdiff(avg, sure_bg)
    sure_bg = cv2.erode(sure_bg, kernel, iterations = 5)

    #encontrando o plano de frente do video
    dist_transform = cv2.distanceTransform(sure_bg,cv2.DIST_L2,3)

    # Threshold
    ret, sure_fg = cv2.threshold(dist_transform,0.1*dist_transform.max(),255,0)

    # encontrando a regiao desconhecida da imagem para conectar e realizar o watershed
    sure_fg = np.uint8(sure_fg)
    unknown = cv2.subtract(sure_bg,sure_fg)

    # criacao dos marcadores
    ret, markers = cv2.connectedComponents(sure_fg)
    markers = markers+1
    markers[unknown==255] = 0

    #aplicando o watershed e pintando o quadro original
    markers = cv2.watershed(frame, markers)
    frame[markers == -1] = [255,255,0]

    #salvando o video
    out.write(frame)
    frame = rescale_frame(frame, percent=50)

    #mostrando o video
    cv2.imshow('video original', frame)

    i += 1
    if cv2.waitKey(1) == 27:
        break

vid.release()
out.release()
cv2.destroyAllWindows()
