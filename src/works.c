#include <stdio.h>

int n;
int k;
int A[100000];




int p(int x){
    int l = 0;
    int i = 0;
    while (i < n){
        if(l > k - 1) return 0;
        if (A[i] < x){
            int j = 1;
            int B = A[i] + A[i+j];
            while (i < n ){
                if (i + j > n - 1) {
                    i ++;
                    break;
                }                
                else if(B < x){
                    B = B + A[j+1];
                    j++;
            }
                else if (B == x){
                     i = i + j +1;
                    l++;
                    break;
            }
                else {
                    i = i + j;
                    l++;
                    break;
            }
            }
        }
        else if (A[i] == x){
            if (i < n-1){
                i ++;
                l++;
            }
            else {
                i ++;
            }
        }
        else return 0;
  }
  if (l <= k -1 ) return 1;
  else return 0;
  }


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int sigma = 0;
  for (i = 0; i < n; i++){
    sigma = sigma + A[i];
  }
  lb = 0;
  ub = sigma;
  while(ub - lb > 1) {
        int m = (lb + ub) / 2;
        if (p(m)) ub = m;
        else lb = m;
    }
    printf("%d\n", ub);
  return 0;
}
