/* Program 54 */
/* Program for adding and deleting nodes from an ascending order */
/* linked list */
#include <stdio.h> /* Included for C89 */
#include <malloc.h> /* Book uses alloc.h */

struct node {
    int data;
    struct node *link;
};

main()
{
    struct node *p;
    p = NULL; /* empty linked list */

    add(&p, 5);
    add(&p, 1);
    add(&p, 6);
    add(&p, 4);
    add(&p, 7);

    /* clrscr(); */
    display(p);
    printf("\nNo. of elements in the Linked List = %d", count(p));

    delete(&p, 7);
    delete(&p, 4);
    delete(&p, 5);
    delete(&p, 9);

    display(p);
    printf("\nNo. of elements in the Linked List = %d", count(p));
}

/* adds node to an ascending order linked list */
add(struct node **q, int num)
{
    struct node *r, *temp = *q;
    r = malloc(sizeof(struct node));
    r->data = num;

    /* if list is empty or if new node is to be instered before */
    /* the first node */
    if(*q == NULL || (*q)->data > num)
    {
        *q = r;
        (*q)->link = temp;
    }
    else
    {
        /* traverse the entire linked list to search the position to insert */
        /* the first node */
        while(temp != NULL)
        {
            if(temp->data<=num && (temp->link->data > num || temp->link == NULL))
            {
                r->link = temp->link;
                temp->link = r;
                return;
            }
            temp = temp->link; /* go to the next node */
        }
    }
}

/* displays the contents of the linked list */
display(struct node *q)
{
    printf("\n");

    /* traverse the entire linked list */
    while(q != NULL)
    {
        printf("%d", q->data);
        q = q->link; /* go to the next node */
    }
}

/* counts the number of nodes present in the linked list */
count(struct node *q)
{
    int c = 0;

    /*traverse the entire linked list */
    while(q != NULL)
    {
        q = q->link; /* go to the next node */
        c++;
    }
    return c;
}

/* deletes the specified node from the linked list */
delete(struct node **q, int num)
{
    struct node *old, *temp;

    temp = *q;

    while(temp != NULL)
    {
        if(temp->data == num)
        {
            /* if node to be deleted is the first node on the linked list */
            if(temp == *q)
            {
                *q = temp->link;
                /* free the memory occupied by the node */
                free(temp);
                return;
            }
            /* deletes the intermediate node in the linked list */
            else
            {
                old->link = temp->link;
                /* free the memory occupied by the node */
                free(temp);
                return;
            }
        }
        /* traverse the linked list till the last node is reached */
        else
        {
            old=temp; /* old points to the previous node */
            temp=temp->link; /* go to the next node */
        }
    }
    printf("\nElement %d not found", num);
}