#include <stdio.h>
#include <stdlib.h>

int main(void){
  FILE *pont_arq;
  char palavra[20];

  pont_arq = fopen("arquivo_palavra.txt", "w");

  if(pont_arq == NULL){
    printf("Erro na Abertura do Arquivo");
    return 1;
  }

  printf("Escreva uma palavra: ");
  scanf("%s", palavra);

  fprintf(pont_arq, "%s", palavra);

  fclose(pont_arq);

  printf("Dados Gravados com Sucesso");

  return 0;
}

int pesquisa(){

}
