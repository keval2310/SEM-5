#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100

void selectionsort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
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
        selectionsort(arr, N);
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