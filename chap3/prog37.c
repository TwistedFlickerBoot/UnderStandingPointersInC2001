/* Program 37 */
#include <stdio.h> /* Included for C89 */
#include <string.h> /* Included for string functions */

main()
{
    char str1[20] = "Bamboozled";
    char str2[20] = "Chap";
    char str3[20];
    int l, k;

    l = strlen(str1);
    printf("\nlength of string = %d", l);

    strcpy(str3, str1);
    printf("\nafter copying, str3 = %s", str3);

    k = strcmp(str1, str2);
    printf("\nnon comparing str1 and str2 = %d", k);

    k = strcmp(str3, str1);
    printf("\nnon comparing str3 and str1 = %d", k);

    strcat(str1, str2);
    printf("\nnon concatenating str1 = %s", str1);
}