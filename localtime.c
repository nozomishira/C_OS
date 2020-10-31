//情報科学部　B184645　白石望


#include <stdio.h>
#include <time.h>

int main(){
  time_t timer;
  struct tm *t_st;
  char *wday[]={"Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
//配列で曜日を格納する

  time(&timer);


  t_st = localtime(&timer); //localtime関数を使う

  printf("%s\n", wday[t_st->tm_wday]);

  return 0;
}

/*実行結果
白石望@DESKTOP-DU1O254 ~/a
$ gcc localtime.c -o localtime

白石望@DESKTOP-DU1O254 ~/a
$ ./localtime
Thursday

白石望@DESKTOP-DU1O254 ~/a

*/