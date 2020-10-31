情報科学部　B184654　白石望

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>



int main(int argc, char *argv[]){
    
  struct stat sbuf; //以下ファイルの状態を取得するシステムコール
      
	time_t  st_atime;
	time_t  st_mtime;
    	time_t  st_ctime;
  if(stat(argv[1],&sbuf)==-1){
    perror("stat");　	//エラー表示
      
   }else{

       struct tm *tmnow1;
       struct tm *tmnow2;
       struct tm *tmnow3;
	
	st_atime=time(NULL);
        st_mtime=time(NULL);
	st_ctime=time(NULL);
         tmnow1=localtime(&st_atime); //localtimeを使って代入
         tmnow2=localtime(&st_mtime);
	 tmnow3=localtime(&st_ctime);

      printf("Fainal access time: %d %d %d %d %d\n",tmnow1->tm_year+1900,tmnow1->tm_mon+1,tmnow1->tm_mday,tmnow1->tm_hour,
                  tmnow1->tm_min,tmnow1->tm_sec);
      printf("Fainal change time: %d %d %d %d %d\n",tmnow2->tm_year+1900,tmnow2->tm_mon+1,tmnow2->tm_mday,tmnow2->tm_hour,
                  tmnow2->tm_min,tmnow2->tm_sec);
      printf("Fainal status time: %d %d %d %d %d\n",tmnow3->tm_year+1900,tmnow3->tm_mon+1,tmnow3->tm_mday,tmnow3->tm_hour,
                  tmnow3->tm_min,tmnow3->tm_sec);
   // }

}
