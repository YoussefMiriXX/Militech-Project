#include<SoftwareSerial.h>
#define RX A9
#define TX A8
SoftwareSerial BlueT(RX,TX);
char Data;


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






void setup() {
Serial.begin(9600);
delay(500);
Serial.println("Bonjour -Pret pour les commandes AT");
BlueT.begin(9600);
delay(500);
}

void loop() {
while (BlueT.available()) {
Serial.print(char(BlueT.read())); }
while (Serial.available()) {
BlueT.write(char(Serial.read())); }

if (BlueT.available()){
    Data=char(BlueT.read());
    if (Data=='F') {
digitalWrite(pin1AvantDroit,HIGH);
digitalWrite(pin2AvantDroit,LOW);  
digitalWrite(pin1ArriereDroit,HIGH);
digitalWrite(pin2ArriereDroit,LOW);            //aucun obstacle a moins de 40 cm :les cheinilles tournent dans
digitalWrite(pin1AvantGauche,HIGH);            //le même sens et le robot avance tout droit
digitalWrite(pin2AvantGauche,LOW);  
digitalWrite(pin1ArriereGauche,HIGH);
digitalWrite(pin2ArriereGauche,LOW);
 
digitalWrite(moteurArriereDroit,HIGH);
digitalWrite(moteurArriereGauche,HIGH);            //activation des quatres moteurs
digitalWrite(moteurAvantDroit,HIGH);
digitalWrite(moteurAvantGauche,HIGH);
      delay(500);
    }
    else if (Data=='B') {
digitalWrite(pin2AvantDroit,HIGH);
digitalWrite(pin1AvantDroit,LOW);  
digitalWrite(pin2ArriereDroit,HIGH);
digitalWrite(pin1ArriereDroit,LOW);            //aucun obstacle a moins de 40 cm :les cheinilles tournent dans
digitalWrite(pin2AvantGauche,HIGH);            //le même sens et le robot avance tout droit
digitalWrite(pin1AvantGauche,LOW);  
digitalWrite(pin2ArriereGauche,HIGH);
digitalWrite(pin1ArriereGauche,LOW);
 
digitalWrite(moteurArriereDroit,HIGH);
digitalWrite(moteurArriereGauche,HIGH);            //activation des quatres moteurs
digitalWrite(moteurAvantDroit,HIGH);
digitalWrite(moteurAvantGauche,HIGH);
      delay(500);
    }
    else if (Data=='R') {
digitalWrite(pin1AvantDroit,LOW);
digitalWrite(pin2AvantDroit,HIGH);  
digitalWrite(pin1ArriereDroit,LOW);
digitalWrite(pin2ArriereDroit,HIGH);                              //tourne a droite 
digitalWrite(pin1AvantGauche,HIGH);
digitalWrite(pin2AvantGauche,LOW);  
digitalWrite(pin1ArriereGauche,HIGH);
digitalWrite(pin2ArriereGauche,LOW);
 
digitalWrite(moteurArriereDroit,HIGH);
digitalWrite(moteurArriereGauche,HIGH);
digitalWrite(moteurAvantDroit,HIGH);
digitalWrite(moteurAvantGauche,HIGH);

      delay(500);
    }
    else if (Data=='L') {
digitalWrite(pin1AvantDroit,HIGH);
digitalWrite(pin2AvantDroit,LOW);  
digitalWrite(pin1ArriereDroit,HIGH);                     //tourne a gauche
digitalWrite(pin2ArriereDroit,LOW); 
digitalWrite(pin1AvantGauche,LOW);
digitalWrite(pin2AvantGauche,HIGH);  
digitalWrite(pin1ArriereGauche,LOW);
digitalWrite(pin2ArriereGauche,HIGH);
 
digitalWrite(moteurArriereDroit,HIGH);
digitalWrite(moteurArriereGauche,HIGH);
digitalWrite(moteurAvantDroit,HIGH);
digitalWrite(moteurAvantGauche,HIGH);
      delay(500);
    }
    Serial.println(Data);
  }

}
