#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define LEN 101

int main(void){
	
	
	FILE *Fptr;
	Fptr = fopen("dataset2.txt","w");

	char str[LEN];
	int a;
	if(!Fptr){
		printf("file open failed");
	}
	for(int i = 0;i < MAX;i++){
	   for(int j = 0;j < LEN;j++){
	       a = (i + j);
	       srand(a);
	       str[j] = 'a' + (rand()%24);
	   }
	   str[LEN-1] = '\0';
	   fprintf(Fptr,"%s\n",str);
	}
	
	fclose(Fptr);
	return 0;

}
