#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = -1;
  ub = n;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  if (A[n-1] < k)  printf("%d\n", n);
  else {
    while(ub - lb > 1) {
        int m = (lb + ub) / 2;
        if (A[m] >= k) ub = m;
        else lb = m;
    }
    printf("%d\n", ub);
}
  return 0;
}
