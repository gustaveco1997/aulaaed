#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>
#include <stack>
#include <iostream>

using namespace std;

void exibirMenu();
void abastecerPilhas();
void retirarImpares();
void verificarSomaPilhas();
void imprimirPilhas();
void imprimirPilha1();
void imprimirPilha2();
void imprimirPilhaImpares();
void removerNumeroPilha1();
void removerNumeroPilha2();

stack<int> pilha1;
stack<int> pilha2;
stack<int> pilhaImpares;

int main(){
  setlocale(LC_ALL, "Portuguese");
  abastecerPilhas();
  exibirMenu();
}

void exibirMenu(){
  printf("\n---------- MENU ----------\n");
  printf("0 - Preencher pilhas\n");
  printf("1 - Imprimir pilhas\n");
  printf("2 - Verificar soma pilhas\n");
  printf("3 - Retirar ímpares\n");
  printf("4 - Imprimir ímpares\n");
  printf("5 - Sair\n");

  int valor = 0;
  printf("Opção: ");
  scanf("%d", &valor);

  switch (valor) {
    case 0:
      system("clear");
      abastecerPilhas();
      exibirMenu();
      break;
    case 1:
      system("clear");
      imprimirPilhas();
      exibirMenu();
      break;
    case 2:
      system("clear");
      verificarSomaPilhas();
      exibirMenu();
      break;
    case 3:
      system("clear");
      retirarImpares();
      exibirMenu();
      break;
    case 4:
      system("clear");
      retirarImpares();
      exibirMenu();
      break;
    case 5:
      exit(11);
      break;
    default:
      printf("Comando Inválido");
  }
}

void apagarPilhas(){
  while(!pilha1.empty()){
    pilha1.pop();
  }
  while(!pilha2.empty()){
    pilha2.pop();
  }
  while(!pilhaImpares.empty()){
    pilhaImpares.pop();
  }
}

void abastecerPilhas(){
  apagarPilhas();
  srand(time(NULL));
  for(int i = 0 ; i < 40 ; i++){
    pilha1.push(rand() % 999999);
  	pilha2.push(rand() % 999999);
  }
}


void imprimirPilhaImpares(){
  stack<int> pilha_temp = pilhaImpares;
  printf("\nPilha Ímpares\n");
  while(!pilha_temp.empty()){
    printf("-> %d \n", pilha_temp.top());
    pilha_temp.pop();
  }
}

void removerNumeroPilha1(){
  stack<int> pilha_temp = pilha1;
  stack<int> pilha_aux;

  while(!pilha_temp.empty()){
    int numero = pilha_temp.top();
    if(numero % 2 != 0)
      pilhaImpares.push(numero);
    else
      pilha_aux.push(numero);

    pilha_temp.pop();
  }

  pilha1 = pilha_aux;
}

void removerNumeroPilha2(){
  stack<int> pilha_temp = pilha2;
  stack<int> pilha_aux;

  while(!pilha_temp.empty()){
    int numero = pilha_temp.top();
    if(numero % 2 != 0)
      pilhaImpares.push(numero);
    else
      pilha_aux.push(numero);

      pilha_temp.pop();
  }

  pilha2 = pilha_aux;
}

void retirarImpares(){
  removerNumeroPilha1();
  removerNumeroPilha2();
  imprimirPilhaImpares();
}

int somaPilha1(){
  int total = 0;
  stack<int> pilha_temp = pilha1;
  while(!pilha_temp.empty()){
    total += pilha_temp.top();
	   pilha_temp.pop();
	}

  return total;
}
int somaPilha2(){
  int total = 0;
  stack<int> pilha_temp = pilha2;
	while(!pilha_temp.empty()){
    total += pilha_temp.top();
		pilha_temp.pop();
	}

  return total;
}

void verificarSomaPilhas(){
  int totalPilha1 = somaPilha1();
  int totalPilha2 = somaPilha2();

  printf("---------- SOMATÓRIO ---------- ");
  printf("\nSoma pilha 1: -> %d", totalPilha1);
  printf("\nSoma pilha 2: -> %d", totalPilha2);

  if(totalPilha1 > totalPilha2)
    printf("\nMaior: -> Pilha 1");
  else
    printf("\nMaior: -> Pilha 2\n");

}

void imprimirPilha1(){
  stack<int> pilha_temp = pilha1;
	printf("\nPilha 1\n");
  while(!pilha_temp.empty()){
	   printf("-> %d \n", pilha_temp.top());
    pilha_temp.pop();
	}
}

void imprimirPilha2(){
  stack<int> pilha_temp = pilha2;
  printf("\nPilha 2\n");
  while(!pilha_temp .empty()){
    printf("-> %d \n", pilha_temp .top());
    pilha_temp .pop();
  }
}

void imprimirPilhas(){
  imprimirPilha1();
  imprimirPilha2();
}
