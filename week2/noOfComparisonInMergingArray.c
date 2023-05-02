#include <stdio.h>

void mergeSort(int *arr, int n, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (ei + si) / 2;

    mergeSort(arr, n, si, mid);
    mergeSort(arr, n, mid + 1, ei);

    int temp[ei - si + 1];
    int i = si;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }

        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= ei)
    {
        temp[k++] = arr[j++];
    }

    for (int i = si, j = 0; j < k; i++, j++)
    {
        arr[i] = temp[j];
    }
}

int main()
{
    int n;
    printf("Enter the no of arrays : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the size of arryas\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr,n,0,n-1);

    int comparison[n - 1];
    int ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        comparison[i] = arr[i] + arr[i + 1];
        arr[i] = 0;
        arr[i + 1] = comparison[i];
        mergeSort(arr, n, 0, n - 1);
    }

    for (int i = 0; i < n - 1; i++)
    {
        ans += (comparison[i] - 1);
    }

    printf("The no of comparisons in the worst case of the best algorithm is %d\n", ans);

    return 0;
}