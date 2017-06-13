#include <stdio.h>

void myflush(void){
	int c;
	do{
		c = getchar();
		} while (c != '\n' && c != EOF);
	}

int main(){
	char str[60];
	scanf("%[^a]",str);//stop taking input when a is found from there only..
	printf("%s\n",str);
	myflush();
	scanf("%[0-9]",str);//read only numbers
	printf("%s\n",str);
	myflush();
	printf("%%\n i wish we dont miss out a sign here ->");
	printf("\% ");//glitch ??
	printf(" <- where did previous sign go ? \% \\ \n");
	return 0;
	}
