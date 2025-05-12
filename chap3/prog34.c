/* Program 34 */
/* Program to print string elements using pointer arithmetic */
#include <stdio.h> /* included to compile c89 */
main()
{
    char name[] = "Klinsman";
    char *ptr;

    ptr = name; /* pointer to the first element of the array/base address */

    while(*ptr != '\0') /* loop until null character */
    {
        printf("%c", *ptr); /* print the character pointed to by ptr */
        ptr++; /* increment pointer to point to the next character */
    }
}