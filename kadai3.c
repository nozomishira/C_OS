/*コメントアウトで説明をつけるとcygwinでエラーがでます。コメントアウト外すとコンパイル通ります.たぶん日本語が半角でないことが原因です*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int n=0;

void ctrlc(){
    printf("Ctrl-C pressede\n");
    n=0;
}

void alarmrecieved(){
    printf("SIGALRM recieved\n");
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

/*ctrl関数を作る
alarmrecieved関数でSIGALARMを受け取ったことを出力
19to25でエラー処理
２８でalarmをセット
30でpause
３２でexitする
*/