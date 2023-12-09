# <p align="center"><ins> Rapport Séance 3:

##### 9 décembre 2023

### <ins>Résumé:
Mon but principal dans cette séance était l'amélioration de la précision de la reconnaissance faciale parce que, la précision est cruciale pour le bon fonctionnement de notre robot `MILITECH`

### <ins>Solutions adaptées:

Après plusieurs recherches j'ai trouvé que c'est possible d'utiliser une machine pour créer une base de donnée et bien détecter la personne dans cette base de donnée.
Cette machine utilisée trouvabel sur Google.com s'appelle`Teacheable machine.`
Son but principale est de fournir des données: images,sons etc puis créer une classe à partir de ces donnée.

L'utilisateur peut toujours changer le nom de la classe.Ainsi,en ouvrant par exemple ma caméra, la machine peut savoir si cette donnée de caméra correspond à une  classe prédéfinis par l'utilisateur.

### <ins>Avantages:
1- La machine est hyper simple à utiliser il suffit juste de fournir des données et voilà! avec le bouton train your model, notre modèle est prêt à être utiliser

2- Le téléchargement et l'exportation du modèle est très simple.En fait , on peut exporter le modèle et l'utiliser directement avec `open-cv` la librairie déjà utiliser avant mais aussi l'exportation pour les micro-controlleurs comme `Arduino` et `Rasberry-pi` est toujours possible.
En effet, ça va facsiliter les étapes suivantes de la conception du robot avec `Arduino`.

### <ins>Démarches:
le modèle fonctionne avec une autre librairie qui s'appelle ` Tensorflow`,le téléchargement de la librairie avec plusieurs autres librairies comme `Keras` m'a pris beaucoup de temps.Créer un environnemnt `Conda` était nécéssaire pour le bon fonctionnemnt du programme.



### <ins>Contraintes:
Des problèmes de stabilités existent toujours même parfois de la précison.

### <ins>Travail de la  séance suivante:


La séance suivante va être divisé en deux parties:

1. Faire plus de recherches pour assurer le bon fonctionnement du modèle.

2. Transférer le programme sur la carte Arduino pour controler selon les données un servo-Moteur.




