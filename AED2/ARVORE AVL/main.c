#include <stdio.h>
#include <stdlib.h>



typedef int Cont;
typedef int Chave;

typedef struct noh {
	int bal;
	Chave chave;
	Cont conteudo;
	struct noh *pai;
	struct noh *esq;
	struct noh *dir;
} Noh;

typedef Noh *Arvore;

Arvore rotacaoDir(Arvore r) {
	Noh *aux;
	aux = r->esq;
	r->esq = aux->dir;
	if (aux->dir != NULL) aux->dir->pai = r;
	aux->dir = r;
	r->pai = aux;
	return aux; // nova raiz da subárvore
}

 Arvore rotacaoEsq(Arvore r) {
 	Noh *aux;
 	aux = r->dir;
	r->dir = aux->esq;
	if (aux->esq != NULL) aux->esq->pai = r;
	aux->esq = r;
	r->pai = aux;
	return aux; // nova raiz da subárvore
 }
 
 Noh *novoNoh(Chave chave, Cont conteudo) {
 Noh *novo;
 novo = (Noh *)malloc(sizeof(Noh));
 novo->bal = 0;
 novo->chave = chave;
 novo->conteudo = conteudo;
 novo->esq = NULL;
 novo->dir = NULL;
 novo->pai = NULL;
 return novo;
}
Arvore insereAVL(Noh *r, Noh *novo, int *aumentou_altura) {
 if (r == NULL) { // Caso 1: subárvore era vazia
 novo->pai = NULL;
 *aumentou_altura = 1;
 return novo;
 }
 if (novo->chave <= r->chave) { // desce à esquerda
 r->esq = insereAVL(r->esq, novo, aumentou_altura);
 r->esq->pai = r;
 if (*aumentou_altura == 1) { // altura da subárvore esquerda aumentou após inserção
 if (r->bal == +1) { // Caso 2: inseriu do lado mais baixo
 r->bal = 0;
 *aumentou_altura = 0;
 }
 else if (r->bal == 0) { // Caso 3: dois lados tinham a mesma altura
 r->bal = -1;
 *aumentou_altura = 1;
 }
 else if (r->bal == -1) { // inseriu do lado mais alto
 if (r->esq->bal == -1) { // Caso 4.1: inseriu à esquerda do filho esquerdo
 // rotação simples à direita
 r = rotacaoDir(r);
 r->dir->bal = 0;
 }
 else { // r->esq->bal == +1 - Caso 4.2: inseriu à direita do filho esquerdo
 // rotação dupla esquerda-direita
 r->esq = rotacaoEsq(r->esq);
 r = rotacaoDir(r);
 if (r->bal == 0) {
 r->esq->bal = 0;
 r->dir->bal = 0;
 }
 else if (r->bal == -1) {
 r->esq->bal = 0;
 r->dir->bal = +1;
 }
 else { // r->bal == +1
 r->esq->bal = -1;
 r->dir->bal = 0;
 }
 }
 r->bal = 0;
 *aumentou_altura = 0;
 }
 }
 }
 else {
 r->dir = insereAVL(r->dir, novo, aumentou_altura);
 r->dir->pai = r;
 if (*aumentou_altura == 1) { // altura da subárvore esquerda aumentou após inserção
 if (r->bal == -1) { // Caso 2: inseriu do lado mais baixo
 r->bal = 0;
 *aumentou_altura = 0;
 }
 else if (r->bal == 0) { // Caso 3: dois lados tinham a mesma altura
 r->bal = +1;
 *aumentou_altura = 1;
 }
 else if (r->bal == -1) { // inseriu do lado mais alto
 if (r->dir->bal == -1) { // Caso 4.1: inseriu à esquerda do filho esquerdo
 // rotação simples à direita
 r = rotacaoEsq(r);
 r->esq->bal = 0;
 }
 else { // r->esq->bal == +1 - Caso 4.2: inseriu à direita do filho esquerdo
 // rotação dupla esquerda-direita
 r->dir = rotacaoDir(r->dir);
 r = rotacaoEsq(r);
 if (r->bal == 0) {
 r->dir->bal = 0;
 r->esq->bal = 0;
 }
 else if (r->bal == -1) {
 r->dir->bal = 0;
 r->esq->bal = +1;
 }
 else { // r->bal == +1
 r->dir->bal = -1;
 r->esq->bal = 0;
 }
 }
 r->bal = 0;
 *aumentou_altura = 0;
 }
 }
 }
 return r;
}
Arvore inserir(Arvore r, Chave chave, Cont conteudo) {
 int aumentou_altura;
 Noh *novo = novoNoh(chave, conteudo);
 return insereAVL(r, novo, &aumentou_altura);
}

void main(){
	return;
}
