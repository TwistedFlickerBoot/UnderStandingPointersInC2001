/* Program 26 */
main()
{
    int a[2][3][2]={
        {
            {2,4},
            {7,8},
            {3,4}
        },
        {
            {2,2},
            {2,3},
            {3,4}
        }
    };

    printf("\n%u", a);
    printf("\n%u", *a);
    printf("\n%u", **a);
    printf("\n%d", ***a);
    printf("\n%u", a+1);
    printf("\n%u", *a+1);
    printf("\n%u", **a+1);
    printf("\n%d", ***a+1);
}