#define DCA 5
#define C_1 2
#define C_2 3
int estadoAnterior = 1, estado = 1;

void setup() {
  Serial.begin(9600);
  pinMode(DCA, INPUT_PULLUP);
  pinMode(C_1, OUTPUT);
  pinMode(C_2, OUTPUT);
  digitalWrite(C_1, LOW);
  digitalWrite(C_2, LOW);
  Serial.println("Sistema Iniciado");
}

void pulso() {
  Serial.println("Pulso de acionamento.");
  digitalWrite(C_1, HIGH);
  digitalWrite(C_2, HIGH);
  delay(500);
  digitalWrite(C_1, LOW);
  digitalWrite(C_2, LOW);
}

void loop() {
  estado = digitalRead(DCA);

  if (estadoAnterior == LOW && estado == HIGH) {
    pulso();
  } else if (estadoAnterior == HIGH && estado == LOW) {
    pulso();
  }
  estadoAnterior = estado;
  delay(200);
  Serial.print("Leitura: ");
  Serial.println(estado);
}
