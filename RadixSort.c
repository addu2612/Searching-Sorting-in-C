#include<stdio.h>

int MaxNo(int a[],int n){
    int i,j;
    int max=0;
    for(i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

void CountingSort(int a[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }
}


void Radix(int a[],int n){
    int max=MaxNo(a,n);
    for(int exp=1;max/exp>0;exp*=10){
        CountingSort(a,n,exp);
    }
}


int main() {
    int a[100];
    int n;
    printf("Enter number of components:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    Radix(a, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
