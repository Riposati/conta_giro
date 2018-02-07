#define pino 3

long aux=0;

void isr(){
  aux++;
}

void setup() {  
  
  pinMode(pino, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pino),isr,RISING);
}

void loop() {
  
  long a = millis();
  float rpm = float(aux * 60)/4;
  aux = 0;
  Serial.println(rpm);
  while( (millis()-a) < 1000 );
}
