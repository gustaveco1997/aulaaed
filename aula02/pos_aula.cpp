#include <stdlib.h>
#include <stdio.h>

int main(void){
  int x = 2, y = 3;
  int z = x + y;

  printf("Os endereços das variáveis são:\n");
  printf("x = %d\n", &x);
  printf("y = %d\n", &y);
  printf("z = %d\n", &z);
  printf("\n");

  printf("Os valores das variáveis são:\n");
  printf("x = %d\n", x);
  printf("y = %d\n", y);
  printf("z = %d\n", z);
  printf("\n");

  int *px = &x;
  int *py = &y;
  int *pz = &z;

  printf("Os endereços dos ponteiros são:\n");
  printf("&px = %d\n", &px);
  printf("&py = %d\n", &py);
  printf("&pz = %d\n", &pz);
  printf("\n");

  printf("Os valores das variáveis são:\n");
  printf("px = %d\n", px);
  printf("py = %d\n", py);
  printf("pz = %d\n", pz);
  printf("\n");

  printf("Os valores apontados pelos ponteiros são:\n");
  printf("*px = %d\n", *px);
  printf("*py = %d\n", *py);
  printf("*pz = %d\n", *pz);
  printf("\n");

  return 0;
}
