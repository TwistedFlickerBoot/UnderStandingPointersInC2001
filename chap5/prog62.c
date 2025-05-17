/* Program 62 */
/* Program to multiply two polynomials maintained as linked lists */
#include <stdio.h> /* included for C89 */
#include <malloc.h>

/* structure representing a node of a linked list. The node ca store a term of
   a polynomial */
struct polynode
{
    float coeff; /* coefficient of the term */
    int exp;     /* exponent of the term */
    struct polynode *link; /* pointer to the next node */
};

void poly_append(struct polynode **, float, int);
void poly_multiply(struct polynode *, struct polynode *, struct polynode **);
padd(float, int, struct polynode **);

main()
{
    struct polynode *first, *second, *mult;
    int i = 1;

    first = second = mult = NULL; /* empty linked lists */

    poly_append(&first, 3, 5); /* 3x^5 */
    poly_append(&first, 2, 4); /* 2x^4 */
    poly_append(&first, 1, 2); /* 1x^2 */

    /* clrscr(); */
    display_poly(first);

    poly_append(&second, 1, 6); /* 1x^6 */
    poly_append(&second, 2, 5); /* 2x^5 */
    poly_append(&second, 3, 4); /* 3x^4 */

    printf("\n\n");
    while(i++ < 79)
        printf("-");
    poly_multiply(first, second, &mult);
    printf("\n\n");
    display_poly(mult);
}

/* adds a term to a polynomial */
void  poly_append(struct polynode **q, float x, int y)
{
    struct polynode *temp;
    temp = *q;

    /* create a new node if the list is empty */
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
        
        /* create a new node at intermediate stages */
        temp->link = malloc(sizeof(struct polynode));
        temp = temp->link;
    }

    /* assign coefficient and exponent */
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

    printf("\b\b\b"); /* remove the last colon */
}

/* multiplies the two polynomials */
void poly_multiply(struct polynode *x, struct polynode *y, struct polynode **m)
{
    struct polynode *y1;
    float coeff, exp1;

    y1 = y; /* point to the starting of the second linked list */

    if(x == NULL && y == NULL)
        return; /* both polynomials are empty */
    
    /* if one of the list is empty */
    if(x == NULL)
        *m = y;
    else
    {
        if(y == NULL)
            *m = x;
        else /* if both linked lists exists */
        {
            while(x != NULL)
            {
                /* multiply each term of the second linked list with
                   a term of the first linked list */
                while(y != NULL)
                {
                    coeff = x->coeff * y->coeff; /* multiply coefficients */
                    exp1 = x->exp + y->exp; /* add exponents */
                    y = y->link; /* move to the next node */

                    /* add the term to the resultant polynomial */
                    padd(coeff, exp1, m);
                }

                y = y1; /* reposition the pointer to the starting of 
                           the second linked list */

                x = x->link; /* move to the next node */
            }
        }
    }
}
/* adds a term to the polynomial in the descending order of the exponent */
padd(float c, int e, struct polynode **s)
{
    struct polynode *r, *temp = *s;

    /* if list is empty or if the node is to be inserted before the first node */
    if(*s == NULL || e > (*s)->exp)
    {
        *s = r = malloc(sizeof(struct polynode));
        (*s)->coeff = c;
        (*s)->exp = e;
        (*s)->link = temp; /* link the new node to the list */
    }
    else
    {
        /* traverse the entire linked list to search the position to insert a new
           node */
        while(temp != NULL)
        {
            if(temp->exp == e)
            {
                temp->coeff += c; /* add the coefficient */
                return; /* no need to insert a new node */
            }
            if(temp->exp > e && (temp->link->exp < e || temp->link == NULL))
            {
                r = malloc(sizeof(struct polynode));
                r->coeff = c;
                r->exp = e;
                r->link = temp->link; /* link the new node to the list */
                temp->link = r; /* link the previous node to the new node */
                return; /* exit from the function */
            }
                        
            temp = temp->link; /* move to the next node */
        }
        r->link = NULL; /* last node points to NULL */
        temp->link = r; /* link the previous node to the new node */
    }
}