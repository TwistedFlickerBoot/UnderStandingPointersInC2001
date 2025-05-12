/* Program 50 */
#include <stdio.h> /* Included for C89 */
main()
{
    struct book
    {
        char name[25];
        char author[25];
        int callno;
    };
    struct book b1 = {"Let us C", "YPK", 101};
    struct book *ptr;

    ptr = &b1; /* ptr points to b1 */
    printf("%s %s %d\n", b1.name, b1.author, b1.callno);
    printf("%s %s %d\n", ptr->name, ptr->author, ptr->callno);
}