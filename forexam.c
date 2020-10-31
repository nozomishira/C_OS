#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main(){
pid_t pid;
unsigned int c;
if((pid=fork())==0){
execl("kill-child","kill-child",NULL);
perror("execl");
exit(EXIT_FAILURE);
}
do{
printf("Send signal (y/n)? ");
while((c=getchar())!=EOF)
if(c!='\n')
break;
if(c=='y')
kill(pid,SIGUSR1); printf("killed");
} while(c!=EOF);
return 0;
}