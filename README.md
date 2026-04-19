# Verne_Code7448
Biblioteca para controlar o descodificador 7448

# Biblioteca para Arduino/ESP32 Verne_Code7448.

Está biblioteca serve para controlar o decodificador 7448.

![Verne_Code7448](\7448.jpeg)
![Verne_Code7448](\7448_display.png)

## Uso

O decodificador é inicializado pelo criação de uma istância da classe Verne_Code7448 e com 4 parámetros que são os pinos D, C, B e A.
```C
Verne_Code7448 display(pinD, pinC, pinB, pinA);
```

Para imprimir um dígito no display, você apenas chama o método `digito(int digito)` e se o valor for maior que 9 vai aparecer deformado ou nem vai aparecer nada.

Para fazer contagem progressiva, você apenas chama o método `cont_progress(int digito)` a contagem vai de 0 a valor.

Para fazer contagem regressiva, você apenas chama o método `cont_regress(int digito)` a contagem vai de valor a 0.

Para escolher o tipo de contagem (prog. ou reg.), você apenas chama o método `cont(valor, type type_cont, time)` se type_cont for igual a `PROGRESS`-contagem progressiva caso seja igual a `REGRESS`-contagem Regressiva.

OBS: Para não houver má impressão dos dígitos utilize dígitos de 0 a 9.
Se forem introduzidos valores inválidos, retorna t no display para erro.

## Exemplo

Para utilizar o mesmo é necessário dos seguintes mateirais:
  - Microcontrolador (Arduino/ESP);
  - Decodificador 7448
  - Display de 7 seguimentos cátodo comum

```c
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

```
## Proprietário
Júlio Muanza Monteiro
(c) Júlio Muanza Monteiro. Todos os direitos reservados.

Autor: Júlio Muanza Monteiro
Gmail: juliomuanzam@gmail.com
WT: 955196927
Tel: 937875350 / 955196927
