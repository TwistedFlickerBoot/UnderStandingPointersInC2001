/* Program 61 */
/* Program to add two polynomials maintained as linked lists */
#include <stdio.h> /* Included for C89 */
#include <malloc.h> /* book uses alloc.h */
/* structure representing a node of a linked list. The node can store
   a term of a polynomial */
struct polynode
{
    float coeff; /* coefficient of the term */
    int exp; /* exponent of the term */
    struct polynode *link; /* pointer to the next node */
};

void poly_append(struct polynode **, float, int);
void poly_addition(struct polynode *, struct polynode *, struct polynode **);

main()
{
    struct polynode *first, *second, *total;
    int i = 0;

    first = second = total = NULL; /* empty linked lists */

    poly_append(&first, 1.4, 5);
    poly_append(&first, 1.5, 4);
    poly_append(&first, 1.7, 2);
    poly_append(&first, 1.8, 1);
    poly_append(&first, 1.9, 0);

    /* clrscr(); */
    display_poly(first);

    poly_append(&second, 1.5, 6);
    poly_append(&second, 2.5, 5);
    poly_append(&second, -3.5, 4);
    poly_append(&second, 4.5, 3);
    poly_append(&second, 6.5, 1);

    printf("\n\n");
    display_poly(second);

    /* draws a dashed horizontal line */
    printf("\n");
    while(i++ < 79)
        printf("-");
    printf("\n\n"); 

    poly_addition(first, second, &total);
    /* display the result */
    display_poly(total);
}

/* adds a term to a polynomial */
void poly_append(struct polynode **q, float x, int y)
{
    struct polynode *temp;
    temp = *q;

    /* creates a new node if the list is empty */
    if(*q == NULL)
    {
        *q = malloc(sizeof(struct polynode));
        temp = *q;
    }
    else
    {
        /* traverse the entire linked list */
        while(temp->link != NULL)
            temp = temp->link;
            /* create new node at intermediate stages */
            temp->link = malloc(sizeof(struct polynode));
            temp = temp->link;
    }
    /* assignn coefficient and exponent */
    temp->coeff = x;
    temp->exp = y;
    temp->link = NULL; /* last node points to NULL */
}

/* displays the contents of linked list representing a polynomial */
display_poly(struct polynode *q)
{
    /* traverse till the end of the linked list */
    while(q != NULL)
    {
        printf("%.1fx^%d : ", q->coeff, q->exp);
        q = q->link; /* move to the next node */
    }
    printf("\b\b\b"); /* erases the last colon */
}

/* adds two polynomials */
void poly_addition(struct polynode *x, struct polynode *y, struct polynode **s)
{
    struct polynode *z;

    /* if both linked lists are empty */
    if(x == NULL && y == NULL)
        return;
    /* traverse till one of the list ends */
    while(x != NULL && y != NULL)
    {
        /* create a new node if the list is empty */
        if(*s == NULL)
        {
            *s = malloc(sizeof(struct polynode));
            z = *s;
        }
        /* create new nodes at intermediate stages */
        else
        {
            z->link = malloc(sizeof(struct polynode));
            z = z->link;
        }

        /* store a term of the larger degree polynomial */
        if(x->exp < y->exp)
        {
            z->coeff = y->coeff;
            z->exp = y->exp;
            y = y->link; /* move to the next node */
        }
        else
        {
            if(x->exp > y->exp)
            {
                z->coeff = x->coeff;
                z->exp = x->exp;
                x = x->link; /* move to the next node */
            }
            else
            {
                /* add the coefficients, when exponents are equal */
                if(x->exp == y->exp)
                {
                    /* assigning the added coefficient */
                    z->coeff = x->coeff + y->coeff;
                    z->exp = x->exp;
                    /* go to the next node */
                    x = x->link;
                    y = y->link;
                }
            }
        }
    }
    /* assign remaining terms of the first polynomial to the result */
    while(x != NULL)
    {
        if(*s == NULL)
        {
            *s = malloc(sizeof(struct polynode));
            z = *s;
        }
        else
        {
            z->link = malloc(sizeof(struct polynode));
            z = z->link;
        }
        /* assign coefficient and exponent */
        z->coeff = x->coeff;
        z->exp = x->exp;
        x = x->link; /* go to the next node */
    }

    /* assign remaining terms of the second polynomial to the result */
    while(y != NULL)
    {
        if(*s == NULL)
        {
            *s = malloc(sizeof(struct polynode));
            z = *s;
        }
        else
        {
            z->link = malloc(sizeof(struct polynode));
            z = z->link;
        }

        /* assign coeffient and exponent */
        z->coeff = y->coeff;
        z->exp = y->exp;
        y = y->link; /* go to the next node */
    }
    z->link = NULL; /* last node points to NULL */
}