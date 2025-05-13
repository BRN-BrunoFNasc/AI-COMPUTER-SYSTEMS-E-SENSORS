#define LED 26
#define BOTAO 15

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP); // "INPUT_PULLUP" = HIGH (botão sempre se inicia ligado)

  Serial.println("Pressione o botão e mantenha pressionado para piscar o LED");
}
 
void loop() {
  while (digitalRead(BOTAO) == HIGH) {
    // não faz nada até que o botão seja precionado
  }

  // Quando o botão for pressionado, automaticamente o sistema sai do "while" e vai para o restante do código
  Serial.println("Botão pressionado");
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
}
 