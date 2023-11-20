#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
 
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
 
int countDigits(int n)
{
    int c = 0;
    while (n > 0)
    {
        c++;
        n /= 10;
    }
    return c;
}
 
int findMAX(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
 
void Insert(struct Node *BinCell[], int value, int index)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;
    if (!BinCell[index])
        BinCell[index] = t;
    else
    {
        struct Node *head = BinCell[index];
        while (head->next)
            head = head->next;
        head->next = t;
    }
}
 
int Delete(struct Node *BinCell[], int index)
{
    struct Node *head = BinCell[index];
    BinCell[index] = BinCell[index]->next;
    int x = head->data;
    free(head);
    return x;
}
 
void Radix(int a[], int n)
{
    int d = countDigits(findMAX(a, n));
    int i, j, div = 1;
    struct Node *bins[10]; 
    for (i = 0; i < 10; i++)
        bins[i] = NULL;
    for (int p = 1; p <= d; p++) 
    {
        for (i = 0; i < n; i++)
            Insert(bins, a[i], (a[i] / div) % 10); 
        i = j = 0;
        while (i < 10)
        {
            while (bins[i] != NULL)
                a[j++] = Delete(bins, i); 
            i++;
        }
        div = div * 10;
    }
}
 
int main()
{
    int i, n;
    printf("Enter your array size: ");
    scanf("%d", &n);
    int arr[n];
 
    printf("Enter the array elements\n");
    input(arr, n);
 
    printf("Original Array : ");
    display(arr, n);
 
    Radix(arr, n);
 
    printf("Sorted Array : ");
    display(arr, n);
    return 0;
}