/* Program 60 */
/* Program to merge two linked lists, restricting the common elements
   to occur only once */
#include <stdio.h> /* included for C89 */
#include <malloc.h> /* book uses alloc.h */

struct node
{
    int data;
    struct node *link;
};

main()
{
    struct node *first, *second, *third;
    first = second = third = NULL; /* empty linked lists */

    add(&first, 1);
    add(&first, 2);
    add(&first, 3);
    add(&first, 4);
    add(&first, 5);
    add(&first, 6);
    add(&first, 7);

    /* clrscr(); */
    printf("First linked list: ");
    display(first);
    printf("\nNo. of elements in Linked List: %d", count(first));

    add(&second, 8);
    add(&second, 9);
    add(&second, 3);
    add(&second, 4);
    add(&second, 5);
    add(&second, 6);
    add(&second, 7);

    printf("\n\nSecond linked list: ");
    display(second);
    printf("\nNo. of elements in Linked List: %d", count(second));

    merge(first, second, &third);

    printf("\n\nThe concatenated list: ");
    display(third);
    printf("\nNo. of elements in Linked List: %d", count(third));
}

/* adds node to an ascending order linked list */
add(struct node **q, int num)
{
    struct node *r, *temp = *q;
    r = malloc(sizeof(struct node));
    r->data = num;

    /* if list is empty or if new node is to be inserted before the first node */
    if(*q == NULL || (*q)->data > num)
    {
        *q = r;
        (*q)->link = temp;
    }
    else
    {
        /* traverse the entire linked list to search the position to insert
           the new node */
        while(temp != NULL)
        {
            if(temp->data < num && (temp->link->data > num || temp->link == NULL))
            {
                r->link = temp->link;
                temp->link = r;
                break;
            }
            temp = temp->link; /* go to next node */
        }
        r->link = NULL; /* last node */
        temp->link = r; /* link the last node */
    }
}

display(struct node *q)
{
    printf("\n");

    /* traverse the entire linked list */
    while(q != NULL)
    {
        printf("%d ", q->data);
        q = q->link; /* go to next node */
    }
}

/* counts the number of nodes present in the linked list */
count(struct node *q)
{
    int c = 0;

    /* traverse the entire linked list*/
    while(q != NULL)
    {
        q=q->link; /* go to next node */
        c++; /* increment the count */
    }
    return c; /* return the count */
}

/* merges the two linked lists, restricting the common elements to occur
   only once in the final list */
merge(struct node *p, struct node *q, struct node **s)
{
    struct node *z;

    z = NULL;

    /* if both lists are empty */
    if(p == NULL && q == NULL)
        return;
    
    /* traverse both linked lists till the end. If end of any one list is reached
       loop is terminated */
    while(p!= NULL && q == NULL)
    {
        /* if node being added in the first node */
        if(*s == NULL)
        {
            *s = malloc(sizeof(struct node));
            z = *s;
        }
        else
        {
            z->link = malloc(sizeof(struct node));
            z = z->link;
        }

        if(p->data < q->data)
        {
            z->data = p->data;
            p = p->link; /* go to next node */
        }
        else
        {
            if(q->data < p->data)
            {
                z->data = q->data;
                q = q->link; /* go to next node */
            }
            else
            {
                if(p->data == q->data)
                {
                    z->data = p->data;
                    p = p->link; /* go to next node */
                    q = q->link; /* go to next node */
                }
            }
        }
    }
    /* if end of first list has not been reached */
    while(p != NULL)
    {
        z->link = malloc(sizeof(struct node));
        z = z->link;
        z->data = p->data;
        p = p->link; /* go to next node */
    }

    /* if end of second list has been reached */
    while(q != NULL)
    {
        z->link = malloc(sizeof(struct node));
        z = z->link;
        z->data = q->data;
        q = q->link; /* go to next node */
    }
    z->link = NULL; /* last node */
}
