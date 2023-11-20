#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// count fxn
int count(struct Node *p)
{
    int count = 0;
    while (p != 0)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insert(struct Node *p, int x, int index)
{
    struct Node *t;
    if (index < 0 || index > count(p))
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int delete_node(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;
    if (index < 1 && index > count(p))
    {
        return -1;
    }
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

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

void BinSort(int a[], int n) {
    int i, j, max;
    struct Node **Bins;

    max = findMax(a, n);
    Bins = (struct Node **)malloc(sizeof(struct Node *) * (max + 1));

    for (i = 0; i < max + 1; i++) {
        Bins[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        int index = a[i];

        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = a[i];
        temp->next = NULL;

        if (Bins[index] == NULL) {
            Bins[index] = temp;
        } else {
            struct Node *last = Bins[index];
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = temp;
        }
    }

    i = 0, j = 0;
    for (i = 0; i < max + 1; i++) {
        struct Node *current = Bins[i];
        while (current != NULL) {
            a[j++] = current->data;
            struct Node *temp = current;
            current = current->next;
            free(temp); // free the allocated memory for the nodes
        }
    }

    printf("After sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(Bins); // free the allocated memory for the bins
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

    BinSort(a, n);

    return 0;
}
