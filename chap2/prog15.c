/* Program 15 */
main()
{
    int i = 3, *x;
    float j = 1.5, *y;
    char k = 'c', *z;

    printf("\nValue of i = %d", i);
    printf("\nValue of j = %f", j);
    printf("\nValue of k = %c", k);

    x = &i;
    y = &j;
    z = &k;

    printf("\n\nOriginal value in x = %u", x);
    printf("\nOriginal value in y = %u", y);
    printf("\nOriginal value in z = %u", z);

    x++;
    y++;
    z++;

    printf("\n\nNew value in x = %u", x);
    printf("\nNew value in y = %u", y);
    printf("\nNew value in z = %u", z);
}