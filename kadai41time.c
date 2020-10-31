#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

void end(void){
  exit(EXIT_SUCCESS);
}

void *func(void){
time_t now;
struct tm *tmnow;

if(signal(SIGUSR1, (void*)end)==SIG_ERR){//シグナルを受け取る
  perror("signal");//err処理
  exit(EXIT_FAILURE);
}

  while(1){
    now = time(NULL);
    tmnow=localtime(&now);
    
    printf("\r%02d:%02d:%02d",tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec);

    fflush(stdout);
    sleep(1);//sleepする
  }
  //a=getc(stdin);
    return NULL;
}

int main(){
pid_t pid;

//pid=getpid();
//fork();

if((pid=fork())==-1){//forkしてpidに代入した値が－１を返す時エラー出力
  perror("fork");
  exit(EXIT_FAILURE);
}else if(pid==0){
  func();//func関数を呼び出す
}
else{

if((getc(stdin))=='\n'){
    kill(pid, SIGUSR1);//childをkillする
    exit(EXIT_SUCCESS);//err出力
  }
}
  
}



