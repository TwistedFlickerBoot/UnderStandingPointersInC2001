/* Program 24 */
main()
{
    int a[][4]={
        5,7,5,9,
        4,6,3,1,
        2,9,0,6
    };

    int *p;
    int (*q)[4];
    q = a; // q points to the first row of a

    printf("\n%u %u", p, q);
    p++;
    q++;
    printf("\n%u %u", p, q);
}