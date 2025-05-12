/* Program 46 */
#include <stdio.h> /* Included for C89 */
main()
{
    char *names[6];
    int i;
    for(i = 0; i <= 5; i++)
    {
        printf("\nEnter name: ");
        scanf("%s", names[i]);
    }
}