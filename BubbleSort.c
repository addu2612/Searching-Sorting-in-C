#include <stdio.h>

void BubbleSort(int a[],int n){
    int i,j;
    int temp=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
          }
        }
    }
    printf("After sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main(){
    int a[100];
    int n;
    printf("Enter number of components");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element:");
        scanf("%d",&a[i]);
    }
    BubbleSort(a,n);
}

//make bubble sort adaptive by using flag variable

/*

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int a[],int n){
    int i,j,flag=0;

    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
            swap(&a[i],&a[j])
            flag=1;
          }
          if(flag==0){
            break;    
    }
    printf("After sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
*/
