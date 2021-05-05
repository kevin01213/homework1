#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include<unistd.h>

#define MAX 1000000
#define LEN 102

char array[MAX][LEN];

char a[MAX/2][LEN];
char b[MAX/2][LEN];

void merge_sort(char [MAX][LEN],int ,int);
void merge(char [MAX][LEN],int ,int ,int);
void swap(char *,char *);

int main(void){
   
    int i=0;
    char buffer[LEN];
    FILE *Fptr;
    int Cnt = 0;
    
    Fptr = fopen("dataset2.txt","r");
    if(Fptr == NULL){
        printf("file open failed!\n");
        return 0;
    }
    
    while(fgets(array[Cnt++],LEN,Fptr)){    
    }
    
    struct timeval start;
    struct timeval end;

    unsigned long diff;

    gettimeofday(&start,NULL);
    merge_sort(array,0,MAX);
    gettimeofday(&end,NULL);

    diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    
    
    int j;
    for(j=0;j < 100;j++){
        printf("%s\n",array[j]);
    }
    
    printf("merge_sort_number time spend %ld\n",diff);
    fclose(Fptr);
    return 0;
}


void swap(char *a,char *b){
	char temp[LEN];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}

void merge(char array[MAX][LEN],int start,int mid,int end){
    
    int len1 = mid - start + 1;
    int len2 = end - mid;
    
       
    for(int i = 0;i < len1;i++){
        
	strcpy(a[i],array[start + i]);
    }
    
    for(int i = 0;i < len2;i++){
	
	strcpy(b[i],array[mid + i + 1]);
    }
    
    int rightidx = 0;
    int leftidx = 0;
    int i = start;
   while(rightidx < len1 && leftidx < len2){
       
       if(strcmp(a[rightidx],b[leftidx])  <= 0){
	   
	   strcpy(array[i++],a[rightidx++]);
       }
       else{
	   strcpy(array[i++],b[leftidx++]);
       }
   }
   
   while(rightidx < len1){
       strcpy(array[i++],a[rightidx++]);
   }
   while(leftidx < len2){
       strcpy(array[i++],b[leftidx++]);
   }
}


void merge_sort(char a[MAX][LEN],int start,int end){
    
    if(start < end){
        
        int mid = (start + end) / 2;
        merge_sort(a,start,mid);
        merge_sort(a,(mid + 1),end);
        merge(a,start,mid,end);
    }
}
