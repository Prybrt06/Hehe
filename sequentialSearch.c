#include<stdio.h>

int searchIndexSequentially(int *arr,int n,int k)
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
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int k;
    scanf("%d",&k);

    int ans = searchIndexSequentially(arr,n,k);

    if(ans==-1)
    {
        printf("The element is not present in the array\n");
    }

    else
    {
        printf("The element is present in the index %d\n",ans);
    }

    printf("%d\n",ans);

    return 0;
}