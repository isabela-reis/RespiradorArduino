#include <Servo.h>
Servo servo;
int velocidade;

int botaoMaisRapido = 5;
int botaoMaisDevagar = 4;

bool estaLigado = 0;

int ledVermelho = 8;
int ledVerde = 7;

int botaoOff = 3;
int botaoOn = 2;

int buzzer = 6;

void setup()
{
  	Serial.begin(9600);
  	pinMode(botaoMaisRapido,INPUT_PULLUP);
  	pinMode(botaoMaisDevagar,INPUT_PULLUP);
  	pinMode(botaoOn,INPUT_PULLUP);
    pinMode(botaoOff,INPUT_PULLUP);
  	pinMode(ledVermelho,OUTPUT);
  	pinMode(ledVerde,OUTPUT);
  	pinMode(buzzer,INPUT);
  	
}

void loop()
{
  
  velocidade = 1500;
  
  bool estadoRapido = digitalRead(botaoMaisRapido);
  bool estadoDevagar = digitalRead(botaoMaisDevagar);
  bool estadoLigado = digitalRead(botaoOn);
  bool estadoDesligado = digitalRead(botaoOff);
  
  Serial.print(estaLigado);
  
  if(estadoRapido == LOW) {
  	velocidade = 1000;
    ligarRespirador();
  }
  
  else if (estadoDevagar == LOW) {
  	velocidade = 5000;
    ligarRespirador();
  }
  
  
  else if(estadoLigado == LOW) {
  	estaLigado = 1;
    ligarRespirador();
  }
  
  else if(estadoDesligado == LOW) {
  	estaLigado = 0; 
    desligarRespirador();
  }
  
  else if(estaLigado == true) {
  	ligarRespirador();
  }
  
  else if(estaLigado == false) {
  	desligarRespirador();
  }
}


void ligarRespirador() {
  	servo.attach(9);
  	digitalWrite(ledVermelho,LOW);
    digitalWrite(ledVerde,HIGH);
  	servo.write(0);
  	delay(velocidade);
  	tone(buzzer,166);
  	delay(60);
  	noTone(buzzer);
  	servo.write(90);
  	delay(velocidade);
  	tone(buzzer,255);
  	delay(60);
  	noTone(buzzer);
}

void desligarRespirador() {
  	servo.detach();
  	digitalWrite(ledVermelho,HIGH);
    digitalWrite(ledVerde,LOW);
	servo.write(0);
  	delay(velocidade);
}