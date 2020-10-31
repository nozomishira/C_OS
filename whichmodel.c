#include <stdio.h>

int main(){
	int a,b,c,d;
	a=sizeof(int);
	b=sizeof(long int);
	c=sizeof(int*);
	if(a==4&&b==4&&c==8){
		printf("LLP64");
	}else if(a==4&&b==8&&c==8){
		printf("LP64");
	}else if(a==8&&b==8&&c==8){
		printf("IP64");
	}else if(a==4&&b==4&&c==4){
		printf("ILP32");
	}else if(a==2&&b==4&&c==4){
		printf("LP32");
	}else if(a==2&&b==4&&c==2){
		printf("16bit Os");
	}
		return 0;
}

