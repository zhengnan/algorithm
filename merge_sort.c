#include <stdio.h>
#include <stdlib.h>
#define MAX_INT ~(1<<31)

void merge(int *arr, int p, int q, int t){
	if(arr==NULL)return;
	int n1=q-p+1;
	int n2=t-q;//r代表数组需要排序的最后一个数的下标
	int *l=(int *)malloc((n1+1)*sizeof(int));
	int *r=(int *)malloc((n2+1)*sizeof(int));
	int i,j;
	for(i=0;i<n1;i++){
		l[i]=arr[p+i];
	}
	for(j=0;j<n2;j++){
		r[j]=arr[q+j+1];
	}
        l[n1]=MAX_INT;
        r[n2]=MAX_INT;
	int k;
	i=0,j=0;
	for(k=p;k<=t;k++){
		if(l[i]<=r[j]){
			arr[k]=l[i++];
		}
		else{
			arr[k]=r[j++];
		}
	}
	free(l);
	free(r);
}

void merge_sort(int *arr, int p, int r){
	if(p<r){
		int q=p+((r-p)>>1);
		merge_sort(arr, p, q);
		merge_sort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}

int main(){
	int arry[10]={1,3,5,7,9,2,4,6,8,10};
	merge_sort(arry, 0, 9);
	int i;
	for(i=0;i<10;i++){
		printf("%d\n",arry[i]);
	}
	return 0;
}
