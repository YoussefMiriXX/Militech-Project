# <p align="center"><ins> Rapport Séance 2:

##### 21 novemebre 2023

### <ins>Résumé:
Durant cette séance mon but principal est de continuer le travail sur la détection faciale, tout en développant le code qui permet l'identification de la personne captée par la caméra .


### <ins>Le Code:

le code utilisé se base sur les mêmes librairies utilisés pendant la première séance `OpenCv` et  `Face-recognition`
et c'est écrit en langage Python.
```
import cvzone
from cvzone.FaceDetectionModule import FaceDetector
import cv2
import numpy as np
import face_recognition
import os
from datetime import datetime
# from PIL import ImageGrab
 
path = 'Images'
images = []
classNames = []
myList = os.listdir(path)
print(myList) #find  all names in my list# 
for cl in myList:
 curImg = cv2.imread(f'{path}/{cl}')
 images.append(curImg)
 classNames.append(os.path.splitext(cl)[0])  #remove jpg from the name of the  person#
print(classNames)
 
def findEncodings(images):
  encodeList = []
  for img in images:
      img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
      encode = face_recognition.face_encodings(img)[0]
      encodeList.append(encode)
  return encodeList
 




 
encodeListKnown = findEncodings(images)
print('Encoding Complete')
 
cap = cv2.VideoCapture(1, cv2.CAP_DSHOW)


 
while True:

    success, img = cap.read()   #img = captureScreen()

    imgS = cv2.resize(img,(0,0),None,0.25,0.25)#img resise for simpler processing
    imgS = cv2.cvtColor(imgS, cv2.COLOR_BGR2RGB) #converting into rgb#

    success, img = cap.read()
  
   

    facesCurFrame = face_recognition.face_locations(imgS)
    encodesCurFrame = face_recognition.face_encodings(imgS,facesCurFrame)
 
    for encodeFace,faceLoc in zip(encodesCurFrame,facesCurFrame):#zip for using in the same loop#
       matches = face_recognition.compare_faces(encodeListKnown,encodeFace) #send and compare faces 
       faceDis = face_recognition.face_distance(encodeListKnown,encodeFace) #find face distance
       matchIndex = np.argmin(faceDis)
    
  
       
       if faceDis[matchIndex]< 0.60:
         name = classNames[matchIndex].upper()
      
       else: name = 'Unknown'


       y1,x2,y2,x1 = faceLoc
       y1, x2, y2, x1 = y1*4,x2*4,y2*4,x1*4
       cv2.rectangle(img,(x1,y1),(x2,y2),(0,255,0),2)
       cv2.rectangle(img,(x1,y2-35),(x2,y2),(0,255,0),cv2.FILLED)
       cvzone.putTextRect(img,name,(x1+6,y2-6),cv2.FONT_HERSHEY_COMPLEX,1,(255,255,255),2)
 
 
    cv2.imshow('Webcam',img)
    cv2.waitKey(1)
```

Le principe c'est que après détection de la personne, il faut aussi identifier son nom d'après une base de donnée,et signaler son nom comme `unknown` ou inconnu si son nom n'existe pas.
Tout ça sera possible à cause des encodeurs qui vont permettre le traitement de l'image et l'identification des personnes.

### <ins>Résultats:


<img src= "https://github.com/YoussefMiriXX/Militech-Project/blob/4942b8eafd8b4f58cd58bf870f2dfe2e8c05c426/Youssef%20Miri/Images/test1.png" width="250" alt="Test1">

<img src= "https://github.com/YoussefMiriXX/Militech-Project/blob/4942b8eafd8b4f58cd58bf870f2dfe2e8c05c426/Youssef%20Miri/Images/Test2.png" width="275"  alt ="Test ">

je remerque bien que le code utilisé m'a permit d'identifier le nom de la personne.


### <ins>Contraintes:
L'identification du nom de la personne m'a obligé de changer le code utilisé dans la séance 1;Ce changement m'a permis d'identifier les noms des personnes mais en revanche j'ai perdu de la précision. 

### <ins>Amélioration à faire:

Pendant la séance suivante, je vais améliorer la précision et la portée de la détection faciale.

