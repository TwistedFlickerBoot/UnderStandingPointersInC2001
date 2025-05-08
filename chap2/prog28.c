/* Program 28 */
/* Three ways of returning a 2-D array from a function */
#define ROW 3
#define COL 4

main()
{
    int i, j;

    int *a;
    int *fun1();

    int (*b)[COL];
    int( *fun2())[COL];
    int *p;

    int (*c)[ROW][COL];
    int (*fun3())[ROW][COL];

    clrscr();
    a = fun1(); /* 1st way of returning a 2-D array */

    printf("\nArray a[][] in main():\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
            printf("%d ", *(a+i * COL + j));
        printf("\n");
    }
    getch();

    b = fun2(); /* 2nd way of returning a 2-D array */

    printf("\nArray b[][] in main():\n");
    for(i=0;i<ROW;i++)
    {
        p = b + i;
        for(j=0;j<COL;j++)
        {
            printf("%d ", *p);
            p++;
        }
        printf("\n");
    }
    getch();
    c = fun3(); /* 3rd way of returning a 2-D array */

    printf("\nArray c[][] in main():\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
            printf("%d ", (*c)[i][j]);
        printf("\n");
    }
    getch();
}

int *fun1()
{
    static int a[ROW][COL] = { 
        {1, 2, 3, 4}, 
        {5, 6, 7, 8},
        {9, 0, 1, 6}
     };
    int i, j;
    printf("\nArray a[][] in fun1():\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return (int *)a; /* 1st way of returning a 2-D array */
}

int (*fun2())[COL]
{
    static int b[ROW][COL] = { 
        {1, 2, 3, 4}, 
        {5, 6, 7, 8},
        {9, 0, 1, 6}
     };
    int i, j;
    printf("\nArray b[][] in fun2():\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    return b; /* 2nd way of returning a 2-D array */
}

int (*fun3())[ROW][COL]
{
    static int c[ROW][COL] = { 
        {6, 3, 9, 1}, 
        {2, 1, 5, 7},
        {4, 1, 1, 6}
     };

    int i, j;
    printf("\nArray c[][] in fun3():\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return (int (*)[ROW][COL])c; /* 3rd way of returning a 2-D array */
}