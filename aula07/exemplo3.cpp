#include <iostream>
#include <queue>
#include <locale.h>

using namespace std;


void showInformacoes(queue<int> fila);

void imprime(queue<int> fila){
  printf("\nImpressão da Fila");
  printf("\nInício -> ");
  while(!fila.empty()){
    printf("%d - ", fila.front());
    fila.pop();
  }

  printf("<-- Fim\n");
}

void imprime_sem_apagar(queue<int> fila){
  queue<int> fila_temp = fila;

  printf("\nImpressão da Fila");
  printf("\nInício -> ");
  while(!fila_temp.empty()){
    printf("%d - ", fila_temp.front());
    fila_temp.pop();
  }

  printf("<-- Fim\n");
}

int main(){
  queue<int> fila;
  int i;
  setlocale(LC_ALL, "Portuguese");

  for(i = 0 ; i < 10 ; i ++){
    fila.push(i);
  }

  showInformacoes(fila);

  printf("\n\n");

  imprime(fila);

  return 0;
}

void showInformacoes(queue<int> fila){
    printf("Informações da Fila\n");
    printf("Tamanho da Fila: %d\n", fila.size());
    printf("Primeiro Elemento da Fila: %d\n", fila.front());
    printf("Último elemento da Fila: %d\n", fila.size());
}
