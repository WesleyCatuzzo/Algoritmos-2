#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5 // ordem da árvore

typedef struct NodeB NodeB;

NodeB* criar();

int liberar(NodeB *tree);

int pesquisar(int key, NodeB *tree);

int pesquisaSequencial(int key, NodeB *tree);


NodeB* inserir(NodeB *tree, int key);

struct NodeB{
     int nro_chaves;    // quantidade de chaves (elementos) na página
     int chaves[N - 1]; // Elementos da página
     NodeB *filhos[N];  // Referências para as próximas páginas
     int eh_no_folha;   // Verificar se a página é folha: onde as operações de inserção são realizadas
};


NodeB* criar(){
    NodeB *tree= malloc(sizeof(NodeB));
    int i;

    tree->eh_no_folha = 1;
    tree->nro_chaves = 0;

    for (i = 0; i < N; i++)
        tree->filhos[i] = NULL;

    return tree;
}

int liberar(NodeB *tree){
    if (tree != NULL){
        free(tree);

        return 1;
    }

    return 0;
}


int busca_binaria(int key, NodeB *tree){
    int ini, fim, meio;

    if (tree != NULL){
        ini = 0;
        fim = tree->nro_chaves - 1;

        while (ini <= fim){
            meio = (ini + fim) / 2;

            if (tree->chaves[meio] == key)
                return meio;
            else if (tree->chaves[meio] > key)
                fim = meio - 1;
            else
                ini = meio + 1;
        }


        return ini;
    }

    return -1;
}


int pesquisaSequencial(int key, NodeB *tree){
    int i;

    if (tree != NULL){
        for (i = 0; i < tree->nro_chaves && key < tree->chaves[i]; i++);

	if (key == tree->chaves[i])
        	return 1;
        else
        	return pesquisaSequencial(key, tree->filhos[i]);
    }

    return 0;
}


int pesquisar(int key, NodeB *tree){
    int pos = busca_binaria(key, tree);

    if (pos >= 0){
        if (tree->chaves[pos] == key)
            return 1;
        else
            return pesquisar(key, tree->filhos[pos]);
    }

    return 0;
}


NodeB * split_pag(NodeB *pai, int posF_cheio){
    int i;
    NodeB *pag_esq = pai->filhos[posF_cheio];
    NodeB *pag_dir;
    pag_dir = criar();
    pag_dir->eh_no_folha = pag_esq->eh_no_folha;


    pag_dir->nro_chaves = round((N - 1) / 2);


    for (i = 0; i < pag_dir->nro_chaves; i++)
        pag_dir->chaves[i] = pag_esq->chaves[i + pag_dir->nro_chaves];


    if (!pag_esq->eh_no_folha)
        for (i = 0; i < pag_dir->nro_chaves; i++)
            pag_dir->filhos[i] = pag_esq->filhos[i + pag_dir->nro_chaves];

    pag_esq->nro_chaves = (N - 1) / 2;


    for (i = pai->nro_chaves + 1; i > posF_cheio + 1; i--)
        pai->filhos[i + 1] = pai->filhos[i];


    pai->filhos[posF_cheio + 1] = pag_dir;
    pai->filhos[posF_cheio] = pag_esq;
    pai->chaves[posF_cheio] = pag_dir->chaves[0];
    pai->nro_chaves++;


    for (i = 0; i < pag_dir->nro_chaves ; i++)
        pag_dir->chaves[i] = pag_dir->chaves[i + 1];

    pag_dir->nro_chaves--;


    return pai;
}



 NodeB * inserir_pagina_nao_cheia(NodeB *tree, int key){
    int i;
    int pos = busca_binaria(key, tree);


    if (tree->eh_no_folha){

        for (i = tree->nro_chaves; i > pos; i--)
            tree->chaves[i] = tree->chaves[i - 1];


        tree->chaves[i] = key;


        tree->nro_chaves++;


    }else{
        if (tree->filhos[pos]->nro_chaves == N - 1){
            tree = split_pag(tree, pos);


            if (key > tree->chaves[pos])
                pos++;
        }


        tree->filhos[pos] = inserir_pagina_nao_cheia(tree->filhos[pos], key);

    }

    return tree;
}

NodeB * inserir(NodeB *tree, int key){
    NodeB *aux = tree;
    NodeB *nova_pag;

    if (aux->nro_chaves == N - 1){
        nova_pag = criar();
        tree = nova_pag;

        nova_pag->eh_no_folha = 0;
        nova_pag->filhos[0] = aux;
        nova_pag = split_pag(nova_pag, 0);
        nova_pag = inserir_pagina_nao_cheia(nova_pag, key);
        tree = nova_pag;
    }else
        tree = inserir_pagina_nao_cheia(aux, key);

    return tree;
}

int soma_paginas_folhas(NodeB *tree, int *qtd)
{
    int soma=0;
    int i=0;

    if(tree != NULL)
    {
        if (tree->eh_no_folha)
        {
            *qtd = *qtd + tree->nro_chaves;

            while(i<tree->nro_chaves)
            {
                soma = soma + tree->chaves[i];
                i++;
            }
        }
        else
            for (i = 0; i <= tree->nro_chaves; i++)
                soma += soma_paginas_folhas(tree->filhos[i], qtd);
    }

    return soma;
}


int media_paginas_folhas(NodeB *tree)
{
    int soma, qtd = 0;

    soma = soma_paginas_folhas(tree, &qtd);

    if (qtd > 0)
        return soma / qtd;
    else
        return 0;
}



int main(){

    int qtd_chaves;
    int i=0;
    int chaves;

    scanf("%d", &qtd_chaves);
    NodeB *tree= criar();
    while(i<qtd_chaves){
        scanf("%d", &chaves);
        tree=inserir(tree, chaves);
        i++;
    }

    printf("%d", media_paginas_folhas(tree));

    return 0;

}
