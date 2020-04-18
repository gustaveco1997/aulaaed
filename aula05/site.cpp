#include <stdio.h>
#include <stdlib.h>

//Estrutura base do nó.
struct node
{
    int nData;
    struct node *pLink;
};

int removeIntermediario(struct node *inicio, struct node *excluir);
//int removeIntermediario(struct node *inicio);
void displayLL(struct node *p);

int main(void){
    struct node *pNode1 = NULL;
    struct node *pNode2 = NULL;
    struct node *pNode3 = NULL;

    //Criando os nos e associando os dados.
    pNode1 = (struct node*) malloc(sizeof(struct node*));
    pNode1->nData = 10;

    pNode2 = (struct node*) malloc(sizeof(struct node*));
    pNode2->nData = 20;

    pNode3 = (struct node*) malloc(sizeof(struct node*));
    pNode3->nData = 30;

    //Conectando os nós
    pNode1->pLink = pNode2;
    pNode2->pLink = pNode3;
    pNode3->pLink = NULL;


    //Mostrando a lista.
    if(pNode1)
        displayLL(pNode1);


    printf("\n");
    if(pNode1)
        displayLL(pNode1);


    removeIntermediario(pNode1, pNode3);


  return 0;
}


int removeIntermediario(struct node *inicio, struct node *excluir){

  if(!(inicio) || !(inicio)-> pLink)
    return -1;

  do{
      printf(" %d", inicio->nData);
      inicio = inicio->pLink;
      if(inicio == excluir->pLink){

          node *aux = (inicio)->pLink;
          int n = aux->nData;
          (inicio)->pLink = aux->pLink; //remove
          free(aux);
          return 0;
      }

  }while(inicio);

  return -1;

  //return n;
  /*if(!(*inicio) || !(*inicio)-> pLink)
    return -1;
  node *aux = (*inicio)->pLinkexcluir;
  int n = aux->nData;
  (*inicio)->pLink = aux->pLink;
  free(aux);
  return 0;
  //return n;*/
}

//Função pra printar o nó na tela.
void displayLL(struct node *p){
  printf("Mostrando a lista:\n");
  if(p){
      do{
          printf(" %d", p->nData);
          p = p->pLink;
      }while(p);
  }
  else
      printf("Lista vazia.");
}
