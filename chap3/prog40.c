/* Program 40 */
#include <stdio.h> /* Included for C89 */

main()
{
    char str1[] = "Hello";
    char *p = "Hello";
    /* str1 = "Bye"; /* Error: str1 is not a pointer ERROR */
    p = "Bye"; /* OK: p is a pointer */
}