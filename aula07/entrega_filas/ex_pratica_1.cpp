#include <iostream>
#include <queue>
#include <locale.h>

using namespace std;

bool buscarValor(queue<int> fila, int valor);

int main(){
  queue<int> fila;
  int i;
  setlocale(LC_ALL, "Portuguese");

  for(i = 0 ; i < 10 ; i ++){
    fila.push(i);
  }

  int valor = 5;
  int isEncontrou = buscarValor(fila, 5);
  buscarValor(fila, 5);
  buscarValor(fila, 5);
  buscarValor(fila, 5);


  return 0;
}

bool buscarValor(queue<int> fila_temp, int valor){
  //queue<int> fila_temp;
  //fila_temp = fila;

  while(!fila_temp.empty()){
    if(fila_temp.front() == valor){

        printf("Valor %d Encontrado\n", valor);
        return 1;
    }else{
      fila_temp.pop();
    }
  }

    printf("Valor %d Não Encontrado\n", valor);
  return 0;
}
