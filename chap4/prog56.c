/* Program 56 */
/* program to implement a stack as a linked list */
#include <stdio.h> /* included for C89 */
#include <malloc.h> /* book uses alloc.h */

struct node 
{
    int data;
    struct node *link;
};

push(struct node **, int);
pop(struct node **);

main()
{
    struct node *top; /* pointer to the top of the stack */
    int item;

    top = NULL; /* empty stack */

    push(&top, 11);
    push(&top, 12);
    push(&top, 13);
    push(&top, 14);
    push(&top, 15);
    push(&top, 16);
    push(&top, 17);

    /* clrscr(); */

    stack_display(top);
    printf("No. of items in the stack = %d", count(top));

    printf("\nItems extracted from the stack: ");
    item = pop(&top);
    printf("%d ", item);

    item = pop(&top);
    printf("%d ", item);

    item = pop(&top);
    printf("%d ", item);

    stack_display(top);
    printf("No. of items in stack = %d", count(top));
}

/* adds a new element on the top of stack */
push(struct node **s, int item)
{
    struct node *q;
    q = malloc(sizeof(struct node));
    q->data = item;
    q->link = *s;
    *s = q;
}

/* removes an element from top of stack */
pop(struct node **s)
{
    int item;
    struct node *q;

    /* if stack is empty */
    if(*s == NULL)
        printf("Stack is empty");
    else
    {
        q = *s;
        item = q->data;
        *s = q->link;
        free(q);
        return item;
    }
}

/* displays whole of the stack */
stack_display(struct node *q)
{
    printf("\n");

    /* traverse the entire linked list */
    while(q != NULL)
    {
        printf("%2d ", q->data);
        q = q->link;
    }
    printf("\n");
}

/* counts the number of nodes present in the linked list 
   representing the stack*/
count(struct node *q)
{
    int c = 0;

    /* traverse the entire linked list */
    while(q != NULL)
    {
        q = q->link;
        c++;
    }
    return c;
}