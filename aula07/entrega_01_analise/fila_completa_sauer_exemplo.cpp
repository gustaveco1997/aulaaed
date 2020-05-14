#include <iostream>
#include <queue>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h> //similiar conio.h para linux

using namespace std;

void preencher(queue <int> fila);
void menu(queue <int> fila);
void imprime(queue <int> fila);
void informacoes(queue <int> fila);
void busca(queue <int> fila);
void gotoxy(int x, int y);
void remover(queue <int> fila);
void remover_todos(queue <int> fila);


void gotoxy(int x, int y){
     //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void menu(queue <int> fila){
	int opcao;
	system("cls");
    system("color 0F");
    printf("\t\t##############################\n");
    printf("\t\t# MENU DE OPERAÇÕES COM FILA #\n");
    printf("\t\t##############################\n\n");

    printf("1 - INSERIR ELEMENTOS NA FILA \n2 - BUSCAR ELEMENTO NA FILA \n3 - REMOVER ELEMENTO NA FILA \n4 - IMPRIMIR A FILA \n5 - INFORMAÇÕES SOBRE A FILA \n6 - LIMPAR A FILA \n7 - SAIR\n\nInforme a opção desejada:[  ]");
    gotoxy(27,13);
	scanf("%d", &opcao);
    switch (opcao) {
    case 1:
        system("cls");
        printf("PREENCHER\n");
        preencher(fila);
        break;
    case 2:
        system("cls");
        printf("BUSCAR\n");
        busca(fila);
        break;
    case 3:
        system("cls");
        printf("REMOVER ELEMENTO NA FILA:\n");
        remover(fila);
        break;
    case 4:
        system("cls");
        printf("IMPRIMIR A FILA:\n");
        imprime(fila);
        break;
    case 5:
        system("cls");
        printf("INFORMAÇÕES DA FILA\n");
        informacoes(fila);
        break;

     case 6:
        system("cls");
        remover_todos(fila);
        getch();
        break;

    case 7:
        system("cls");
        printf("Obrigado e Tchau! Pressione qualquer tecla para continuar\n");
        getch();
        break;

    default:
        printf("Voce deve escolher uma opcao valida\n");
        system("pause");
        system("cls");
        menu(fila);
    }
} //end menu

void preencher(queue <int> fila){
	int i,valor;
		for(i=0;i<10;i++){
			valor = rand() % 100 +1;
			fila.push(valor);
		}
	printf("\n!!Lista preenchida com 10 elementos !!");
	getch();
	menu(fila);

} //end preencher

void imprime(queue <int> fila){
	queue <int> fila_temp;
	fila_temp = fila;

		if(fila_temp.empty()){
			printf("\n!! A fila está VAZIA !!");
		}else{
			 printf("\n\nINICIO: --> ");
			while(!fila_temp.empty()){
				printf("%d - ", fila_temp.front());
				fila_temp.pop();
			}
			printf("<-- FIM\n");
		}
		getch();
		menu(fila);
}

void informacoes(queue <int> fila){
    if(!fila.empty()){
		printf("\tTamanho da fila: %d \n", fila.size());
		printf("\tPrimeiro elemento da Fila: %d \n", fila.front());
		printf("\tUltimo elemento da Fila: %d \n", fila.back());
		printf("\n\n");
	}else {
		printf("\nA Fila está vazia. Impossivel fornecer informações\n");
	}
	getch();
	menu(fila);
}


void remover(queue <int> fila){
	printf("\nREMOVENDO O VALOR %d DA FILA:", fila.front());
	fila.pop();
	printf("\nITEM REMOVIDO. O PRIMEIRO DA FILA AGORA É O VALOR %d.", fila.front());
	getch();
	menu(fila);
}


void remover_todos(queue <int> fila){
	printf("\nREMOVENDO TODOS ELEMENTOS DA FILA");
	while(!fila.empty())
	{
	fila.pop();
	}
	printf("\nTodos elementos da fila foram removidos");
	getch();
	menu(fila);
}


void busca(queue <int> fila){
	queue <int> fila_temp;
	int valor;

	fila_temp = fila;

	printf("Informe o valor a ser pesquisado na fila:");
	scanf("%d",&valor);
		while(!fila_temp.empty()){
			if (fila_temp.front() == valor)
			{
				printf("Valor %d encontrado na fila", valor);
				getch();
				menu(fila);
				exit;
			}
		fila_temp.pop();
		}
    printf("Valor %d  NÃO encontrado na fila", valor);
    getch();
    menu(fila);
	exit;
}

int main(){
   queue<int> fila;
   setlocale(LC_ALL, "Portuguese"); // Seta caracteres PT-BR <locale.h>
   menu(fila);
}//end main()
