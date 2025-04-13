#define trigArriereGauche 12
#define echoArriereGauche 50

#define echoDiagoGauche 18
#define trigDiagoGauche 19

#define echoDiagoDroit A2
#define trigDiagoDroit A3

#define trigArriereDroit A1
#define echoArriereDroit A0

#define trigAvantGauche 19
#define echoAvantGauche 18

#define trigAvantDroit A5
#define echoAvantDroit A4

#define trigAvant  52
#define echoAvant  53

#define moteurArriereDroit 13
#define moteurArriereGauche 5 

#define moteurAvantDroit 6
#define moteurAvantGauche 11

#define pin1ArriereGauche 9
#define pin2ArriereGauche 10

#define pin1ArriereDroit A14
#define pin2ArriereDroit A15

#define pin1AvantGauche A10
#define pin2AvantGauche A11

#define pin1AvantDroit 16
#define pin2AvantDroit 17


// Pins encodeurs (Arduino Mega compatibles interruptions)
#define encArriereDroitA 2
#define encArriereDroitB 23
#define encArriereGaucheA 3
#define encArriereGaucheB 22
#define encAvantDroitA 20
#define encAvantDroitB 51
#define encAvantGaucheA 21
#define encAvantGaucheB 49

volatile long posArriereDroit = 0;
volatile long posArriereGauche = 0;
volatile long posAvantDroit = 0;
volatile long posAvantGauche = 0;
int encoderTarget = 300;
float avgEncoders;

void encodeurSetup() {
  pinMode(encArriereDroitA, INPUT_PULLUP);
  pinMode(encArriereDroitB, INPUT_PULLUP);
  pinMode(encArriereGaucheA, INPUT_PULLUP);
  pinMode(encArriereGaucheB, INPUT_PULLUP);
  pinMode(encAvantDroitA, INPUT_PULLUP);
  pinMode(encAvantDroitB, INPUT_PULLUP);
  pinMode(encAvantGaucheA, INPUT_PULLUP);
  pinMode(encAvantGaucheB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encArriereDroitA), [](){posArriereDroit += digitalRead(encArriereDroitB) ? -1 : 1;}, RISING);
  attachInterrupt(digitalPinToInterrupt(encArriereGaucheA), [](){posArriereGauche += digitalRead(encArriereGaucheB) ? 1 : -1;}, RISING);
  attachInterrupt(digitalPinToInterrupt(encAvantDroitA), [](){posAvantDroit += digitalRead(encAvantDroitB) ? -1 : 1;}, RISING);
  attachInterrupt(digitalPinToInterrupt(encAvantGaucheA), [](){posAvantGauche += digitalRead(encAvantGaucheB) ? 1 : -1;}, RISING);
}

void resetEncoderPositions() {
  posArriereDroit = 0;
  posArriereGauche = 0;
  posAvantDroit = 0;
  posAvantGauche = 0;
}

unsigned long mesureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.017;
}

void controleMoteur(bool avantGauche, bool avantDroit, bool arriereGauche, bool arriereDroit) {
  digitalWrite(pin1AvantGauche, avantGauche); digitalWrite(pin2AvantGauche, !avantGauche);
  digitalWrite(pin1AvantDroit, avantDroit); digitalWrite(pin2AvantDroit, !avantDroit);
  digitalWrite(pin1ArriereGauche, arriereGauche); digitalWrite(pin2ArriereGauche, !arriereGauche);
  digitalWrite(pin1ArriereDroit, arriereDroit); digitalWrite(pin2ArriereDroit, !arriereDroit);

  analogWrite(moteurArriereDroit, 180);
  analogWrite(moteurArriereGauche, 180);
  analogWrite(moteurAvantDroit, 180);
  analogWrite(moteurAvantGauche, 180);
}

void arretMoteurs() {
  // Arrêter les moteurs en mettant tous les pins à LOW
  digitalWrite(pin1AvantGauche, LOW);
  digitalWrite(pin2AvantGauche, LOW);
  digitalWrite(pin1AvantDroit, LOW);
  digitalWrite(pin2AvantDroit, LOW);
  digitalWrite(pin1ArriereGauche, LOW);
  digitalWrite(pin2ArriereGauche, LOW);
  digitalWrite(pin1ArriereDroit, LOW);
  digitalWrite(pin2ArriereDroit, LOW);

  analogWrite(moteurArriereGauche, 0);  // Arrêter moteur Arrière Gauche
  analogWrite(moteurArriereDroit, 0);   // Arrêter moteur Arrière Droit
  analogWrite(moteurAvantGauche, 0);    // Arrêter moteur Avant Gauche
  analogWrite(moteurAvantDroit, 0);     // Arrêter moteur Avant Droit
}

