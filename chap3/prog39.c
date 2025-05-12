/* Program 39 */
#include <stdio.h> /* Included for C89 */

main()
{
    char str1[] = "Hello";
    char str2[10];

    char *s = "Good Morning";
    char *q;

    /* str2 = str1; /* This is not allowed in C ERROR */
    q = s; /* This is allowed in C */
}