#include<stdio.h>

int main (void)
{
    //Input Variables
    int a, b;

    //Prompt the user for the values of a and b
    printf("Enter the values of a and b : ");
    scanf("%d %d", &a, &b);

    //Display the value before swapping
    printf("\nValues before swapping (a, b) are (%d, %d) respectively.", a, b);

    //Swap Operation Logic
    a = a + b;
    b = a - b;
    a = a - b;

    //Display the value before swapping
    printf("\nValues after swapping (a, b) are (%d, %d) respectively.\n", a, b);

    return 0;
}

