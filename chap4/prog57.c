/* Program 57 */
/* program to omplement a queue as a linked list */
#include <stdio.h> /* included for C89 */
#include <malloc.h> /* book uses alloc.h */

struct node
{
    int data;
    struct node *link;
};

void addq(struct node **, struct node **, int); /* add an element to the queue */
delq(struct node **, struct node **); /* delete an element from the queue */

main()
{
    struct node *front, *rear;
    int item;

    front = rear = NULL; /* empty queue */

    addq(&front, &rear, 11);
    addq(&front, &rear, 12);
    addq(&front, &rear, 13);
    addq(&front, &rear, 14);
    addq(&front, &rear, 15);
    addq(&front, &rear, 16);
    addq(&front, &rear, 17);

    /* clrscr(); */
    q_display(front);
    printf("\nNo. of items in queue = %d", count(front));

    printf("\n\nItems extracted from queue: ");
    item = delq(&front, &rear);
    printf("%d ", item);

    item = delq(&front, &rear);
    printf("%d ", item);

    item = delq(&front, &rear);
    printf("%d ", item);

    printf("\n");
    q_display(front);
    printf("\nNo. of items in queue = %d", count(front));
}

/* adds a new element at the end of queue */
void addq(struct node **f, struct node **r, int item)
{
    struct node *q;

    /* create new node */
    q = malloc(sizeof(struct node));
    q->data = item;
    q->link = NULL;

    /* if queue is empty */
    if(*f == NULL)
        *f = q;
    else
        (*r)->link = q; /* link the new node to the end of queue */

    *r = q; /* make the new node the rear of queue */
}

/* removes an element from front of queue */
delq(struct node **f, struct node **r)
{
    struct node *q;
    int item;

    /* if queue is empty */
    if(*f == NULL)
        printf("\nQueue is empty");
    else
    {
        /* delete the node */
        q = *f; /* get the front node */
        item = q->data; /* get the data */
        *f = q->link; /* move front pointer to next node */
        free(q); /* free the node */

        /* if on deletion the queue has become empty */
        if(*f == NULL)
            *r = NULL; /* make rear pointer NULL */

        return(item); /* return the data */
    }
}

/* display all elements of the queue */
q_display(struct node *q)
{
    printf("\nfront -> ");

    /* traverse the entire linked list */
    while(q != NULL)
    {
        if(q->link == NULL)
            printf(" <- rear");

        printf("%2d ", q->data);
        q = q->link; /* move to next node */
    }
    printf("\n");
}

/* counts the number of nodes present in the linked list 
   representing a queue */
count(struct node *q)
{
    int c = 0;

    /* traverse the entire linked list */
    while(q!= NULL)
    {
        q = q->link; /* move to next node */
        c++; /* increment the count */
    }
    return(c); /* return the count */
}