/*
	Nome: Verne_Code7448
	Copyright: Verne_Code7448
	Versão 1.0.0
	Autor: Júlio Muanza Monteiro
	Data: 11/04/26 20:26
	Descrição: Controle do decodificador 7448
*/

// Incluindo biblioteca Verne_Code7448
#include "Verne_Code7448.h"


// Construtor
Verne_Code7448::Verne_Code7448(int d, int c, int b, int a)
{
	pinCode[0] = d;
	pinCode[1] = c;
	pinCode[2] = b;
	pinCode[3] = a;

	// Configurar os pinos como saída
	for (int i = 0; i < pinos; i++)
	{
		pinMode(pinCode[i], OUTPUT);
	}
}


// Mostrar digito
void Verne_Code7448::digito(int digito)
{
	if(digito < 0 || digito > 9) return; // Não faz nada
	
	for (int byte = 0; byte < pinos; byte++)
	{
		// Desloca digito em byte posições e verifica se é igual a 1
		// Para fazer a conversão de decinal para binário
		digitalWrite(pinCode[byte], ((digito >> byte) & 1));
	}
}


// Contagem de 0-9
void Verne_Code7448::contagemProgressiva(int digito)
{
	for (int conta = 0; conta <= digito; conta++)
	{
		// Conversão da base decimal para binária
		for (int byte = 0; byte < pinos; byte++)
		{
			// Desloca conta em byte posições e verifica se é igual a 1
			// Para fazer a conversão de decimal para binério
			digitalWrite(pinCode[byte], ((conta >> byte) & 1));
		}
		delay(1000);
	}
}


// Contagem regressiva de 9-0
void Verne_Code7448::contagemRegressiva(int digito)
{
	for (digito; digito >= 0; digito--)
	{
		for (int byte = 0; byte < pinos; byte++)
		{
			// Desloca digito em byte posições e verifica se é igual a 1
			// Para fazer a conversão de decimal para binário
			digitalWrite(pinCode[byte], ((digito >> byte) & 1));
		}
		delay(1000);
	}
}


// Contagem progressiva (0-9) ou regressiva (0-9)
void Verne_Code7448::tipoContagem(int digito, bool estadoContagem)
{
	if (estadoContagem == true)
	{
		for (int conta = 0; conta <= digito; conta++)
		{
			// Conversão da base decimal para binária
			for (int byte = 0; byte < pinos; byte++)
			{
				// Desloca conta em byte posições e verifica se é igual a 1
				// Para fazer a conversão de decimal para binário
				digitalWrite(pinCode[byte], ((conta >> byte) & 1));
			}
			delay(1000);
		}
	}
	else
	{
		for (digito; digito >= 0; digito--)
		{
			for (int byte = 0; byte < pinos; byte++)
			{
				// Desloca digito em byte posições e verifica se é igual a 1
				// Para fazer a conversão de decimal para binário
				digitalWrite(pinCode[byte], ((digito >> byte) & 1));
			}
			delay(1000);
		}
	}

}

// Limpar - Zera o display
void Verne_Code7448::limpar() {
	for(int i = 0; i < pinos; i++)
	{
		digitalWrite(pinCode[i], LOW);
	}
	
}