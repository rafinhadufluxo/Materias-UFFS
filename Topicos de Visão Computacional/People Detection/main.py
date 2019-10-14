import numpy as np
import cv2

#Este trabalho tem como objetivo encontrar pessoas andando em um vídeo de segurança atraves da remocao de background corrida

#leitura do video
vid = cv2.VideoCapture('vid.mpg')

#itens para morfologia
kernel = np.ones((3,3),np.uint8)

#itens para a media corrida
ret, frame = vid.read()
grayFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
avg = np.float32(grayFrame)

frame_width = int(vid.get(3))
frame_height = int(vid.get(4))

# criacao dos arquivos para salvar
out  = cv2.VideoWriter('outColorido.avi',cv2.VideoWriter_fourcc('M','J','P','G'), 60, (frame_width,frame_height))

while(True):
    #leitura do frame
    ret, frame = vid.read()

    if(not ret):
        break

    #transformacao em cinza
    grayFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    #acumulo da media
    cv2.accumulateWeighted(grayFrame, avg, 0.001)
    bg = cv2.convertScaleAbs(avg)

    #remocao do fundo
    removal = cv2.absdiff(grayFrame, bg)
    ret, rem = cv2.threshold(removal, 22, 255,cv2.THRESH_BINARY)

    #morfologia
    rem = cv2.erode(rem, kernel, iterations = 1)
    rem = cv2.dilate(rem, kernel, iterations = 5)
    rem = cv2.erode(rem, kernel, iterations = 8)
    rem = cv2.dilate(rem, kernel, iterations = 16)

    #retangulos
    x,y,w,h = cv2.boundingRect(rem)
    frame = cv2.rectangle(frame ,(x,y),(x+w,y+h),(255,255,0),2)
    grayFrame = cv2.rectangle(grayFrame ,(x,y),(x+w,y+h),(0,255,0),2)

    #exibicao do video
    cv2.imshow('video original', frame)
    cv2.imshow('video gray', grayFrame)
    cv2.imshow('media corrida', rem)

    #armazenamento do Video
    out.write(frame)

    if cv2.waitKey(1) == 27:
        break

vid.release()
out.release()
cv2.destroyAllWindows()
