#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>
#include<string.h>

#define MAX 1000000

void MaxHeapify(int *,int,int);
void BuildMaxHeap(int *);
void HeapSort(int *);
void swap(int *,int *);
void printF(int *);

int main(){
    
    
    int a[MAX+1];
    int cnt = 1;
    char temp[100];
    FILE *fptr = fopen("dataset1.txt","r");
    if(fptr == NULL){
        printf("file open failed!\n");
        return 0;
    }
    while(fgets(temp,100,fptr)){
        a[cnt++] = atoi(temp);
    }
    
    struct timeval start;
    struct timeval end;
    
    unsigned long diff;
    
  
    gettimeofday(&start,NULL);
    HeapSort(a);
    gettimeofday(&end,NULL);
    
    for(int i = 0;i < 100;i++){
	    printf("%d\n",a[i]);
    }
    
    diff = MAX *(end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("the heapSort time spend: %ld\n",diff);
    fclose(fptr);
    return 0;
}

void BuildMaxHeap(int *array){
    int n = ((MAX+1) / 2);
    for(int i = n;i >= 1;i--){
        MaxHeapify(array,i,MAX);
    }
}

void HeapSort(int *array){
    BuildMaxHeap(array);
    int size = MAX;
    for(int i = size;i >= 2;i--){
        swap(&array[1],&array[i]);
        size--;
        MaxHeapify(array,1,size);
    }
}

void MaxHeapify(int *array,int root,int length){
    
    int left = 2 * root;
    int right = 2 * root + 1;
    int largest;
    
    if(left <= length && array[left] > array[root]){
        largest = left;
    }
    else{
        largest = root;
    }
    if(right <= length && array[right] > array[largest]){
        largest = right;
    }

    if(largest != root){
        swap(&array[largest],&array[root]);
        MaxHeapify(array,largest,length);
    }
}
void printF(int *array){
    for(int i = 1;i <= 100;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
