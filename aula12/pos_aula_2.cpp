#include <iostream>
#include <list>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

list<int> gerarNumeros(list<int> lista);
list<int> setImpares(list<int> lista);
list<int> setPares(list<int> lista);

void exibir(list<int> lista, list<int> listaImpares, list<int> listaPares);
void exibirPares(list<int> listaPares);
void exibirImpares(list<int> listaImpares);
void exibirSimples(list<int> lista);


list<int> teste;

int main(){
  setlocale(LC_ALL, "Portuguese");

  list<int> lista;
  list<int> listaImpares;
  list<int> listaPares;

  lista = gerarNumeros(lista);
  listaImpares = setImpares(lista);
  listaPares = setPares(lista);

  exibir(lista, listaImpares, listaPares);
  return 0;
}

list<int> gerarNumeros(list<int> lista){
  srand(time(NULL));
  for(int i = 0 ; i < 1000 ; i ++){
    int numero = rand() % 5;
    lista.push_back(numero);
  }

  return lista;
}

list<int> setImpares(list<int> lista){
  list<int> impares;
  list<int>::iterator it;

  for(it = lista.begin() ; it != lista.end() ; it++){
    if(*it % 2 != 0){
      impares.push_back(*it);
    }
  }
  it--;

  return impares;
}

list<int> setPares(list<int> lista){
  list<int> pares;
  list<int>::iterator it;

  for(it = lista.begin() ; it != lista.end() ; it++){
    if(*it % 2 == 0){
      pares.push_back(*it);
    }
  }
  it--;

  return pares;
}

void exibirPares(list<int> listaPares){
  printf("\n\n------------ Pares ------------\n");
  list<int>::iterator it;


	for(it = listaPares.begin() ; it != listaPares.end() ; it++){
    printf("-> %d \n",*it);
	}
	it--;
}

void exibirImpares(list<int> listaImpares){
  printf("\n\n------------ Ímpares ------------\n");
  list<int>::iterator it;


	for(it = listaImpares.begin() ; it != listaImpares.end() ; it++){
		printf("-> %d \n",*it);
	}
	it--;
}

void exibirSimples(list<int> lista){
  printf("\n\n------------ Lista Simples ------------\n");
  list<int>::iterator it;


	for(it = lista.begin() ; it != lista.end() ; it++){
		printf("-> %d \n",*it);
	}
	it--;
}

void exibir(list<int> lista, list<int> listaImpares, list<int> listaPares){
  exibirSimples(lista);
  exibirPares(listaPares);
  exibirImpares(listaImpares);
}
