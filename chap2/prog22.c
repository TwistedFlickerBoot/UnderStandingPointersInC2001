/* Program 22 */
/* Refer figure 2.3 given in the previous section */
main()
{
    int stud[5][2] = {
        {1234,56},
        {1212,33},
        {1434,80},
        {1312,78},
        {1203,75}
    };
    int i, j;

    for(i=0;i<=4;i++)
        printf("\nAddress of %d th 1-D array = %u", i, stud[i]);
}