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
