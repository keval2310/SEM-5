#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100000

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
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
    const char *filename = "D:\\SEM-5\\DAA\\Arrays\\worst_case_100000.txt";
    if(readArrayFromFile(filename, arr, N)){
        start=clock();
        insertionSort(arr, N);
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