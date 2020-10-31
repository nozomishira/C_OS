#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *func(void *arg){
time_t now;
struct tm *tmnow;
//char a;

  while(1){
    now = time(NULL);
    tmnow=localtime(&now);
    
    printf("\r%02d:%02d:%02d",tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec);

    fflush(stdout);
  }
  //a=getc(stdin);
    return NULL;
}

int main(){
pid_t pid;
pthread_t thread_id;
 

pid=getpid();
//printf("main: pid=%d\n",pid);
  /*if((a=getc(stdin))!="\n"){
    exit(EXIT_SUCCESS);
  }*/

if(pthread_create(&thread_id,NULL,func,NULL) !=0){
    perror("pthread_create");
    exit(EXIT_FAILURE);
}

/*if((getc(stdin))=='\n'){
    exit(EXIT_SUCCESS);
  }*/
pthread_join(thread_id,NULL);
    exit(EXIT_SUCCESS);

    if((getc(stdin))=='\n'){
    exit(EXIT_SUCCESS);
  }
}