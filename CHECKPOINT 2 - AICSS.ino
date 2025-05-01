// CHECKPOINT 2 - AICSS //
// Integrantes: Bruno 552574 + Edgar 565260 + Júlia 566325

// ÁREA DE VARIAVIES ======================================================================================//
// EXERCICIO 1 - VARIAVIES DE LIGA E DESLIGA DOS LEDs
#define LEDVERMELHO 32
#define LEDAMARELO 33
const int tempo_desligado = 1000;
const int tempo_ligado = tempo_desligado * 3;

// EXERCICIO 2 - CONTROLE DE BRILHO DOS LEDs
uint8_t BRILHO_LEDVERMELHO = 32; // unit8_t devido o valor ser de 0 a 255 
uint8_t BRILHO_LEDAMARELO = 255; // unit8_t devido o valor ser de 0 a 255

// EXERCICIO 4 - COPIANDO E COLOCANDO
char array[29] = "";

// EXERCICIO 5 - LISTAGEM DE UMA STRING, CARACTER POR CARACTER
String texto = "LISTAGEM";

// EXERCICIO 6 - CONTAGEM DE UM INTERVALO DE TEMPO
#include "esp_timer.h"

// EXERCICIO 8 - ARMAZENAMENTO DE VALORES
uint16_t valor_1= 1000; // unit16_t devido o valor ser de 0 a 65.535

// EXERCICIO 9 - CALCULO DE TEMPERATURA
float temperatura = 35.8;
float umidade = 55.7;

// EXERCICIO 10 - CALCULO DE POTENCIA ELETRICA
float tensao = 3.3;
float resistencia = 100.0;

