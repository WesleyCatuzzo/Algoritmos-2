#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int pilha[200];
int pri, ult;

int pop(int n, int key[n])
{

    int min = 99999, i, j;

    i = pri;
    while(i < ult && key[i] > min)
    {
        i++;
    }

    int vertice;
    vertice = pilha[i];

    if(i != pri && i != ult)
    {
        for ( j = i; j < ult; j++)
        {
            pilha[j] = pilha[j + 1];
        }
        ult--;
    }
    if(i == pri)
        pri++;
    if(i == ult)
        ult--;

    return vertice;
}

void criarPilha(){
    pri=ult=0;
}

int vazio(void){
    if(pri==ult)
        return 0;
    else
        return 1;
}


void Prim(int n, int MA[n][n])
{

    int pai[n], key[n], i, v;

    i=0;
    while (i<n)
    {
        pai[i] = 0;
        key[i] = 99999;
        i++;
    }
    key[0] = 0;
    criarPilha();

    i=0;
    while (i<n)
    {
        pilha[ult++] = i;
        i++;
    }

    int j;
    while(vazio() != 0)
    {
        v = pop(n, key);

        i=0;
        while(i<n)
        {
            if (MA[v][i] != 0)
            {
                if(MA[v][i] < key[i])
                {
                    for ( j = pri; j < ult; j++)
                    {
                        if(pilha[j] == i)
                        {
                            pai[i] = v;
                            key[i] = MA[v][i];
                        }
                    }

                }
            }
            i++;
        }
    }

    printf("0: -\n");
    i=1;
    while(i < n)
    {
        printf("%d: %d\n", i, pai[i]);
        i++;
    }
}

int main()
{

    int i=0, j=0, nVertices;
    scanf(" %d",&nVertices);


    int MA[nVertices][nVertices];
    while(i<nVertices)
    {
        j=0;
        while(j<nVertices)
        {
            scanf(" %d",&MA[i][j]);
            j++;
        }
        i++;
    }

    Prim(nVertices, MA);

    return 0;
}
