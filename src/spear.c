#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  int max = 0;
  for (i = 0; i < n; i++){
    if (A[i] > max) max = A[i];
  }
  lb = 0;
  ub = max;
  
  while (ub - lb > 1) {
    int m = (lb + ub) /2;
    int i, sigma = 0;
    for (i = 0; i < n; i++) {
        sigma = sigma + A[i]/m;
  }
    if (sigma >= k) lb = m;
    else ub = m;
}
printf("%d\n", lb);
  


  return 0;
}
