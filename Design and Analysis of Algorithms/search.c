
// void linear_search(int arr[], int n, int key)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == key)
//             return i; 
//     }
// }


// void binary_search(int arr[], int low, int high, int x){
//     while(low<=high){
//         int mid = low + ( low - high ) / 2 ;

//         if(arr[mid] == x){
//             return mid ;
//         }
//         else if(arr[mid] < x){
//             low = mid + 1 ;
//         }
//         else{
//             high = mid - 1 ;
//         }
//     }   
// }


// int main()
// {
//     FILE *file;

//     file = fopen("bestcase.txt", "w");



//     fclose(file);

// }

#include <stdio.h>

int linear_search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int binary_search(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    FILE *file = fopen("bestcase.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int arr[] = {1, 2, 5, 8, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;

    int lin_index = linear_search(arr, n, x);
    fprintf(file, "Linear Search:\n");
    if (lin_index != -1)
        fprintf(file, "Element %d found at index %d\n", x, lin_index);
    else
        fprintf(file, "Element %d not found\n", x);

    // Binary Search
    int bin_index = binary_search(arr, 0, n - 1, x);
    fprintf(file, "\nBinary Search:\n");
    if (bin_index != -1)
        fprintf(file, "Element %d found at index %d\n", x, bin_index);
    else
        fprintf(file, "Element %d not found\n", x);

    fclose(file);
    return 0;
}
