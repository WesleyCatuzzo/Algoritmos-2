#include <stdio.h>
#include <stdlib.h>

typedef struct GrafoMA GrafoMA;


GrafoMA* iniciar_grafoMA(int v);

int aresta_existe(GrafoMA* G, int v1, int v2);

void inserir_aresta(GrafoMA* G, int v1, int v2);

void remover_aresta(GrafoMA* G, int v1, int v2);

void imprimir_arestas(GrafoMA* G);

void liberarGMA(GrafoMA* G);


struct GrafoMA{
   int V; // numero de vertices
   int A; // numero de arestas
   int **mat;
};

 int** iniciar_MA(int n){
    int i, j;
    int **mat = (int**) malloc(n * sizeof(int*));

    for (i = 0; i < n; i++)
        mat[i] = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mat[i][j] = 0;

    return mat;
}


int valida_vertice(GrafoMA* G, int v){
    return (v >= 0) && (v < G->V);
}


GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));

    G->V = v;
    G->A = 0;
    G->mat = iniciar_MA(G->V);

    return G;
}


int aresta_existe(GrafoMA* G, int v1, int v2){
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] == 1);
}


void inserir_aresta(GrafoMA* G, int v1, int v2){
    if ((G != NULL) && (valida_vertice(G, v1)) && (valida_vertice(G, v2)) && (!aresta_existe(G, v1, v2))){
        G->mat[v1][v2] = G->mat[v2][v1] = 1;
        G->A++;
    }
}

void remover_aresta(GrafoMA* G, int v1, int v2){
    if ((G != NULL) && (valida_vertice(G, v1)) && (valida_vertice(G, v2)) && (aresta_existe(G, v1, v2))){
        G->mat[v2][v1] = G->mat[v1][v2] = 0;
        G->A--;
    }
}

void imprimir_arestas(GrafoMA* G){
    int i, j;

    for (i = 1; i < G->V; i++)
        for (j = 0; j < i; j++)
            if (G->mat[i][j] == 1)
                printf("(%d, %d)\n", i, j);
}


void liberarGMA(GrafoMA* G){
    if (G != NULL){
        free(G->mat);
        free(G);
    }
}


void direcionado_em_ndirecionado(int n){

    int i, j, matriz_adjacencia[n][n];

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf(" %d",&matriz_adjacencia[i][j]);                 //LENDO A MATRIZ DE ADJACENCIA, GRAFO ORIENTADO
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {                                                                  // UM GRAFO NAO ORIENTADO EH SIMETRICO
            if(matriz_adjacencia[i][j]==1 && matriz_adjacencia[j][i]==0)  //se na posiçao da matriz[i][j] (exemplo:[2][3]) tiver o numero 1
            {                                                             // e seu simetrico [3][2] tiver o numero 0, entao deve ser feita a substituiçao para que mantenha a simetria
                matriz_adjacencia[j][i]=1;
            }
        }
    }
    printf("\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",matriz_adjacencia[i][j]);   //PRINTANDO A MATRIZ APOS AS ALTERACOES
        }
        printf("\n");
    }


}


int main(){

    int n;
    scanf("%d",&n);

    direcionado_em_ndirecionado(n);


    return 0;

}



