#include <stdio.h>

int main(){
    int A[8] = {7,2,3,4,8,1,5,6};
    int n = 8;
    int j=n;
    int i;
while(i<7){　　　//iが７より小さい間でループを回す
    while(j-1>i){
        if(A[j-1]<A[j-2]){
            int a=A[j-1];
            A[j-1]=A[j-2];　　//A[j-1]をA[j-2]を交換
            A[j-1]=a;     //aに代入　　　
            j--; 
    for(j=0;j<8;j++){
      printf("%d",A[j]);　　//出力
    }
     printf("\n");
        }else j=j-1;
    }i++;
}
    
}

実行結果
白石望@DESKTOP-DU1O254 ~/a
$ ./kadai1
72341856
72341586
72341568
72314568
72134568
71234568
17234568
12734568
12374568
12347568
12345768
12345678

白石望@DESKTOP-DU1O254 ~/a
