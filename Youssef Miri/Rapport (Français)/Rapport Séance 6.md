# <p align="center"><ins> Rapport Séance 6
##### 17 Janvier 2024
### <ins>Résumé:
Durant cette séance j'ai réussi à controler 2 Servo-Moteurs selon la position du visage détectée par Open-Cv.

#### <ins> 1-Programme en Python:
Une modification du programme de la séance passée était obligeatoire pour réussir à controler les Servos.
Le problème était tout simplement, que mon code python, n'a pas réussi à encoder les coordonnées en Bytes pour que l'arduino peut comprendre la position du visage.
```
import cv2
import serial,time
face_cascade= cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
cap=cv2.VideoCapture(1, cv2.CAP_DSHOW  )

#fourcc= cv2.VideoWriter_fourcc(*'XVID') 
#commande Fourcc utilisée pour sauvegarder tous que la caméra peut enregistrer dans un fichier, pas nécessaire pour le fonctionnement du programme.

ArduinoSerial=serial.Serial('com3',19200,timeout=0.1)
#out= cv2.VideoWriter('face detection4.avi',fourcc,20.0,(640,480))
time.sleep(1)



while cap.isOpened():
    ret, frame= cap.read()
    frame=cv2.flip(frame,1)  #mirror the image
    #print(frame.shape)
    gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    faces= face_cascade.detectMultiScale(gray,1.1,6)  #detect the face
    for x,y,w,h in faces:
        #sending coordinates to Arduino
        string='X{0:d}Y{1:d}Z'.format((x+w//2),(y+h//2))
        print(string)
        ArduinoSerial.write(string.encode('utf-8'))
        #plot the center of the face
        cv2.circle(frame,(x+w//2,y+h//2),2,(0,255,0),2)
        #plot the roi
        cv2.rectangle(frame,(x,y),(x+w,y+h),(0,0,255),3)
    #plot the squared region in the center of the screen
    cv2.rectangle(frame,(640//2-30,480//2-30),
                 (640//2+30,480//2+30),
                  (255,255,255),3)
    #out.write(frame)
    cv2.imshow('img',frame)
    #cv2.imwrite('output_img.jpg',frame)
    '''for testing purpose
    read= str(ArduinoSerial.readline(ArduinoSerial.inWaiting()))
    time.sleep(0.05)
    print('data from arduino:'+read)
    '''
    # press q to Quit
    if cv2.waitKey(10)&0xFF== ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
``` 
` Pour assurer le bon fonctionnement du programme il faut que la carte aurduino doit être connectée au port déjà indiqué dans le programme python pour avoir une communication pySerial dans notre cas c'est le COM3.`

#### <ins>2-Résultats:
| Reconnaissance Faciale                          | Coordonnées Envoyées                           
| ----------------------------------- | ----------------------------------- 
| ![Reconnaissance](https://github.com/YoussefMiriXX/Militech-Project/blob/a575f1bd3b72b09fffa051cb5fb984d02ad46fc4/Youssef%20Miri/Images/Reconnaissance%20faciale.png) | ![Coordonnées](https://github.com/YoussefMiriXX/Militech-Project/blob/a575f1bd3b72b09fffa051cb5fb984d02ad46fc4/Youssef%20Miri/Images/Coordonnes.png)| 

#### <ins> 3-Code Arduino:
Le code Arduino reste le même.
```
#include <Servo.h>

Servo servoVer; // Servo vertical
Servo servoHor; // Servo horizontal

int x;
int y;

int prevX;
int prevY;

void setup()
{
  Serial.begin(19200);
  servoVer.attach(5); // Attache le servo vertical à la broche 5
  servoHor.attach(6); // Attache le servo horizontal à la broche 6
  servoVer.write(90);
  servoHor.write(90);
}

void Pos()
{
  if (prevX != x || prevY != y)
  {
    int servoX = map(x, 600, 0, 70, 179);
    int servoY = map(y, 450, 0, 179, 95);

    servoX = min(servoX, 179);
    servoX = max(servoX, 70);
    servoY = min(servoY, 179);
    servoY = max(servoY, 95);

    servoHor.write(servoX);
    servoVer.write(servoY);
  }
}

void loop()
{
  if (Serial.available() > 0)
  {
    if (Serial.read() == 'X')
    {
      x = Serial.parseInt();
      if (Serial.read() == 'Y')
      {
        y = Serial.parseInt();
        Pos();
      }
    }
    while (Serial.available() > 0)
    {
      Serial.read();
    }
  }
}
```
#### <ins>4-Branchement des Servos:

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/a575f1bd3b72b09fffa051cb5fb984d02ad46fc4/Youssef%20Miri/Images/Branchement%20Servo1.jpg" width="250" alt="Branchement">


Le circuit est assez simple. Il suffit de connecter deux servomoteurs à l'Arduino.

- Vertical au Pin 5
- Horizontal au Pin 6
- Alimentation à +5V
- Masse à GND

##### Shéma finale:

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/a575f1bd3b72b09fffa051cb5fb984d02ad46fc4/Youssef%20Miri/Images/testservos.jpg" width="250" alt="Branchement">
 

### <ins>5-Séances prochaine:

A la fin de la séance j'ai eu accès à la carte 
`Jetson Nano`une carte informatique destinée à l'intelligence artificielle (IA) embarquée et au traitement des données.Alors, pendant les séances à venir, je vais transférer tout mon programme sur la carte Jetson.


