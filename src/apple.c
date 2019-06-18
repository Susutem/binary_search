#include <stdio.h>

int n;
int k;
int A[100000];




int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = 0;
  ub = 100000;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
while (ub - lb > 1) {
    int m = (lb + ub) /2;
    int i, sigma = 0;
    for (i = 0; i < n; i++) {
        sigma = sigma + (A[i] + m -1) /m;
  }
    if (sigma <= k) ub = m;
    else lb = m;
}
printf("%d\n", ub);
  return 0;
}
