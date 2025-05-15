/* Program 55 */
/* Program to reverse a linked list */
#include <stdio.h> /* included for C89 */
#include <malloc.h> /* original book calls for alloc.h */

/* structure containing a data part and link part */
struct node
{
    int data; /* data part */
    struct node *link; /* link part */
};

reverse(struct node **); /* function prototype */
/* function to reverse a linked list */

main()
{
    struct node *p;

    p = NULL; /* empty linked list */

    addatbeg (&p, 1); /* add 1 at beginning */
    addatbeg (&p, 2); /* add 2 at beginning */
    addatbeg (&p, 3); /* add 3 at beginning */
    addatbeg (&p, 4); /* add 4 at beginning */
    addatbeg (&p, 5); /* add 5 at beginning */
    addatbeg (&p, 6); /* add 6 at beginning */

    /* clrscr(); */
    display (p); /* display the linked list */
    printf("\nNo. of elements in the linked list = %d", count(p));

    reverse(&p); /* reverse the linked list */
    display (p); /* display the linked list */
    printf("\nNo. of elements in the linked list = %d", count(p));
}

/* adds a new node at the beginning of the linked list */
addatbeg(struct node **q, int num)
{
    struct node *temp; /* pointer to a new node */

    /* Add new node */
    temp = malloc(sizeof(struct node)); /* allocate memory */
    temp->data = num; /* assign data part */
    temp->link = *q; /* assign link part */
    *q = temp; /* assign new node to the head */
}

reverse(struct node **x)
{
    struct node *q, *r, *s; /* pointers to traverse the list */

    q = *x; /* assign head to q */
    r = NULL; /* assign NULL to r */

    /* traverse the entire linked list */
    while(q != NULL)
    {
        s =r;
        r = q; /* assign q to r */
        q = q->link; /* assign next node to q */
        r->link = s; /* assign previous node to r */
    }

    *x = r; /* assign new head to the linked list */
}

/* displays the contents of the linked list */
display(struct node *q)
{
    printf("\n");

    /* traverse the entire linked list */
    while(q != NULL)
    {
        printf("%d", q->data); /* display data part */
        q = q->link; /* assign next node to q */
    }
}

/* counts the number of nodes present in the linked list */
count (struct node *q)
{
    int c = 0; /* counter variable */

    /* traverse the entire linked list */
    while(q != NULL)
    {
        q = q->link; /* assign next node to q */
        c++; /* increment counter */
    }
    return c; /* return the count */
}