#include <stdio.h>

int searchIndexBinary(int *arr, int k, int si, int ei)
{
    if (si > ei)
    {
        return -1;
    }
    int mid = (ei + si) / 2;

    if (arr[mid] == k)
    {
        return mid;
    }

    else if (arr[mid] > k)
    {
        return searchIndexBinary(arr, k, 0, mid - 1);
    }

    else
    {
        return searchIndexBinary(arr, k, mid + 1, ei);
    }

    return -1;
}

void mergeSort(int *arr,int n,int si,int ei)
{
    if(si>=ei)
    {
        return;
    }
    int mid = (ei+si)/2;

    mergeSort(arr,n,si,mid);
    mergeSort(arr,n,mid+1,ei);

    int temp[ei-si+1];
    int i = si;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=ei)
    {
        if(arr[i]<arr[j])
        {
            temp[k++] = arr[i++];
        }

        else
        {
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid)
    {
        temp[k++] = arr[i++];
    }

    while (j<=ei)
    {
        temp[k++] = arr[j++];
    }
    
    for(int i=si,j=0;j<k;i++,j++)
    {
        arr[i] = temp[j];
    }
}

int searchIndex(int *arr,int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            return i;
        }
    }

    return -1;
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

    int temp[n];

    for(int i=0;i<n;i++)
    {
        temp[i] = arr[i];
    }

    mergeSort(temp,n,0,n-1);

    int k;
    scanf("%d", &k);

    int x = searchIndexBinary(temp, k, 0, n - 1);

    if(x==-1)
    {
        printf("The element is not present in the array\n");
    }

    else
    {
        int index = searchIndex(arr,n,k);
        printf("The element is present in the index %d\n",index);
    }

    return 0;
}