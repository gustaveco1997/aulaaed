#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>

using namespace std;

void exibirMenu();

void abastecerVetor();
void imprimirVetor();
void imprimirCrescente();
void imprimirDecrescente();
void exibirQuantidadeRepetida();
bool verificarOrdemCrescente();
bool verificarOrdemDecrescente();
void abastecerVetorContador();
void show();
int qntNumeroX(int numero);
int getIndiceObjeto(int numero);


struct ContadorNumero{
  int numero;
  int qnt;
};


int qntNumeros = 10000;
int numeros[10000];
ContadorNumero objetos[10000];

int main(){

  setlocale(LC_ALL, "Portuguese");
  abastecerVetor();
  abastecerVetorContador();
  exibirMenu();
  return 0;
}

void show(){
  int total = 0;
  for(int i = 0 ; i < qntNumeros  ; i ++){
    if(objetos[i].numero != -1 && objetos[i].qnt != 1){
      printf("--- Número.... -> %d\n", objetos[i].numero);
      printf("Repetições -> %d\n", objetos[i].qnt);
      printf("-------\n");
      total++;
    }
    //contadorNumerosRepetidos
  }

  printf("Total Repetidos: %d\n", total);
}

int qntNumeroX(int numero){
  int count = 0;
  for(int i = 0 ; i < qntNumeros ; i ++){
    if(numeros[i] == numero){
      count++;
    }
  }

  return count;
}

int getIndiceObjeto(int numero){
  for(int i = 0 ; i < qntNumeros ; i ++){
    if(numero == objetos[i].numero){
      return i;
    }
  }
  return -1;
}

void abastecerVetorContador(){
  //limpar o lixo
  for(int i = 0 ; i < qntNumeros ; i ++){
    objetos[i].numero = -1;
    objetos[i].qnt = -1;
  }

  for(int i = 0 ; i < qntNumeros ; i ++){

    int quantidade = qntNumeroX(numeros[i]);
    if(getIndiceObjeto(numeros[i]) == -1){
      objetos[i].numero = numeros[i];
      objetos[i].qnt = quantidade;
    }
  }
}
void abastecerVetor(){
  srand(time(NULL));
  /*int count = 0;
  numeros[0] = 1;
  numeros[1] = 3;
  numeros[2] = 3;
  numeros[3] = 3;
  numeros[4] = 1;*/

  /*for(int i = 5 ; i != 0  ; i --){
    numeros[count] = i;
    count++;
    //numeros[i] = rand();
  }*/
  for(int i = 0 ; i < qntNumeros  ; i ++){
    //numeros[i] = i;
    numeros[i] = rand();
  }
}

void imprimirVetor(){
  printf("----- Imprimindo vetor: -----\n");
  for(int i = 0 ; i < qntNumeros  ; i ++){
    printf("-> %d\n", numeros[i]);
  }
}

void imprimirCrescente(){
  for(int i = 0 ; i < qntNumeros  ; i ++){
    if(i < (qntNumeros-1)){
      if(numeros[i] > numeros[i+1]){

        int aux;
        int *pnum1 = &numeros[i];
        int *pnum2 = &numeros[i+1];
        int *paux = &aux;

        *paux = numeros[i];
        *pnum1 = numeros[i+1];
        *pnum2 = aux;
      }
    }
  }

  bool isOrdemCrescenteCorreta = !verificarOrdemCrescente();
  if(!isOrdemCrescenteCorreta){
    imprimirCrescente();
    return;
  }

  printf("----- Imprimindo Ordem Crescente: -----\n");
  imprimirVetor();
}

void imprimirDecrescente(){
  for(int i = 0 ; i < qntNumeros  ; i ++){
    if(i < (qntNumeros-1)){
      if(numeros[i] < numeros[i+1]){
        int aux;
        int *pnum1 = &numeros[i];
        int *pnum2 = &numeros[i+1];
        int *paux = &aux;

        *paux = numeros[i];
        *pnum1 = numeros[i+1];
        *pnum2 = aux;
      }
    }
  }

  bool isOrdemDecrescenteCorreta = !verificarOrdemDecrescente();
  if(!isOrdemDecrescenteCorreta){
    imprimirDecrescente();
    return;
  }

  printf("----- Imprimindo Ordem Decrescente: -----\n");
  imprimirVetor();
}


bool verificarOrdemCrescente(){
  for(int i = 0 ; i < qntNumeros  ; i ++){
    if(i < (qntNumeros-1)){
      if(numeros[i] > numeros[i+1]){
        return true; //significa que está errado
      }
    }
  }
  return false;
}

bool verificarOrdemDecrescente(){
  for(int i = 0 ; i < qntNumeros  ; i ++){
    if(i < (qntNumeros-1)){
      if(numeros[i] < numeros[i+1]){
        return true; //tá errado ainda
      }
    }
  }
  return false;
}

void exibirQuantidadeRepetida(){
  printf("----- Imprimindo Números Repetidos: -----\n");
  show();
}

void exibirMenu(){
    printf("\n---------- MENU ----------\n");
    printf("0 - Abastecer Vetor\n");
    printf("1 - Imprimir Vetor\n");
    printf("2 - Imprimir em forma Crescrente\n");
    printf("3 - Imprimir em forma Decrescente\n");
    printf("4 - Exibir Quantidade números repetidos\n");
    printf("5 - Sair\n");

    int valor = 0;
    printf("Opção: ");
    scanf("%d", &valor);

    switch (valor) {
      case 0:
        system("clear");
        abastecerVetor();
        exibirMenu();
        break;
      case 1:
        system("clear");
        imprimirVetor();
        exibirMenu();
        break;
      case 2:
        system("clear");
        imprimirCrescente();
        exibirMenu();
        break;
      case 3:
        system("clear");
        imprimirDecrescente();
        exibirMenu();
        break;
      case 4:
        system("clear");
        exibirQuantidadeRepetida();
        exibirMenu();
        break;
      case 5:
        exit(11);
        break;
      default:
        system("clear");
        printf("Opção Inválida");
        exibirMenu();
        break;
    }
}
