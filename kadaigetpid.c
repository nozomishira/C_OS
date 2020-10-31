/*コメントアウトで説明をつけるとcygwinでエラーがでます。コメントアウト外すとコンパイル通ります.たぶん日本語が半角でないことが原因です*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


int n=0;　

void ctrlc(){　
     //int n=0;
    //printf("Ctrl-C pressed %d time \n",++m);
    printf("Ctrl-C pressed \n");
    //m=m-1;
    //if(m==1){
        //printf("SIGALARM has reset.\n");
         // n=0;
          // exit(EXIT_SUCCESS);
     
    //}
    n=0;　
}

void alarmrecieved(){
    ++n;
    printf("SIGALRM recieved \n");
}


int main(){
    if(signal(SIGALRM, (void *)alarmrecieved)==SIG_ERR){　
        perror("signal");
        exit(EXIT_FAILURE);
    }
    if(signal(SIGINT, (void *)ctrlc)==SIG_ERR){　　
        perror("signal");
        exit(EXIT_FAILURE);
    }
     while(n<3){
    alarm(5);　　
    printf("Alarm has set\n");
    pause();　
     }
    
     exit(EXIT_SUCCESS);　　

     
    
    
}

