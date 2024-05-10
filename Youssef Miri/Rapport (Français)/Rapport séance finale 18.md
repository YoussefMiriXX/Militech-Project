# <p align="center"><ins> Rapport Séance 18 et FINALE
##### 7 Mai 2024

### <ins> Résumé:

Pendant cette séance, j'ai réussi à entrainé un modèle avec YOLOV8 qui détecte que les cibles.
En plus, j'ai réussi à controler un servo moteur et un moteur pas à pas.

### <ins>L'entrainement du modèle:

#### <ins> 1-Base de Donnée:

Pour entrainer un modèle, il faut avant tous construire une base de donnée pour l'objet qu'on veut détecter.

Cette étape peut être trop lente, et difficile parfois car il faut collecter à peu près 700 images pour une seule classe puis après "labeliser" chaque image.Ce qui consiste à tracer des rectangles autour de l'objet désiré.

Roboflow est un site open-source qui nous permet de labeliser des images collectées.
Mais pour fasciliter le boulot, Robolow Universe offre l'opportunité d'utiliser des bases de données déjà faite par des collaborateurs.
Heureusement, j'ai pu trouvé une base de donnée qui détecte que des cibles.
#### <ins> Éxemple d'une image Labelisé:

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/d1da8614aa5dbbff6a5da18aa22904fa01e4ef2a/Youssef%20Miri/Images/Exemble%20label.png" width="350" alt="Label">


#### <ins> 2- Entrainer le modèle:

Après que la base de donnée est prête, c'est l'heure de l'entrainement.
Cependant, mon ordinateur portable ne possède pas une carte graphique et normalement un GPU est demandé pour entrainer un modèle.
Pour faire face à ce problème, j'ai décidé d'utilisé `Collab` une plateforme proposé par `Google` qui ressemble à `jupyter notebook`.Mais l'avantage est que je peux utiliser des GPU dans le `Cloud` proposé gratuitement par Google. Le GPU utilisé est Tesla A100 est coûte généralement, `10000$`.

#### <ins>Lien du Collab:
`https://colab.research.google.com/github/roboflow-ai/notebooks/blob/main/notebooks/train-yolov8-object-detection-on-custom-dataset.ipynb`

L'entrainement prend environ 15 minutes pour 150 Epochs.Il ne faut pas abuser avec le nombre d'Epochs pour ne pas avoir une sur saturation du modèle. 


#### <ins> Résultats:
<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/d1da8614aa5dbbff6a5da18aa22904fa01e4ef2a/Youssef%20Miri/Images/Target%20detec.png" width="350" alt="Label">

`La détection était un succès.`


### <ins> Partie intermédiare:

Le modèle entrainé, est exporté sous format `tensorrt fp16` sur la jetson, ce qui permet d'optimiser le rendement et la précision.
J'ai reçu à avoir `20 FPS` ce qui est suffisant. 

### <ins> Contrôle du Servo Moteur et du moteur pas à pas:

Pyfirmata permet facilement de contrôler un servo-moteur il faut préciser le mode du Pin dans le code qui sera forcément SERVO. Par rapport au Stepper, le code de l'initialisation est le même d'une simple LED.

#### <ins> Programme détection:
```
import cv2
from ultralytics import YOLO
import control as cnt


# load my YOLO model
model = YOLO("best_openvino_model")


# using webcam
cap = cv2.VideoCapture(1,cv2.CAP_DSHOW)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # object detection
    results = model(frame,show=True)
    objects_detected = False
   
    for box in results[0].boxes:
        class_id = int(box.cls)  # Get class ID
        class_label = results[0].names[class_id]  # Get class label from class ID
        print(f'Detected class: {class_label}')  # Print class label
        cnt.led(class_label)
        rotate="90"
        cnt.servo(rotate)
        cnt.step_motor(0, 0)
        

        objects_detected = True
    
    if  not objects_detected :
        class_label="youssef"
        cnt.led(class_label)
        rotate="0"
        cnt.servo(rotate)
        cnt.step_motor(1, 40)

```
#### <ins> Changement faite:

- Ajouter la fonction cnt.servo qui contrôle le servo moteur en communiquant avec le fichier control.py .

- Ajouter  cnt.step_motor qui contrôle un moteur pas à pas.


#### <ins> Control.py: contrôle de l'arduino

```
import pyfirmata
from pyfirmata import Arduino, SERVO
from time import sleep
import time

comport='COM3'
pin=10

board=pyfirmata.Arduino(comport)
board.digital[10].mode=SERVO

led_1=board.get_pin('d:13:o')
led_2=board.get_pin('d:12:o')
led_3=board.get_pin('d:11:o')
STEP_PIN=board.get_pin('d:3:o')
DIR_PIN=board.get_pin('d:2:o')

def led(class_label):
    if class_label=="Target": 
        led_1.write(1)
        led_2.write(1)
        led_3.write(1)
        print("led on")

    elif class_label=="youssef":  # No detection mode
        led_1.write(0)
        led_2.write(0)
        led_3.write(0)
        print("no object detected")
       
    else:
        led_1.write(1)
        led_2.write(0)
        led_3.write(0)
        print("led off")


def rotateservo(pin,angle):
    board.digital[pin].write(angle)
    sleep(0.015)


def servo(rotate):
    if rotate=="90":
        i=90
        rotateservo(pin,i)
    if rotate=="0":
        i=0
        rotateservo(pin,i)
        
   
def step_motor(direction, steps):
    DIR_PIN.write(direction)
    for _ in range(steps):
      STEP_PIN.write(1)
      time.sleep(0.0005)  # Adjust for your motor speed
      STEP_PIN.write(0)
      time.sleep(0.0004)  

```
#### <ins> Éxplication:
On peut voir que l'initialisation des Pins Step et Dir se fait comme une simple led mais par contre le pin 10 est sur mode SERVO.

La classe `Person` est changé par `Target`.

Si le programme ne détecte pas la cible qui est `Target`, le Moteur Pas à pas continuer à tourner avec un pas 40 et le servo sera toujours sur position 0 degrès.

Dans le cas où une cible est détectée, le pas à pas arrête et le servo prend une position de 90 degrès pour appuyer sur un boutton qui déclenche par suite le cannon magnétique.
2 Leds et un Laser vont être allumé ainsi.

