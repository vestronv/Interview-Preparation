#include <stdio.h>

void myflush(void){
	int c;
	do{
		c = getchar();
		} while (c != '\n' && c != EOF);
	}

int main(){
	char a,b;
	scanf("%c %c",&a,&b);// i/p = ab
	printf("a=%c b=%c\n",a,b);
	myflush();
	scanf("%c%c",&a,&b);// i/p = ab
	printf("a=%c b=%c\n",a,b);
	myflush();
	scanf("%c,%c",&a,&b);// i/p = a,b
	printf("a=%c b=%c\n",a,b);
	myflush();
	scanf("%c %c",&a,&b);//i/p = a.b
	printf("a=%c b=%c\n",a,b);
	myflush();
	return 0;
	}
