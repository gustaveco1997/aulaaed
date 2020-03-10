#include <stdio.h>
#include <stdlib.h>

struct numero {
    int number;
};

int somar(struct numero *numeros);

int main(void){

    struct numero numeros[4];

    for(int i ; i < 4 ; i ++){
        printf("Digite o %d númerio: ", i);
        scanf("%d", &numeros[i].number);
    }

    int somatorio = somar(numeros);

    printf("Total: %d", somatorio);

    return 0;
}

int somar(struct numero *numeros){

    int total = 0;
    for(int i ; i < 4 ; i++){
        total += numeros[i].number;
    }

    return total;

}
