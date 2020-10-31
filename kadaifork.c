/*コメントアウトで説明をつけるとcygwinでエラーがでます。コメントアウト外すとコンパイル通りました.たぶん日本語が半角でないことが原因です*/

#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
  pid_t child_pid1, child_pid2, child_pid3;//三つの子供を宣言しておく
  child_pid1=fork();//プロセスを生成
  if(child_pid1==0){
    printf("I am a first child with pid=%d. my parent pid is %d.\n",getpid(), getppid());
  }else{
    child_pid2=fork();//プロセスを生成

    if(child_pid2==0){
      printf("I am a second child with pid=%d. My parent is %d.\n", getpid(),getppid());
    }else{
      child_pid3=fork();//プロセスを生成

    if(child_pid3==0){
      printf("I am a third child with pid = %d. My parent is %d.\n", getpid(),getppid());  
    }else{
      printf("I am a parent with pid = %d. My first, second and third children are %d and %d and %d.\n", getpid(), child_pid1,child_pid2, child_pid3);
    }
   }
  }
  exit(EXIT_SUCCESS);//exitする
}

