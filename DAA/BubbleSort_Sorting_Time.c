#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 100000

int readArrayFormatFile(const char *filename, int arr[], int n)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("can't open the file %s\n", filename);
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &arr[i]);
    }
    fclose(f);
    return 1;
}

void bubbleSort(int arr[], int n)
{
    int swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
            if (swapped == 0)
            {
                break;
            }
        }
    }
}
int main()
{
    int arr[Max];
    clock_t start, end;
    double time_taken;
    if (readArrayFormatFile("D:/SEM-5/DAA/Arrays/worst_case_100000.txt", arr, Max))
    {
        start = clock();
        bubbleSort(arr, Max);
        end = clock();
        time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
        printf("worst time case is %lf", time_taken);
    }
    return 0;
}