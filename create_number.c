#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int main(void){

	FILE *Fptr;
	int a[MAX];

	Fptr = fopen("dataset1.txt","w");

	if(NULL == Fptr){
		perror("file open failed");
	}


	else{
            for(int i = 0;i < MAX;i++){
		srand(i);
		a[i] = (rand() % 2147483647);
		fprintf(Fptr,"%d\n",a[i]);
	    }

	}	    
	fclose(Fptr);
	return 0;
}
