# Verne_Code7448
Biblioteca para controlar o descodificador 7448

# Biblioteca para Arduino/ESP32 Verne_Code7448.

Está biblioteca serve para controlar o decodificador 7448.

![Verne_Code7448](\7448.jpeg)
![Verne_Code7448](\7448_display.png)

## Uso

O decodificador é inicializado pelo criação de uma istância da classe Verne_Code7448 e com 4 parámetros que são os pinos D, C, B e A.
```C
Verne_Code7448 code(pinD, pinC, pinB, pinA);
```

Para imprimir um dígito no display, você apenas chama o método `digito(valor)` e se o valor for maior que 9 vai aparecer deformado ou nem vai aparecer nada.

Para fazer contagem progressiva, você apenas chama o método `contagemProgessiva(valor)` a contagem vai de 0 a valor.

Para fazer contagem regressiva, você apenas chama o método `contagemRegessiva(valor)` a contagem vai de valor a 0.

Para escolher o tipo de contagem (prog. ou reg.), você apenas chama o método `tipoContagem(valor, estado)` se estado for igual a `true`-contagem progressiva caso seja igual a `false`-contagem Regressiva.

OBS: Para não houver má impressão dos dígitos utilize dígitos de 0 a 9.

## Exemplo

Para utilizar o mesmo é necessário dos seguintes mateirais:
  - Microcontrolador (Arduino/ESP);
  - Decodificador 7448
  - Display de 7 seguimentos cátodo comum

```c
#include <Verne_Code7448.h>

Verne_Code7448 code(2, 3, 4, 5);

int digito = 9;
bool estado = true;

void setup() {
}

void loop() {
  code.digito(6); // imprime 6 no display
  delay(1000);
  code.digito(9); // imprime 9 no display
  delay(1000);
  code.digito(3); // imprime 3 no display
  delay(1000);

  estado = true;
  code.tipoContagem(digito, estado); // Realiza um contagem de 0 a 9
  delay(3000);
  estado = false;
  code.tipoContagem(digito, estado); // Realiza um contagem de 9 a 0
  delay(3000);
}
```
## Proprietário
Júlio Muanza Monteiro
(c) Júlio Muanza Monteiro. Todos os direitos reservados.

Autor: Júlio Muanza Monteiro
Gmail: juliomuanzam@gmail.com
WT: 955196927
Tel: 937875350 / 955196927
