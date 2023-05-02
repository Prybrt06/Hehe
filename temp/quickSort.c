#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int pivotIndex(int *arr, int n, int si, int ei)
{
    int pivot = arr[si];

    int countLess = 0;

    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[i] < pivot)
        {
            countLess++;
        }
    }

    swap(&arr[si], &arr[countLess]);

    int i = si;
    int j = ei;

    while (i < countLess && j > countLess)
    {
        if (arr[i] < pivot)
        {
            i++;
        }

        else if (arr[j] > pivot)
        {
            j--;
        }

        else
        {
            swap(&arr[i], &arr[j]);

            i++;
            j--;
        }
    }

    return countLess;
}

void quickSort(int *arr, int n, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int pivot = pivotIndex(arr, n, si, ei);
    quickSort(arr, n, si, pivot - 1);
    quickSort(arr, n, pivot + 1, ei);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, n, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}