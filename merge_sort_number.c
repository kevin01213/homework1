#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>

#define MAX 1000000

void merge_sort(int *,int ,int);
void merge(int *,int ,int ,int);

int main(void){
    
    int a[MAX]={0};
    int i=0;
    char buffer[100];
    FILE *Fptr;
    int Cnt = 0;
    
    Fptr = fopen("dataset1.txt","r");
    if(Fptr == NULL){
        printf("file open failed!\n");
        return 0;
    }
    
    while(fgets(buffer,100,Fptr)){
        a[Cnt++] = atoi(buffer);    
    }
    
    struct timeval start;
    struct timeval end;

    unsigned long diff;

    gettimeofday(&start,NULL);
    merge_sort(a,0,MAX);
    gettimeofday(&end,NULL);

    diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    
    
    int j;
    for(j=0;j < MAX;j++){
        printf("%d\n",a[j]);
    }
    
    printf("merge_sort_number time spend %ld\n",diff);
    fclose(Fptr);
    return 0;
}



void merge(int *array,int start,int mid,int end){
    
    int len1 = mid - start + 1;
    int len2 = end - mid;
    
    int a[len1];
    int b[len2];
    
    for(int i = 0;i < len1;i++){
        a[i] = array[start + i];
    }
    
    for(int i = 0;i < len2;i++){
        b[i] = array[mid + i+1];
    }
    
    int rightidx = 0;
    int leftidx = 0;
    int i = start;
   while(rightidx < len1 && leftidx < len2){
       
       if(a[rightidx] <= b[leftidx]){
           array[i++] = a[rightidx++];
       }
       else{
           array[i++] = b[leftidx++];
       }
   }
   
   while(rightidx < len1){
       array[i++] = a[rightidx++];
   }
   while(leftidx < len2){
       array[i++] = b[leftidx++];
   }
}


void merge_sort(int *a,int start,int end){
    
    if(start < end){
        
        int mid = (start + end) / 2;
        merge_sort(a,start,mid);
        merge_sort(a,(mid + 1),end);
        merge(a,start,mid,end);
    }
}
  
