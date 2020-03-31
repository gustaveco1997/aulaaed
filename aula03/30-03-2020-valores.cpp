#include<stdio.h>
#include<stdlib.h>

float calcularAliquota(float taxa, float dinheiro, float reais);

int main(){
	float taxa = 2.5;
	float dinheiro = 1000;
	float aliquotaReais = 0;

	aliquotaReais = calcularAliquota(taxa, dinheiro, aliquotaReais);
	printf("Taxa em Reais: R$ %.2f", aliquotaReais);

	return 0;
}

float calcularAliquota(float taxa, float dinheiro, float reais){
	reais = (taxa*dinheiro) / 100;
	return reais;
}