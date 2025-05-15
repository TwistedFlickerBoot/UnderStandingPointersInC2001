/* Program 53 */
/* Program to maintain a linked list */
#include <stdio.h> /* For C89 */
#include <malloc.h>

/* Structure containing a data part and link part */
struct node 
{
    int data; /* Data part */
    struct node *link; /* Link part */
};

main()
{
    struct node *p;
    p = NULL; /* empty linked list */

    printf("\nNo. of elements in the Linked List = %d", count(p));
    append(&p, 1);
    append(&p, 2);
    append(&p, 3);
    append(&p, 4);
    append(&p, 17);

    /* clrscr(); */
    display(p);

    addatbeg(&p, 999);
    addatbeg(&p, 888);
    addatbeg(&p, 777);

    display(p);

    addafter(p, 7, 0);
    addafter(p, 2, 1);
    addafter(p, 1, 99);

    display(p);
    printf("\nNo. of elements in the Linked List = %d", count(p));

    delete (&p, 888);
    delete (&p, 1);
    delete (&p, 10);

    display(p);
    printf("\nNo. of elements in the Linked List = %d", count(p));
}

/*adds a node at the end of a linked list */
append(struct node **q, int num)
{
    struct node *temp, *r;
    temp = *q;

    if(*q == NULL) /* if the list is empty, create first node */
    {
        temp = malloc(sizeof(struct node));
        temp->data = num;
        temp->link = NULL;
        *q = temp;
    }
    else 
    {
        temp = *q;

        /* goto last node */
        while(temp->link != NULL)
            temp = temp->link;
        
        /* add node at the end */
        r = malloc(sizeof(struct node));
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}

/* adds a new node at the beginning of the linked list */
addatbeg(struct node **q, int num)
{
    struct node *temp;

    /* add new node */
    temp = malloc(sizeof(struct node));

    temp->data = num;
    temp->link = *q; /* link new node to the first node */
    *q = temp; /* make new node as first node */
}

/* adds a new node after the specified number of nodes */
addafter(struct node *q, int loc, int num)
{
    struct node *temp, *r;
    int i;

    temp = q;
    /* skip to desired portion */
    for(i = 0; i < loc; i++)
    {
        temp = temp->link;

        /* if end of linked list is encountered */
        if(temp == NULL)
        {
            printf("\n There are less than %d elements in the list", loc);
            return;
        }
    }

    /* insert new node */
    r = malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link; /* link new node to the next node */
    temp->link = r; /* link previous node to new node */
}

/* displays the contents of the linked list */
display(struct node *q)
{
    printf("\n");
    
    /* traverse the entire list */
    while(q != NULL)
    {
        printf("%d -> ", q->data);
        q = q->link; /* move to next node */
    }
}

/* counts the number of nodes present in the linked list */
count(struct node *q)
{
    int c = 0;

    /* traverse the entire list */
    while(q != NULL)
    {
        q = q->link; /* move to next node */
        c++;
    }
    return c; /* return the count */
}

/* deletes the specified node from the linked list */
delete(struct node **q, int num)
{
    struct node *old, *temp;

    temp = *q;

    while(temp != NULL)
    {
        if(temp->data == num) /* if node to be deleted is found */
        {
            if(temp == *q) /* if first node is to be deleted */
            {
                *q = temp->link; /* make next node as first node */
                free(temp); /* free the memory */
                return;
            }
            /* deletes the intermediate nodes in the linked list */
            else
            {
                old->link = temp->link; /* link previous node to next node */
                free(temp); /* free the memory */
                return;
            }
        }

        /* traverse the linked list till the last node is reached */
        else
        {
            old = temp; /* store the previous node */
            temp = temp->link; /* move to next node */
        }
    }

    printf("\nElement %d not found", num);
}