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

  if(novo == NULL)
  {
    return NULL;
  }

  novo->item = item;
  novo->esquerda = novo->direita = NULL;
  return novo;
}

no* inserir(int item, no *raiz){

  if (raiz == NULL)
    return criar(item);
  if (item < raiz->item)
    raiz->esquerda  = inserir(item, raiz->esquerda);
  else if(item > raiz->item)
    raiz->direita = inserir(item, raiz->direita);


  return raiz;

}


int somaNosFolhas(no *raiz){
    int soma=0;

    if(raiz == NULL){
       return 0;
    }
    if((raiz->direita==NULL)&&(raiz->esquerda==NULL)){
        return soma=soma+raiz->item;
    }
    return somaNosFolhas(raiz->direita) + somaNosFolhas(raiz->esquerda);

}


int main(){


    int qtd_nos;
    int i, item;
    scanf("%d",&qtd_nos);
    scanf("%d",&item);

    arvore *a = criar(item);
    inicializar(a);

    a->raiz = inserir(item, a->raiz);

    for(i=1; i<qtd_nos; i++){
        scanf("%d",&item);
        inserir(item, a->raiz);
    }


    printf("%d", somaNosFolhas(a->raiz));

    return 0;
}
