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
	char *dataFabricacao;
	char *dataValidade;
	char *nomeLaboratorio;
	int idLaboratorio;
};

//Declarações
struct Laboratorio{
	int id;
	char *nome;
	int maxDiaria;
	list<Vacina> vacinas;
};

struct Galpao{
	stack<Vacina> pilhaRitmo;
	stack<Vacina> pilhaComp;
	stack<Vacina> pilhaRaja;
	stack<Vacina> pilhaBed;
};


Laboratorio labRitmo;
Laboratorio labComp;
Laboratorio labRaja;
Laboratorio labBed;

Galpao galpao;

list<Laboratorio> laboratorios;


//retirar
//stack<Vacina> vacinasParaTransporte;

stack<Vacina> centroAfrica;
stack<Vacina> centroAmerica;
stack<Vacina> centroAntartica;
stack<Vacina> centroAsia;
stack<Vacina> centroOceania;
stack<Vacina> centroEuropa;

//---------- FIM Declarações

//Fabricação/Produção
void produzirVacinas(int labInt);

//pesquisa
list<Vacina> obterVacinas(char *nomeLaboratorio, int qnt);
Laboratorio buscarLaboratorioFromId(int idLaboratorio);

//Pesquisa Válida
void buscarVacinaPorNumero();
void buscarVacinaPorDataFabricacao();
void buscarVacinaPorDataValidade();
void buscarVacinaPorLaboratorio();
void buscarVacinaPorNomeLaboratorio();

//Distribuição

void retirarVacinasNoLaboratorio();
void entregarVacinasCentroDistribuicao();
void entregarVacinasPorContinente(int continente, int quantidadeVacinas);
void entregarContinente(int value, int qnt);
void listarVacinasEntregues();
void quantitativoVacinasPorContinente();

//Gerar Dados

//Menu Principal e segurança
void exibirMenu();
void exibirMenuEscolherLabProducao();
void exibirMenuListarVacinas();
void exibirVacinasFromLaboratorio(int labInt);
void exibirMenuBuscaRefinada();
void exibirMenuLogin();

void exibirCustoTotalLaboratorio();
void exibirTopLaboratorios();

void exibirMenuDistribuicaoVacinas();
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
queue<Vacina> vacinasFila;

float precoVacinaUnid = 22.90;
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
	labRitmo.id = 999;
	labRitmo.nome = "Ritmo";
	labRitmo.maxDiaria = 30000;

	labBed.id = 777;
	labBed.nome = "Bed";
	labBed.maxDiaria = 20000;

	labComp.id = 555;
	labComp.nome = "Comp";
	labComp.maxDiaria = 18000;

	labRaja.id = 333;
	labRaja.nome = "Raja";
	labRaja.maxDiaria = 15000;


	laboratorios.push_back(labRaja);
	laboratorios.push_back(labComp);
	laboratorios.push_back(labBed);
	laboratorios.push_back(labRitmo);
}

Laboratorio buscarLaboratorioFromId(int idLaboratorio){

	list<Laboratorio>::iterator it;
	for(it = laboratorios.begin() ; it != laboratorios.end() ; it++){
		if (it->id == idLaboratorio) {
			return *it;
		}
	}

	Laboratorio labVazio;
	return labVazio;
	//return NULL;

}

void produzirVacinas(int labInt){
	//Referenciar objetos internos de ponteiros utiliza ->
	int qnt;
	char dataValidade[50];
	printf("Quantas Vacinas deseja produzir? ");
	scanf("%d", &qnt);

	printf("Validade: p (06/2027) ");
	scanf("%s", &dataValidade);
	fflush(stdin);

	if (strcmp(dataValidade, "p") == 0){
		strcpy(dataValidade, "06/2027");
	}

	int idLaboratorio;
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


	idLaboratorio = laboratorio->id;
	nomeLaboratorio = laboratorio->nome;

	for (int i=0 ; i < qnt ; i ++){
		Vacina vacina;
		vacina.numeroVacina = i;

		vacina.dataValidade = dataValidade;
		vacina.dataFabricacao = "06/2020";

		vacina.idLaboratorio = idLaboratorio;

		vacina.nomeLaboratorio = nomeLaboratorio;
		laboratorio->vacinas.push_back(vacina);

		vacinas.push_back(vacina);
	}


	list<Vacina>::iterator it;
	for(it = vacinas.begin() ; it != vacinas.end() ; it++){
		vacinasFila.push(*it);
	}

	vacinas.clear();

	int total = laboratorio->vacinas.size();
	printf("\n---------- VACINAS PRODUZIDAS ----------\n");

	printf("Nome Laboratório: %s\n", nomeLaboratorio);
	printf("Total Vacinas: %d\n", total);
	printf("Gasto: R$ %.2f\n", ((float) total) * precoVacinaUnid);

	exibirMenu();
}

