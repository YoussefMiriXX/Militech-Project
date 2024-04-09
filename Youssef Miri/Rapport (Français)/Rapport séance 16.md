# <p align="center"><ins> Rapport Séance 16
##### 9 Avril 2024


### <ins> Configuartion de Docker:
```
mkdir -p ~/nvdli-data # Créer un dossier de travail pour le conteneur
sudo docker run --runtime nvidia -it --rm --network host \
--volume ~/nvdli-data:/nvdli-nano/data \
--device /dev/video0 \
nvcr.io/nvidia/dli/dli-nano-ai:v2.0.2-r32.7.1
```

Docker est une plateforme open-source conçue pour automatiser le déploiement, la gestion et le dimensionnement des applications dans des environnements de conteneurisation. Les conteneurs sont des environnements légers et autonomes qui encapsulent les applications et leurs dépendances, permettant aux développeurs de les exécuter de manière cohérente sur n'importe quel système d'exploitation.

### <ins>1- Installation de YOLO "You Only Look Once"

YOLO, qui signifie "You Only Look Once" (Vous ne regardez qu'une fois), est un algorithme d'apprentissage en profondeur populaire utilisé pour la détection d'objets dans les images et les vidéos. Il est connu pour sa vitesse et sa précision, ce qui le rend largement utilisé dans diverses applications de vision par ordinateur.

L'innovation clé de YOLO est sa capacité à détecter les objets dans une image en un seul passage à travers le réseau neuronal, contrairement aux approches précédentes qui nécessitaient plusieurs passages. Cela rend YOLO beaucoup plus rapide que d'autres méthodes de détection d'objets tout en maintenant une haute précision.

#### <ins>Étapes suivies:

1- La jetson est fournit avec une version python 3.6.9,cependant, il est difficile de télécharger de nombreuses librairies telles que cvzone et ultralytics.

<ins>D'où c'était nécassaire de télécharger la version 3.8 en 3 commandes:
```
sudo apt install python3.8
sudo apt install python3.8-venv # Espace virtuelle python
sudo apt install binutils
```
2- <ins>Activer Notre espace virtuelle en 3 commandes:
```
python3.8 -m venv <Nom du fichier> # Créer un environnemment virtuel python avec le nom du fichier choisi
cd <Nom du fichier>  # Aller au répertoire du fichier créer.
source bin/activate # Activer l'environnement virtel
```
3-<ins>Télécharger librairies nécéssaires:
```
pip3 install ultralytics
```
Quand le téléchargeemnt d'Ultralytics est fini, on peut avoir accès directment à une version yolo8 déjà entrainé.
il suffit d'utiliser cette commande pour utiliser YOLOV8.

```
yolo task=detect mode=predict model=yolov8n.pt source=0 show=True # source=0 avoir accès à la caméra intégrée.
```

<ins>Résultats:

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/394fdbeef3926accb4aeb917ccf40e68b797f615/Youssef%20Miri/Images/yolo.png" width="350" alt="Hello Yolo">

Le model yolov8n est incroyable pour la détection des objets il offre en plus l'opportunité d'entrainer notre propre modèle et faire ainsi une détection.

### <ins>2-Installation de VNC viewer: 

Contrôler la jetson quand elle est utilisé sur le robot est impossible avec un écran, un clavier et souris....
C'est pourcela, j'ai télécharger VNC viewer  un système qui permet de contrôler à distance un ordinateur à travers un réseau informatique.

L'idée de base est que le logiciel VNC permet à un utilisateur de voir l'écran d'un ordinateur distant et d'interagir avec lui comme s'il était assis devant cet ordinateur, même s'il se trouve physiquement à un endroit différent.
