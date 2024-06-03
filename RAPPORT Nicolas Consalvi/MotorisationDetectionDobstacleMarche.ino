#define trigArriereGauche 12
#define echoArriereGauche 11

#define echoDiagoGauche 29
#define trigDiagoGauche 28

#define echoDiagoDroit A2
#define trigDiagoDroit A3


#define trigArriereDroit A1
#define echoArriereDroit A0

#define trigAvantGauche 18
#define echoAvantGauche 19

#define trigAvantDroit A5
#define echoAvantDroit A4

#define trigAvant  A7
#define echoAvant  A6

#define moteurArriereDroit 4 
#define moteurArriereGauche 5 

#define moteurAvantDroit 6
#define moteurAvantGauche 8

#define pin1ArriereGauche 10
#define pin2ArriereGauche 9

#define pin1ArriereDroit 3
#define pin2ArriereDroit 2

#define pin1AvantGauche A10
#define pin2AvantGauche A11

#define pin1AvantDroit 16
#define pin2AvantDroit 17





// Définir les broches de contrôle des moteurs

int impulseTime1;
int impulseTime2;
unsigned long distanceArriereGauche;
unsigned long distanceArriereDroit;
unsigned long distanceAvantGauche;
unsigned long distanceAvantDroit;
unsigned long distanceAvant;
unsigned long distanceDiagoGauche;
unsigned long distanceDiagoDroit;
int lectureDiagoDroit;
int lectureDiagoGauche;
int lectureArriereGauche;
int lectureArriereDroit;
int lectureAvantGauche;
int lectureAvantDroit;
int lectureAvant;
int initialMillis;
int initialMicros=0;
unsigned long currentMillis;
unsigned long currentMicros;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trigArriereGauche, OUTPUT);
  pinMode(trigArriereDroit, OUTPUT);
  pinMode(trigAvantGauche, OUTPUT);
  pinMode(trigAvantDroit, OUTPUT);
  pinMode(trigAvant, OUTPUT);
  pinMode(trigDiagoDroit, OUTPUT);
   pinMode(trigDiagoGauche, OUTPUT);
  
  pinMode(echoArriereGauche, INPUT);
  pinMode(echoArriereDroit, INPUT);
  pinMode(echoAvantGauche, INPUT);
  pinMode(echoAvantDroit, INPUT);
  pinMode(echoAvant, INPUT);
  pinMode(echoDiagoGauche, INPUT);
  pinMode(echoDiagoDroit, INPUT);
  
  pinMode(moteurAvantGauche,OUTPUT);
  pinMode(moteurAvantDroit,OUTPUT);
  pinMode(moteurArriereGauche,OUTPUT);
  pinMode(moteurArriereDroit,OUTPUT);


pinMode(pin1ArriereGauche,OUTPUT);
pinMode(pin2ArriereGauche,OUTPUT);

pinMode(pin1ArriereDroit,OUTPUT);
pinMode(pin2ArriereDroit,OUTPUT);

pinMode(pin1AvantGauche,OUTPUT);
pinMode(pin2AvantGauche, OUTPUT);

pinMode(pin1AvantDroit, OUTPUT);
pinMode(pin2AvantDroit, OUTPUT);

digitalWrite(pin2AvantDroit,HIGH);
digitalWrite(pin2AvantGauche,HIGH);
digitalWrite(pin2ArriereGauche,HIGH);
digitalWrite(pin2ArriereDroit,HIGH);
digitalWrite(pin1ArriereGauche,LOW);
digitalWrite(pin1ArriereDroit,LOW);  
digitalWrite(pin1AvantGauche,LOW);  
digitalWrite(pin1AvantDroit,LOW); 

digitalWrite(moteurAvantGauche,HIGH);
digitalWrite(moteurAvantDroit,HIGH);
digitalWrite(moteurArriereGauche,HIGH);
digitalWrite(moteurArriereDroit,HIGH);
}


