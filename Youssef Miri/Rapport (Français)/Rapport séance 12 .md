# <p align="center"><ins> Rapport Séance 12
##### 12 Mars 2024
### <ins>Résumé:
Pendant cette séance j'ai continué le travail sur la tourelle.


### <ins>Tests des Moteurs:

Au début, j'ai testé le fonctionnement du système d'engrenage avec un servo-moteur qui peut supporter normalement 35 kg de charges.
Mais avec le système d'engrenage, le servo-moteur n'est pas le choix correspondant et cela pour plusieurs raisons.

1- Le servo-moteur ne me permet pas de faire une rotation de 360 degrès , et cela pose un problème surtout que le servo ne peut pas continuer à tourner vers l'infini, il va être bloqué.

2-Le servo-moteur est caractérisé par sa sa vitesse, mais il n'a pas un couple suffisant pour déplacer de grandes charges.

C'est pourcela,j'ai décidé d'utiliser un moteur pas-à-pas caractérisé par un grand couple et une vitesse résonnable pour ma tourelle.

### <ins>1-Moteur  pas-à-pas 28BYJ-48:
Le moteur 28BYJ-48, était un bon choix pour commencer à faire mes tests.
Mais après plusieurs tests sur mon montage de référence j'ai trouvé que ce moteur,n'a pas un couple assez puissant pour supporter les différentes charges.En plus, sa vitesse maximale est 10 tours par minute ce qui peut être insuffisant.

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/d6148e4d0149983cd2cce7f39dd90c2842860e57/Youssef%20Miri/Images/servo-potenc.jpg" width="250" alt="Branchement">

#### <ins> Montage de référence:

<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/d6148e4d0149983cd2cce7f39dd90c2842860e57/Youssef%20Miri/Images/servo-potenc.jpg" width="250" alt="Branchement">

### <ins> 2-Moteur pas-à-pas NEMA17:

Le NEMA17 effectue 200 pas pour faire une rotation complète de 360 degrés. Cela signifie que pour chaque pas, le moteur avance de 1,8 degré.

Le module pilote de moteur pas à pas A4988 est utilisé pour contrôler le moteur pas à pas NEMA17. 

#### <ins>Branchement:
<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/d6148e4d0149983cd2cce7f39dd90c2842860e57/Youssef%20Miri/Images/servo-potenc.jpg" width="250" alt="Branchement">

Le moteur NEMA17, est le choix idéale pour faire tourner la tourelle avec du couple mais aussi avec vitesse beaucoup plus grande que le  28BYJ-48.


