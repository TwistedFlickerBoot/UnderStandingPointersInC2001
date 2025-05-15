/* Program 58 */
/* program to implement a dequeue as a linked list */
#include <stdio.h> /* Included for C89 */
#include <malloc.h> /* book uses alloc.h */

struct node
{
    int data;
    struct node *link;
};

void addqatend(struct node **, struct node **, int);
void addqatbeg(struct node **, struct node **, int);
delqatbeg(struct node **, struct node **);
delqatend(struct node **, struct node **);

main()
{
    struct node *front, *rear;
    int item;

    front = rear = NULL; /* empty queue */

    addqatend(&front, &rear, 11);
    addqatend(&front, &rear, 10);
    addqatend(&front, &rear, 12);
    addqatend(&front, &rear, 13);
    addqatend(&front, &rear, 14);
    addqatend(&front, &rear, 15);
    addqatend(&front, &rear, 16);
    addqatend(&front, &rear, 17);

    /* clrscr(); */
    q_display(front);
    printf("\nNo of items in queue = %d", count(front));

    printf("\n\nItems extracted from queue: ");
    item = delqatbeg(&front, &rear);
    printf("%d ", item);

    item = delqatbeg(&front, &rear);
    printf("%d ", item);

    item = delqatbeg(&front, &rear);
    printf("%d ", item);

    item = delqatbeg(&front, &rear);
    printf("%d ", item);

    printf("\n");
    q_display(front);
    printf("\nNo of items in queue = %d", count(front));
}

/* adds a new element at the end of queue */
void addqatend(struct node **f, struct node **r, int item)
{
    struct node *q;

    /* create new node */
    q = malloc(sizeof(struct node));
    q->data = item;
    q->link = NULL;

    /* if the queue is empty */
    if(*f == NULL)
        *f = q;
    else
        (*r)->link = q; /* link the new node to the last node */
    *r = q; /* make the new node the last node */
}

/* adds a new element at the beginning of the queue */
void addqatbeg(struct node **f, struct node **r, int item)
{
    struct node *q;
    int *temp;

    /* create new node */
    q = malloc(sizeof(struct node));
    q->data = item;
    q->link = NULL;

    /* if the queue is empty */
    if(*f == NULL)
        *f=*r = q;
    else
    {
        q->link = *f; /* link the new node to the first node */
        *r = *f; /* make the new node the last node */
        *f = q; /* make the new node the first node */
    }
}

/* removes an element from the front of queue */
delqatbeg(struct node **f, struct node **r)
{
    struct node *q;
    int item;

    /* if queue is empty */
    if(*f == NULL)
        printf("Queue is empty");
    else
    {
        /* delete the node */
        q = *f; /* get the first node */
        item = q->data; /* get the data */
        *f = q->link; /* make the next node the first node */
        free(q); /* free the memory */

        /* if on deletion the queue has become empty */
        if(*f == NULL)
            *r = NULL; /* make rear NULL */
        
        return item; /* return the data */
    }
}

/* removes an element from rear of queue */
delqatend(struct node **f, struct node **r)
{
    struct node *q, *rleft, *temp;
    int item;

    temp = *f;
    /* if queue is empty */
    if(*r == NULL)
        printf("queue is empty");
    else
    {
        /* traverse the queue to find the previous elements address */
        while(temp != *r)
        {
            rleft = temp;
            temp = temp->link;
        }
        /* delete the node */
        q = *r; /* get the last node */
        item = q->data; /* get the data */
        free(q); /* free the memory */

        *r = rleft; /* make the previous node the last node */
        (*r)->link = NULL; /* make the last node point to NULL */

        /* if on deletion the queue has become empty */
        if(*r == NULL)
            *f = NULL; /* make front NULL */

        return item; /* return the data */
    }
}

/* displays all elements of the queue */
q_display(struct node *q)
{
    printf("\nfront -> ");

    /* traverse the entire list */
    while(q != NULL)
    {
        if(q->link == NULL)
            printf(" <- rear");
        printf("%2d ", q->data);
        q = q->link; /* move to the next node */
    }
    printf("\n");
}

/* counts the number of nodes present in the linked list 
   representing a queue */
count(struct node *q)
{
    int c = 0;

    /* traverse the entire linked list */
    while(q != NULL)
    {
        q = q->link; /* move to the next node */
        c++; /* increment the count */
    }

    return c; /* return the count */
}