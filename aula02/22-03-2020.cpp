#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct acao{
	char nome_companhia[50];
	char area_atuacao[50];
	float valor_atual;
	float valor_anterior;
	double variacao;
};

const int qntAcoesInseridas = 2;
struct acao minhas_acoes[2];

void printAcoesAbaxo(struct acao acao);
void printMediaAcoes();
void alteraTodos(float novoValor);
void printRelatorio();

int main(){
	
	for(int i = 0 ; i < qntAcoesInseridas ; i ++){


		printf("Nome da Companhia: ");
		scanf("%s", &minhas_acoes[i].nome_companhia);

		fflush(stdin);

		printf("Área de Atuação: ");
		scanf("%s", &minhas_acoes[i].area_atuacao);

		fflush(stdin);

		printf("Valor Atual: ");
		scanf("%f", &minhas_acoes[i].valor_atual);

		fflush(stdin);

		printf("Valor Anterior: ");
		scanf("%f", &minhas_acoes[i].valor_anterior);

		
		float valorAtual =  minhas_acoes[i].valor_atual;
		float valorAnterior = minhas_acoes[i].valor_anterior;

		minhas_acoes[i].variacao =  ((valorAtual - valorAnterior) * 100) / valorAtual;
		printf("Taxa Variação: %.2f", minhas_acoes[i].variacao);

		printAcoesAbaixo(minhas_acoes[i]);
	}

	//alteraTodos(2.2);
	printRelatorio();
	alteraTodos(2.2);
	printRelatorio();

	return 0;
}

void printRelatorio(){
	for(int i = 0 ; i < qntAcoesInseridas ; i ++){
		printf("\n ------- Relatório ------- \n");
		printf("Empresa: %s\n", minhas_acoes[i].nome_companhia);
		printf("Área Atuação: %s\n", minhas_acoes[i].area_atuacao);
		printf("Valor Atual: %.2f\n", minhas_acoes[i].valor_atual);
		printf("Valor Anterior: %.2f\n", minhas_acoes[i].valor_anterior);
		printf("Variação: %.2f\n", minhas_acoes[i].variacao);
	}	
}

void printAcoesAbaixo(struct acao acaoQueDigitei){
	// acao que digitei
	// menor que as outras

	float valorAtual = acaoQueDigitei.valor_atual;
	for(int i = 0 ; i < qntAcoesInseridas ; i ++){
		//Corrigir
		if(valorAtual > minhas_acoes[i].valor_atual){
			printf("\n Esta ação menor: Empresa: %s -> Valor: %.2f\n", minhas_acoes[i].nome_companhia, minhas_acoes[i].valor_atual);
		}
	}
}

void alteraTodos(float novoValor){
	for(int i = 0 ; i < qntAcoesInseridas ; i ++){
		
		minhas_acoes[i].valor_anterior = minhas_acoes[i].valor_atual;
		minhas_acoes[i].valor_atual = novoValor;

		//Corrigir
		minhas_acoes[i].variacao =  ((minhas_acoes[i].valor_atual - minhas_acoes[i].valor_anterior) * 100) / minhas_acoes[i].valor_atual;

		printf("\n");
		printf("\nValor Alterado Empresa: %s\n", minhas_acoes[i].nome_companhia);

	}
}

void printMediaAcoes(){
	float valorTotal = 0;
	for(int i = 0 ; i < qntAcoesInseridas ; i ++){
		valorTotal += minhas_acoes[i].valor_atual;
	}

	printf("\nA média é: %.2f" , valorTotal / qntAcoesInseridas);
}