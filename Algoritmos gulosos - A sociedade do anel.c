#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 99999

int int_MAX = 9999999;

int **mat(int l, int c)
{
    int i = 0;
    int **mat = (int **)malloc(sizeof(int *) * l);
    for (i = 0; i < l; i++)
        mat[i] = (int *)malloc(sizeof(int) * c);
    return mat;
}

int aventura(int **mat, int lin, int col, int li, int ci, int lf, int cf, int X[], int Y[], int w)
{

    int l, c, i, laux = 0, caux = 0, soma=0;
    int aux = int_MAX;

    if (((li + 1) == lf) && ((ci + 1) == cf)){
        return 0;
    }
    else
    {

        for (i = 0; i < 4; i++)
        {

            l = li + X[i];
            c = ci + Y[i];
            if ((l >= 0) && (l < lin) && (c >= 0) && (c < col) && (mat[l][c] < aux))
            {
                aux = mat[l][c];
                laux = l;
                caux = c;
            }
        }


        if (aux != int_MAX)
        {
            mat[li][ci] = int_MAX;
            soma = aux + aventura(mat, lin, col,  laux, caux, lf, cf, X, Y, w);
            return soma;
        }
        else
        {
            w = 1;
            return MAX;
        }
    }
}

int main()
{

    int i = 0, j = 0;
    int l, c, li=0, ci=0, lf, cf, r, w=1;
    int *X = {0, 1, 0, -1};
    int *Y = {1, 0, -1, 0};

    scanf("%d %d", &l, &c);

    int **m = mat(l, c);

    for (i = 0; i < l; i++)
    {

        for (j = 0; j < c; j++)
        {

            scanf("%d", &m[i][j]);
        }
    }

    lf = l;
    cf = c;

    li = 0;
    ci = 0;

    r=aventura(m, l, c, li, ci, lf, cf, X, Y, w);
    if (r >= MAX){
        printf("sem solucao");
    }
    else
        printf("%d", r);


    return 0;
}
