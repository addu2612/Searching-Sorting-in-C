#include <stdio.h>

void InsertionSort(int a[], int n) {
    int i, j, x;
    for (i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;

        while (j >=0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }

    printf("After sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int a[1000];
    int n;

    printf("Enter number of components: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &a[i]);
    }

    InsertionSort(a, n);

    return 0;
}
