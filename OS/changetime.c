情報科学部　B184654

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int num;
        num = atoi(argv[1]);//atoi関数を使う

	time_t t = time(NULL);
	t+=num;	//numを足す
 	printf("%s", ctime(&t));
	


/*実行結果
白石望@DESKTOP-DU1O254 ~/a
$ ./changetime 90
Thu Oct 17 16:11:04 2019

白石望@DESKTOP-DU1O254 ~/a

*/