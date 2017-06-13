#include <stdio.h>

void myflush(void){
	int c;
	do{
		c = getchar();
		} while (c != '\n' && c != EOF);
	}

int main(){
	float a,b;
	scanf("%d %d",&a,&b);//i/p = 3 5
	printf("a=%d b=%d\n",a,b);	
	myflush();
	scanf("%d %d",&a,&b);//i/p = 3.0 5
	printf("a=%d b=%d\n",a,b);
	myflush();
	scanf("%f %d",&a,&b);//i/p = 3.0 5
	printf("a=%f b=%d\n",a,b);	
	myflush();
	int c;
	scanf("%d %d",&c,&a);//i/p = 3 5.0
	printf("c=%d a=%d\n",c,a);	
	myflush();
	return 0;
	}
