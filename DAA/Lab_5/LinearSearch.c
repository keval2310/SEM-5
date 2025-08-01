#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100

int linearSearch(int arr[], int size, int target) {
    for (int i=0;i<size;i++){
        if(arr[i]==target)return i;
    }
    return -1;
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
    int target;
    clock_t start,end;
    double time_taken;

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    if (readArrayFromFile("D:\\SEM-5\\DAA\\Arrays\\worst_case_100.txt", arr, N)) {
        start = clock();
        int result = linearSearch(arr, N, target);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        
        if (result == -1)
            printf("Element not found.\n");
        else {
            printf("Element found at index %d\n", result);
            printf("Time taken to search %d in the best case array is %f ms\n", target, time_taken);
        }
    }
    else {
        printf("Failed to read best case file");
    }
}