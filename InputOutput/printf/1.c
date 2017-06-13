#include <stdio.h>

void myflush(void){
	int c;
	do{
		c = getchar();
		} while (c != '\n' && c != EOF);
	}

int main(){
	int i=200;
	printf("%*d",i);
	myflush();
	return 0;
	}
