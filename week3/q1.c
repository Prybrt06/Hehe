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

    int ans = 0;

    while (n != 1)
    {
        int a = arr[1];
        delete (arr, n + 1);

        n--;
        int b = arr[1];

        delete (arr, n + 1);

        int result = a + b;

        arr[n] = result;
        ans += result;

        heapify(arr, n + 1);
    }

    printf("%d", ans);

    return 0;
}