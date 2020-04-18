#include <iostream>
#include <queue>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Cliente{
  char nome[50];
  int qntComprada;
  float valorUnitario;
  float total;
};

void imprimir_fila(queue<Cliente> clientes);
void adicionarCliente(Cliente cliente);
void proximoCliente();
void adicionarClientes();
void atenderClientes();

queue<Cliente> clientes;

int main(){
  setlocale(LC_ALL, "Portuguese");

  adicionarClientes();
  //Clientes no caixa
  imprimir_fila(clientes);

  atenderClientes();

  //imprimir_fila(clientes);
  return 0;
}

void atenderClientes(){
  int v = -1;
  while(clientes.size() > 0 && v == -1){
    char atendimento;
    printf("\nDeseja Atender o próximo Cliente? y|n\n");
    scanf("%s", &atendimento);
    fflush(stdin);

    if(atendimento == 'y'){
      proximoCliente();
      v = -1;
    }else{
      v = 0;
    }

  }
  printf("\nCaixa Livre\n");
  printf("Deseja Incluir mais clientes? y|n \n");
  char incluirClientes;
  scanf("%s", &incluirClientes);
  if(incluirClientes == 'y'){
    adicionarClientes();
  }
}

void adicionarClientes(){
  printf("\nClientes no Supermercado: \n");
  int i = -1;
  while(i != 0){
    Cliente c1;

    printf("\nNome Cliente: ");
    scanf("%s", &c1.nome);
    fflush(stdin);

    printf("Quantidade Comprada: ");
    scanf("%i", &c1.qntComprada);

    printf("Valor Unitário: ");
    scanf("%f", &c1.valorUnitario);

    float qntComprada = (float) c1.qntComprada;
    printf("Total: %.2f\n", qntComprada * c1.valorUnitario);

    adicionarCliente(c1);

    printf("\nDigite 1 para adicionar Cliente\n");
    printf("Digite 0 para ir ao atendimento\n");
    scanf("%i", &i);
  }
}

void proximoCliente(){
  if(!clientes.empty()){
    printf("\nCliente Atendido: %s\n", clientes.front().nome);
    clientes.pop();
  }
}
void adicionarCliente(Cliente cliente){
  clientes.push(cliente);
}

void imprimir_fila(queue<Cliente> clientes){
  queue<Cliente> clientes_temp = clientes;

  printf("\nClientes no Caixa\n");
  while(!clientes_temp.empty()){
    printf("Nome: %s\n", clientes_temp.front().nome);

    clientes_temp.pop();
  }
  printf("\n");
}


  //int totalPessoas = 4;


  //mock
  /*int qntsCompradas[totalPessoas] = {2,5,1,7};
  int valoreUnitarios[totalPessoas] = {1,2,3,4};
  int totais[totalPessoas] = {50,12,30,23};

  Cliente c1,c2,c3,c4;
  strcpy(c1.nome, "Gustavo");
  c1.qntComprada = qntsCompradas[1];
  c1.valorUnitario = valoreUnitarios[1];
  c1.total = totais[1];


  strcpy(c2.nome, "Henrique");
  c2.qntComprada = qntsCompradas[2];
  c2.valorUnitario = valoreUnitarios[2];
  c2.total = totais[2];

  strcpy(c3.nome, "Paula");
  c3.qntComprada = qntsCompradas[3];
  c3.valorUnitario = valoreUnitarios[3];
  c3.total = totais[3];


  strcpy(c4.nome, "Daiane");
  c4.qntComprada = qntsCo*mpradas[0];
  c4.valorUnitario = valoreUnitarios[0];
  c4.total = totais[0];*/
