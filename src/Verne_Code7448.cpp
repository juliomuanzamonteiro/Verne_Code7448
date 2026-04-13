/*
	Nome: Verne_Code7448
	Copyright: Verne_Code7448
	Versão 1.0.1
	Autor: Júlio Muanza Monteiro
	Data: 11/04/26 20:26
	Descrição: Controle do decodificador 7448
*/

// Incluindo biblioteca Verne_Code7448
#include "Verne_Code7448.h"


// Construtor  Verne_Code7448
Verne_Code7448::Verne_Code7448(int d, int c, int b, int a)
{
	pinCode[0] = a;
	pinCode[1] = b;
	pinCode[2] = c;
	pinCode[3] = d;

	// Configurar os pinos do decodificador como saída
	for (int i = 0; i < pinos; i++)
	{
		pinMode(pinCode[i], OUTPUT);
	}
}


// Mostrar digito
void Verne_Code7448::digito(int digito) 
{
	if(digito < 0 || digito > 9) return; // Não executa nada
	
	for (int byte = 0; byte < pinos; byte++)
	{
		// Desloca digito em byte posições e verifica se é igual a 1
		// Para fazer a conversão de decinal para binário
		digitalWrite(pinCode[byte], ((digito >> byte) & 1));
	}
}


// Contagem de 0-9
void Verne_Code7448::cont_progress(int digito) 
{
	if (digito < 0 || digito > 9) return; // Não executa nada

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
void Verne_Code7448::cont_regress(int digito) 
{
	if (digito < 0 || digito > 9) return; // Não executa nada

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
void Verne_Code7448::cont(int digito, int type_cont, int time)
{
	if ((digito < 0 || digito > 9) || (type_cont != PROGRESS || type_cont != REGRESS)) 
	return; // Não executa nada

	if (type_cont == PROGRESS) // Realiza a contagem progressiva
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
			delay(time);
		}
	}
	else if (type_cont == REGRESS) // Realiza a contagem regressiva
	{
		for (digito; digito >= 0; digito--)
		{
			for (int byte = 0; byte < pinos; byte++)
			{
				// Desloca digito em byte posições e verifica se é igual a 1
				// Para fazer a conversão de decimal para binário
				digitalWrite(pinCode[byte], ((digito >> byte) & 1));
			}
			delay(time);
		}
	}

}


// Limpar - Zera o display
void Verne_Code7448::clear() 
{
	for(int byte = 0; byte < pinos; i++)
	{
		digitalWrite(pinCode[byte], LOW); // Zera o display
	}
	
}
