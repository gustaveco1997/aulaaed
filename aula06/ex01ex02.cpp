#include <stack>
#include <iostream>

using namespace std;

void imprime_pilha(stack<int> pilha){
	printf("\nPilha:\n");
	while(!pilha.empty()){
		printf("%d \n", pilha.top());
		pilha.pop();
	}

	printf("\n");
}

int main(){
	stack<int> minha_pilha;
	for(int i = 0 ; i < 100 ; i ++){
		minha_pilha.push((rand() % 100) + 1);
	}

	imprime_pilha(minha_pilha);
}