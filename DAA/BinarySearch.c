#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
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
    printf("\n");
    int target;
    printf("Enter the target element between 1 and %d: ", size);
    scanf("%d", &target);
    int result = binarySearch(arr, size, target);
    printf("Element %d found at index %d\n", target, result);
    return 0;
}