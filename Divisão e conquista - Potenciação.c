#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int potenciaDC(int a, int n){
  if (n == 0)
    return 1;
  else if (n == 1)
    return a;
  else
    if (n % 2 == 0)
      return potenciaDC(a, n / 2) * potenciaDC(a, n / 2);
    else
      return potenciaDC(a, (n - 1) / 2) * potenciaDC(a, (n - 1) / 2) * a;
}

int main() {

  int a,b;
  scanf("%d %d", &a, &b);
  printf("%d\n", potenciaDC(a, b));


  return 0;
}
