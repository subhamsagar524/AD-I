#include<stdio.h>

void without_thirdswap(int x, int y);
void with_thirdswap(int x, int y);
void xwith_thirdswap(int *x, int *y);
void xwithout_thirdswap(int *x, int *y);

int main (void)
{
    //Input Variables
    int a, b;

    //Prompt the user for the values of a and b
    printf("Enter the values of a and b : ");
    scanf("%d %d", &a, &b);

    //Display the value before swapping
    printf("\nThis is call by value...");
    printf("\nValues before swapping (a, b) are (%d, %d) respectively.", a, b);

    //Calling swap function with and without third variable
    without_thirdswap(a, b);
    with_thirdswap(a, b);

    //Calling swap function by address
    printf("\nThis is call by address...");
    printf("\nValues before swapping (a, b) are (%d, %d) respectively.", a, b);
    xwithout_thirdswap(&a, &b);	//Without third variable
    printf("\nValues after swapping without using a third variable (a, b) are (%d, %d) respectively.\n", a, b);

    printf("\nValues before swapping (a, b) are (%d, %d) respectively.", a, b);
    xwith_thirdswap(&a, &b);  //Without third variable
    printf("\nValues after swapping without using a third variable (a, b) are (%d, %d) respectively.\n", a, b);

    return 0;
}

void without_thirdswap(int x, int y)
{
    x = x + y;
    y = x - y;
    x = x - y;

    printf("\nValues after swapping without using a third variable (a, b) are (%d, %d) respectively.\n", x, y);
}

void with_thirdswap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;

    printf("\nValues after swapping without using a third variable (a, b) are (%d, %d) respectively.\n", x, y);
}

void xwithout_thirdswap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void xwith_thirdswap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

