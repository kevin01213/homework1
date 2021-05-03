#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>
#include<string.h>

#define MAX 1000000
#define LEN 102

void swap(int*,int*);
void quickSort(int*,int,int);
int partition(int*,int,int);
void hello(void);
void hello1(void);

//void swap(char *,char *);
//void quickSort(char **,char *,char *);
//int partition(char **,char *,char *);

int main(void){

	hello1();
	hello();
        return 0;
}

void hello1(void){
    int a[MAX]={0};
    int i=0;
    char buffer[100];
    FILE *Fptr;
    int Cnt = 0;

     struct  timeval start;
     struct  timeval end;

     unsigned long diff;

    Fptr = fopen("dataset1.txt","r");
    if(Fptr == NULL){
        printf("file open failed!\n");
        return ;
    }

    while(fgets(buffer,100,Fptr)){
        a[Cnt++] = atoi(buffer);
    }

    gettimeofday(&start,NULL);
    quickSort(a,0,MAX);
    gettimeofday(&end,NULL);

    diff = MAX *(end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

    printf("total time expend: %ld\n",diff);
    fclose(Fptr);
}
 
void hello(void){

   char *str[MAX];

    for(int i = 0;i < MAX ;i++){
	    str[i] = malloc(sizeof(char)*200);
    }

    char temp[LEN];
    FILE *fptr;
    fptr = fopen("dataset2.txt","r");
    if(!fptr){
	    printf("file open failed!");
	    return;
    }
    
    int cnt = 0;
    while(fgets(temp,102,fptr)){
	    strcpy(str[cnt],temp);
	    cnt++;
    }


    

   fclose(fptr);
   
}


int partition(int *a,int start,int end){
    int pivot=a[start];
    int i=start+1;
    int j=end;
    while(i<=j){
        if((a[i]>pivot)&&(a[j]<pivot))swap(&a[i],&a[j]);
        if(a[i]<=pivot)i++;
        if(a[j]>=pivot)j--;
    }
    swap(&a[start],&a[j]);
    return j;
}
void quickSort(int *a,int start,int end){
    if(start<end){
        int k=partition(a,start,end);
        quickSort(a,start,k-1);
        quickSort(a,k+1,end);
    }

}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

