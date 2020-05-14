#include<stdio.h>
#include<stdlib.h>

int troca(int num1, int num2);

int main(){

	int x,y, z;
	x = 2;
	y = 4;
	z = 0;

	printf("Pre troca\n");
	printf("X: %d", x);
	printf("\nY: %d", y);

	x = troca(x,y);
	y = troca(x,y);

	printf("\nPos troca");
	printf("\nX: %d", x);
	printf("\nY: %d", y);
	printf("\nZ: %d", z);

	return 0;
}

int troca(int num1, int num2){
	int aux;
	aux = num1;
	num1 = num2;
	num2 = aux;

	printf("\nValor num1: %d", num1);
	printf("\nValor num2: %d", num2);
	printf("\nValor aux: %d", aux);
	return num2, num1;
}
