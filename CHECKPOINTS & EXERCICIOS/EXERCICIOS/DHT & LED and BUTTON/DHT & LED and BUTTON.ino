// DHT
#include <DHT.h>
#define DHTPIN 19
#define DHTMODEL DHT22
DHT dht(DHTPIN, DHTMODEL);

// LED e BOTAO
#define LED 26
#define BOTAO 18

void setup() {
  Serial.begin(9600); // Liga o ESP32
  dht.begin(); // liga o DHT
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP);
  Serial.println("Pressione o botão para ler a temperatura e umidade");
}
 
void loop() {
  // Fica em loop desligado até que seja precionado o BOTÃO
  while(digitalRead(BOTAO) == HIGH) {
    // faz nada
  }
  
  // Define as variaveis de temperatura e umidade do DHT
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();

  // Verifica se o valor de TEMP ou UMID é nulo e exibe um alerta
  if (isnan(temp) || isnan(umid)) {
    Serial.println("Leituras incorretas!");
    delay(2000);
    return;
  }

  // Calcula o indice de calor com as variaveis temp, umid e false (trás o resultado em °C)
  float ic = dht.computeHeatIndex(temp, umid, false);

  // Exibe os valores de temp, umid e ic
  Serial.println("--- Temperatura: " + String(temp));
  Serial.println("--- Umidade: " + String(umid));
  Serial.println("--- IC: " + String(ic));
  Serial.println("");

  // Verifica o valor do resultado do indice de calor
  if (ic > 25) { // se for maior que 25
    Serial.println("Indice de calor ALTO! (LED ACESSO)");
    digitalWrite(LED, HIGH);
  } else { // se for menor que 25
    Serial.println("Indice de calor BAIXO! (LED DESLIGADO)");
    digitalWrite(LED, LOW);
  }

  // Depois de 2,5seg o LED apaga
  delay(2500);
  digitalWrite(LED, LOW);
}
 