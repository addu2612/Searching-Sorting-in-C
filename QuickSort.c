#include <stdio.h>

int Partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (a[start] <= pivot) {
            start++;
        }
        while (a[end] > pivot) {
            end--;
        }
        if (start < end) {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }

    int temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;

    return end;
}

void QuickSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int pivotIndex = Partition(a, lb, ub);
        QuickSort(a, lb, pivotIndex - 1);
        QuickSort(a, pivotIndex + 1, ub);
    }
}

int main() {
    int a[100];
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    QuickSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
