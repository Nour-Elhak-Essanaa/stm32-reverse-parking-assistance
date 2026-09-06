
const int trigPin = 2;
const int echoPin = 3;
const int interrupteurPin = 4;
const int buzzerPin = 5;
const int ledOrange = 6;
const int ledRouge = 9;
const int ledVerte = 13;


const int latchPin = 10;
const int clockPin = 11;
const int dataPin = 12;

const byte chiffres[10] = {
  0b11000000, 
  0b11111001, 
  0b10100100, 
  0b10110000,
  0b10011001, 
  0b10010010,
  0b10000010,
  0b11111000,
  0b10000000,
  0b10010000 
};

void setup() {

  Serial.begin(9600);


  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  pinMode(ledVerte, OUTPUT);
  pinMode(ledOrange, OUTPUT);
  pinMode(ledRouge, OUTPUT);


  pinMode(interrupteurPin, INPUT_PULLUP);


  pinMode(buzzerPin, OUTPUT);


  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  digitalWrite(ledVerte, LOW);
  digitalWrite(ledOrange, LOW);
  digitalWrite(ledRouge, LOW);
  noTone(buzzerPin);


  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0xFF);
  shiftOut(dataPin, clockPin, MSBFIRST, 0xFF);
  digitalWrite(latchPin, HIGH);

  Serial.println("Systeme pret.");
}

void loop() {


  bool marcheArriere = (digitalRead(interrupteurPin) == LOW);



  if (marcheArriere) {

  
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    long duree = pulseIn(echoPin, HIGH);

    float distanceCm = duree * 0.034 / 2;

    Serial.print("Distance : ");
    Serial.print(distanceCm);
    Serial.println(" cm");


  
    if (distanceCm > 120) {

      digitalWrite(ledVerte, HIGH);
      digitalWrite(ledOrange, LOW);
      digitalWrite(ledRouge, LOW);

      noTone(buzzerPin);
    }

    
    else if (distanceCm >= 30 && distanceCm <= 120) {

      digitalWrite(ledVerte, LOW);
      digitalWrite(ledOrange, HIGH);
      digitalWrite(ledRouge, LOW);

 
      long intervalle = map((long)distanceCm, 30, 120, 0, 1000);

      tone(buzzerPin, 440, 100);

      delay(intervalle);
    }

   
    else {

      digitalWrite(ledVerte, LOW);
      digitalWrite(ledOrange, LOW);
      digitalWrite(ledRouge, HIGH);

      tone(buzzerPin, 440);
    }


    int distanceDecimetres = (int)(distanceCm / 10.0);

    int unite = distanceDecimetres / 10;
    int decimale = distanceDecimetres % 10;

    if (unite > 9) {
      unite = 9;
      decimale = 9;
    }

    byte codeUnite = chiffres[unite];
    byte codeDecimale = chiffres[decimale];

 
    codeUnite = codeUnite & 0b01111111;


    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, codeDecimale);
    shiftOut(dataPin, clockPin, MSBFIRST, codeUnite);

    digitalWrite(latchPin, HIGH);

    delay(100);
  }

 
  else {

    digitalWrite(ledVerte, LOW);
    digitalWrite(ledOrange, LOW);
    digitalWrite(ledRouge, LOW);

    noTone(buzzerPin);

   
    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, 0xFF);
    shiftOut(dataPin, clockPin, MSBFIRST, 0xFF);

    digitalWrite(latchPin, HIGH);

    Serial.println("Systeme en veille...");

    delay(500);
  }
}