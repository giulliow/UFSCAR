#include "Pilha.h"

void empilhar(struct pilha *pilha, int elem, bool *check){
	int j = tam - 1;//variavel da posicao do topo da pilha (tamanho menos um)
	if(pilha->topo == j){//verifica se existe espaco para empilhar
		*check = false;
	}
	else{
		pilha->topo++;//aumenta a posicao do topo
		pilha->num_elementos[pilha->topo] = elem;//add o elemento novo no topo
		*check = true;
	}
}

void desempilhar(struct pilha *pilha, int *elem, bool *check){
	if(pilha->topo < 0){//verifica se existe algum elemento para desempilhar
		*check = false;
	}
	else{
		*elem = pilha->num_elementos[pilha->topo];//retira o elemento e armazena na variavel
		pilha->num_elementos[pilha->topo] = 0;//elimina o topo
		pilha->topo--;//diminui uma posicao no topo
		*check = false;
	}
	
}

void criar(struct pilha *pilha){//criando uma pilha com o topo em -1, significa que esta vazia
	pilha->topo = -1;
}

bool vazia(struct pilha *pilha){
	if(pilha->topo > 0){//verifica se o topo eh menor que 0 (pilha vazia)
		return true;
	}
	else{
		return false;
	}
}

bool cheia(struct pilha *pilha){
	int k = tam -1;//variavel da posicao do topo da pilha (tamanho menos um)
	if(pilha->topo == k){//verifica se o topo atingiu o tamanho da pilha(pilha cheia)
		return true;
	}
	else{
		return false;
	}
}
