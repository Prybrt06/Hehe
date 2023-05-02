#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);

    int weight[n];
    int value[n];
    int quantity[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &quantity[i]);
    }

    float valPerKg[n];

    for (int i = 0; i < n; i++)
    {
        valPerKg[i] = (value[i] * 1.0) / (weight[i] * 1.0);
        // printf("%f\n", valPerKg[i]);
    }

    int totalWeight = 0;
    int totalValue = 0;
    int i = 0;

    while (i < n && totalWeight < 20)
    {
        int maxIndex = -1;
        int max = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            if (valPerKg[j] > max)
            {
                max = valPerKg[j];
                maxIndex = j;
            }
        }

        int a = (20 - totalWeight) / weight[maxIndex];

        // printf("%d %d\n", max, value[maxIndex]);

        if (a <= quantity[maxIndex])
        {
            totalValue += a * value[maxIndex];
            totalWeight += a * weight[maxIndex];
            quantity[maxIndex] -= a;
        }

        else
        {
            totalValue += quantity[maxIndex] * value[maxIndex];
            totalWeight += quantity[maxIndex] * weight[maxIndex];
            quantity[maxIndex] = 0;
        }

        valPerKg[maxIndex] = 0;
        i++;
    }

    printf("%d", totalValue);
}