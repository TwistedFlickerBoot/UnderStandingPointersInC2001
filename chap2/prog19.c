/* Program 19 */
main()
{
    int num[]={24,34,12,44,56,17};
    display(&num[0], 6);
}

display(int *j, int n)
{
    int i = 1;
    while(i<=n)
    {
        printf("\nelement = %d", *j);
        i++;
        j++; // increment pointer to point to next location/element
    }
}