import numpy as np
import cv2 as cv

#código adaptado de https://docs.opencv.org/3.4/d4/dee/tutorial_optical_flow.html

cap = cv.VideoCapture('imnew.mp4')

frame_width = int(cap.get(3))
frame_height = int(cap.get(4))

out  = cv.VideoWriter('out-100-2121.avi',cv.VideoWriter_fourcc('M','J','P','G'), 60, (frame_width,frame_height))

#ShiTomasi
feature_params = dict( maxCorners = 100, qualityLevel = 0.3, minDistance = 7, blockSize = 7 )

#lucas kanade
lk_params = dict( winSize  = (21, 21), maxLevel = 2, criteria = (cv.TERM_CRITERIA_EPS | cv.TERM_CRITERIA_COUNT, 10, 0.03))

# cores randomicas
color = np.random.randint(0,255,(100,3))

#primeiro frame
ret, old_frame = cap.read()
old_gray = cv.cvtColor(old_frame, cv.COLOR_BGR2GRAY)
p0 = cv.goodFeaturesToTrack(old_gray, mask = None, **feature_params)

#marcara de zeros
mask = np.zeros_like(old_frame)

while(1):
    ret,frame = cap.read()
    if(not ret):
        break

    frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

    #optical flow
    p1, st, err = cv.calcOpticalFlowPyrLK(old_gray, frame_gray, p0, None, **lk_params)

    # Selecao de pontos aceitaveis
    good_new = p1[st==1]
    good_old = p0[st==1]

    #linhas de tracking
    for i,(new,old) in enumerate(zip(good_new, good_old)):
        a,b = new.ravel()
        c,d = old.ravel()
        mask = cv.line(mask, (a,b),(c,d), color[i].tolist(), 2)
        frame = cv.circle(frame,(a,b),5,color[i].tolist(),-1)
    img = cv.add(frame,mask)

    cv.imshow('frame',img)
    #salvando o video
    out.write(img)

    k = cv.waitKey(30) & 0xff
    if k == 27:
        break

    #atualizacao para o proximo frame
    old_gray = frame_gray.copy()
    p0 = good_new.reshape(-1,1,2)

out.release()
