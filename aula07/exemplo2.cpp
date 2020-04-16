#include <iostream>
#include <queue>
#include <locale.h>

using namespace std;

void imprime(queue<int> fila){
  queue<int> fila_temp;
  fila_temp = fila;

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

  printf("Tamanho da Fila: %d\n", fila.size());
  printf("Primeiro Elemento da Fila: %d\n", fila.front());
  fila.pop();
  printf("Primeiro Elemento da Fila Agora: %d\n", fila.front());
  printf("Tamanho da Fila: %d\n", fila.size());

  imprime(fila);

  return 0;
}
