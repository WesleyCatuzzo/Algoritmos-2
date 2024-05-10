#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int MA[10][10],visite[10],nVertices;

void Busca_em_Largura(int i)
{
    int j;
    printf("\n%d",i);
    visite[i]=1;
    for(j=0; j<nVertices; j++)
        if(!visite[j]&& MA[i][j]==1)
            Busca_em_Largura(j);
}

void main()
{
    int i,j;

    scanf("%d",&nVertices);

    for(i=0; i<nVertices; i++)
        for(j=0; j<nVertices; j++)
            scanf("%d",&MA[i][j]);


}
