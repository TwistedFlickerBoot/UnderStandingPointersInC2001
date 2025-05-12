/* Program 33 */
#include <stdio.h> /* Added this for the printf to work as I am using */
                   /* C89 Standard*/
main()
{
    char name[] = "Klinsman";
    int i;

    i = 0;
    while(name[i])
    {
        printf("\n%c %c %c %c", name[i], *(name + i), *(i + name), i[name]);
        i++;
    }
}