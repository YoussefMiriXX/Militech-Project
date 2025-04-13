// Pins moteurs
#define moteurArriereDroit 13 
#define moteurArriereGauche 5 
#define moteurAvantDroit 6
#define moteurAvantGauche 11

// Pins directions moteurs
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
#define encAvantGaucheB 15

volatile long posArriereDroit = 0;
volatile long posArriereGauche = 0;
volatile long posAvantDroit = 0;
volatile long posAvantGauche = 0;
int encoderTarget = 710;

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

void controleMoteur(bool avantGauche, bool avantDroit, bool arriereGauche, bool arriereDroit) {
  digitalWrite(pin1AvantGauche, avantGauche); digitalWrite(pin2AvantGauche, !avantGauche);
  digitalWrite(pin1AvantDroit, avantDroit); digitalWrite(pin2AvantDroit, !avantDroit);
  digitalWrite(pin1ArriereGauche, arriereGauche); digitalWrite(pin2ArriereGauche, !arriereGauche);
  digitalWrite(pin1ArriereDroit, arriereDroit); digitalWrite(pin2ArriereDroit, !arriereDroit);

   if (!avantGauche && !avantDroit && !arriereGauche && !arriereDroit) { 
    analogWrite(moteurArriereDroit, 0);
    analogWrite(moteurArriereGauche, 0);
    analogWrite(moteurAvantDroit, 0);
    analogWrite(moteurAvantGauche, 0);
  } else {
    analogWrite(moteurArriereDroit, 255);
    analogWrite(moteurArriereGauche, 255);
    analogWrite(moteurAvantDroit, 255);
    analogWrite(moteurAvantGauche, 255);
  }
}

void setup() {
  Serial.begin(115200);

  int moteurPins[] = {moteurAvantGauche, moteurAvantDroit, moteurArriereGauche, moteurArriereDroit,
                      pin1ArriereGauche, pin2ArriereGauche, pin1ArriereDroit, pin2ArriereDroit,
                      pin1AvantGauche, pin2AvantGauche, pin1AvantDroit, pin2AvantDroit};

  for (int i = 0; i < 12; i++) pinMode(moteurPins[i], OUTPUT);

  encodeurSetup();

  Serial.println("Prêt à effectuer une rotation de 90 degres.");
}

void loop() {
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
      controleMoteur(LOW, LOW, LOW, LOW);
      break;
    }

    delay(60);
  }

  Serial.println("Rotation terminée.");
  delay(2000);
}