/* Program 17 */
main()
{
    int num[]={24,34,12,44,56,17};
    int i = 0;

    while(i<=5)
    {
        printf("\naddress = %u   ", &num[i]);
        printf("element = %d", num[i]);
        i++;
    }
}