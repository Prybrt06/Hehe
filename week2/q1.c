#include<stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elements of the array\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        int a = arr[i];
        int count = 0;

        for(int j=0;j<n;j++)
        {
            if(arr[j]<a)
            {
                count++;
            }
        }

        printf("The element %d should be in the index %d if the array is in sorted manner\n",a,count);
    }

    return 0;
}