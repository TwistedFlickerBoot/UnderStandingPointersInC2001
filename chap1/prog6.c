/* Program 6 */
main()
{
    int i = 54; /* Integer 54 is stored in i upon initialization */
    float a = 3.14; /* Float 3.14 is stored in a upon initialization */
    char *ii, *aa; /* ii and aa are declared as pointers to char */

    ii = (char *)&i; /* ii points to the address of i */
    aa = (char *)&a; /* aa points to the address of a */
    printf("\nAddress contained in ii= %u", ii); /* Prints the address of i */
    printf("\nAddress contained in aa= %u", aa); /* Prints the address of a */
    printf("\nValue at the address contained in ii= %d", *ii); /* Prints the value at the address of i */
    printf("\nValue at the address contained in aa= %f", *aa); /* Prints the value at the address of a */
}