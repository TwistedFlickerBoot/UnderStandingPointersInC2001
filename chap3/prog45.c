/* Program 45 */
#include <stdio.h> /* Included for C89 */

main()
{
    char *names[] = {
        "akshay",
        "parag",
        "raman",
        "srinivas",
        "gopal",
        "rajesh"
    };
    char *temp;

    printf("\nOriginal: %s %s", names[2], names[3]);
    temp = names[2];
    names[2] = names[3];
    names[3] = temp;

    printf("\nNew: %s %s", names[2], names[3]);
}