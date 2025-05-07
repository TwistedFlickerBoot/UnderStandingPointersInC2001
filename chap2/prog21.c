/* Program 21 */
main()
{
    int stud[5][2] = {
        {1234, 56},
        {1212, 33},
        {1434, 80},
        {1312, 78},
        {1203, 75}
    };
    int i, j;

    for(i = 0; i<=4; i++)
    {
        printf("\n");
        for(j = 0; j <= 1; j++)
            printf("%d ", stud[i][j]);
    }
}