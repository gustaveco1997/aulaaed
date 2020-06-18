#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>
#include <locale.h>
#include <curses.h> //Alternativa conio.h para linux
#include <time.h>
#include <list>
#include <string.h>
#include <tr1/functional>

using namespace std;

struct Data{
	int mes;
	int ano;
};

struct Vacina{
	int numeroVacina;
	Data dataFabricacao;
  Data dataValidade;
  char *nomeLaboratorio;
};

//Declarações
struct Laboratorio{
	char *nome;
  int maxDiaria;
  list<Vacina> vacinas;
};


Laboratorio labRitmo;
Laboratorio labComp;
Laboratorio labRaja;
Laboratorio labBed;


stack<Vacina> vacinasParaTransporte;
//---------- FIM Declarações

//Fabricação/Produção
void produzirVacinas(int labInt);
list<Vacina> obterVacinas(char *nomeLaboratorio, int qnt);
//Distribuição

//Gerar Dados

//Menu Principal e segurança
void exibirMenu();
void exibirMenuEscolherLabProducao();
void exibirMenuListarVacinas();
void exibirVacinasFromLaboratorio(int labInt);
void exibirMenuBuscaRefinada();
void exibirMenuLogin();
void limparTela();

//configuração de senha
void criarArquivoPassword();
void lerArquivoPassword(int password);
int calculaHash(int valor);

//Desenvolvimento
void startLaboratorios();

//utiliza
void limparTela();

list<Vacina> vacinas;
queue<Vacina> filavacinas;


//funcao para calcular hash de numeros inteiros
int calculaHash(int valor){
	std::tr1::hash<float> hash_fn;  //Definição do Tipo de Dados Hash chamado hash_fn
  size_t str_hash = hash_fn(valor); //Faz o calculo do HASH
  return(str_hash); //Retorna o Hash
}

int main(){
  setlocale(LC_ALL, "Portuguese");
	startLaboratorios();
	criarArquivoPassword();

	printf("\n        *** Seja bem vindo ao SGV *** \n");
	printf("\n *** Sistema de Gerenciamento de Vacinas ***\n");
	exibirMenuLogin();
  //exibirMenu();
  return 0;
}

void startLaboratorios(){

	//strcpy(labRitmo.nome, "Ritmo"); //Só funciona com o strcpy
	labRitmo.nome = "Ritmo";
  labRitmo.maxDiaria = 30;

	labBed.nome = "Bed";
  labBed.maxDiaria = 20;

	labComp.nome = "Comp";
  labComp.maxDiaria = 18;

	labRaja.nome = "Raja";
  labRaja.maxDiaria = 15;
}

void produzirVacinas(int labInt){
	//Referenciar objetos internos de ponteiros utiliza ->
	float precoVacinaUnid = 22.90;

	int qnt, mesValidade, anoValidade;
	printf("Quantas Vacinas deseja produzir? ");
	scanf("%d", &qnt);

	printf("Mes Validade: ");
	scanf("%d", &mesValidade);

	printf("Ano Validade: ");
	scanf("%d", &anoValidade);

	char *nomeLaboratorio;
	Laboratorio *laboratorio;

	switch (labInt){
		case 1:
			laboratorio = &labRitmo;
			break;
		case 2:
			laboratorio = &labBed;
			break;
		case 3:
			laboratorio = &labComp;
			break;
		case 4:
			laboratorio = &labRaja;
			break;
	}

	int totalProduzidasLab = laboratorio->vacinas.size();
	int maxDiaria = laboratorio->maxDiaria;

	if (totalProduzidasLab + qnt > maxDiaria){
		int podemSerProduzidas = maxDiaria-totalProduzidasLab;
		if (podemSerProduzidas != 0){
			printf("\nEste laborário pode produzir apenas mais %d vacinas \n", podemSerProduzidas);
			exibirMenuEscolherLabProducao();
		}else{
			printf("\n Limite diário de vacinas atingido \n");
			exibirMenu();
		}

		return;
	}

	nomeLaboratorio = laboratorio->nome;

	for (int i=0 ; i < qnt ; i ++){
			Vacina vacina;
			vacina.numeroVacina = i;

			Data dataFabricacao;
			dataFabricacao.mes = 6;
			dataFabricacao.ano = 2020;

			Data dataValidade;
			dataValidade.mes = mesValidade;
			dataValidade.ano = anoValidade;

			vacina.dataValidade = dataValidade;
			vacina.dataFabricacao = dataFabricacao;

			vacina.nomeLaboratorio = nomeLaboratorio;
			laboratorio->vacinas.push_back(vacina);

			vacinas.push_back(vacina);
	}


	list<Vacina>::iterator it;
	for(it = vacinas.begin() ; it != vacinas.end() ; it++){
		filavacinas.push(*it);
	}

	vacinas.clear();

	int total = laboratorio->vacinas.size();
	printf("\n---------- VACINAS PRODUZIDAS ----------\n");

	printf("Nome Laboratório: %s\n", nomeLaboratorio);
	printf("Total Vacinas: %d\n", total);
	printf("Gasto: R$ %.2f\n", total*precoVacinaUnid);

	exibirMenu();
}

list<Vacina> obterVacinas(char *nomeLaboratorio, int qnt){

}

