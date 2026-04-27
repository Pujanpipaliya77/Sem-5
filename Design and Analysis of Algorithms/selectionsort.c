// #include<stdio.h>


// int selection_sort(int arr[], int n){
//     int i,j,min_idx,temp;

//     for(i=0;i<n;i++){
//         min_idx = i;
//         for(j=i+1;j<n;j++){
//             if(arr[j] < arr[min_idx]){
//                 min_idx = j;
//             }
//         }
//         temp = arr[i];
//         arr[i] = arr[min_idx];
//         arr[min_idx] = temp;
//     }
// }

// int main(){
//     FILE *file;

//     file = fopen("bestcase.txt","w");
//     int arr[] = {5,2,8,1,9};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     heap_sort(arr,n);
//     for(int i=0;i<n;i++){
//         fprintf(file,"%d ",arr[i]);
//     }
//     fclose(file);

// }

#include <stdio.h>

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

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}


int main()
{
    FILE *file;

    file = fopen("bestcase.txt", "w");

    int arr[] = {5, 2, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);

}
