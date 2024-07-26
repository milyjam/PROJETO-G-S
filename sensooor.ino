#include <Servo.h>

#define SERVO 9 // Porta Digital 9 PWM

Servo s; // Variável tipo Servo
int pos; // Posição Servo
int Pinbuzzer = 8; //PINO UTILIZADO PELO BUZZER
int PinA0 = A0;//PINO UTILIZADO PELO SENSOR DE GÁS MQ-2
int Pinled = 7;

int leitura_sensor = 100;//DEFININDO UM VALOR LIMITE (NÍVEL DE GÁS NORMAL)


void setup() {
  s.attach(SERVO);
  s.write(0); // Inicia o motor na posição zero
  pinMode(PinA0, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(Pinbuzzer, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(Pinled, OUTPUT);
  Serial.begin(9600);//INICIALIZA A SERIAL

}

void loop() {
  int valor_analogico = analogRead(PinA0); //VARIÁVEL RECEBE O VALOR LIDO NO PINO ANALÓGICO
  Serial.print("Leitura: "); //EXIBE O TEXTO NO MONITOR SERIAL
  Serial.println(valor_analogico);// MOSTRA NO MONITOR SERIAL O VALOR LIDO DO PINO ANALÓGICO

  if (valor_analogico > leitura_sensor) { //SE VALOR LIDO NO PINO ANALÓGICO FOR MAIOR QUE O VALOR LIMITE, FAZ
    digitalWrite(8, HIGH); //ATIVA O BUZZER E O MESMO EMITE O SINAL SONORO
    digitalWrite(7, HIGH); 
    s.write(0);
    delay(15);
  }
  else { //SENÃO, FAZ
    digitalWrite(8, LOW);//BUZZER DESLIGADO
    digitalWrite(7, LOW);
    for (pos = 70; pos >= 0; pos--)
    {
      s.write(70);
      delay(15);
    }
  }
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS

}