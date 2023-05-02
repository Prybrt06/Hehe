#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n)
{
    for (int i = (n / 2); i > 0; i--)
    {
        int j = 2 * i;

        while (j <= (n - 1))
        {
            if ((j + 1) < n)
            {
                if (arr[j] > arr[j + 1])
                {
                    j++;
                }
            }

            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
                i = j;
                j = 2 * i;
            }

            else
            {
                break;
            }
        }
    }
}

void delete(int *arr, int n)
{
    int currentSize = n - 1;

    while (currentSize != 1)
    {
        int a = arr[1];
        arr[1] = arr[currentSize];

        int i = 1;
        int j = 2 * i;

        while (j <= (currentSize - 1))
        {
            if (arr[j] < arr[j + 1])
            {
                j++;
            }

            if (arr[i] < arr[j])
            {
                swap(&arr[i], &arr[j]);
                i = j;
                j = 2 * i;
            }

            else
            {
                break;
            }
        }

        arr[currentSize--] = a;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n + 1];
    arr[0] = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapify(arr, n + 1);

    int k;
    scanf("%d", &k);
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    // printf("\n");

    int i = 1;

    while (i < k)
    {
        delete (arr, n + 1);

        n--;
        i++;
    }

    printf("%d", arr[1]);

    return 0;
}

/*
0 1 2 3 4 5 n=5
0 2 3 4 5 1 n=4

*/