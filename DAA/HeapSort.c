#include<stdio.h>

void heapify(int arr[],int n,int i){
	
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	
	if(left<n && arr[left]>arr[largest]){
		largest = left;
	}
	if(right<n && arr[right]>arr[largest]){
		largest = right;
	}
	
	if(largest!=i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr,n,largest);
	}	
}

void main(){
	
	int a[] = {1,8,5,2,3,6,7,9,10,11,45};
	int n = 11;
	int i,arr[n];
	
	for(i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(i=n-1;i>0;i++){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr,i,0);
	}
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}