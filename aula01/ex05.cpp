#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct ficha_de_aluno{
    char nome[10];
    char disciplina[10];
    float nota_prova_1;
    float nota_prova_2;
};

int main(void){

    struct ficha_de_aluno aluno[10];

    for(int i = 0 ; i < 10 ; i++){
        printf("Cadastro de aluno: ");
        fflush(stdin);

        fgets(aluno[i].nome, 40, stdin);
        fflush(stdin);

        fgets(aluno[i].disciplina, 40, stdin);
        printf("Informe a 1a. nota ..: ");
        scanf("%f", &aluno[i].nota_prova_1);

        printf("Informe a 2a. nota ..: ");
        scanf("%f", &aluno[i].nota_prova_2);
    }

    for(int i = 0 ; i < 10 ; i ++){

        printf("Nome %s", aluno[i].nome);
        printf("Disciplina: %s", aluno[i].disciplina);
        printf("Nota Prova 1 ...: %.2f", aluno[i].nota_prova_1);
        printf("Nota Prova 2...: %.2f", aluno[i].nota_prova_2);
    }

    getch();
    return 0;
}
