/*コメントアウトで説明をつけるとcygwinでエラーがでます。コメントアウト外すとコンパイル通りました.たぶん日本語が半角でないことが原因です*/
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
  pid_t child_pid1,  grand_child_pid2; 
   int status;

   child_pid1=fork();　

   if(child_pid1==-1){
     perror("fork");
     exit(EXIT_FAILURE);
   }else if(child_pid1==0){
     printf("I am a child with pid=%d. my parent pid is %d.\n",getpid(), getppid());
     exit(EXIT_SUCCESS); 
     
   }
    grand_child_pid2=fork(); 

   if(grand_child_pid2==-1){
     perror("fork");
     exit(EXIT_FAILURE);
   }else if(grand_child_pid2==0){
      printf("I am a grandchild with pid=%d. my parent pid is %d.\n",getpid(), child_pid1);
      exit(EXIT_SUCCESS);　
   }else{
      printf("I am a parent with pid = %d. My child is %d.My grandchild id %d\n", getpid(),child_pid1, grand_child_pid2);
      exit(EXIT_SUCCESS);　
   }


}

/*
child_pid1,  grand_child_pid2; を宣言する

// getpid と　getppid でidを出力していく

grand_child_pid2=fork(); でプロセスを生成していく

かくif文でエラー処理を行ってgetpid(),child_pid1, grand_child_pid2で出力していく
*/