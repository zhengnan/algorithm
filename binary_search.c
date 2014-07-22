#include <stdio.h>

int binary_search(int *arr, int left, int right, int key){
    if(arr==NULL || right<left)return -1;
    int low=left;
    int high=right;
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(arr[mid]<key){
            low=mid+1;
        }
        else if(arr[mid]>key){
            high=mid-1;
        }
        else
            return mid;
    }
    return -1;
}

int main(){
    int arry[10]={1,2,3,4,5,6,7,8,9,10};
    int ret=binary_search(arry, 0, 9, 10);
    printf("%d\n",ret);
    return 0;
}