list<Vacina> obterVacinas(char *nomeLaboratorio, int qnt){

}

//Menu Principal e segurança
void exibirMenu(){
	printf("\n---------- MENU ----------\n");
	printf("1 - Produzir Vacinas\n");
	printf("2 - Buscar Vacinas\n");
	printf("3 - Distribuir Vacinas\n");
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
		exibirMenuDistribuicaoVacinas();
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

void retirarVacinasNoLaboratorio(){

	printf("\n---------- Escolha onde Deseja Buscar as Vacinas ----------\n");
	printf("1 - Ritmo (Laboratório) \n");
	printf("2 - Bed (Laboratório) \n");
	printf("3 - Raja (Laboratório) \n");
	printf("4 - Comp (Laboratório) \n");
	printf("5 - Voltar\n");

	int idLaboratorio = 0;
	int valor = 0;
	printf("Opção: ");
	scanf("%d", &valor);

	switch (valor) {
		case 1:
		idLaboratorio = labRitmo.id;
		break;
		case 2:
		idLaboratorio = labBed.id;
		break;
		case 3:
		idLaboratorio = labRaja.id;
		break;
		case 4:
		idLaboratorio = labComp.id;
		break;
		case 5:
		limparTela();
		exibirMenuDistribuicaoVacinas();
		break;
		default:
		printf("\n***** Opção Inválida *****\n");
		retirarVacinasNoLaboratorio();
		return;
	}

	Laboratorio lab;
	lab = buscarLaboratorioFromId(idLaboratorio);

	//vai possuir as vacinas que não foram retiradas da fila
	queue<Vacina> newVacinaFilas;
	queue<Vacina> vacinasFila_temp = vacinasFila;

	int qntVacinasRetiradas = 0;

	while(!vacinasFila_temp.empty()){
		if(vacinasFila_temp.front().idLaboratorio == idLaboratorio){
			qntVacinasRetiradas += 1;
			switch (valor) {
				case 1:
				if (galpao.pilhaRitmo.size() < 100000 ){
					galpao.pilhaRitmo.push(vacinasFila_temp.front());

				}else{
					printf("\n(Ritmo) Capacidade Máxima Atingida\n");
					return;
				}
				case 2:

				if (galpao.pilhaBed.size() < 100000 ){
					galpao.pilhaBed.push(vacinasFila_temp.front());

				}else{
					printf("\n(Bed) Capacidade Máxima Atingida\n");
					return;
				}
				case 3:
				if (galpao.pilhaRaja.size() < 100000 ){
					galpao.pilhaRaja.push(vacinasFila_temp.front());

				}else{
					printf("\n(Raja) Capacidade Máxima Atingida\n");
					return;
				}
				case 4:

				if (galpao.pilhaRitmo.size() < 100000 ){
					galpao.pilhaComp.push(vacinasFila_temp.front());

				}else{
					printf("\n(Comp) Capacidade Máxima Atingida\n");
					return;
				}
			}
		}else{
			newVacinaFilas.push(vacinasFila_temp.front());
		}
		vacinasFila_temp.pop();
	}
	vacinasFila = newVacinaFilas;

	if (qntVacinasRetiradas > 0) {
		printf("\n Vacinas Retiradas (%d)\n", qntVacinasRetiradas);
	}else{
		printf("\n Não há vacinas para serem retiradas\n");
	}

	exibirMenuDistribuicaoVacinas();
}

void entregarVacinasCentroDistribuicao(){
	printf("\n---------- Escolha o centro de Distribuição ----------\n");
	printf("1 - África\n");
	printf("2 - América\n");
	printf("3 - Antártica\n");
	printf("4 - Ásia\n");
	printf("5 - Oceania\n");
	printf("6 - Europa\n");
	printf("7 - Voltar\n");

	int entrada = 0;
	printf("Opção: ");
	scanf("%d", &entrada);


	int quantidade = 0;
	printf("Quantidade: ");
	scanf("%d", &quantidade);

	if (entrada >=1 && entrada <= 6){
		entregarContinente(entrada, quantidade);
		printf("nada  --- %d", entrada);
	}else if (entrada == 7){
		limparTela();
		exibirMenuDistribuicaoVacinas();
	}else{
		printf("\n **** Opção Inválida ****");
		entregarVacinasCentroDistribuicao();
	}
}

//aqui
void entregarContinente(int value, int qnt){

	printf("aquii xxxx");

	stack<Vacina> vacinaToContinente;

	int qntVacinasRequeridas = 0;
	//crash
	while(!galpao.pilhaRaja.empty()){
		if(qntVacinasRequeridas < qnt){
			qntVacinasRequeridas +=1;
			vacinaToContinente.push(galpao.pilhaRaja.top());
			galpao.pilhaRaja.pop();
		}
	}
	printf("aquii");
	while(!galpao.pilhaBed.empty()){
		if(qntVacinasRequeridas < qnt){
			qntVacinasRequeridas +=1;
			vacinaToContinente.push(galpao.pilhaBed.top());
			galpao.pilhaBed.pop();
		}
	}


	while(!galpao.pilhaComp.empty()){
		if(qntVacinasRequeridas < qnt){
			qntVacinasRequeridas +=1;
			vacinaToContinente.push(galpao.pilhaComp.top());
			galpao.pilhaComp.pop();
		}
	}

	while(!galpao.pilhaRitmo.empty()){
		if(qntVacinasRequeridas < qnt){
			qntVacinasRequeridas +=1;
			vacinaToContinente.push(galpao.pilhaRitmo.top());
			galpao.pilhaRitmo.pop();
		}
	}

	char *nomeContinente;

	//Entregar
	while(!vacinaToContinente.empty()){

		switch (value) {
			case 1:
			centroAfrica.push(vacinaToContinente.top());
			nomeContinente = "Africa";
			break;
			case 2:
			centroAmerica.push(vacinaToContinente.top());
			nomeContinente = "America";
			break;
			case 3:
			centroAntartica.push(vacinaToContinente.top());
			nomeContinente = "Antartica";
			break;
			case 4:
			centroAsia.push(vacinaToContinente.top());
			nomeContinente = "Asia";
			break;
			case 5:
			centroOceania.push(vacinaToContinente.top());
			nomeContinente = "Oceania";
			break;
			case 6:
			centroEuropa.push(vacinaToContinente.top());
			nomeContinente = "Europa";
			break;
		}
	}
	printf("Vacinas Distribuídas para o continente: %s", nomeContinente);
	printf("%d Unidades", qntVacinasRequeridas);

}

void entregarVacinasPorContinente(int continente, int quantidadeVacinas){

	printf("aquii");

}
void listarVacinasEntregues(){}
void quantitativoVacinasPorContinente(){}

void exibirMenuDistribuicaoVacinas(){
	printf("\n---------- MENU ----------\n");
	printf("1 - Retirar Vacinas no Laboratório\n");
	printf("2 - Entregar vacinas nos Centros de Distribuição\n");
	printf("3 - Entregar vacinas nos Continentes\n");
	printf("4 - Listar Vacinas Entregues\n");
	printf("5 - Quantitativo Vacinas por continente\n");
	printf("6 - Voltar\n");

	int valor = 0;
	printf("Opção: ");
	scanf("%d", &valor);

	switch (valor) {
		case 1:
		limparTela();
		retirarVacinasNoLaboratorio();
		break;
		case 2:
		limparTela();
		entregarVacinasCentroDistribuicao();
		break;
		case 3:
		limparTela();
		entregarVacinasCentroDistribuicao();

		break;
		case 4:
		limparTela();
		listarVacinasEntregues();
		break;
		case 5:
		limparTela();
		quantitativoVacinasPorContinente();
		break;
		case 6:
		limparTela();
		exibirMenu();
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

	//Linux //Maneira de converter int para intring
	sprintf(variavelConvertida, "%d", hash);


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
	//fflush(stdin);

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


	if (laboratorio->vacinas.size() > 0 ){
		printf("\n ----- \n");
		printf("\nVacinas do laboratório: %s\n", laboratorio->nome);
		printf("\Total de Vacinas %d\n", laboratorio->vacinas.size());
		for(vacina = laboratorio->vacinas.begin() ; vacina != laboratorio->vacinas.end() ; vacina ++){
			printf("\nVacina: -> %d ", vacina->numeroVacina);
			printf("\nData Fabricação: %s", vacina->dataFabricacao);
			printf("\nData Validade: %s", vacina->dataValidade);
			printf("\nLaboratório: %s", laboratorio->nome);
			printf("\n");
		}
		printf("\n ----- \n");
	}
}

void exibirMenuListarVacinas(){

	printf("\n---------- Relatório Vacinas Produzidas----------\n");
	printf("1 - Exibir todas as vacinas \n");
	printf("2 - Busca Refinada \n");
	printf("3 - Listar Custo Total (Laboratórios)\n");
	printf("4 - Top Laboratórios (Ranking Geral)\n");
	printf("5 - Voltar \n");


	int valor = 0;
	printf("Opção: ");
	scanf("%d", &valor);

	switch (valor) {
		case 1:
		for(int i = 1 ; i <= 4 ; i ++){
			exibirVacinasFromLaboratorio(i);
		}
		exibirMenuListarVacinas();
		break;
		case 2:
		exibirMenuBuscaRefinada();
		break;
		case 3:
		exibirCustoTotalLaboratorio();
		exibirMenuListarVacinas();
		break;
		case 4:
		exibirTopLaboratorios();
		break;
		case 5:
		exibirMenu();
		break;
		default:
		printf("\n***** Opção Inválida *****\n");
		exibirMenuListarVacinas();
	}
}

void exibirTopLaboratorios(){

	int totalRitmo = 0;
	int totalBed = 0;
	int totalRaja = 0;
	int totalComp = 0;

	queue<Vacina> vacinasFila_temp = vacinasFila;
	while(!vacinasFila_temp.empty()){
		if(vacinasFila_temp.front().idLaboratorio == labBed.id){
			totalRitmo += 1;
		}else if(vacinasFila_temp.front().idLaboratorio == labRitmo.id){
			totalRitmo += 1;
		}else if(vacinasFila_temp.front().idLaboratorio == labRaja.id){
			totalRaja += 1;
		}else if(vacinasFila_temp.front().idLaboratorio == labComp.id){
			totalComp += 1;
		}

		vacinasFila_temp.pop();
	}

}

void exibirCustoTotalLaboratorio(){ //all

	float totalRitmo = 0.0;
	float totalBed = 0.0;
	float totalRaja = 0.0;
	float totalComp = 0.0;

	queue<Vacina> vacinasFila_temp = vacinasFila;
	while(!vacinasFila_temp.empty()){
		if(vacinasFila_temp.front().idLaboratorio == labBed.id){
			totalBed += precoVacinaUnid;
		}else if(vacinasFila_temp.front().idLaboratorio == labRitmo.id){
			totalRitmo += precoVacinaUnid;
		}else if(vacinasFila_temp.front().idLaboratorio == labRaja.id){
			totalRaja += precoVacinaUnid;
		}else if(vacinasFila_temp.front().idLaboratorio == labComp.id){
			totalComp += precoVacinaUnid;
		}

		vacinasFila_temp.pop();
	}

	printf("\n**** Custo Total por Laboratório ****\n");
	printf("\nRaja \n");
	printf(" -- Custo: R$ %.2f", totalRitmo);
	printf("\nComp \n");
	printf(" -- Custo: R$ %.2f", totalComp);
	printf("\nBed \n");
	printf(" -- Custo: R$ %.2f", totalBed);
	printf("\nComp \n");
	printf(" -- Custo: R$ %.2f\n\n", totalComp);
}


void exibirMenuBuscaRefinada(){
	printf("\n---------- Escolha a forma que deseja pesquisar ----------\n");
	printf("1 - Número da Vacina\n");
	printf("2 - Data de Fabricação \n");
	printf("3 - Data de Validade \n");
	printf("4 - Laboratório \n");
	printf("5 - Nome do Laboratório\n");
	printf("6 - Voltar \n");

	int valor = 0;
	printf("Opção: ");
	scanf("%d", &valor);
	//foi
	switch (valor) {
		case 1:
		buscarVacinaPorNumero();
		break;
		case 2:
		buscarVacinaPorDataFabricacao();
		break;
		case 3:
		buscarVacinaPorDataValidade();
		break;
		case 4:
		buscarVacinaPorLaboratorio();
		break;
		case 5:
		buscarVacinaPorNomeLaboratorio();
		break;
		case 6:
		exibirMenuListarVacinas();
		break;
		default:
		printf("\n***** Opção Inválida *****\n");
		exibirMenuBuscaRefinada();
	}

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
		exibirMenuEscolherLabProducao();
	}
}


//Implementação dos motores de
void buscarVacinaPorNumero(){

	printf("Digite número da vacina que deseja: ");

	int numeroVacina;
	scanf("%d", &numeroVacina);
	fflush(stdin);
	//split em C++
	//Faço para pegar a data, pois salva a data em outro struct

	int qntVacinasEncontradas = 0;
	queue<Vacina> vacinasFila_temp = vacinasFila;
	while(!vacinasFila_temp.empty()){
		if(vacinasFila_temp.front().numeroVacina == numeroVacina){

			Laboratorio lab;
			lab = buscarLaboratorioFromId(vacinasFila_temp.front().idLaboratorio);

			printf("\n -----");
			printf("\nVacina: -> %d ", vacinasFila_temp.front().numeroVacina);
			printf("\nData Fabricação: %s", vacinasFila_temp.front().dataFabricacao);
			printf("\nData Validade: %s", vacinasFila_temp.front().dataValidade);
			printf("\nLaboratório: %s\n", lab.nome);
			printf("\n");

			qntVacinasEncontradas += 1;
		}

		vacinasFila_temp.pop();
	}

	printf("\nEsta busca retornou %d resultados.\n", qntVacinasEncontradas);
	exibirMenuBuscaRefinada();
}

void buscarVacinaPorDataFabricacao(){

	printf("Digite a data desejada: ");

	char data[20];
	scanf("%s", &data);
	fflush(stdin);
	//split em C++
	//Faço para pegar a data, pois salva a data em outro struct

	int qntVacinasEncontradas = 0;
	queue<Vacina> vacinasFila_temp = vacinasFila;
	while(!vacinasFila_temp.empty()){
		if(strcmp (vacinasFila_temp.front().dataFabricacao, data) == 0){

			Laboratorio lab;
			lab = buscarLaboratorioFromId(vacinasFila_temp.front().idLaboratorio);

			printf("\n ----- \n");
			printf("\nVacina: -> %d ", vacinasFila_temp.front().numeroVacina);
			printf("\nData Fabricação: %s", vacinasFila_temp.front().dataFabricacao);
			printf("\nData Validade: %s", vacinasFila_temp.front().dataValidade);
			printf("\nLaboratório: %s\n", lab.nome);
			printf("\n");


			printf("\n ----- \n");

			qntVacinasEncontradas += 1;
		}

		vacinasFila_temp.pop();
	}

	printf("\nEsta busca retornou %d resultados.\n", qntVacinasEncontradas);
	exibirMenuBuscaRefinada();
}

void buscarVacinaPorDataValidade(){
	printf("Digite a data desejada: ");

	char data[20];
	scanf("%s", &data);
	fflush(stdin);
	//split em C++
	//Faço para pegar a data, pois salva a data em outro struct

	int qntVacinasEncontradas = 0;
	queue<Vacina> vacinasFila_temp = vacinasFila;
	while(!vacinasFila_temp.empty()){
		if(strcmp (vacinasFila_temp.front().dataValidade, data) == 0){

			Laboratorio lab;
			lab = buscarLaboratorioFromId(vacinasFila_temp.front().idLaboratorio);

			printf("\n ----- \n");
			printf("\nVacina: -> %d ", vacinasFila_temp.front().numeroVacina);
			printf("\nData Fabricação: %s", vacinasFila_temp.front().dataFabricacao);
			printf("\nData Validade: %s", vacinasFila_temp.front().dataValidade);
			printf("\nLaboratório: %s\n", lab.nome);
			printf("\n");

			printf("\n ----- \n");

			qntVacinasEncontradas += 1;
		}

		vacinasFila_temp.pop();
	}

	printf("\nEsta busca retornou %d resultados.\n", qntVacinasEncontradas);
	exibirMenuBuscaRefinada();
}

void buscarVacinaPorLaboratorio(){

}

void buscarVacinaPorNomeLaboratorio(){
	printf("Digite a nome do laboratório desejado: ");

	char nomeLaboratorioPesquisa[20];
	scanf("%s", &nomeLaboratorioPesquisa);
	fflush(stdin);
	//split em C++
	//Faço para pegar a data, pois salva a data em outro struct

	int qntVacinasEncontradas = 0;
	queue<Vacina> vacinasFila_temp = vacinasFila;
	while(!vacinasFila_temp.empty()){
		if(strcmp (vacinasFila_temp.front().nomeLaboratorio, nomeLaboratorioPesquisa) == 0){

			Laboratorio lab;
			lab = buscarLaboratorioFromId(vacinasFila_temp.front().idLaboratorio);

			printf("\n -----");
			printf("\nVacina: -> %d ", vacinasFila_temp.front().numeroVacina);
			printf("\nData Fabricação: %s", vacinasFila_temp.front().dataFabricacao);
			printf("\nData Validade: %s", vacinasFila_temp.front().dataValidade);
			printf("\nLaboratório: %s\n", lab.nome);
			printf("\n");

			qntVacinasEncontradas += 1;
		}

		vacinasFila_temp.pop();
	}

	printf("\nEsta busca retornou %d resultados.\n", qntVacinasEncontradas);
	exibirMenuBuscaRefinada();
}


//util
void limparTela(){
	system("clear");
}