void loop() {  // put your main code here, to run repeatedly
currentMillis=millis();
currentMicros=micros();
if ((currentMillis-initialMillis)>60){

digitalWrite(trigArriereGauche,LOW);                 //activation capteur ultrasonore arriere gauche               
  if ((currentMicros-initialMicros)>2){
  digitalWrite(trigArriereGauche,HIGH);
  initialMicros=currentMicros;
  }
  if ((currentMicros-initialMicros)>10){
  digitalWrite(trigArriereGauche,LOW);
  initialMicros=currentMicros;
  }   
lectureArriereGauche=pulseIn(echoArriereGauche,HIGH);
distanceArriereGauche=lectureArriereGauche*0.017;
initialMillis=currentMillis;
Serial.print("ArriereGauche ");
Serial.println(distanceArriereGauche);             // mesure distance capteur ultrasonore arriere gauche  
//Serial.println(currentMillis); 

digitalWrite(trigArriereDroit,LOW);                //activation capteur ultrasonore arriere droit   
  if ((currentMicros-initialMicros)>2){
  digitalWrite(trigArriereDroit,HIGH);
  initialMicros=currentMicros;
  }
  if ((currentMicros-initialMicros)>10){
  digitalWrite(trigArriereDroit,LOW);
  initialMicros=currentMicros;
  }
lectureArriereDroit=pulseIn(echoArriereDroit,HIGH);                  // mesure distance capteur ultrasonore arriere droit
distanceArriereDroit=lectureArriereDroit*0.017;
Serial.print("ArriereDroit ");
Serial.println(distanceArriereDroit);

digitalWrite(trigAvantDroit,LOW);                //activation capteur ultrasonore avant droit   
  if ((currentMicros-initialMicros)>2){
  digitalWrite(trigAvantDroit,HIGH);
  initialMicros=currentMicros;
  }
  if ((currentMicros-initialMicros)>10){
  digitalWrite(trigAvantDroit,LOW);
  initialMicros=currentMicros;
  }
lectureAvantDroit=pulseIn(echoAvantDroit,HIGH);                  // mesure distance capteur ultrasonore avant droit
distanceAvantDroit=lectureAvantDroit*0.017;
Serial.print("AvantDroit ");
Serial.println(distanceAvantDroit);

digitalWrite(trigAvantGauche,LOW);                //activation capteur ultrasonore avant gauche 
  if ((currentMicros-initialMicros)>2){
  digitalWrite(trigAvantGauche,HIGH);
  initialMicros=currentMicros;
  }
  if ((currentMicros-initialMicros)>10){
  digitalWrite(trigAvantGauche,LOW);
  initialMicros=currentMicros;
  }
lectureAvantGauche=pulseIn(echoAvantGauche,HIGH);                  // mesure distance capteur ultrasonore avant gauche
distanceAvantGauche=lectureAvantGauche*0.017;
Serial.print("AvantGauche ");
Serial.println(distanceAvantGauche);

digitalWrite(trigAvant,LOW);                //activation capteur ultrasonore avant 
  if ((currentMicros-initialMicros)>2){
  digitalWrite(trigAvant,HIGH);
  initialMicros=currentMicros;
  }
  if ((currentMicros-initialMicros)>10){
  digitalWrite(trigAvant,LOW);
  initialMicros=currentMicros;
  }
lectureAvant=pulseIn(echoAvant,HIGH);                  // mesure distance capteur ultrasonore avant 
distanceAvant=lectureAvant*0.017;
Serial.print("Avant ");
Serial.println(distanceAvant);


digitalWrite(trigDiagoDroit,LOW);                //activation capteur ultrasonore diago droit   
  if ((currentMicros-initialMicros)>2){
  digitalWrite(trigDiagoDroit,HIGH);
  initialMicros=currentMicros;
  }
  if ((currentMicros-initialMicros)>10){
  digitalWrite(trigDiagoDroit,LOW);
  initialMicros=currentMicros;
  }
lectureDiagoDroit=pulseIn(echoDiagoDroit,HIGH);                  // mesure distance capteur ultrasonore diago droit
distanceDiagoDroit=lectureDiagoDroit*0.017;
Serial.print("DiagoDroit ");
Serial.println(distanceDiagoDroit);



digitalWrite(trigDiagoGauche,LOW);                //activation capteur ultrasonore diago gauche   
  if ((currentMicros-initialMicros)>2){
  digitalWrite(trigDiagoGauche,HIGH);
  initialMicros=currentMicros;
  }
  if ((currentMicros-initialMicros)>10){
  digitalWrite(trigDiagoGauche,LOW);
  initialMicros=currentMicros;
  }
lectureDiagoGauche=pulseIn(echoDiagoGauche,HIGH);                  // mesure distance capteur ultrasonore diago gauche
distanceDiagoGauche=lectureDiagoGauche*0.017;
Serial.print("DiagoGauche ");
Serial.println(distanceDiagoGauche);



if (distanceAvant>=60 && distanceAvantGauche>=60 && distanceAvantDroit>=60 ) {

digitalWrite(pin1AvantDroit,HIGH);
digitalWrite(pin2AvantDroit,LOW);  
digitalWrite(pin1ArriereDroit,HIGH);
digitalWrite(pin2ArriereDroit,LOW);            //aucun obstacle a moins de 40 cm :les cheinilles tournent dans
digitalWrite(pin1AvantGauche,HIGH);            //le même sens et le robot avance tout droit
digitalWrite(pin2AvantGauche,LOW);  
digitalWrite(pin1ArriereGauche,HIGH);
digitalWrite(pin2ArriereGauche,LOW);
 
analogWrite(moteurArriereDroit,255);
analogWrite(moteurArriereGauche,255);            //activation des quatres moteurs
analogWrite(moteurAvantDroit,255);
analogWrite(moteurAvantGauche,255);

}

else {


if (distanceArriereGauche>=distanceArriereDroit){

  if (distanceDiagoDroit>=30 && distanceAvantDroit>=30){

digitalWrite(pin1AvantDroit,HIGH);
digitalWrite(pin2AvantDroit,LOW);  
digitalWrite(pin1ArriereDroit,HIGH);
digitalWrite(pin2ArriereDroit,LOW);            // tant qu'il n'y a aucun obstacle a moins sur la diago droite :les cheinilles tournent dans
digitalWrite(pin1AvantGauche,HIGH);            //le même sens et le robot avance tout droit
digitalWrite(pin2AvantGauche,LOW);  
digitalWrite(pin1ArriereGauche,HIGH);
digitalWrite(pin2ArriereGauche,LOW);
 
analogWrite(moteurArriereDroit,255);
analogWrite(moteurArriereGauche,255);            //activation des quatres moteurs
analogWrite(moteurAvantDroit,255);
analogWrite(moteurAvantGauche,255);


  }

  else {

digitalWrite(pin1AvantDroit,HIGH);
digitalWrite(pin2AvantDroit,LOW);  
digitalWrite(pin1ArriereDroit,HIGH);                     //tourne a gauche
digitalWrite(pin2ArriereDroit,LOW); 
digitalWrite(pin1AvantGauche,LOW);
digitalWrite(pin2AvantGauche,HIGH);  
digitalWrite(pin1ArriereGauche,LOW);
digitalWrite(pin2ArriereGauche,HIGH);
 
analogWrite(moteurArriereDroit,255);
analogWrite(moteurArriereGauche,255);
analogWrite(moteurAvantDroit,255);
analogWrite(moteurAvantGauche,255);

 }

}

else {

  if (distanceDiagoGauche>=30 && distanceAvantGauche>=30){

digitalWrite(pin1AvantDroit,HIGH);
digitalWrite(pin2AvantDroit,LOW);  
digitalWrite(pin1ArriereDroit,HIGH);
digitalWrite(pin2ArriereDroit,LOW);            // tant qu'il n'y a aucun obstacle a moins sur la diago droite :les chenilles tournent dans
digitalWrite(pin1AvantGauche,HIGH);            //le même sens et le robot avance tout droit
digitalWrite(pin2AvantGauche,LOW);  
digitalWrite(pin1ArriereGauche,HIGH);
digitalWrite(pin2ArriereGauche,LOW);
 
analogWrite(moteurArriereDroit,255);
analogWrite(moteurArriereGauche,255);            //activation des quatres moteurs
analogWrite(moteurAvantDroit,255);
analogWrite(moteurAvantGauche,255);
}

else {


digitalWrite(pin1AvantDroit,LOW);
digitalWrite(pin2AvantDroit,HIGH);  
digitalWrite(pin1ArriereDroit,LOW);
digitalWrite(pin2ArriereDroit,HIGH);                              //tourne a droite 
digitalWrite(pin1AvantGauche,HIGH);
digitalWrite(pin2AvantGauche,LOW);  
digitalWrite(pin1ArriereGauche,HIGH);
digitalWrite(pin2ArriereGauche,LOW);
 
analogWrite(moteurArriereDroit,255);
analogWrite(moteurArriereGauche,255);
analogWrite(moteurAvantDroit,255);
analogWrite(moteurAvantGauche,255);


}


} 

}
}
}





