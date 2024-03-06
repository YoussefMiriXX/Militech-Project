# <p align="center"><ins> Rapport Séance 11
##### 3 Mars 2024
### <ins>Résumé:
Cette séance été consacré pour la conception de la tourelle, et aider mon binôme à finir sa partie de travail concernant le bon placement des composés électronique et assurer un bon branchement.


### <ins> Système de fonctionnemnt de la tourelle:

Le système de tourelle repose sur l'utilisation de deux engrenages de tailles différentes, où le premier engrenage entraîne le mouvement du second. Ce dernier est spécialement conçu pour recevoir les composants du canon magnétique du système c'est pourcela il sera d'une taille plus grande . Un servomoteur est connecté à une carte Arduino Uno, ce qui permet de contrôler le mouvement des engrenages. De plus, le moteur peut être piloté via Bluetooth en ajoutant un module Bluetooth à l'Arduino.

Le Servo-moteur utilisé fait parti des moteurs qui vont être pilotés par la detection faciale.
Mais pour le moment, j'ai intégré le système Bluetooth car la partie de détection va être optimisée plus tard.

Il faut noté que le nombre de dents du grand engrenage est le double du petit.Cela signifie que si le petit fait 2 tours le grand engrenage, va faire une seule.

Plusieurs tests seront faits après pour déterminer le bon rapport entre les deux ainsi je peux optimiser la vitesse de la tourelle pour avoir un bon rendememt. 

### <ins>Déroulemet de la conception:

La conception des engrenages est faite sur inkscape.
Le petit d'engrenage est fait en plexiglass et le grand est fait en bois par découpe laser.


<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/efb2bc8df0fd496679bbdbb024ede58e4ff296e6/Youssef%20Miri/Images/engrenage.png" width="300" alt="Engrenages">

Apès, le branchement du servo moteur à l'arduino est fait en ajoutant aussi le module bluetooth.
Code Arduino:

```
#include <SoftwareSerial.h> // TX RX software library for bluetooth

#include <Servo.h> // servo library 
Servo myservo; // servo name

int bluetoothTx = 10; // bluetooth tx to 10 pin
int bluetoothRx = 11; // bluetooth rx to 11 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo.attach(9); // attach servo signal wire to pin 9
  //Setup usb serial connection to computer
  Serial.begin(9600);
  Serial.print("Bonjour");

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
  delay(500);

}

void loop(){

  //Read from bluetooth and write to usb serial
  if(bluetooth.available()> 0 ) // receive number from bluetooth
  {
    int servopos = bluetooth.read(); // save the received number to servopos
    Serial.println(servopos); // serial print servopos current number received from bluetooth
    myservo.write(servopos); // roate the servo the angle received from the android app
  
  }

}
```

### <ins> Assiter mon binôme:

En premeir temps , on a fixé sur la planche les divers éléments requis pour la motorisation (2 ponts en H l298N/carte arduino méga/supports des capteurs ultrasons imprimés en 3D au fablab).
Par la suite, on a coupé les vis dépassant de la planche en bois à l’aide d’une meuleuse
dans le but de la visser sur le châssis en aluminium de notre robot.

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/8ccb46a0ad9631af09e1d11dbcabbe0421302e2d/Youssef%20Miri/Images/Mod%C3%A8le.png" width="300" alt="Shéma finale">

### <ins>Séance prochaine:
Au cours de la semaine prochaine, je vais poursuivre les travaux sur la tourelle afin de garantir son bon fonctionnement avec le servo utilisé.Par la suite, je prévois de construire un second étage en bois où la tourelle sera installée. 
