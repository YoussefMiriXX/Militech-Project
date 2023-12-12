# <p align="center"><ins> Rapport Séance 4
##### 12 décembre 2023
### <ins>Résumé:
Durant cette séance, mon but principal est de relier la caméra à un servo-moteur et de controler le Servo avec  un PWM.


### <ins>Branchement nécéssaire:

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/d6148e4d0149983cd2cce7f39dd90c2842860e57/Youssef%20Miri/Images/servo-potenc.jpg" width="250" alt="Branchement">






~~~
#include <Servo.h>

Servo Servo1;

int servoPin = 10;
int potPin = A0;


void setup() {
    Servo1.attach(servoPin);
}


void loop() {
    int reading = analogRead(potPin);
    int angle = map(reading, 0, 1023, 0, 180);
    Servo1.write(angle);
}



~~~

### <ins>Explication du programme:

1- Pour éviter tous problème il est crucial, d'ajouter la librairie Servo.h pour qu'on puisse controler le servo.
2- On commence toujours par la déclaration du numéro du pin du Servo puis  l'entrée analog A0 du potentiomètre.
3- La commande ~     Servo1.attach(servoPin);~ sert à relier le servo moteur au pin déjà déclarer comme 10.
4-Avec le potentiomètre on peut avoir une tension analogique compris entre 0 et 1023; cette tension sera après transformer en tension compris entre 0 et5V pqr l'arduino.
5- Du coup pour controler le servo avec un angle précis il est important de convertir cette tension analogique en un angle compris par le servo c'est avec la commande ~int angle = map(reading, 0, 1023, 0, 180);~ qu'on transforme le 0 en 0 degrés et le 1023 en 180 degrés.
6- Enfin ~Servo1.write(angle);~ transmet l'angle de rotation pour le Servo Moteur.


### <ins>Montage finale :
La caméra est monté au dessus du Servo anisi on peut tourner la caméra d'un angle compris entre 0 et 180 degrés.
<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/70a8a529522d50621e297062ebb881b77164e0b0/Youssef%20Miri/Images/Montage.jpg" width="250" alt="Montage">


### <ins>Problèmes rencontrés :
1-L'alimentation en 12 V à l'Arduino, a créée une fumée donc la carte a brûlé, après discussion avec le Prof, on n'a pas trouvé le problème.
2- La manipulation avec la tension 12V  a rendu hors service mon ordinateur.
















