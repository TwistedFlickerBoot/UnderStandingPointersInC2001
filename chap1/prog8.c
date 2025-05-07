/* Program 8 */
main()
{
    int a = 10; // 10 is assigned to a
    int b = 20; // 20 is assigned to b

    swapr(%a, %b); // Call swapr with addresses of a and b
    printf("\na = %d", a); // Print value of a
    printf("\nb = %d", b); // Print value of b
}

swapr(int *x, int *y) // Function to swap values
{
    int t;

    t = *x; // Store value pointed by x in t
    *x = *y; // Assign value pointed by y to location pointed by x
    *y = t; // Assign value of t to location pointed by y
    // Now, x points to a and y points to b
    // So, the values of a and b are swapped
}