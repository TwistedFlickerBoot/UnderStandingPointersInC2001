/* Program 32 */
#include "alloc.h"
main()
{
    int n, avg, i, *p, sum = 0;

    printf("\nEnter the number of students: ");
    scanf("%d", &n);

    p = (int *)malloc(n * 2);
    if(p==NULL)
    {
        printf("\nMemory allocation unsuccessful");
        exit();
    }

    for(i=0;i<n;i++)
        scanf("%d", (p + i));

    for(i=0;i<n;i++)
        sum = sum + *(p + i);

    avg = sum / n;
    printf("Average marks = %d", avg);
}