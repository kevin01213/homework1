#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX 1000001
#define LEN 102


void swap1(char *,char *);
void quickSort1(char [MAX][LEN],int ,int );
int partition1(char [MAX][LEN],int ,int );


char a[MAX][LEN];

int main(void){
        
	char temp[LEN];
	FILE *fptr;
	fptr = fopen("dataset2.txt","r");

	if(fptr == NULL){
		printf("file open failed!\n");
		return 0;
        }
        int cnt = 0;
	while(fgets(a[cnt++],102,fptr)){
	}
	
	struct timeval start;
	struct timeval end;
	unsigned long diff;	
	
	gettimeofday(&start,NULL);
	quickSort1(a,0,MAX);
	gettimeofday(&end,NULL);
        
	for(int i = 0;i < 100;i++){
		printf("%s\n",a[i]);
	}
        diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

        printf("total time string expend: %ld\n",diff);

	fclose(fptr);
	return 0;
}

    
  
int partition1(char a[MAX][LEN],int start,int end){

        char pivot[LEN];
        strcpy(pivot,a[start]);
        int i = start + 1;
        int j = end;
        while(i <= j){
           if( (strcmp(a[i],pivot) > 0) && (strcmp(a[j],pivot) < 0) )swap1(a[i],a[j]);
           if(strcmp(a[i],pivot) <= 0)i++;
           if(strcmp(a[j],pivot) >= 0)j--;
        }

        swap1(a[start],a[j]);
        return j;
}

void quickSort1(char a[MAX][LEN],int start,int end){

    if(start < end){
        int k = partition1(a,start,end);
        quickSort1(a,start,k-1);
        quickSort1(a,k+1,end);
    }
}

void swap1(char *a,char *b){

        char temp[LEN];
        strcpy(temp,a);
        strcpy(a,b);
        strcpy(b,temp);
}

