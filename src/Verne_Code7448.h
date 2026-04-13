/*
	Nome: Verne_Code7448
	Copyright: Verne_Code7448
	Versão 1.0.1
	Autor: Júlio Muanza Monteiro
	Data: 11/04/26 20:26
	Descrição: Controle do decodificador 7448
*/

#ifndef VERNE_CODE_7448_H
#define VERNE_CODE_7448_H

#include "Arduino.h"


enum digitos { // Digito para a contagem
	ZERO, 		// dígito 0
	UM, 		// dígito 1
	DOIS, 		// dígito 2
	TRES, 		// dígito 3
	QUATRO, 	// dígito 4
	CINCO, 		// dígito 5
	SEIS, 		// dígito 6
	SETE, 		// dígito 7
	OITO, 		// dígito 8
	NOVE 		// dígito 9
};

enum typeCont { // tipo de contagem
	PROGRESS, 		// Progressiva
	REGRESS 		// Regressiva
};


// Classe Verne_Code7448
class Verne_Code7448 
{
	private:
		// Quantidade de pinos do decodificador
		static const int pinos = 4;
		// pinos do decodificador 7448
		int pinCode[pinos];
				
	public:
		Verne_Code7448(int d, int c, int b, int a); // Construtor Verne_Code7448
		

		// ---------- Métodos ----------

		void digito(int digito); // Mostrar um dígito no display

		void cont_progress(int digito); // Fazer contagem progressiva de 0-9

		void cont_regress(int digito); // Fazer contagem regressiva de 9-0

		void cont(int digito, int type_cont, int time); // Escolhe o tipo de contagem entre progressiva ou regressiva

		void clear();
};

#endif // VERNE_CODE_7448_H
