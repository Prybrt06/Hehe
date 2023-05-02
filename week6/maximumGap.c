#include <stdio.h>
#include <stdlib.h>

int getMax(int *nums, int n)
{
    int max = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }

    return max;
}

void countingSort(int *nums, int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(nums[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(nums[i] / exp) % 10] - 1] = nums[i];
        count[(nums[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = output[i];
    }
}

void radixSort(int *nums, int n)
{
    int max = getMax(nums, 0);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(nums, n, exp);
    }
}

int maximumGap(int *nums, int numsSize)
{
    if(numsSize<2)
    {
        return 0;
    }

    radixSort(nums,numsSize);

    int max_gap = 0;

    for(int i=1;i<numsSize;i++)
    {
        int gap = nums[i] - nums[i-1];

        if(gap>max_gap)
        {
            max_gap = gap;
        }
    }

    return max_gap;
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

    if (n <= 1)
    {
        printf("0\n");
        return 0;
    }

    int maxGap = maximumGap(arr,n);

    printf("%d\n",maxGap);

    return 0;
}