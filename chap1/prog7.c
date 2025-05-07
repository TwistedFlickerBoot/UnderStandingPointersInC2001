/* Program 7 */
main()
{
    int a = 10; /* Integer 10 is assigned to a upon initialization */
    int b = 20; /* Integer 20 is assigned to b upon initialization */

    swapv(int x, int y); /* Function prototype for swapv */
    printf("\na = %d", a); /* Print the value of a */
    printf("\nb = %d", b); /* Print the value of b */
}

swapv(int x, int y) /* Function definition for swapv */
{
    int t; /* Temporary variable t */
    t = x; /* Assign the value of x to t */
    x = y; /* Assign the value of y to x */
    y = t; /* Assign the value of t to y */

    printf("\nx = %d", x); /* Print the value of x */
    printf("\ny = %d", y); /* Print the value of y */
}