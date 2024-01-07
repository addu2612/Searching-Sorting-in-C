#include<stdio.h>

void Merge(int a[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int size = ub - lb + 1;  
    int b[size];

    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
        
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
            
        
    }

    for(k=lb;k<=ub;k++){
        a[k]=b[k];
    }
}

void MergeSort(int a[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        MergeSort(a,lb,mid);
        MergeSort(a,mid+1,ub);
        Merge(a,lb,mid,ub);
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

    MergeSort(a,0,n-1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
