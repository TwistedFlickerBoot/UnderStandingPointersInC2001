/* Program 38 */
#include <stdio.h>

main()
{
    char arr[] = "Bambozzled";
    int len1, len2;

    len1 = xstrlen(arr);
    len2 = xstrlen("HumptyDumpty");
    printf("\nstring = %s length = %d", arr, len1);
    printf("\nstring = %s length = %d", "HumptyDumpty", len2);   
}

xstrlen(char *s)
{
    int length = 0;
    while(*s != '\0')
    {
        length++;
        s++;
    }

    return(length);
}