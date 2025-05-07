/* Program 18 */
main()
{
    int num[]={24,34,12,44,56,17};
    int i = 0, *j;

    j = &num[0]; // j points to the first element of num

    while(i<=5)
    {
        printf("\naddress = %u   ", &num[i]);
        printf("element = %d", *j);

        i++;
        j++; // increment the pointer to point to the next location/element
    }
}