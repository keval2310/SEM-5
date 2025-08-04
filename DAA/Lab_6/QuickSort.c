#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100

int pivot(int arr[], int i, int j) {
    int p=arr[i],temp;
    int k=i;
    int l=j+1;
    do{
        k++;
    }
    while(k<=j && arr[k]<=p);

    do{
        l--;
    }
    while(arr[l]>p);
    while(k<l){
        temp=arr[k];
        arr[k]=arr[l];
        arr[l]=temp;
        k++;
        l--;
        do{
            k++;
        }
        while(k<=j && arr[k]<=p);
        do{
            l--;
        }
        while(arr[l]>p);
    }
    arr[i]=arr[l];
    arr[l]=p;
    return l;
}

void quicksort(int arr[], int i, int j) {
    if (i < j) {
        int k = pivot(arr, i, j);
        quicksort(arr, i, k - 1);
        quicksort(arr, k + 1, j);
    }
}


void printArray(int arr[],int size) {
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
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

int main(){
    int arr[N];
    clock_t start,end;
    double time_taken;
    const char *filename = "D:\\SEM-5\\DAA\\Arrays\\best_case_100.txt";
    if(readArrayFromFile(filename, arr, N)){
        start=clock();
        quicksort(arr, 0, N - 1);
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