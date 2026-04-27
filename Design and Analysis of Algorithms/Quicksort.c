#include <stdio.h>

int pivot(int T[], int i, int j)
{
    int p = T[i];
    int k = i;

    for (int m = i + 1; m <= j; m++)
    {
        if (T[m] < p)
        {
            k++;
            int temp = T[k];
            T[k] = T[m];
            T[m] = temp;
        }
    }

    int temp = T[i];
    T[i] = T[k];
    T[k] = temp;

    return k;
}

void quicksort(int T[], int i, int j)
{
    if (i < j)
    {
        int p = pivot(T, i, j);
        quicksort(T, i, p - 1);
        quicksort(T, p + 1, j);
    }
}

int main()
{
    int arr[] = {55, 64, 19, 48, 99, 86};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
