# <p align="center"><ins> Rapport Séance 10
##### 22 Février 2024
### <ins>Résumé:
Pendant cette séance,j'ai essayé le max possible d'avoir un bon rendement en remarquant le changement des fps, selon le programme éxécuté.

#### <ins>Erreur d'installation de CUDA:
L'installation de cuda a pris beaucoup de temps environ 2 à 3 heures, pour avoir une installation complète.Mais par contre, plusieurs erreurs ont été présenté d'où la plus importante était `gcc version is not supported`
De nombreux logiciels liés à CUDA nécessitent la version 8 de gcc.
Nous avons installé les versions 8 de gcc et g++ en parallèle de la version 9 préinstallée.
Il  faut  choisir la  version 8 de gcc avec ` sudo update-alternatives --config gcc` et ` sudo update-alternatives --config g++`.

Quand la version gcc est changé, l'installation passe sans aucun problème mais la Jetson se chauffe beaucoup et un message de système m'avertis que la température est élevée.
Désormais sur `jtop` maintenant on peut voir clairement que opencv est compilé avec `Cuda`.

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/a5528b1e123e43b11b5bd024b7272c23d3882d57/Youssef%20Miri/Images/vscode.png" width="250" alt="Cuda yes">

#### <ins> Surveillance de Fps:
Le programme utilisé pour surveiller toujours le rendement de la jetson pour  la reconnaissance faciale.

```
import cv2
import time

# Load the pre-trained face detection model
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Initialize the video capture object
cap = cv2.VideoCapture(0)  # 0 for the default camera, you can change it to 1, 2, etc. for other cameras

# Initialize variables for FPS calculation
frame_count = 0
start_time = time.time()

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()

    # Convert the frame to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Detect faces in the frame
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    # Draw rectangles around the detected faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

    # Display the frame with the detected faces
    cv2.imshow('Faces Detected', frame)

    # Increment frame count
    frame_count += 1

    # Calculate FPS every 10 frames
    if frame_count % 10 == 0:
        end_time = time.time()
        fps = frame_count / (end_time - start_time)
        print("FPS:", fps)
        frame_count = 0
        start_time = time.time()

    # Press 'q' to exit the loop
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture object and close the window
cap.release()
cv2.destroyAllWindows()
```
##### <ins> Commentaire: 
Après exécution du programme dans le terminal linux, en premier temps j'ai un fps compris entre 1.5 et 3, ce qui est insuffisant pour la reconnaissance faciale.
Après changement de la taille du frame avec la commande `resize`,j'ai un fps compris entre 7 et 7.5.

### <ins>Conclusion:
Un fps de 7 suffira jamais pour avoir un bon rendement pour bien détecter la personne.
Cepandant sur `Jtop`, je remarque toujours que le pourcentage de CPU est beaucoup plus élevé que celui du GPU.
Donc je ne suis pas certain, si la jetson utilise son gpu pour traiter le programme python.