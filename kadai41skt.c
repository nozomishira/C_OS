#include <sys/types.h>//library から読み取る
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define SOCKET_NAME "/tmp/my_socket"

int main(){
int fd1;
int cint,size;
char c;
int count1;
struct sockaddr_un server;

if((fd1=socket(PF_UNIX,SOCK_STREAM,0))==-1){
    perror("socket");//err出力
   exit(EXIT_FAILURE);
}
memset(&server,0,sizeof(struct sockaddr_un));//ある一定のバイトでメモリ領域を埋める　ゼロリセット
server.sun_family = AF_UNIX;
memcpy(server.sun_path, SOCKET_NAME ,//メモリ領域のコピー
sizeof(SOCKET_NAME));

if(connect(fd1,(struct sockaddr *)&server,sizeof(struct sockaddr_un))==-1){
   perror("connect");//err出力
    exit(EXIT_FAILURE);
}

/*if((size=write(fd1,&count1,sizeof(int)))==-1){
    perror("write");
     exit(EXIT_FAILURE);
}else */
   if((size=read(fd1,&count1,sizeof(int)))==-1){//クライアントからのデータを受信
    perror("read");//err出力
      exit(EXIT_FAILURE);
    }else if(size==4)
    printf("count is %d",count1);

  
    close(fd1);//closeする
    exit(EXIT_SUCCESS);
}