void tournerAGauche() {
  Serial.println("Début rotation...");
  
  // Réinitialisation des encodeurs
  posArriereDroit = 0;
  posArriereGauche = 0;
  posAvantDroit = 0;
  posAvantGauche = 0;

  // Activation des moteurs
  controleMoteur(LOW, HIGH, LOW , HIGH );
  
  // Boucle d'attente jusqu'à ce que la moyenne atteigne la cible
  while (true) {
    // Calcul de la moyenne des encodeurs
    long sumEncoders = abs(posArriereDroit) + abs(posArriereGauche) + abs(posAvantDroit) + abs(posAvantGauche);
    float avgEncoders = sumEncoders / 4.0; // Diviser par 4 pour obtenir la moyenne

    Serial.print("Encoders: ");
    Serial.print(posArriereDroit); Serial.print(" ");
    Serial.print(posArriereGauche); Serial.print(" ");
    Serial.println(posAvantDroit); Serial.print(" ");
    Serial.print(posAvantGauche); Serial.print(" | Moyenne: ");
    Serial.println(avgEncoders);
    
    // Vérification si la moyenne atteint la cible
    if (avgEncoders >= encoderTarget) {
      Serial.println("Seuil atteint. Arrêt des moteurs.");
      controleMoteur(HIGH,HIGH,HIGH,HIGH);
      break;
    }
  }

}
void tournerADroite() {
  Serial.println("Début rotation...");
  
  // Réinitialisation des encodeurs
  posArriereDroit = 0;
  posArriereGauche = 0;
  posAvantDroit = 0;
  posAvantGauche = 0;

  // Activation des moteurs
  controleMoteur(HIGH, LOW, HIGH, LOW );
  
  // Boucle d'attente jusqu'à ce que la moyenne atteigne la cible
  while (true) {
    // Calcul de la moyenne des encodeurs
    long sumEncoders = abs(posArriereDroit) + abs(posArriereGauche) + abs(posAvantDroit) + abs(posAvantGauche);
    float avgEncoders = sumEncoders / 4.0; // Diviser par 4 pour obtenir la moyenne

    Serial.print("Encoders: ");
    Serial.print(posArriereDroit); Serial.print(" ");
    Serial.print(posArriereGauche); Serial.print(" ");
    Serial.println(posAvantDroit); Serial.print(" ");
    Serial.print(posAvantGauche); Serial.print(" | Moyenne: ");
    Serial.println(avgEncoders);
    
    // Vérification si la moyenne atteint la cible
    if (avgEncoders >= encoderTarget) {
      Serial.println("Seuil atteint. Arrêt des moteurs.");
      controleMoteur(HIGH,HIGH,HIGH,HIGH);
      break;
    }

  }

  
}

void setup() {
  Serial.begin(115200);

  encodeurSetup();

  int trigPins[] = {trigArriereGauche, trigArriereDroit, trigAvant, trigDiagoGauche, trigDiagoDroit};
  int echoPins[] = {echoArriereGauche, echoArriereDroit, echoAvant, echoDiagoGauche, echoDiagoDroit};

  for (int i = 0; i < 5; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
  }

  int moteurPins[] = {moteurAvantGauche, moteurAvantDroit, moteurArriereGauche, moteurArriereDroit,
                      pin1ArriereGauche, pin2ArriereGauche, pin1ArriereDroit, pin2ArriereDroit,
                      pin1AvantGauche, pin2AvantGauche, pin1AvantDroit, pin2AvantDroit};

  for (int i = 0; i < 12; i++) pinMode(moteurPins[i], OUTPUT);

  // Initialisation moteurs
  digitalWrite(pin1AvantDroit, HIGH);
  digitalWrite(pin1AvantGauche, HIGH);
  digitalWrite(pin1ArriereGauche, HIGH);
  digitalWrite(pin1ArriereDroit, HIGH);

  digitalWrite(pin2ArriereGauche, LOW);
  digitalWrite(pin2ArriereDroit, LOW);
  digitalWrite(pin2AvantGauche, LOW);
  digitalWrite(pin2AvantDroit, LOW);

  digitalWrite(moteurAvantGauche, LOW);
  digitalWrite(moteurAvantDroit, LOW);
  digitalWrite(moteurArriereGauche, LOW);
  digitalWrite(moteurArriereDroit, LOW);
}


void loop() {

  posArriereDroit = 0;
  posArriereGauche = 0;
  posAvantDroit = 0;
  posAvantGauche = 0;

  unsigned long distanceAvant = mesureDistance(trigAvant, echoAvant);
  unsigned long distanceDiagoGauche = mesureDistance(trigDiagoGauche, echoDiagoGauche);
  unsigned long distanceDiagoDroit = mesureDistance(trigDiagoDroit, echoDiagoDroit);
  unsigned long distanceArriereGauche = mesureDistance(trigArriereGauche, echoArriereGauche);
  unsigned long distanceArriereDroit = mesureDistance(trigArriereDroit, echoArriereDroit);

  Serial.print("Avant: "); Serial.println(distanceAvant);
  Serial.print("DiagoDroit: "); Serial.println(distanceDiagoDroit);
  Serial.print("DiagoGauche: "); Serial.println(distanceDiagoGauche);
  Serial.print("ArriereGauche: "); Serial.println(distanceArriereGauche);
  Serial.print("ArriereDroit: "); Serial.println(distanceArriereDroit);
  
  if (distanceAvant >= 50 && distanceDiagoGauche >=40 &&distanceDiagoDroit >=40) {
    controleMoteur(true, true, true, true); // Avancer tout droit
  } else {
    if (distanceArriereGauche >= distanceArriereDroit) {
      if (distanceDiagoDroit >= 40 && distanceAvant >= 40) {
        controleMoteur(true, true, true, true); // Avancer tout droit
      } else {
        tournerAGauche(); // Tourner à gauche
      }
    } else {
      if (distanceDiagoGauche >= 40 && distanceAvant >= 40){
        controleMoteur(true, true, true, true); // Avancer tout droit
      } else {
        tournerADroite(); // Tourner à droite
      }
    }
  } 

  delay(60);
}