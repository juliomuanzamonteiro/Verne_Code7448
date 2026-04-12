#include <Verne_Code7448.h>

Verne_Code7448 display(2, 3, 4, 5);
int digito = 5;
bool estado = true;

void setup() {
}

void loop() {
  // put your main code here, to run repeatedly:
  display.digito(SEIS);
  delay(1000);
  display.digito(9);
  delay(1000);
  display.digito(DOIS);
  delay(1000);

  estado = false;
  display.tipoContagem(digito, estado);
  estado = true;
  display.tipoContagem(digito, estado);

  display.limpar();
  delay(3000);


}
