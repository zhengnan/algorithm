#include <stdio.h>

int partition(int *arr, int low, int high){
    int p=arr[high];
    int i=low-1;
    int j,temp;
    for(j=low;j<high;j++){
        if(arr[j]<p){
            temp=arr[++i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    arr[high]=arr[i+1];
    arr[i+1]=p;
    return i+1;
}

void quick_sort(int *arr, int low, int high){
    if(low<high){
        int mid=partition(arr, low, high);
        quick_sort(arr, low, mid-1);
        quick_sort(arr, mid+1, high);
    }
}

int main(){
    int a[10]={10,9,1,3,2,4,6,5,8,7};
    quick_sort(a, 0, 9);
    int i;
    for(i=0;i<10;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
