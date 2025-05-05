// AULA 07 - BOOL - IF ELSE - OPERADORES LÓGICOS - OPERADORES RELACIONAIS

// ÁREA DE EXECUÇÃO (APENAS UMA VEZ) ===================================================================== //
void setup() {
  Serial.begin(115200);

// OPERADORES LÓGICOS OR (||) e AND (&&)
  Serial.println("\nOPERADORES LÓGICOS OR (||) e AND (&&) _________________________________________\n");
  int a, b;
  int c = 23;
  int d = 27;
// || = OR (OU)
  a = (c < 20) || (d > c);
  Serial.println("'a' é igual a 1 (verdadeiro)");
// && = AND (E)
  b = (c < 20) && (d > c);
  Serial.println("'b' é igual a 0 (falso)");

// OPERADORES LÓGICOS AND (&&)
// Só será verdadeiro se TODAS as condições forem verdadeiras.
// Se qualquer uma for falsa, o resultado será falso.
  Serial.println("\nOPERADORES LÓGICOS AND (&&) ___________________________________________________\n");
  bool deverFeito = true;
  bool solBrilhando = true;
  
  // Se ambos valores forem "true" deve ser exibido no terminal "Posso sair!"
  if (deverFeito == true && solBrilhando == true) {
    Serial.println("Posso sair!");
  } else { // Se qualquer valor for "false" deve ser exibido no terminal "Fico em casa."
    Serial.println("Fico em casa.");
  }

// OPERADORES LÓGICOS OR (||)
// Se pelo menos uma condição for verdadeira, o resultado será verdadeiro.
// Se todas forem falsas, o resultado será falso.
Serial.println("\nOPERADORES LÓGICOS OR (||) _______________________________________________________\n");
bool sol = false;
bool temGuardaChuva = true;

// Se qualquer valor for "true" deve ser exibido no terminal "Você pode ir!"
if (sol == true || temGuardaChuva == true) {
  Serial.println("Você pode ir!");
} else { // Se qualquer todos os valores forem "false" deve ser exibido no terminal "Melhor ficar em casa."
  Serial.println("Melhor ficar em casa.");
}
}

// ÁREA DE EXECUÇÃO (REPTIDAS VEZES) ===================================================================== //
void loop() {

}
