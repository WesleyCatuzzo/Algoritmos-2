#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int pilha[200];
int pri, ult;

int pop(int n, int key[n])
{

    int min = 99999, i, j, i2 = pri;

    i = pri;
    while(i < ult)
    {
        if(key[pilha[i]] < min)
        {
            min = key[i];
            i2= i;
        }
        i++;
    }

    int vertice;
    vertice = pilha[i2];

    if(i2 != pri && i2 != ult)
    {
        for (j = i2; j < ult; j++)
        {
            pilha[j] = pilha[j + 1];
        }
        ult--;
    }
    if(i2 == pri)
        pri++;
    if(i2 == ult)
        ult--;

    return vertice;
}


void criarPilha(){
    pri=ult=0;
}

int vazio(void){
    if(ult < pri)
        return 0;
    else
        return 1;
}


void Dijkstra(int n, int MA[n][n])
{

    int pai[n], key[n], i, v;

    i=0;
    while(i<n)
    {
        pai[i] = 0;
        key[i] = 99999;
        i++;
    }
    key[0] = 0;
    criarPilha();

    i=0;
    while(i<n)
    {
        pilha[ult++]=i;
        i++;
    }

    while(vazio()!=0)
    {
        v = pop(n, key);
        i=0;
        while(i<n)
        {
            if (MA[v][i] != 0)
            {
                if(key[i] > key[v] + MA[v][i])
                {
                    pai[i] = v;
                    key[i] = key[v] + MA[v][i];

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

int main(void)
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

    Dijkstra(nVertices, MA);

    return 0;
}
