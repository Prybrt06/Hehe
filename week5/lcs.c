#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

int lcs_simple(char *str1, char *str2, int len1, int len2)
{
    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }

            printf("%d ", dp[i][j]);
        }

        printf("\n");
    }

    char str[100];

    int k = dp[len1][len2] - 1;

    int i = len1, j = len2;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            str[k--] = str1[i - 1];
            i--;
            j--;
        }

        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }

            else
            {
                i--;
            }
        }
    }

    printf("%s\n", str);

    return dp[len1][len2];
}


int main()
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int lcs_length;
    char lcs_str[MAX_LENGTH + 1];
    memset(lcs_str, '\0', sizeof(lcs_str)); // Initialize the LCS string to NULL

    // lcs(str1, str2, len1, len2, &lcs_length, lcs_str);
    lcs_length = lcs_simple(str1, str2, len1, len2);

    printf("The length of the Longest Common Subsequence is: %d\n", lcs_length);
    printf("The Longest Common Subsequence is: %s\n", lcs_str);

    return 0;
}
