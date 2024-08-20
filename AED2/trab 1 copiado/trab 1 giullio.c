#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct comp {
  int valor;
  char *chave;
} comp;

typedef struct hash {
  comp Comp;
  struct hash *dir, *esq;
} hash;

hash *criar(comp comp) {
  hash *lul = (hash *)malloc(sizeof(hash));
  lul->Comp = comp;
  lul->dir = lul->esq = NULL;
  return lul;
}

hash *adc(hash *raiz, comp comp) {
  if (raiz == NULL)
    return criar(comp);
  if (strcmp(raiz->Comp.chave, comp.chave) > 0)
    raiz->dir = adc(raiz->dir, comp);
  else if (strcmp(raiz->Comp.chave, comp.chave) < 0)
    raiz->esq = adc(raiz->esq, comp);

  return raiz;
}

int buscar(hash *raiz, char *chave) {
  if (raiz == NULL)
    return -10;
  if (strcmp(raiz->Comp.chave, chave) == 0)
    return raiz->Comp.valor;
  else if (strcmp(raiz->Comp.chave, chave) > 0)
    return buscar(raiz->dir, chave);
  else
    return buscar(raiz->esq, chave);
}

int main(void) {
  int N, M;
  hash *raiz = NULL;
  scanf("%d %d\n", &N, &M);
  while (N>0) {
    comp comp;
    comp.chave = (char *)malloc(sizeof(char) * 100);
    comp.valor = 0;
    scanf("%s %d\n", comp.chave, &comp.valor);
    raiz = adc(raiz, comp);
    N--;
  }
  while (M>0) {
    int Nota, i;
    Nota = i = 0;
    char *palavra = (char *)malloc(sizeof(char) * 100);
    char caractere;

    while ((caractere = getchar())) {
      if (caractere == '.')
        break;
      if (isspace(caractere)) {
        if (i == 0)
          continue;
        palavra[i] = 0;
        Nota = Nota + buscar(raiz, palavra);
        i = 0;
        continue;
      }
      palavra[i+1] = caractere;
    }
    printf("%d\n", Nota);
    M--;
  }
}
