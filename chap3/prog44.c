/* Program 44 */
#include <stdio.h> /* Included for C89 */
#include <string.h> /* Included for string functions */
#define FOUND 1
#define NOT_FOUND 0
main()
{
    char masterlist[6][10] = {
        "akshay",
        "parag",
        "raman",
        "srinivas",
        "gopal",
        "rajesh"
    };
    int i, flag, a;
    char yourname[10];

    printf("Enter your name: ");
    scanf("%s", yourname);

    flag = NOT_FOUND;
    for (i = 0; i <= 5; i++)
    {
        a = strcmp(masterlist[i], yourname);
        if (a == 0)
        {
            printf("Welcome, you can enter the palace");
            flag = FOUND;
            break;
        }
    }
    if (flag == NOT_FOUND)
    {
        printf("Sorry, you are a trespasser");
    }
}