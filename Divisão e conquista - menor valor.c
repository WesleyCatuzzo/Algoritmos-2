#include <stdio.h>
#include <string.h>
#include <math.h>
#define min(a, b) a < b ? a : b //passado em aula (como se fosse um if else)

int menor(int v[], int ini, int fim){
    int m, a, b;

    if ((fim - ini) <= 1)
        return v[ini] < v[fim] ? ini : fim;  //se v[ini] é menor que o v[fim] entao retorna ini, senão retorna fim
    else{
        m = (ini + fim) / 2;
        a = menor(v, ini, m);
        b = menor(v, m + 1, fim);
    }


    return v[a] < v[b] ? v[a] : v[b];

}


int main(){
    int tam;
    int i;

    scanf("%d", &tam);

    int vetor[tam];
    for(i=0; i<tam; i++)
    {
        scanf("%d", &vetor[i]);
    }


    printf("%d", menor(vetor, 0, tam-1));


    return 0;
}
