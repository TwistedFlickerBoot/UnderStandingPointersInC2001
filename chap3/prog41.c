/* Program 41 */
#include <stdio.h> /* Included for C89 */

main()
{
    float r, a;
    const float PI = 3.14;

    printf("\nEnter radius: ");
    scanf("%f", &r);

    a = PI * r * r;
    printf("\nArea of circle = %f", a);
}