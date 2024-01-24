# <p align="center"><ins> Rapport Séance 7
##### 24 Janvier 2024
### <ins>Résumé:
Lors de ma première séance de travail avec Jetson Nano, j'ai entrepris l'excitante tâche de l'initialisation de cette carte.
Le travail était divisé en plusieurs étapes.

### <ins> Étape 1:

 Le processus a commencé par la configuration matérielle, où j'ai connecté tous les composants nécessaires, tels que la carte SD, l'alimentation et les périphériques externes.
 Après avoir réussi cette étape, j'ai procédé à l'installation du système d'exploitation, en l'occurrence, probablement Ubuntu qui est  adapté à la Jetson Nano. Cette phase a été cruciale pour garantir un environnement de travail stable et performant.

 <img src="https://github.com/YoussefMiriXX/Militech-Project/blob/71a6080021624a174ddc6273e96ba358f51d919a/Youssef%20Miri/Images/nvidia.png" width="350" alt="Jetson Nano">

 ### <ins>Étape 2:
 La découverte de l'interface utilisateur a été une étape intrigante, où j'ai pu explorer les fonctionnalités de Jetson Nano et prendre connaissance de son potentiel. Les premières impressions ont inclus la rapidité et la réactivité de l'appareil, ainsi que la facilité de navigation dans l'interface.
 La documentation fournie par NVIDIA a été une ressource précieuse, me permettant de résoudre rapidement d'éventuels problèmes et de mieux comprendre les fonctionnalités avancées de Jetson Nano.
 ### <ins>Étape 3 :Télécharger visual studio

 Pour que je puisse transférer le travail déjà fait pour la reconnaissance faciale sur la Jetson le  téléchargement  et la configuration de  Visual Studio Code directement sur Jetson Nano était très important.
  Cette étape m'a offert un environnement de développement intégré (IDE) pratique et convivial, facilitant l'écriture, le débogage et la gestion des projets.
  Ouvrir un terminal : Connectez-vous à votre Jetson Nano et ouvrez un terminal.

 ##### <ins>J'ai réalisé cette étape en suivant les instructions suivantes:

Mettre à jour le système : Avant d'installer de nouveaux logiciels, il est recommandé de mettre à jour le système. Utilisez la commande suivante dans le terminal :



` sudo apt update && sudo apt upgrade `

Télécharger Visual Studio Code : Utilisez la commande suivante pour télécharger le paquet DEB de Visual Studio Code depuis le site officiel de Microsoft :



`wget -O code.deb https://go.microsoft.com/fwlink/?LinkID=760868`

Installer Visual Studio Code : Installez le paquet que vous venez de télécharger à l'aide de la commande dpkg :



`sudo dpkg -i code.deb`

Installer les dépendances manquantes : Vous pourriez rencontrer des dépendances manquantes lors de l'installation de Visual Studio Code. Utilisez la commande suivante pour résoudre les dépendances :



`sudo apt install -f`

Vérifier l'installation : Vous pouvez maintenant vérifier si Visual Studio Code a été correctement installé en tapant simplement code dans le terminal.

Optionnel : Installer des extensions pour Jetson Nano : Explorez les extensions disponibles pour Visual Studio Code en recherchant celles spécifiquement conçues pour le développement sur Jetson Nano. Ces extensions peuvent faciliter le travail avec le matériel spécifique et les bibliothèques associées.

Lancer Visual Studio Code : Vous pouvez démarrer Visual Studio Code en utilisant la commande suivante dans le terminal :



`code`

### <ins>Étape 4:
Au cours de ma première séance de travail avec Jetson Nano, j'ai également consacré du temps à explorer des bibliothèques en vision par ordinateur, notamment TensorFlow et OpenCV. Ces deux bibliothèques jouent un rôle essentiel dans le domaine de l'intelligence artificielle et de l'analyse d'images.

Ces explorations ont jeté les bases pour des projets futurs dans le domaine de la vision par ordinateur, où Jetson Nano, associé à des bibliothèques telles que TensorFlow et OpenCV, devient un environnement idéal pour le développement d'applications intelligentes, allant de la reconnaissance d'objets à la création de prototypes avancés en vision artificielle.

### <ins> Conclusion:
En somme, ma première séance de travail avec Jetson Nano a été une introduction passionnante à ce nano-ordinateur puissant. L'initialisation réussie, la découverte des outils de développement et l'exploration des projets potentiels ont créé une base solide pour des aventures futures.

Pour la séance suivante, je vais transférer tous mon travail sur la jetson et assurer que je peux bien controler les moteurs avec la reconnaissance faciale avant de passer à la conception du canon de Gauss.

