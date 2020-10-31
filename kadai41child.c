#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    int code;
    if (argc<=1){
       fprintf(stderr,"NO argument.\n");
       exit(EXIT_FAILURE);
    }
    code=system(argv[1]);
    if(code==1){
        perror("system");
        exit(EXIT_FAILURE)
    }else{
        fprintf(stderr,"Call %s is terminated with %x\n",argv[1],code);
        exit(EXIT_SUCCESS);
    }
    
}

