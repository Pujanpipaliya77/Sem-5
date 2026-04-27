#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int T[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = T[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = T[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            T[k] = L[i];
            i++;
        } else {
            T[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        T[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        T[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int T[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(T, l, m);
        mergeSort(T, m + 1, r);
        merge(T, l, m, r);
    }
}

void pivot(int T[], int i, int j)
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

void quick_sort(int T[], int i, int j)
{
    if (i < j)
    {
        int p = pivot(T, i, j);
        quick_sort(T, i, p - 1);
        quick_sort(T, p + 1, j);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i++)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void selection_sort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void best_case(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
}

void worst_case(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

void average_case(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

void cpu_time_used(int choice, int arr[], int n)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    switch (choice)
    {
    case 1:
        selection_sort(arr, n);
        break;
    case 2:
        bubble_sort(arr, n);
        break;
    case 3:
        insertion_sort(arr, n);
        break;
    case 4:
        heap_sort(arr, n);
        break;
    case 5:
        quick_sort(T, 0, n - 1);
        break;
    case 6:
        merge_sort(T, 0, n - 1);
        break;
    default:
        printf("Invalid Sorting Choice!\n");
        return;
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    printf("");
}

int main()
{
    int n, algo_choice, case_choice;
    int arr[100000];

    printf("Enter number of elements (100, 1000, 10000): ");
    scanf("%d", &n);

    if (n != 100 && n != 1000 && n != 100000)
    {
        printf("Invalid input size.\n");
        return 1;
    }

    printf("Choose Sorting Algorithm:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Heap Sort\n");
    printf("5. Quick Sort\n");
    printf("5. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &algo_choice);

    printf("Choose Case:\n");
    printf("1. Best Case\n");
    printf("2. Worst Case \n");
    printf("3. Average Case \n");
    printf("Enter your choice: ");
    scanf("%d", &case_choice);

    switch (case_choice)
    {
    case 1:
        best_case(arr, n);
        break;
    case 2:
        worst_case(arr, n);
        break;
    case 3:
        average_case(arr, n);
        break;
    default:
        printf("Invalid Case Choice!\n");
        return 1;
    }

    printf("Sorting...\n");
    cpu_time_used(algo_choice, arr, n);
}