// ÁREA DE EXECUÇÃO (APENAS UMA VEZ) ===================================================================== //
void setup() {
  Serial.begin(115200);

// EXERCICIO 1 - LIGANDO e DESLIGANDO OS LEDs
Serial.println("\nEXERCICIO 1 _________________________________________________________________________________\n");
  
Serial.println("LEDs ligados por 3 segundos..."); 
  // EXERCICIO 1 - LIGANDO OS LEDs PELA PRIMEIRA VEZ
  analogWrite(LEDVERMELHO, HIGH);
  analogWrite(LEDAMARELO, HIGH);
  delay(tempo_ligado);
  // EXERCICIO 1 - DESLIGANDO OS LEDs
  Serial.println("LEDs desligados...");  
  analogWrite(LEDVERMELHO, LOW);
  analogWrite(LEDAMARELO, LOW);
  delay(tempo_desligado);

// EXERCICIO 2 - LIGANDO OS LEDs POR 2seg E DESLIGANDO
Serial.println("\nEXERCICIO 2 _________________________________________________________________________________\n");
  
Serial.println("LEDs ligados por 2 segundos...");
  Serial.println("BRILHO LED AMARELO: " + String(BRILHO_LEDAMARELO));
  Serial.println("BRILHO LED VERMELHO: " + String(BRILHO_LEDVERMELHO));
  // EXERCICIO 2 - LIGANDO OS LEDs e APLICANDO O BRILHO
  analogWrite(LEDVERMELHO, BRILHO_LEDVERMELHO);
  analogWrite(LEDAMARELO, BRILHO_LEDAMARELO);
  delay(2000);
  // EXERCICIO 2 - DESLIGANDO OS LEDs
  Serial.println("\nLEDs desligados...");  
  analogWrite(LEDVERMELHO, 0);
  analogWrite(LEDAMARELO, 0);
  delay(600);

// EXERCICIO 3 - CORRIGIR O CÓDIGO FORNECIDO

  // #define TEMPO 1000
  // void setup() {
  // Serial.begin(115200);
  // TEMPO = 2000;
  // Serial.println(TEMPO);
  // }
  // void loop () { }

  Serial.println("\nEXERCICIO 3 _________________________________________________________________________________\n");
  
  Serial.println("#define TEMPO 1000");
  Serial.println("TEMPO = 2000;");
  Serial.println("\n No inicio 'TEMPO' foi declarado com o valor 1000, depois voce tentar definir o valor novo para 2000, o sistema nao vai permitir por nao ser possivel alterar o valor de uma define");

// EXERCICIO 4 - ATIVIDADES COM CHAR e ARRAY
  Serial.println("\nEXERCICIO 4 _________________________________________________________________________________\n");

  // EXERCICIO 4 - COPIANDO A ARRAY "ABACAXI" E EXIBINDO NO TERMINAL
  strcpy(array, "Abacaxi");
  Serial.println("Texto adicionado com strcpy: " +  String(array) + " | O seu tamanho é de: " + strlen(array) + " caracteres");
  // EXERCICIO 4 * COPIANDO A ARRAY "NA BRASA E MUITO BOM", COLANDO NA ARRAY ANTERIOR E EXIBINDO NO TERMINAL
  strcat(array, " na brasa e muito bom");
  Serial.println("Texto adicionado com strcat: " + String(array) + " | O seu tamanho é de: " + strlen(array) + " caracteres");

// EXERCICIO 5 - ATIVIDADE COM STRING
  Serial.println("\nEXERCICIO 5 _________________________________________________________________________________\n");

  // EXERCICIO 6 - INICIO DO CRONOMETRO
  uint64_t start =esp_timer_get_time(); // unit64_t devido o valor ser para representar tempo (necessita de um espaço maior)

  // EXERCICIO 5 - ESTRUTURA DE REPETIÇÃO PARA EXIBIR TODAS AS POSIÇÕES DO CHAR ATÉ O FIM
  for (int i = 0; i < texto.length(); i++){
    Serial.println("Item da posição " + String(i) + ": " + String(texto[i]));
  }

  // EXERCICIO 6 - FIM DO CRONOMETRO
  uint64_t finish = esp_timer_get_time();  // unit64_t devido o valor ser para representar tempo (necessita de um espaço maior) 
    // EXERCICIO 6 - CALCULO DO TEMPO GASTO PELA MAQUINA EM SEGUNDOS
  float duracao = (finish - start) / 1000000.0;
  
  Serial.println("\nEXERCICIO 6 _________________________________________________________________________________\n");
  
  // EXERCICIO 6 - EXIBE OS VALORES INICIAL E FINAL DO CRONOMETRO E O TEMPO ENTRE ESSE INTERVALO
  Serial.println("INICIO DO CRONOMETRO: " + String(start) + " microssegundos");
  Serial.println("FIM DO CRONOMETRO: " + String(finish) + " microssegundos\n");
  Serial.println("Tempo utilizado para imprimir os caracteres de " + texto + " foi de: " + String(duracao, 3) + " segundos");  

// EXERCICIO 8 - ARMAZENANDO VALORES
  Serial.println("\nEXERCICIO 8 _________________________________________________________________________________\n");

  // EXERCICIO 8 - ACRESCENTA O VALOR NOVO COM O ANTIGO E EXIBE NO TERMINAL
  uint16_t valor_2 = valor_1 + 30000; // unit16_t devido o valor ser de 0 a 65.535 
  Serial.println("Valor 1: " + String(valor_1));
  Serial.println("Valor 2: " + String(valor_2));

// EXERCICIO 9 - CALCULO DE INDICE DE CALOR
  Serial.println("\nEXERCICIO 9 _________________________________________________________________________________\n");
  
  // EXERCICIO 9 - REALIZA O CALCULO DE INDICE DE CALOR DE ACORDO COM AS VARIAVEIS DEFINIDAS NO INICIO DO CÓDIGO
  float IC = temperatura + (0.3 * umidade) - 0.7;

  // EXERCICIO 9 - EXIBE NO TERMINAL O PAINEL DE INDICE DE CALOR
  Serial.println("Índice de Calor: " + String(IC, 2) +
                 " | Temperatura: " + String(temperatura, 1) + " ºC" +
                " | Umidade: " + String(umidade, 1) + " %");

// EXERCICIO 10 - CALCULO DE POTENCIA ELETRICA
  Serial.println("\nEXERCICIO 10 ________________________________________________________________________________\n");

  // EXERCICIO 10 - REALIZA O CALCULO DA PONTENCIA DE ACORDO COM AS VARIAVIES DEFINIDAS NO INICIO DO CÓDIGO
  float potencia = (tensao * tensao) / resistencia;

  // EXERCICIO 10 - EXIBE OS VALORES DAS VARIAVEIS DO CALCULO E O RESULTADO
  Serial.println("Tensão: " + String(tensao));
  Serial.println("Resistencia: " + String(resistencia));
  Serial.println("\nPotência elétrica: " + String(potencia, 4) + " W");

  Serial.println("\n__________________________________        ÁREA DE LOOP        ________________________________\n");
}

// ÁREA DE EXECUÇÃO (REPTIDAS VEZES) ===================================================================== //
void loop() {
// EXERCICIO 7 - ARMAZENANDO UM VALOR INTEIRO EM STRING
  String valor_inicial = "10000";
// EXERCICIO 7 - CONVERTENDO STR EM INT
  Serial.println("\nEXERCICIO 7 - LOOP DE 5 seg _________________________________________________________________\n");
  
  uint16_t valor_convertido = valor_inicial.toInt(); // unit16_t devido o valor ser de 0 a 65.535
  Serial.println("Valor convertido para int: " + String(valor_convertido));
// EXERCICIO 7 - FAZENDO COM QUE SEJA EXIBIDO NO TERMINAL A CADA 5 SEGUNDOS
  delay(5000);
}