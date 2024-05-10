#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define max(a, b) a > b ? a : b

int mochila_binariaBT(int capacidade, int *peso, int *valor, int x)
{
   if(x < 0)
        return 0;
   if(peso[x]> capacidade)
        return mochila_binariaBT(capacidade, peso, valor, x-1);
   else
        return max(mochila_binariaBT(capacidade, peso, valor, x-1), valor[x]+ mochila_binariaBT(capacidade-peso[x], peso, valor, x-1));

}


int main()
{
    int capacidade_mochila, num_objetos, i;
    scanf("%d", &capacidade_mochila);
    scanf("%d", &num_objetos);

    int peso[num_objetos], valor[num_objetos];


    while(i<num_objetos)
    {
        scanf("%d %d", &peso[i], &valor[i]);
        i++;
    }

    printf("%d\n", mochila_binariaBT(capacidade_mochila, peso, valor, num_objetos-1));


    return 0;
}
