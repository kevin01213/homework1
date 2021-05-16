#include <stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>
#include<string.h>

#define MAX 1000000
#define LEN 102

void swap2(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void HeapSort(int *array){
    BuildMaxHeap(array);
    int size = MAX;
    for(int i = size;i >= 2;i--){
        swap2(&array[1],&array[i]);
        size--;
        MaxHeapify(array,1,size);
    }
}


void BuildMaxHeap(int *array){
    int n = ((MAX+1) / 2);
    for(int i = n;i >= 1;i--){
        MaxHeapify(array,i,MAX);
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
        swap2(&array[largest],&array[root]);
        MaxHeapify(array,largest,length);
    }
}
void printF(int *array){
    for(int i = 1;i <= 100;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}


void Heap_sort(void){


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

    

    diff = MAX *(end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("the heapSort time spend: %ld\n",diff);
    fclose(fptr);
    return;
}

