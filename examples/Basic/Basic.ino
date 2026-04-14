#include <Verne_Code7448.h>

// Criando um instância display do tipo Verne_Code7448
Verne_Code7448 display(2, 3, 4, 5);

void setup() {
}

void loop() 
{
  // Realiza uma contagem regressiva de 9-0 como tempo de troca entre dígitos de 1s
  display.cont(9, PROGRESS, 200);

  // Imprime digitos direitos no display
  display.digito(3);  // dígito 3
  delay(1000);
  display.digito(UM);  // dígito 1
  delay(1000);
  display.digito(4);  // dígito 4
  delay(1000);
  display.digito(OITO);  // dígito 8
  delay(1000);

  display.clear(); // Limpa o display
  delay(1000);

  /*
  display.cont_regress(3); // Contagem regressiva
  display.cont_progress(8); // Contagem progressiva
  */
}
