#include <stdio.h>
#include <stdlib.h>

int findMax(int a[],int n){
    int max=0;
    int i;
    for(i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}


void CountSort(int a[],int n){
    int i,j,max;
    int *C;
    max=findMax(a,n);
    C=(int *)malloc(sizeof(int)*(max+1));
    for(i=0;i<max+1;i++){
        C[i]=0;
    }
    for(i=0;i<n;i++){
        C[a[i]]++;
    }
    i=0,j=0;
    while(i<max+1){
        if(C[i]>0){
            a[j++]=i;
            C[i]--;
        }
        else{
            i++;
        }
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

    CountSort(a, n);

    return 0;
}