#include <stdio.h>
#include <stdlib.h>
 
typedef struct TreeNode {
    int data; 
    struct TreeNode* esquerda, *direita; 
    int eh_folha; 
}TreeNode;
 
TreeNode* cria(int data) {
    TreeNode* node = (TreeNode*) calloc (1, sizeof(TreeNode));
    node->data = data;
    node->esquerda = node->direita = NULL;
    node->eh_folha = 1;
    return node;
}
 
TreeNode* insere(TreeNode* raiz, int data) {
    if (!raiz) {
        raiz = cria(data);
        return raiz;
    }
    else {
        TreeNode* node = cria(data);
        TreeNode* temp = raiz;
        while (temp) {
            if (temp->eh_folha) {
                if (temp->data > data) {
                    temp->esquerda = node;
                    temp->eh_folha = 0;
                    break;
                }
                else {
                    temp->direita = node;
                    temp->eh_folha = 0;
                    break;
                }
            }
            else {
                if (temp->data > data) {
                    if (temp->esquerda == NULL) {
                        temp->esquerda = node;
                        break;
                    }
                    temp = temp->esquerda;
                }
                else {
                    if (temp->direita == NULL) {
                        temp->direita = node;
                        break;
                    }
                    temp = temp->direita;
                }
            }
        }
    }
    return raiz;
}

int esta_na_arvore(TreeNode* raiz, int valor) {
    if (!raiz)
        return 0;
    if (raiz->data == valor)
        return 1;
    else if (raiz->data > valor)
        return esta_na_arvore(raiz->esquerda, valor);
    else
        return esta_na_arvore(raiz->direita, valor);
    return 0;
}
 
void destroi(TreeNode* raiz) {
    if (!raiz)
        return;
    destroi(raiz->esquerda);
    destroi(raiz->direita);
    free(raiz);
}
 
void print_EnA(TreeNode* raiz, int valor) { //printa se esta na arvore
    if (esta_na_arvore(raiz, valor) == 1) {
        printf("Value: %d esta na arvore!\n", valor);
    }
    else {
        printf("Value: %d nao esta na arvore.\n", valor);
    }
}
 
void imprime_todos(TreeNode* raiz) { //printa a arvore
    if (!raiz)
        return;
    imprime_todos(raiz->esquerda);
    printf("Node: %d -> ", raiz->data);
    imprime_todos(raiz->direita);
}

int soma(TreeNode* raiz)
{
    if (raiz == NULL)
        return 0;
    return (raiz->data + soma(raiz->esquerda) + soma(raiz->direita));
}
 
int main() {
    TreeNode* raiz = cria(45);
    raiz = insere(raiz, 20);
    raiz = insere(raiz, 15);
    raiz = insere(raiz, 60);
    raiz = insere(raiz, 40);
    raiz = insere(raiz, 50);
    raiz = insere(raiz, 70);
    imprime_todos(raiz);
    printf("\n");
    int sum = soma(raiz);
    printf("soma: %d ",sum);
    printf("\n");
    print_EnA(raiz, 15);
    print_EnA(raiz, 70);
    print_EnA(raiz, 35);
    destroi(raiz);
    return 0;
}
