# <p align="center"><ins> Rapport Séance 8
##### 8 Février 2024
### <ins>Résumé:
- Changement d'image iso de la jetson.
- Téléchargement d'un visual studio code stable.
- Téléchargement d'Arduino Ide stable.
- Téléchargement des librairies nécéssaires.


### <ins> 1-Nouvelle Image Iso de la jetson:

Malheureusement, la dernière version d'`Ubuntu` officelle supporté par `Nvida` est le 18.04.
Cependant, cette version est obsolète, et plusieurs application comme `VsCode` ne sont pas stables, et parfois sont supprimées du système.

En fait, après beaucoup d'essaies pour  trouver une solution pour le problème, j'ai rendu compte que ubuntu 18.04 ne me permet pas de valider mon travail.
C'est pour cela, j'ai trouvé une version d' `ubuntu 20.04`, non supporté par Nvidia.

Cette version est trouvable sur [ICI](https://github.com/Qengineering/Jetson-Nano-Ubuntu-20-image).

Cette version ne présente aucun problème pour le moment.Cependant, ça reste une version non officielle de NVIDIA.

### <ins> 2-Télécharger VsCode:

Désormais, le téléchargerement de VsCode est beaucoup plus facile.

Il suffit de trouver le site officielle de vscode  mais attention if faut télécharger la version .deb Arm64, la version adéquate pour la jetSon nano.

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/a5528b1e123e43b11b5bd024b7272c23d3882d57/Youssef%20Miri/Images/vscode.png" width="250" alt="Vscode">

Après le téléchargement, on doit ouvrir le paquet téléchargé.
Pour faire ça il faut aller dans le path du paquet ouvrir le terminal puis taper le code suivant:
```
sudo apt install filename.deb
```
Et finalement, on a une version stable  de  Vs code qui nous permet de travailler facilement sur notre programme.

### <ins> 3-Télécharger Arduino Ide:
Cette étape, était faite aisement surtout avec l'ubuntu 20.04.

Pour le téléchargement, il suffit de taper dans le terminal le scripte suivant:
```
    $ git clone https://github.com/JetsonHacksNano/installArduinoIDE

    $ cd installArduinoIDE

    $ ./installArduinoIDE.sh
```
Après quelques minutes, le script d'installation vous demandera de redémarrer le Jetson. Il y a un raccourci sur le bureau pour lancer l'IDE Arduino (vous pouvez également le lancer depuis le tableau de bord Ubuntu). Après avoir sélectionné votre carte et port dans le menu Outils, vous êtes prêt à commencer !

### <ins> 4-Téléchargement des librairies nécéssaires:

Le téléchargemet des librairies déjà utilisé se fait directement en tapant dans le terminal les commandes suivantes:

```
sudo apt install 
sudo apt update && sudo apt upgrade
sudo apt install opencv-python
sudo apt install mediapipe
sudo apt install cvzone
sudo apt install dlib

```
### <ins> Conclusion:
Le travail effectué pendant les séances passées est transféré désormais sur la Jetson Nano qui va être utilisé sur le robot Militech.


