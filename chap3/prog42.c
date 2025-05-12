/* Program 42 */
#include <stdio.h> /* Included for C89 */
main()
{
    char str1[] = "Nagpur";
    char str2[10];

    xstrcpy(str2, str1); /* Copy str1 to str2 */
    printf("\n%s", str2); /* Print str2 */
}

xstrcpy(char *t, char *s)
{
    while(*t != '\0') 
    {
        *t = *s; /* Copy character from s to t */
        t++; /* Move to next character in t */
        s++; /* Move to next character in s */
    }
    *t = '\0'; /* Null-terminate the string */
}