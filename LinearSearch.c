#include<stdio.h>

int LinearSearch(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}


int main() {
    int a[1000];
    int n;
    int e;
    printf("Enter number of components: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &a[i]);
    }
    printf("Element you want to search:");
    scanf("%d",&e);    
    int searchIndex=LinearSearch(a, n,e);
    if(searchIndex==-1){
        printf("Element not found");
    }
    else{
        printf("Element %d was found at position %d",e,searchIndex);
    }

    return 0;  
}