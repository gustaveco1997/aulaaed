#include <iostream>
#include <list>
#include <locale.h>

using namespace std;

void imprime(list <int> lista){
	list<int>::iterator it;
	printf("\t");

	for(it = lista.begin(); it!=lista.end();it++){
		printf("%d - ",*it);
	}
	printf("\n");
	it--;
}

void pesquisa(list <int> lista, int valor){
	int i=0;
	list<int>::iterator it;
	printf("Busca:\t");
	for(it = lista.begin(); it!=lista.end();it++){
		if (valor == *it){
			printf ("Valor %d encontrado na posição %d da lista",valor,i);
		}
		i++;
	}
	it--;
}


void apaga(list <int> lista, int valor){
	int i=0;
	list<int>::iterator it;
	printf("\nApagar: ");
	for(it = lista.begin(); it!=lista.end();it++){
		if (valor == *it){
			printf ("Registro %d apagado\n",valor);
			lista.erase(it);
			imprime(lista);
		}
		i++;
	}
	it--;
}



int main(){

	list<int> lista;

	list<int>::iterator it;

   setlocale (LC_ALL, "Portuguese");


	for(int i=0;i<5;i++){
		 //insere elementos no final da lista
		lista.push_back(i);
	}

	for(int i=5;i<10;i++){
		 //insere elementos no início
		lista.push_front(i);
	}


	// Conteudo da lista: 9 8 7 6 5 0 1 2 3 4
	printf("\tINFORMAÇÕES DA LISTA:\n");
	printf("Tamanho da lista %d \n", lista.size());
	printf("Primeiro elemento da lista %d \n", lista.front());
	printf("Último elemento da lista %d \n", lista.back());


	printf("Imprimindo a lista:\n");
	imprime(lista);

	// Apaga primeiro elemento da lista
	printf("Apagado primeiro elemento da lista:\n");
	lista.pop_front();
	imprime(lista);

	// Apaga ultimo elemento da lista
	printf("Apagado último elemento da lista:\n");
	lista.pop_back();
	imprime(lista);


    // ordenar a lista em ordem crescente
    printf("Ordenando lista em ordem crescente:\n");
    lista.sort();
	imprime(lista);

	// ordenar a lista em ordem decrescente
    printf("Ordenando lista em ordem decrescente:\n");
	lista.reverse();
	imprime(lista);

	// Pesquisa o numero 5 da lista
	pesquisa(lista,5);

	// apaga o numero 5 da lista
	apaga(lista,5);


}
