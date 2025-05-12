/* Program 51 */
/* Passing address of a structure variable */
#include <stdio.h> /* Included for C89 */
struct book
{
    char name [25];
    char author [25];
    int callno;
};

main()
{
    void display (struct book *);
    struct book b1 = {"Let us C", "YPK", 101};
    display (&b1);
}

void display (struct book *b) /* b is a pointer to as structure */
{
    printf("\n%s\n%s\n%d\n", b->name, b->author, b->callno);
}