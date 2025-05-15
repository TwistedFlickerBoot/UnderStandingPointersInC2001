/* Program 59 */
/* program to maintain a doubly linked list */
#include <stdio.h> /* included for C89 */
#include <malloc.h> /* book uses alloc.h */

/* structure for representing a node of the doubly linked list */
struct node
{
    struct dnode *prev; /* pointer to the previous node */
    int data; /* data part */
    struct dnode *next; /* pointer to the next node */
};

main()
{
    struct dnode *p;

    p = NULL; /* empty doubly linked list */

    d_append(&p, 11); 
    d_append(&p, 21);

    /* clrscr(); */
    printf("\nNo. of elements in the DLL = %d\n", d_count(p));

    d_addatbeg(&p, 33);
    d_addatbeg(&p, 55);

    d_display(p);
    printf("\nNo. of elements in the DLL = %d\n", d_count(p));

    d_addafter(&p, 1, 4000);
    d_addafter(&p, 2, 9000);

    d_display(p);
    printf("\nNo. of elements in the DLL = %d\n", d_count(p));

    d_delete(&p, 51);
    d_delete(&p, 21);

    d_display(p);
    printf("\nNo. of elements in the DLL = %d\n", d_count(p));
}

/* adds a new node at the end of the doubly linked list */
d_append(struct dnode **s, int num)
{
    struct dnode *r, *q = *s;

    /* if the linked list is empty */
    if(*s == NULL)
    {
        /* create new node */
        *s = malloc(sizeof(struct dnode));
        (*s)->prev = NULL;
        (*s)->data = num;
        (*s)->next = NULL;
    }
    else
    {
        /* traverse the linked list till the last node is reached */
        while(q->next != NULL)
            q = q->next;
    
        /* add a new node at the end */
        r = malloc(sizeof(struct dnode));
        r->data = num;
        r->next = NULL;
        r->prev = q;
        q->next = r;
    }
}

/* adds a new node at the beginning of the linked list */
d_addatbeg(struct dnode **s, int num)
{
    struct dnode *q;

    /* create a new node */
    q = malloc(sizeof(struct dnode));

    /* assign data and pointer to the new node */
    q->prev = NULL;
    q->data = num;
    q->next = *s;

    /* make new node the head node */
    (*s)->prev = q;
    *s = q;
}

/* adds a new node after the specified number of nodes */
d_addafter(Struct dnode *q, int loc, int num)
{
    struct dnode *temp;
    int i;

    /* skip to desired position */
    for(i=0; i < loc; i++)
    {
        q = q->next;
        /* if end of linked list is encountered*/
        if(q == NULL)
        {
            printf("\nThere are less than %d elements", loc);
            return;
        }
    }

    /* insert new node */
    q = q->prev;
    temp = malloc(sizeof(struct dnode));
    temp->data = num;
    temp->prev = q;
    temp->next = q->next;
    temp->next->prev = temp;
    q->next = temp;
}

/* displays the contents of the linked list */
d_display(struct dnode *q)
{
    printf("\n");

    /* traverse the entire linked list */
    while(q != NULL)
    {
        printf("%2d <-->", q->data);
        q = q->next;
    }

    printf("--< NULL\n");
}

/* counts the number of nodes present in the linked list */
d_count(struct dnode *q)
{
    int c = 0;

    /* traverse the entire linked list */
    while (q != NULL)
    {
        q = q->next;
        c++;
    }
    
    return c;
}

/* deletes the specified node from the double linked list */
d_delete(struct dnode **s, int num)
{
    struct dnode *q = *s;

    /* traverse the entire linked list */
    while(q != NULL)
    {
        /* if node to be deleted is found */
        if(q->data == num)
        {
            /* if node to be deleted is the first node */
            if(q == *s)
            {
                *s = (*s)-next;
                (*s)->prev = NULL;
            }
            else
            {
                /* if node to be deleted is the last node */
                if(q->next == NULL)
                    q->prev->next = NULL;
                else
                /* if node to be deleted is any intermediate node */
                {
                    q->prev->next = q->next;
                    q->next->prev = q->prev;
                }
                free(q);
            }
            return;
        }
        q = q->next;
    }
    printf("\n%d not found.", num);
}