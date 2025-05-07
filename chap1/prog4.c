/* Program 4 */
main()
{
    int i = 3;
    int *j;
    int **k;

    j = &i;
    k = &j;

    printf("\nAddress of i = %u", &i);
    printf("\nAddress of i = %u", j);
    printf("\nAddress of i = %u", *k);
    printf("\nAddress of j = %u", &j);
    printf("\nAddress of j = %u", k);
    printf("\nAddress of j = %u", *k + 1);

    printf("\n\nValue of j = %u", j);
    printf("\nValue of k = %u", k);
    printf("\nValue of i = %d", i);
    printf("\nValue of i = %d", *(&i));
    printf("\nValue of i = %d", **k);
}