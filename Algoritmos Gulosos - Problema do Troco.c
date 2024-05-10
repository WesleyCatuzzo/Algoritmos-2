#include <stdio.h>
#include <stdlib.h>

void seq_moedas(int troco, int n)
{
    int i = 0, j = 0;
    int aux;
    int moedas[n];

    while (i<n)
    {
        scanf("%d", &moedas[i]);
        i++;
    }

    while (troco > 0)
    {
        aux = troco + 1;
        for (i = 0; i < n; i++)
        {
            if(troco/moedas[i]>0 && troco/moedas[i]<= aux)
            {
                aux = troco/moedas[i];
                j=i;
            }
        }
        for (i = 0; i < aux; i++)
        {
            printf("%d\n",moedas[j]);
        }
        troco = troco - moedas[j]*aux;
    }

}

int main()
{
  int troco;
  int n;

  scanf("%d",&troco);
  scanf("%d",&n);

  seq_moedas(troco, n);


  return 0;
  }
