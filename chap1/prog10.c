/* Program 10 */
main()
{
    int *p;
    int *fun(); /* function prototype */
    p = fun(); /* function call */
    printf("\n%u", p); /* print address of p */
    printf("\n%d", *p); /* print value of p */
}
int *fun() /* function definition */
{
    int i = 20; /* local variable */
    return(&i); /* return address of local variable */
    /* this is not a good practice - book is from last */
    /* century. DO NOT DO THIS IN 2025+ <<<UNSAFE C>>>*/
} /* end of function fun */
