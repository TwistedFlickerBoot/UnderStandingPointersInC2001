/* Program 9 */
main()
{
    int radius; 
    float area, perimeter;

    printf("Enter radius of circle: ");
    scanf("%d", &radius);
    areaperi(radius, &area, &perimeter);
    printf("Area = %f", area);
    printf("\nPerimeter = %f", perimeter);
}
/* Function to calculate area and perimeter of circle */
areaperi(int r, float *a, float *p)
{
    *a = 3.14 * r * r; // Area = pi * r^2
    *p = 2 * 3.14 * r; // Perimeter = 2 * pi * r
}