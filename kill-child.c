#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void siguser(void){
    static int n=0;
    printf("Signal recieved %d time \n",++n);
    if(n==10){
        printf("kill-child is termination\n");
        exit(EXIT_SUCCESS);
    }
}

int main(){
    if(signal(SIGUSR1, (void *)siguser)==SIG_ERR){
        perror("signal");
        exit(EXIT_FAILURE);
    }
    for(;;){}
}