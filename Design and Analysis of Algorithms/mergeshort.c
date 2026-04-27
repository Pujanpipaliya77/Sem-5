#include <stdio.h>

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

int main() {
    int T[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(T) / sizeof(T[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }

    mergeSort(T, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
}
