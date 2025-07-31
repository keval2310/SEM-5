#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100000

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void readArrayFromFile(const char *filename, int arr[], int n) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Cannot open file %s\n", filename);
        return;
    }
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &arr[i]);
    }
    fclose(f);
}

int main() {
    int arr[N];
    clock_t start, end;
    double time_taken;
    const char *filename = "D:\\SEM-5\\DAA\\Arrays\\worst_case_100000.txt";
    
    readArrayFromFile(filename, arr, N);
    
    start = clock();
    heapsort(arr, N);
    end = clock();
    
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort the array from %s: %.2f ms\n", filename, time_taken);
    printf("Sorted array: \n");
    // printArray(arr, N);
    
    return 0;
}