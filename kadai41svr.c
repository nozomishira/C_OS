#include <sys/types.h> //リブラアリーから読み取る
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#define SOCKET_NAME "/tmp/my_socket"

int main(){
int fd1,fd2,size;
int count=0;
char c;
struct sockaddr_un server,client;
int clientlen=sizeof(struct sockaddr_un);
if((fd1=socket(PF_UNIX,SOCK_STREAM,0))==-1){ //エラー出力
    perror("socket");
    exit(EXIT_FAILURE);
}
memset(&server,0,sizeof(struct sockaddr_un));//ある一定のバイトでメモリ領域を埋める　ゼロリセット
server.sun_family = AF_UNIX;
memcpy(server.sun_path,SOCKET_NAME,sizeof(SOCKET_NAME));//メモリ領域のコピー


unlink(SOCKET_NAME);
if(bind(fd1,(struct sockaddr*)&server,sizeof(server))==-1){ //エラー出力
     perror("bind");//エラー出力
     exit(EXIT_FAILURE);
}
if(listen(fd1,1)==-1){ // 接続要求の受け入れ準備
    perror("listen");//エラー出力
    exit(EXIT_FAILURE);
}
for(;;){
    count++;
memset(&client,0,sizeof(struct sockaddr_un));

if((fd2=accept(fd1,(struct sockaddr*)&client,&clientlen))==-1){//接続要求の許可
    perror("accept");//err出力
    exit(EXIT_FAILURE);
    
}


/*if((size=read(fd2,&count,sizeof(int)))==-1){
    perror("read");
   exit(EXIT_FAILURE);
 }else if(size==1){
   if(islower(c))
    c=toupper(c);
 else if(isupper(c))
    c=tolower(c);*/
  if(write(fd2,&count,sizeof(int))==-1){//socketを通じた送受信を行う
    perror("write");//err出力
    exit(EXIT_FAILURE);
    
  
 }

  close(fd2);//ソケットを通じた通信を終了する
   
}
close(fd1);//ソケットを通じた通信を終了する
   exit(EXIT_SUCCESS);
}

