#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*
 * version_compare: 
 * - if v1 > v2 return 1
 * - if v1 = v2 return 0
 * - if v1 < v2 return -1
 * - 1.0 is greater than 1
 * - 1.10 is greater than 1.2
 */

int version_compare(const char *v1, const char *v2)
{
    // strategy loop over strtok calls and compare until we run out of tokens
    char *atok = NULL, *btok = NULL, *a = NULL, *b = NULL;
    int aarr[10], barr[10], i = 0;

    memset(aarr, -1, sizeof(int) * 10);
    memset(barr, -1, sizeof(int) * 10);

    a = malloc(sizeof(char) * strlen(v1));
    b = malloc(sizeof(char) * strlen(v2));

    memcpy(a, v1, sizeof(strlen(v1)));
    memcpy(b, v2, sizeof(strlen(v2)));

    i = 0;
    atok = strtok(a, ".");
    printf("atok = %s\n", atok);
    aarr[i] = atoi(atok);
    i++;

    while ((atok = strtok(NULL, ".")) != NULL)
    {
        printf("atok = %s\n", atok);
        aarr[i] = atoi(atok);
        i++;
    }

    i = 0;
    btok = strtok(b, ".");
    printf("btok = %s\n", btok);
    barr[i] = atoi(btok);
    i++;

    while ((btok = strtok(NULL, ".")) != NULL)
    {
        printf("btok = %s\n", btok);
        barr[i] = atoi(btok);
        i++;
    }

    i = 0;
    while (aarr[i] != -1)
    {
        printf("aarr[i] = %d, barr[i] = %d\n", aarr[i], barr[i]);
        // if has run out of numbers then a wins
        if (barr[i] == -1)
            return 1;
        else if (aarr[i] > barr[i])
            return 1;
        else if (aarr[i] < barr[i])
            return -1;
        i++;
    }
    // if a has run out of numbers and b still has any, then b wins
    if (barr[i] == -1)
        return 0;
    else
        return -1;
}

int main(void)
{
    assert(version_compare("1.1", "1.0") == 1);
    assert(version_compare("1.0", "1.1") == -1);
    assert(version_compare("1.0", "1.0") == 0);
    assert(version_compare("1", "1.0") == -1);
    assert(version_compare("1.0", "1") == 1);
    return 0;
}
