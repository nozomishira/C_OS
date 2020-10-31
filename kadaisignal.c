/*コメントアウトで説明をつけるとcygwinでエラーがでます。コメントアウト外すとコンパイル通りました.たぶん日本語が半角でないことが原因です*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int n=0;
pid_t pid;
void ctrlc(){
    // pid_t pid= pid1;
     printf("Ctrl-C pressed %d\n",++n);
     //if(n>0)
     //kill(pid, SIGUSR1);
      //if(m>0)
        //   kill(pid, SIGUSR1);
        if(n==10){
            printf("kill-child is termination\n");
            exit(EXIT_SUCCESS);
        }
         
   
        if(n>0)
          kill(pid, SIGUSR1); 
        

}

int main(){
    //pid_t pid;
    unsigned int c;
    if((pid=fork())==0){
        execl("kill-child", "kill-child",NULL);
        perror("excel");
        exit(EXIT_FAILURE);
    }
    if(signal(SIGINT, (void *)ctrlc)==SIG_ERR){
        execl("kill-child", "kill-child",NULL);
        perror("excel");
        exit(EXIT_FAILURE);
    }
    do{
        printf("Send signal ");
        while((c=getchar())!=EOF)
         if(c!='\n')
           break;
         // ctrlc(pid);
        //if(c!='y')
         // kill(pid, SIGUSR1);
        //// if(n>0)
          kill(pid, SIGUSR1); 
        
        //}
    }while(c!=EOF);
    exit(EXIT_SUCCESS);
 
    
   
    return 0;
}

/*
書きたいプログラムとしてはシグナルをctrlc関数に送りctrlcが押されたときにkillchildしてシグナルを受け取ったことを出力する
ｎをグローバル変数で宣言しｎが１０になったときにkill-child is terminationを出力する。エラー処理はmainのif文で行う
*/