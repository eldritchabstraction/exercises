#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int is_palindrome(const char * blep)
{
    if (!blep || strlen(blep) == 0)
        return 0;

    char * copy = malloc(sizeof(char) * strlen(blep));
    memcpy(copy, blep, sizeof(char) * sizeof(blep));

    for (char * p = copy; *p; p++)
        *p = tolower(*p);


    int left = 0, right = strlen(blep) - 1;

    while(left < right)
    {
        printf("left = %c, right = %c\n", copy[left], copy[right]);
        if (copy[left] != copy[right])
            return 0;

        left++;
        right--;
    }

    return 1;
}

int main (void)
{
    assert(is_palindrome("") == 0);
    assert(is_palindrome(NULL) == 0);
    printf("erroneous cases passed\n");
    assert(is_palindrome("civic") == 1);
    assert(is_palindrome("abba") == 1);
    assert(is_palindrome("aBa") == 1);
    assert(is_palindrome("statss") == 0);
    assert(is_palindrome("abracadabra") == 0);
    printf("lower case passed\n");
    assert(is_palindrome("ABa") == 1);
    assert(is_palindrome("civiC") == 1);
    printf("upper lower case passed\n");
}
