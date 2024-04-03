# <p align="center"><ins> Rapport Séance 15
##### 2 Avril 2024


### <ins> Présentation du robot:

La première partie de la séance a été consacrée à la présentation du robot devant nos professeurs. Nous avons mis en avant les différentes étapes de son développement, mettant en lumière les progrès accomplis jusqu'à ce stade. Cette présentation a permis de mettre en évidence les spécifications techniques du robot ainsi que les fonctionnalités qu'il est capable d'exécuter.


### <ins> Faire fonctionner la tourelle:

Une fois que le système d'engrenage a été correctement élaboré, il est temps de mettre en marche les moteurs.
Une fois que le moteur a été connecté et alimenté, je constate qu'il ne fonctionne pas correctement, il ne fait que vibrer sans tourner. 

Après avoir testé les différentes pines du moteur, j'ai constaté qu'il y avait un souci, donc j'ai pris la décision de le remplacer .

### <ins>Branchement:
<img src="https://github.com/YoussefMiriXX/Militech-Project/blob/f6d337f770651e6c54c26474f5577b12564c7617/Youssef%20Miri/Images/Branchement%20stepper.png" width="800" alt="Engrenages">

### <ins>Programme Arduino:

```
//Moteur pap
const int Pas=3;
const int Dir=2;




void setup(){
  Serial.begin(9600);
  //pap:
  pinMode(Pas,OUTPUT);
  pinMode(Dir,OUTPUT);
  digitalWrite(Dir,HIGH);
  
}


void loop() {
  digitalWrite(Dir,LOW);
  for(int x=0;x<2000;x++){
    digitalWrite(Pas,HIGH);
    delayMicroseconds(500);
    digitalWrite(Pas,LOW);
    delay(4); 
  } 


  delay(1000);
}

```
 
 Pour changer de sens le moteur je fais digitalWrite(Dir,HIGH) au lieu de digitalWrite(Dir,LOW).
2000 c'est le nombre de pas, 500 c'est le temps d'un pas, 4 c'est le délai entre chaque pas (je peux le modifier pour changer la vitesse, mais il faut pas par contre aller en dessous de 3 pour pas faire trop chauffer le driver).

### <ins>Partie informatique

J'ai également travaillé sur la Jetson Nano. Finalement, j'ai réussi à transférer toutes les tâches déjà accomplies sur mon ordinateur vers la Jetson.

Afin de mettre à l'épreuve le travail, j'ai pu gérer 5 LED avec un arduino en fonction du nombre de doigts détectés par ma Jetson.

<img src="" width="300" alt="Engrenages">
