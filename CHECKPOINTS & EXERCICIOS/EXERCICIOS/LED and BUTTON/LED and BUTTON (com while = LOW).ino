#define LED 26
#define BOTAO 16

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP);

  Serial.println("Pressione o botão e mantenha pressionado para piscar o LED");
}
 
void loop() {
  while (digitalRead(BOTAO) == LOW) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }
}
 