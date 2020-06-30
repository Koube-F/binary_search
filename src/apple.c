#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += (A[i] + m - 1) / m; //ceil(a/x)==floor((a+x-1)/x)
  }
  return sum <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; //絶対失敗
  ub = 1000000000; //絶対成功
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
