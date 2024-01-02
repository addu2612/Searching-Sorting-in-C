#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int a[],int n,int i){
    int largest=i; // Initialize largest as root
    int lchild=2*i+1;
    int rchild=2*i+2;

    if(lchild<n && a[lchild]>a[largest]){
        largest=lchild;
    }
    if(rchild<n && a[rchild]>a[largest]){
        largest=rchild;
    }
    if(largest!=i){
        swap(&a[i],&a[largest]);

        heapify(a,n,largest);  // Recursively heapify the affected sub-tree
    }
}

void HeapSort(int a[],int n){
    // Build heap (rearrange array)
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    // One by one extract an element from heap
    for(int i=n-1;i>0;i--){
        swap(&a[0],&a[i]);
        heapify(a,i,0); // call max heapify on the reduced heap
    }
    printf("After sorting");
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int a[100];
    int n;
    printf("Enter number of components:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    HeapSort(a,n);
}