#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>
#include<string.h>

#define MAX 1000000

void MaxHeapify(int *,int,int);
void BuildMaxHeap(int *);
void HeapSort(int *);
void printF(int *);
void swap2(int *,int *);

void Heap_sort(void);
