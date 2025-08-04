#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define N 100

void merge(int arr[], int left, int mid, int right) {
    int n1=mid-left+1;
    int n2=right-mid;

    int leftArray[n1 + 1], rightArray[n2 + 1];
    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    leftArray[n1] = INT_MAX;
    rightArray[n2] = INT_MAX;

    int i = 0, j = 0,k=left;
    while(k<=right) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
}

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    return;
}

int readArrayFromFile(const char *filename,int arr[],int n){
    FILE *f=fopen(filename,"r");
    if(!f){
        printf("Cannot open file %s\n",filename);
        return 0;
    }
    for(int i=0;i<n;i++){
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    return 1;
}

void printArray(int arr[],int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[N];
    clock_t start,end;
    double time_taken;
    const char *filename = "D:\\SEM-5\\DAA\\Arrays\\best_case_100.txt";
    if(readArrayFromFile(filename, arr, N)){
        start=clock();
        mergeSort(arr, 0, N - 1);
        end=clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        printf("Time taken to sort the array from %s: %.2f ms\n", filename, time_taken);
        printf("Sorted array: \n");
        // printArray(arr, N);
    }
    else{
        printf("Failed to read array from file.\n");
    }
    return 0;
}