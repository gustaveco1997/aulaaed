#include <iostream>
#include <queue>
#include <locale.h>

using namespace std;

int main(){
  queue<int> fila;
  setlocale(LC_ALL, "Portuguese");

  fila.push(0);
  fila.push(1);
  fila.push(2);
  fila.push(3);
  fila.push(4);
  fila.push(5);
  fila.push(6);
  fila.push(7);
  fila.push(8);
  fila.push(9);

  printf("Tamanho da Fila: %d\n", fila.size());
  printf("Primeiro Elemento da Fila: %d\n", fila.front());
  fila.pop();
  printf("Primeiro Elemento da Fila Agora: %d\n", fila.front());
  printf("Tamanho da Fila: %d\n", fila.size());

  return 0;

}
