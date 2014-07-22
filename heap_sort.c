#include <stdio.h>
#include <stdlib.h>
#define LEFT(i) 2*i+1
#define RIGHT(i) 2*(i+1)

void swap(int *a, int *b){
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void heapify(int *arr, int index, int len){
    int l=LEFT(index);
    int r=RIGHT(index);
    int largest=0;
    if(l<len && arr[l]>arr[index]){
        largest=l;
    }
    else
        largest=index;
    if(r<len && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=index){
        swap(&arr[index], &arr[largest]);
        heapify(arr, largest, len);
    }
}

void build_maxheap(int *arr, int len){
    if(arr==NULL || len<=1)return;
    int i;
    for(i=(len+1)/2;i>=0;--i){
        heapify(arr, i, len);
    }
}

void heap_sort(int *arr, int len){
    if(arr==NULL || len<=1)return;
    int i;
    build_maxheap(arr, len);

    for(i=len-1;i>=1;i--){
        swap(&arr[0], &arr[len-1]);
        heapify(arr, 0, --len);
    }
}

int main(){
    int i;
    int a[10]={2,3,5,1,4,10,8,7,9,6};
    heap_sort(a, 10);
    for(i=0;i<10;i++){
        printf("%d\n", a[i]);
    }
    return 0;
}
