# <p align="center"><ins> Rapport Séance 5:

##### le 10 janvier  2024
### <ins>Résumé:
Dans cette séance , nous verrons comment détecter des visages à l'aide de Python et suivre ces visages à l'aide d'un servomoteur contrôlé par un Arduino Uno.

## <ins> 1-Première partie de la séance:

### <ins>a-Avant de commencer:
Installation des modules :

Pour installer les modules requis, nous utiliserons la commande pip install.

Tout d'abord, on ouvre de commandes (CMD) et on saisit  les codes suivants :



`pip install serial`
`pip install opencv-python`
`pip install numpy`
`pip install pyserial`

Ces commandes installeront les modules nécessaires. Nous pouvons maintenant passer à la partie codage...

### <ins>b-Le programme en Python:
Avant de commencer à écrire du code, la première chose à faire est de créer un nouveau dossier, car tout le code doit être stocké dans le même dossier. Ainsi, créez un nouveau dossier, on lui donne le nom de notre  choix, puis il faut  téléchargez le fichier 'Haarcascade'.Ce fichier doit être  Collé  dans le dossier nouvellement créé.

```
# Importation de tous les modules requis
import numpy as np
import serial
import time
import sys
import cv2

# Configuration du chemin de communication avec l'Arduino (Remplacez 'COM5' par le port auquel votre Arduino est connecté)
arduino = serial.Serial('COM5', 9600) 
time.sleep(2)
print("Connecté à l'Arduino...")

# Importation du fichier Haarcascade pour la détection des visages
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# Pour capturer le flux vidéo de la webcam.
cap = cv2.VideoCapture(0)

# Lecture de l'image capturée, conversion en image en niveaux de gris et recherche des visages
while 1:
    ret, img = cap.read()
    cv2.resizeWindow('img', 500,500)
    cv2.line(img,(500,250),(0,250),(0,255,0),1)
    cv2.line(img,(250,0),(250,500),(0,255,0),1)
    cv2.circle(img, (250, 250), 5, (255, 255, 255), -1)
    gray  = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3)

    # Détecte le visage et dessine un rectangle autour de celui-ci.
    for (x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),5)
        roi_gray  = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]

        arr = {y:y+h, x:x+w}
        print (arr)
        
        print ('X :' +str(x))
        print ('Y :'+str(y))
        print ('x+w :' +str(x+w))
        print ('y+h :' +str(y+h))

        # Centre du rectangle (ROI)
        xx = int(x+(x+h))/2
        yy = int(y+(y+w))/2
        print (xx)
        print (yy)
        center = (xx,yy)

        # Envoi des données à l'Arduino
        print("Le centre du rectangle est :", center)
        data = "X{0:d}Y{1:d}Z".format(xx, yy)
        print ("output = '" +data+ "'")
        arduino.write(data)

    # Affiche le flux vidéo.
    cv2.imshow('img',img)

    # Appuyez sur 'Esc' pour terminer l'exécution
    k = cv2.waitKey(30) & 0xff
    if k == 27:
       break
```
### <ins>c-Code Arduino:
Après que le script Python soit prêt, nous avons besoin d'un programme Arduino pour contrôler le servomoteur.
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
  Serial.begin(9600);
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
### <ins>d-Commentaire:
Toute la partie de programmation entre l'ordinateur et l'arduino est  prête pour controler le mouvement de la tourelle selon la position du visage détectée.


## <ins>2-Deuxième partie de la séance:
Durant la deuxième partie de la séance, j'ai participé à la conception des parties nécéssaires pour qu'on puisse passer à la deuxième étape ce qui est la construction de la tourelle.
Le chassis est désormais prêt pour mettre tous les capteurs ultra-sonores.

On a amélioré aussi la rigidité du Robot le chassis est plus stable et robuste.

| Militech                           | Front View                            
| ----------------------------------- | ----------------------------------- 
| ![Militech](https://github.com/YoussefMiriXX/Militech-Project/blob/52232dfc032dcfe40de3911cf2edf47a17fa6158/Youssef%20Miri/Images/Chassis%20Robot.jpg) | ![Militech](https://github.com/YoussefMiriXX/Militech-Project/blob/52232dfc032dcfe40de3911cf2edf47a17fa6158/Youssef%20Miri/Images/Robot%20front.jpg)| 

### <ins>La séance prochaine:

La séance prochaine va être consacrée pour faire le branchement nécéssaire pour controler les deux servo-moteurs et commencer à concevoir la Tourelle.
