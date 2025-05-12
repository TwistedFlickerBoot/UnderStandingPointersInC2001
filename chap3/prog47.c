/* Program 47 */
/* Program to overcome  limitations of array of pointers to strings */
#include <stdio.h> /* Included for C89 */
#include <malloc.h> /* book calls for alloc.h */
#include <string.h>
main()
{
    char *name[5];
    char str[20];
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("Enter a string: ");
        gets(str);
        name[i] = (char *)malloc(strlen(str));
        strcpy(name[i], str);
    }
    for(i = 0; i < 5; i++)
        printf("%s\n", name[i]);
}