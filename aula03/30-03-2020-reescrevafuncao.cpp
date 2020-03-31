#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ZEROABSC -273.15
#define ZEROABSF -459.67

float leTemperatura(int opcao);
float converteTemperatura(int opcao, float *temperatura);
int main(void) {
	float temp, conv;
	int op;

	do{
		printf("1 - Celsius para Fahreinheit\n");
		printf("2 - Fahreinheit para Celsius\n");
 		printf("3 - Sair.\n");
 		printf("Opcao: ");
 		scanf("%d", &op);
		switch(op) {
			case 1: 
				temp = leTemperatura(op);
				conv = converteTemperatura(op, &temp);
				printf("%.2f C sao %.2f F.\n", temp, conv);
			break;
		 	case 2: 
		 		temp = leTemperatura(op);
				conv = converteTemperatura(op, &temp);
				printf("%.2f F sao %.2f C.\n", temp, conv);
			break;
		 	case 3: 
		 		printf("Saindo...\n");
		 	break;
			default: 
				printf("Valor inválido.\n");
		}
 	}while(op != 3);

	system("PAUSE");
 	return 0;
}

float leTemperatura(int opcao){
	float temperatura;
	bool teste;
 	do{
 		printf("Digite a temperatura: ");
 		scanf("%f", &temperatura);
	if( ((opcao == 1) && (temperatura < ZEROABSC)) || ((opcao == 2) && (temperatura <ZEROABSF)) ){
 		printf("Temperatura invalida. Digite novamente.\n");
		teste = false;
 	}
 	else
 		teste = true;
 	} while(!teste);

 	return temperatura;
}

float converteTemperatura(int opcao, float *temperatura) {
	float conversao;
 	if(opcao == 1)
 		conversao = *temperatura * 1.8 + 32;
 	else
 		conversao = (*temperatura - 32) / 1.8;

 	return conversao;
}