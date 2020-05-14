#include <stdio.h>
#include <stdlib.h>

/*
Outras Funções para manupulação de arquivos

FPUTC - Grava 1 Caracter no arquivo
FGETC - Lê 1 Caracter do arquivo

FPUTS - Grava uma sequência de Caracteres no arquivo
FGETS - Lê uma sequência de Caracteres do arquivo

FWRITE - Grava certa quantidade de bytes no arquivo
FREAD - Lê certa quantidade de bytes do arquivo

www.cplusplus.com/reference/

*/


int main(){
    char vetor[60];
    int valor;
    FILE *arquivo;

	// Abrindo arquivo para gravação; sempre wt apaga e recria o arquivo
    arquivo = fopen("teste.txt","wt"); //wt = Gravação
                                       //rt = Leitura
                                       //a  = append

    if(arquivo==NULL){      //Se houver algum erro, o ponteiro apontará para NULL
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }



    fprintf(arquivo,"TesteSauer 234");
    fclose(arquivo);

    arquivo = fopen("teste.txt","rt"); //wt = Gravação
                                       //rt = Leitura
                                       //a  = append

    if(arquivo==NULL){      //Se houver algum erro, o ponteiro apontará para NULL
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }

		fscanf(arquivo,"%s %d", &vetor, &valor); // Le do arquivo e joga para as variáveis;
		printf("\n\n%s %d\n\n", vetor, valor);

//	fscanf(arquivo,"%s", &vetor); // Le do arquivo e joga para as variáveis;
//	printf("%s", vetor);

    fclose(arquivo); //Fecha arquivo;

    system("pause");
    return 0;
}
