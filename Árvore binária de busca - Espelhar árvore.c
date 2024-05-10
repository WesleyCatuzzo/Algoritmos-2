#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct No{
  int item;
  struct No *esquerda;
  struct No *direita;
}no;

typedef struct Arvore{
  no *raiz;
}arvore;

void inicializar(arvore* a){
  a->raiz = NULL;
}


no* criar(int item){
  no *novo = (no *) malloc (sizeof(no));

    if(novo == NULL){
    return NULL;
  }

  novo->item = item;
  novo->esquerda = novo->direita = NULL;
  return novo;
}

no* inserir(int item, no *raiz){

  if (raiz == NULL){
     return criar(item);
  }

  if(item > raiz->item){
     raiz->direita = inserir(item, raiz->direita);
  }

  else if (item < raiz->item){
      raiz->esquerda  = inserir(item, raiz->esquerda);
  }


  return raiz;

}

no * troca(int item, no* raiz){
    no *aux;
    aux = raiz->direita;
    raiz->direita = raiz->esquerda;
    raiz->esquerda = aux;
    return raiz;
}


no* inverte(int item, no* raiz){
    if (raiz !=NULL){
        troca(item, raiz);
        inverte(item, raiz->esquerda);
        inverte(item, raiz->direita);
    }
    return raiz;
}


void imprimearvoreinfix(no *raiz){

    if(raiz != NULL){
      imprimearvoreinfix(raiz->esquerda);
      printf("%d ", raiz-> item);
      imprimearvoreinfix(raiz->direita);
    }
}



int main() {

    int qtd_nos;
    scanf("%d",&qtd_nos);

    arvore *a = (arvore*) malloc (sizeof(arvore));
    inicializar(a);
    int i, p;
    scanf("%d",&p);
    a->raiz = inserir(p, a->raiz);

    for(i=1; i<qtd_nos; i++){
        scanf("%d",&p);
        inserir(p, a->raiz);
    }

    inverte(p, a->raiz);
    imprimearvoreinfix(a->raiz);


    return 0;

}
