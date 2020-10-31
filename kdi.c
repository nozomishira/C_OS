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
     grand_child_pid2=fork();

   if(grand_child_pid2==-1){
     perror("fork");
     exit(EXIT_FAILURE);
   }else if(grand_child_pid2==0){
      printf("I am a grandchild with pid=%d. my parent pid is %d.\n",getpid(), getppid());
   }
      else{
      }
   }
}
   }else{
      printf("I am a parent with pid = %d. My parent pid is %d\n", getpid(),getppid());
   }


  exit(EXIT_SUCCESS);
}