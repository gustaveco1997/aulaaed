#include <iostream>
#include <queue>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<stdbool.h>

using namespace std;

struct Carro{
  char name[50];
  int tempoLimpeza;
};

void imprimir_fila(queue<Carro> carro);
void adicionarCarro(Carro carro);
void proximoCarro();
void adicionarCarros();
void atenderCarros();

queue<Carro> carros;

int main(){
  setlocale(LC_ALL, "Portuguese");

  adicionarCarros();
  imprimir_fila(carros);

  atenderCarros();

  return 0;
}

void atenderCarros(){
  int v = -1;
  while(carros.size() > 0 && v == -1){
    char atendimento;
    printf("\nDeseja Atender o próximo Carro? y|n\n");
    scanf("%s", &atendimento);
    fflush(stdin);

    if(atendimento == 'y'){
      proximoCarro();
      v = -1;
    }else{
      v = 0;
    }
  }

  printf("\nCaixa Livre\n");
  printf("Deseja Incluir mais carros? y|n \n");
  char incluirCarros;
  scanf("%s", &incluirCarros);
  if(incluirCarros == 'y'){
    adicionarCarros();
  }
}

void adicionarCarros(){
  printf("\nCarros na Limpeza: \n");
  int i = -1;
  while(i != 0){
    Carro c1;

    printf("\nNome Carro: ");
    scanf("%s", &c1.name);
    fflush(stdin);

    printf("Tempo Limpeza (Minutos): ");
    scanf("%i", &c1.tempoLimpeza);

    adicionarCarro(c1);

    printf("\nDigite 1 para adicionar outro Carro\n");
    printf("Digite 0 para ir ao atendimento\n");
    scanf("%i", &i);
  }
}

void proximoCarro(){
  if(!carros.empty()){
    printf("\nCarro Atendido: %s\n", carros.front().name);
    carros.pop();
  }
}

void adicionarCarro(Carro carro){
  queue<Carro> carros_alternativo;

  if(!carros.empty()){
    bool isCarroNovoAdicionado = false;
    while(!carros.empty()){
      int tempoCarro = carros.front().tempoLimpeza;
      int tempoCarroRecebido = carro.tempoLimpeza;

      if(!isCarroNovoAdicionado){
        if(tempoCarroRecebido <= tempoCarro){
          isCarroNovoAdicionado = true;
          carros_alternativo.push(carro);
          carros_alternativo.push(carros.front());
        }else{
          carros_alternativo.push(carros.front());
        }
      }else{
          carros_alternativo.push(carros.front());
      }

      carros.pop();
    }

    if(!isCarroNovoAdicionado){

        carros_alternativo.push(carro);
    }
  }else{
    carros_alternativo.push(carro);
  }

  carros = carros_alternativo;
}

void imprimir_fila(queue<Carro> carros){
  queue<Carro> carros_temp = carros;

  printf("\nCarros na fila\n");
  while(!carros_temp.empty()){
    printf("Nome: %s\n", carros_temp.front().name);

    carros_temp.pop();
  }
  printf("\n");
}
