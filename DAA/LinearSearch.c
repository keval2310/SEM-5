#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
const char *filename = "../Arrays/best_case_100000.txt";

int readArrayFromFile(const char *filename, int arr[], int n) {
    FILE *f = fopen(filename, "r");
    
    if (!f) {
        printf("Cannot open file %s\n", filename);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &arr[i]);
    }
    fclose(f);
    return 1;
}


int main() {
    int size = 100000;
    int arr[size];
    readArrayFromFile(filename, arr, size);
    int target;
    printf("Enter the target element between 1 and %d: ", size);
    scanf("%d", &target);
    int result = linearSearch(arr, size, target);
    printf("Element %d found at index %d\n", target, result);
    return 0;
}