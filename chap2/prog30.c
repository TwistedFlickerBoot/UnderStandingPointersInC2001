/* Program 30 */
main()
{
    int *arr[4]; // array of integer pointers
    int i = 31, j = 5, k =19, l = 71, m;

    arr[0]=&i; // arr[0] points to i
    arr[1]=&j; // arr[1] points to j
    arr[2]=&k; // arr[2] points to k
    arr[3] = &l;
    for(m=0;m<=3; m++)
        printf("\n%d", *(arr[m])); // prints the values of i, j, k, l)
}