#include <stdio.h>

int n;
int k;
int A[100000];




int p(int x){ /*最大の仕事量がx以下であれば  １を返す。*/
    int l = 0;  /*分割数*/
    int i = 0;
    while (i < n){
        if (A[i] < x){  /*1要素がx以下なら*/
            int j = 1;
            int B = A[i] + A[i+j];  /*次の要素との和*/
            while (i < n ){
                if (i + j > n - 1) {  /*A[i+j]が存在するか判定*/
                    i = i + j + 1;
                    break;
                }
                else if(B < x) {  /*和がx以下であれば次の要素をさらに加える*/
                    B = B + A[i+j+1];/*ここが間違いでした。*/
                    j++;
            }
                else if (B == x){ /*和がxならば*/
                     i = i + j +1;  /*A[i]を次の要素に置きかえる*/
                     if (i < n){  /*A[i]が存在すれば、分割数を1増やす*/
                       l++;
                       break;
                     }
                     else break;  /*A[i]が存在しないなら、分割数を増やさずにループから抜ける*/
            }
                else {  /*和がxより大きければ分割数を1増やし、A[i+j]をA[i]に置き換える*/
                    i = i + j;
                    l++;
                    break;
            }
            }
        }
        else if (A[i] == x){
            if (i < n-1){ /*A[i]が最後の要素でないなら、分割数を1増やして次の要素をみる。*/
                i ++;
                l++;
            }
            else {  /*A[i]が最後の要素ならば、分割数は増やさない*/
                i ++;
            }
        }
        else return 0;
  }
  if (l <= k -1 ) return 1; /*分割数が人数ー１以下ならば成功*/
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
