#include <iostream>
#include <tr1/functional>
#include <string>
#include <locale.h>

//funcao para calcular hash de numeros inteiros
float calcula_hash_inteiro(int valor){
  std::tr1::hash<float> hash_fn;  //Definição do Tipo de Dados Hash chamado hash_fn
  size_t str_hash = hash_fn(valor); //Faz o calculo do HASH
  return(str_hash); //Retorna o Hash
}


int main()
{

  setlocale (LC_ALL, "Portuguese");

  float hash; //Variável que recebe o hash;
  int numero; //Variavel numero

  printf("\t\t CALCULO DE HASH DE NÚMEROS INTEIROS:\n");

  printf("\nDigite um numero inteiro:");
  scanf("%d",&numero);

  hash = calcula_hash_inteiro(12);
  printf("O Hash do número %d é: %.0f",numero,hash);
}
