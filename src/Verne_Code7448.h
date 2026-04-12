/*
	Nome: Verne_Code7448
	Copyright: Verne_Code7448
	Versão 1.0.0
	Autor: Júlio Muanza Monteiro
	Data: 11/04/26 20:26
	Descrição: Controle do decodificador 7448
*/

#ifndef VERNE_CODE_7448_H
#define VERNE_CODE_7448_H

#include "Arduino.h"

enum numero {
	ZERO, 
	UM, 
	DOIS, 
	TRES, 
	QUATRO, 
	CINCO, 
	SEIS, 
	SETE, 
	OITO, 
	NOVE
};

class Verne_Code7448 {
	private:
		// Quantidade de pinos no decodificador
		static const int pinos = 4;
		// pinos do decodificador 7448
		int pinCode[pinos];
		
	public:
		Verne_Code7448(int d, int c, int b, int a); // Construtor Verne_Code7448
		
		// ----- Métodos -----
		void digito(int digito); // Mostrar digito
		void contagemProgressiva(int digito); // Contagem progressiva de 0-9
		void contagemRegressiva(int digito); // Contagem regressiva de 9-0
		void tipoContagem(int digito, bool estadoContagem); // Contagem progressiva (0-9) ou regressiva (0-9)
		void limpar();
};

#endif

