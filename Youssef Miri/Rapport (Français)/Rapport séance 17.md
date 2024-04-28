# <p align="center"><ins> Rapport Séance 17
##### 16 Avril 2024

### <ins> 1-Optimisation de YOLOV8:

Ce qui intéréssant avec Yolo c'est qu'il offre la possibilité d'optimiser le modèle pour avoir plus de performances non seulement sur le GPU mais sur le CPU aussi.

En gros on passe du modèle yolov8n.pt à une version optimisé par `openVino` efficace sur le CPU et la version `TENSORRT` efficace sur le GPU. 
Cela se passe avec une seule commande tapée sur notre terminal.

```
yolo export model=yolov8n.pt format=openvino #Le modèle est exporté automatiquement sous format onnx puis format openvino
```
### <ins> 2-YOLO + Arduino:

Pour mettre en référence la communication entre YOLO et l'arduino j'ai fait un mini projet qui consiste à allumer 2 leds et un laser si une personne est détectée.

En utilisant la librairie pyfirmata, la programmation de l'arduino se fait par python ce qui fascilite la communication.

##### <ins>Le programme est divisé en 2 parties:

<ins>1- Programme de détection:

```
import cv2
from ultralytics import YOLO
import controller as cnt



# load my YOLO model
model = YOLO("yolov8n_openvino_model")


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
        objects_detected = True
    
    if  not objects_detected :
        class_label="youssef"
        cnt.led(class_label)
```
##### <ins> Pour conclure:
Quand le modèle détecte une personne il va extraire l'ID de la classe mais ainsi son label qui sera dans ce cas person. Puis, il envoie le label à une autre fonction cnt.led qui sera capable de controler l'arduino.
Mais si mon modèle ne détecte aucun objet, la variable class_label sera égale à "youssef" qui sera envoyé aussi à l'arduino.

Par contre j'ai rencontré un problème majeure, quand le modèle ne détecte aucun objet car dans ce cas là, le modèle ne donne aucune valeur aux variables class_id et class_label d'où la nécéssité de créer la fonction `object_detected` qui permet de passer entre le mode détection et non détection.

<ins> 2-Programme d'Arduio:

```
import pyfirmata #Librairie pour communiquer en sérial avec l'arduino


comport='COM3' # Définir le port de l'arduino

board=pyfirmata.Arduino(comport) # initialiser la communication
led_1=board.get_pin('d:13:o')    # Définir le pin 13 comme output pareil pour le 12 et 11
led_2=board.get_pin('d:12:o')
led_3=board.get_pin('d:11:o')

def led(class_label):            # Notre fonction led() qui reçoit la valeur class_label

    if class_label=="person":    # Allume les 2 leds et mon laser
        led_1.write(1)
        led_2.write(1)
        led_3.write(1)
        print("led on")

    elif class_label=="youssef":  # les 2 leds et le laser sont éteint (mode non détection)
        led_1.write(0)
        led_2.write(0)
        led_3.write(0)
        print("no object detected")
       
    else:                         # Si le modèle détecte autre chose que la classe person allume une seule led.
        led_1.write(1)
        led_2.write(0)
        led_3.write(0)
        print("led off")

```
### <ins> Résultats:

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/a6c08130f7f0c38678cf51e86f93c9a66066de94/Youssef%20Miri/Images/YIA.jpg" width="400" alt="YOLO In action">

