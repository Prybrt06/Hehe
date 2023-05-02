#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int char_at(char *str, int d)
{
    if (strlen(str) <= d)
        return -1;
    else
        return str[d];
}

void MSD_sort(char **str, int lo, int hi, int d)
{
    if (hi <= lo)
    {
        return;
    }
    int count[256] = {0};
    char(*temp)[100] = malloc((hi - lo + 1) * sizeof(*temp));
    memset(temp, 0, (hi - lo + 1) * sizeof(*temp));
    for (int i = lo; i <= hi; i++)
    {
        int c = char_at(str[i], d);
        count[c]++;
    }
    for (int i = 1; i < 256; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = lo; i <= hi; i++)
    {
        int c = char_at(str[i], d);
        memcpy(temp[count[c] - 1], str[i], strlen(str[i]) + 1);
        count[c]--;
    }
    for (int i = lo; i <= hi; i++)
    {
        strcpy(str[i], temp[i - lo]);
    }
    for (int i = 0; i < 255; i++)
    {
        MSD_sort(str, lo + count[i], lo + count[i + 1] - 1, d + 1);
    }
    free(temp);
}

void print(char **str, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s ", str[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    // printf("Enter the number of strings: ");
    scanf("%d", &n);

    char **str = malloc(n * sizeof(char *));
    // printf("Enter the strings:\n");
    for (int i = 0; i < n; i++)
    {
        str[i] = malloc(100 * sizeof(char));
        scanf("%s", str[i]);
    }

    // printf("Unsorted array: ");
    // print(str, n);

    MSD_sort(str, 0, n - 1, 0);

    // printf("Sorted array: ");
    print(str, n);

    for (int i = 0; i < n; i++)
    {
        free(str[i]);
    }
    free(str);

    return 0;
}