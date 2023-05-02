#include <stdio.h>
#include <stdlib.h>
#define N 10
struct node
{
    char c;
    int f;
    struct node *l;
    struct node *r;
};

struct node *arr[N];
int size = 0;

struct node *new(char c, int f)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->l = NULL;
    t->r = NULL;
    t->c = c;
    t->f = f;
    return t;
}

void swap(struct node **a, struct node **b)
{
    struct node *t = *a;
    *a = *b;
    *b = t;
}

void heapify(int i)
{
    if (size == 1)
        return;
    int idx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l]->f < arr[idx]->f)
        idx = l;
    if (r < size && arr[r]->f < arr[idx]->f)
        idx = r;
    if (idx != i)
    {
        // swap(&arr[idx], &arr[i]);
        struct node *temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
        heapify(idx);
    }
}

void push(struct node *x)
{
    arr[size++] = x;
    // for (int i = size / 2 - 1; i >= 0; i--)
    //   heapify(i);
    int i = size - 1;
    while (i && x->f < arr[(i - 1) / 2]->f)
    {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    arr[i] = x;
}

struct node *pop()
{
    struct node *x = arr[0];
    // swap(&arr[0], &arr[size - 1]);
    arr[0] = arr[--size];
    arr[size] = NULL;
    heapify(0);
    return x;
}

struct node *tree(char crr[], int frr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        struct node *x = new (crr[i], frr[i]);
        push(x);
    }

    struct node *top;
    struct node *l;
    struct node *r;
    while (size != 1)
    {
        l = pop();
        r = pop();

        top = new ('$', l->f + r->f);
        top->l = l;
        top->r = r;

        push(top);
    }
    return arr[0];
}

void printArray(int s[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", s[i]);
    printf("\n");
}
void print(struct node *t, int s[], int top)
{
    if (t->l)
    {
        s[top] = 0;
        print(t->l, s, top + 1);
    }
    if (t->r)
    {
        s[top] = 1;
        print(t->r, s, top + 1);
    }
    if (!t->l && !t->r)
    {
        printf("%c : ", t->c);
        printArray(s, top);
    }
}

int main()
{
    char crr[] = {'A', 'B', 'C', 'D', 'E'};
    int frr[] = {20, 15, 5, 15, 45};
    int n = sizeof(crr) / sizeof(crr[0]);
    for (int i = 0; i < N; i++)
        arr[i] = NULL;
    struct node *top = tree(crr, frr, n);
    int s[N];
    print(top, s, 0);
}