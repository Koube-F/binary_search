#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int man = 0; //何人目が働いているか
  int work = 0; //その人がこなした仕事量
  for(int i = 0; i < n; i++){ //各時間について繰り返す
    work += A[i]; //働く
    while(m < work){ //過労死していたら
      if(++man == k){ //次の人に交代
        return 0; //人を使いきったら失敗
      }
      work = A[i]; //前の人ができなかった仕事をする
      //もう一度判定
    } //ifとloopでwhile
  }
  return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; //絶対失敗
  ub = 1000000000; //k=1人がn=10**5時間全てa=10**4の仕事をさせられてもOK
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
