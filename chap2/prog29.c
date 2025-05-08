/* Program 29 */
/* Four ways of returning a 3-D array from a function */
#define SET 2
#define ROW 3
#define COL 4

main()
{
    int i, j, k;

    int *a;
    int *fun1();

    int (*b)[COL];
    int (*fun2())[COL];
    int (*c)[ROW][COL];
    int (*fun3())[ROW][COL];
    int *p;

    int (*d)[SET][ROW][COL];
    int (*fun4())[SET][ROW][COL];

    clrscr();
    a = fun1(); 

    printf("\nArray a[][][] in main():\n");
    for(i=0;i<SET;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
                printf("%d ",*(a + i * ROW * COL + j * COL + k));
            printf("\n");
        }
        printf("\n");
    }
    getch();

    b = fun2();
    printf("\nArray b[][][] in main():\n");
    for(i=0;i<SET;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
                printf("%d ", *p);
                p++;
            printf("\n");
        }
        printf("\n");
    }
    getch();

    c = fun3();
    printf("\nArray c[][][] in main():\n");
    for(i=0;i<SET;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
                printf("%d ",*p);
                p++;
            printf("\n");
        }
        printf("\n");
    }
    getch();

    d = fun4();
    printf("\nArray d[][][][] in main():\n");
    for(i=0;i<SET;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
                printf("%d ",(*d)[i][j][k]);
                p++;
            printf("\n");
        }
        printf("\n");
    }
    getch();
}

int *fun1()
{
    int i, j, k;
    static int a[SET][ROW][COL] = {
        {
            1,2,3,4,
            5,6,7,8,
            9,3,2,1
        },
        {
            2,3,5,7,
            4,3,9,2,
            1,6,3,6
        }
    };

    printf("\nArray a[][][] in fun1():\n");
    for(i=0;i<SET;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
                printf("%d ",a[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
    return (int *)a;
}

int (*fun2())[COL]
{
    int i, j, k;
    static int b[SET][ROW][COL] = {
        {
            9,4,6,4,
            1,3,2,1,
            7,5,1,6
        },
        {
            6,3,9,1,
            2,1,5,7,
            4,1,1,6
        }
    };

    printf("\nArray b[][][] in fun2():\n");
    for(i=0;i<SET;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
                printf("%d ",b[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
    return (int (*)[COL])b;
}

int (*fun3())[ROW][COL]
{
    int i, j, k;
    static int c[SET][ROW][COL] = {
        {
            9,4,6,4,
            1,3,2,1,
            7,5,1,6
        },
        {
            6,3,9,1,
            2,1,5,7,
            4,1,1,6
        }
    };

    printf("\nArray c[][][] in fun3():\n");
    for(i=0;i<SET;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
                printf("%d ",c[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
    return (int (*)[ROW][COL])c;
}

int (*fun())[SET][ROW][COL]
{
    int i, j, k;
    static int d[SET][ROW][COL] = {
        {
            3,1,8,5,
            9,6,5,2,
            2,0,1,6
        },
        {
            7,3,2,7,
            1,4,2,3,
            9,1,0,6
        }
    };

    printf("\nArray d[][][][] in fun4():\n");
    for(i=0;i<SET;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
                printf("%d ",d[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
    return (int (*)[SET][ROW][COL])d;
}