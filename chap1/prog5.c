/* Program 5 */
main()
{
    char c, *cc;
    int i, *ii;
    float a, *aa;

    c = 'A'; /*ASCII Value of A gets stored in c */
    i = 54; /*Integer Value of 54 gets stored in i */
    a = 3.14; /*Float Value of 3.14 gets stored in a */
    cc = &c; /*Address of c gets stored in cc */
    ii = &i; /*Address of i gets stored in ii */
    aa = &a; /*Address of a gets stored in aa */
    printf("\nAddress contained in cc = %u", cc); /*Address of c is printed */
    printf("\nAddress contained in ii = %u", ii); /*Address of i is printed */
    printf("\nAddress contained in aa = %u", aa); /*Address of a is printed */
    printf("\nValue of c = %c", *cc); /*Value of c is printed using pointer cc */
    printf("\nValue of i = %d", *ii); /*Value of i is printed using pointer ii */
    printf("\nValue of a = %f", *aa); /*Value of a is printed using pointer aa */
}