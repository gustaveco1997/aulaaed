#include <stack>
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

void imprime_pilha(stack<int> pilha);
void buscarValor(stack<int> pilha, int valor);
void somarValores(stack<int> pilha);

int main(){
	stack<int> minha_pilha;
	//exemplos
	minha_pilha.push(10);
	minha_pilha.push(9);
	minha_pilha.push(8);
	minha_pilha.push(7);
	minha_pilha.push(6);
	minha_pilha.push(5);
	//minha_pilha.push(7);
	//minha_pilha.push(6);
	//minha_pilha.push(5);

	//imprime_pilha(minha_pilha);
	//somarValores(minha_pilha);
	buscarValor(minha_pilha, 9);
	getch();
	return 0;
}

void buscarValor(stack<int> pilha, int valor){
	while(!pilha.empty()){
		if(valor == pilha.top()){
			//nada a fazer 
			break;
		}else{
			pilha.pop();		
		}
	}

	
	imprime_pilha(pilha);
}

void somarValores(stack<int> pilha){
	int resultado = 0;
	while(!pilha.empty()){
		resultado += pilha.top();
		pilha.pop();
	}
	printf("%d\n", resultado);
}

void imprime_pilha(stack<int> pilha){
	printf("\nPilha:\n");
	while(!pilha.empty()){
		printf("%d \n", pilha.top());
		pilha.pop();
	}

	printf("\n");
}