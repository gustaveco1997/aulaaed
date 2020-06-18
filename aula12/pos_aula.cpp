#include <iostream>
#include <list>
#include <locale.h>

using namespace std;

void gerarNumeros();
void exibirRelatorio();
void pegarMaiorVezes();
void pegarMenorVezes();
int possuiNovaLista(int valor);

list<int> lista;
list<int> listaSemRepetidos;

using namespace std;

//Mais se repete e menos se repete
//Não considera apenas um número na lista
//repetição tem que ter pelo menos dois itens na lista

int main(){
  setlocale(LC_ALL, "Portuguese");
  gerarNumeros();
  exibirRelatorio();
  return 0;
}

int possuiNovaLista(int valor){
  int i = 0;
  list<int>::iterator it;
  for(it = listaSemRepetidos.begin(); it != listaSemRepetidos.end();it++){
		if (valor == *it){
      return 1;
		}
		i++;
	}
	it--;
  return 0;
}
void gerarNumeros(){
  srand(time(NULL));

  lista.push_back(1);
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(2);

  lista.push_back(3);
    lista.push_back(3);
  lista.push_back(4);
  lista.push_back(4);
  lista.push_back(4);
  lista.push_back(5);
  lista.push_back(5);

  lista.push_back(5);
  list<int>::iterator it;
  for(it = lista.begin(); it != lista.end();it++){

    if(possuiNovaLista(*it) == 0){
      listaSemRepetidos.push_back(*it);

    }
	}
	it--;

  for(int i = 0 ; i < 10 ; i ++){
    int numero = rand() % 5;
    //lista.push_back(*it);
  }
}

void pegarMaiorVezes(){
  int i = 0;
  int i2 = 0;
  list<int>::iterator it;
  list<int>::iterator it2;

  list<int> listaTemp = lista;
  int nMaiorQnt = -1;
  int nQntEncontradas = 0;

  //Pega o primeiro que mais se repete
  for(it = listaSemRepetidos.begin(); it != listaSemRepetidos.end() ; it ++){
    int qntEncontradas = 0;
    for(it2 = listaTemp.begin() ; it2 != listaTemp.end() ; it2 ++){
      if (*it == *it2){
        qntEncontradas += 1;
        if(qntEncontradas > nQntEncontradas){
          nQntEncontradas = qntEncontradas;
          nMaiorQnt = *it;
        }
      }
    }
    it2--;
  }
  it--;

  if(nQntEncontradas > 1 && nMaiorQnt > 0){
    printf("\nMais se repete: %d\n", nMaiorQnt);
  }else{
    printf("\nMais se repete: - INEXISTENTE\n");
  }
}

void pegarMenorVezes(){
  int i = 0;
  int i2 = 0;
  list<int>::iterator it;
  list<int>::iterator it2;

  list<int> listaTemp = lista;
  int nMenorQnt = -1;
  int nQntEncontradas = 99;

  //pega o primeiro que menos se repete
  for(it = listaSemRepetidos.begin(); it != listaSemRepetidos.end() ; it ++){
    int qntEncontradas = 0;
    for(it2 = listaTemp.begin() ; it2 != listaTemp.end() ; it2 ++){
      if (*it == *it2){
        qntEncontradas += 1;
      }
    }

    if(qntEncontradas > 1 &&  qntEncontradas < nQntEncontradas ){
      nQntEncontradas = qntEncontradas;
      nMenorQnt = *it;
    }

    it2--;
  }
  it--;

  if(nQntEncontradas > 1 && nMenorQnt > -1){
    printf("\nMenos se repete: %d\n", nMenorQnt);
  }else{
    printf("\nMenos se repete: - INEXISTENTE\n");
  }
}

void exibirRelatorio(){
  printf("------------ Relatório ------------\n");
  pegarMenorVezes();
  pegarMaiorVezes();


}
