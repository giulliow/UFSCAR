#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define tam 10

struct pilha//base da pilha
{
	int num_elementos[tam];
	int topo;

};

//funcao para empilhar um elemento na pilha
void empilhar(struct pilha *pilha, int elem, bool *check );

//funcao para desempilhar um elemento da pilha
void desempilhar(struct pilha *pilha, int *elem, bool *check);

//funcao para criar a pilha
void criar(struct pilha *pilha);

//funcao para checar se a pilha esta vazia
bool vazia(struct pilha *pilha);

//funcao para checar se a pilha esta cheia
bool cheia(struct pilha *pilha);