//Menu Principal e segurança
void exibirMenu(){
  printf("\n---------- MENU ----------\n");
  printf("1 - Produzir Vacinas\n");
  printf("2 - Buscar Vacinas\n");
  //printf("3 - Ver Distribuição\n");
  //printf("4 - Verificar Clientes na Fila\n");
  printf("5 - Sair\n");

  int valor = 0;
  printf("Opção: ");
  scanf("%d", &valor);

  switch (valor) {
    case 1:
			limparTela();
      exibirMenuEscolherLabProducao();
      break;
    case 2:
			limparTela();
			exibirMenuListarVacinas();
      break;
    case 3:
			limparTela();
      break;
    case 4:
			limparTela();
      break;
    case 7:
      //11 é saída com sucesso
      exit(11);
      break;
  }
}

void criarArquivoPassword(){
	FILE *arquivo;

	// Abrindo arquivo para gravação
	arquivo = fopen("passwd.txt","wt");

	if(arquivo==NULL){
			printf("Não foi possivel abrir o arquivo");
			exit(0);
	}

	//senha padrao
	int hash = calculaHash(1111);

  fprintf(arquivo, "%d", hash);
  fclose(arquivo);

}

//aqui está errado
void lerArquivoPassword(int password){
  char vetor[60];
  int valor;
  FILE *arquivo;

  arquivo = fopen("passwd.txt","rt");

  if(arquivo == NULL){
      printf("\nNão foi possivel abrir o arquivo\n");
      exit(0);
  }


		//itoa(a,buffer,10);

		int hash = calculaHash(password);
		char variavelConvertida[20];

		//Linux //Unica maneira de converter int para intring
	 	sprintf( variavelConvertida, "%d", hash);
		//printf("Decimal value = %s\n", variavelConvertida);

		//printf("Teste22: %s" , str);

	fscanf(arquivo,"%s %d", &vetor, &valor); // Le do arquivo e joga para as variáveis;
	//fscanf(arquivo,"%s %d", &vetor, &valor);
	//strcmp é utilizado para comparar "string"
  //Da outra maneira vem lixo
  //if (strcmp (vetor, password) == 0){

	if ((strcmp (vetor, variavelConvertida) == 0)){
		printf("\nOlá Fulano");
		printf("\nStatus: Ativo\n");
		exibirMenu();
	}else{
		printf("\n*** Senha Incorreta, tente novamente ***\n");
		exibirMenuLogin();
	}
}

void exibirMenuLogin(){

	printf("\nCredencial de acesso: \n");

	int password;
	scanf("%d", &password);
	fflush(stdin);

	lerArquivoPassword(password);
}

void exibirVacinasFromLaboratorio(int labInt){

	Laboratorio *laboratorio;

	switch (labInt){
		case 1:
			laboratorio = &labRitmo;
			break;
		case 2:
			laboratorio = &labBed;
			break;
		case 3:
			laboratorio = &labComp;
			break;
		case 4:
			laboratorio = &labRaja;
			break;
	}

	list<Vacina>::iterator vacina;


	printf("\n ----- \n");
	printf("\nVacinas do laboratório: %s\n", laboratorio->nome);
	printf("\Total de Vacinas %d\n", laboratorio->vacinas.size());
	for(vacina = laboratorio->vacinas.begin() ; vacina != laboratorio->vacinas.end() ; vacina ++){
		printf("\nVacina: -> %d ", vacina->numeroVacina);
		printf("\nData Fabricação: %d/%d", vacina->dataFabricacao.mes, vacina->dataFabricacao.ano);
		printf("\nData Validade: %d/%d\n", vacina->dataValidade.mes, vacina->dataValidade.ano);
		printf("\n");
	}

	printf("\n ----- \n");

}

void exibirMenuListarVacinas(){

	  printf("\n---------- Relatório Vacinas Produzidas----------\n");
		printf("1 - Exibir todas as vacinas \n");
		printf("2 - Busca Refinada \n");
		printf("3 - Voltar \n");


	  int valor = 0;
	  printf("Opção: ");
	  scanf("%d", &valor);

		switch (valor) {
	    case 1:
				for(int i = 1 ; i <= 4 ; i ++){
					exibirVacinasFromLaboratorio(i);
				}
				break;
	    case 2:
				break;
			case 3:
				exibirMenu();
				break;
    	default:
      	printf("\n***** Opção Inválida *****\n");
		}
}


void exibirMenuBuscaRefinada(){
}

void exibirMenuEscolherLabProducao(){

  printf("\n---------- Produção de Vacinas----------");
  printf("\n---------- Escolha o Laborário----------\n");
  printf("1 - Ritmo (Laboratório) \n");
  printf("2 - Bed (Laboratório) \n");
  printf("3 - Raja (Laboratório) \n");
  printf("4 - Comp (Laboratório) \n");
  printf("5 - Voltar\n");

  int valor = 0;
  printf("Opção: ");
  scanf("%d", &valor);

  switch (valor) {
    case 1:
    case 2:
    case 3:
    case 4:
			limparTela();
      produzirVacinas(valor);
      break;
    case 5:
			limparTela();
      exibirMenu();
      break;
    default:
      printf("\n***** Opção Inválida *****\n");
  }
}


//util
void limparTela(){
	system("clear");
}
