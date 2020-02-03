
// C program to find the largest number from three numbers using user defined functions
#include <stdio.h> 

int getMax(int a, int b, int c);

int main(void) 
{ 
    //Input Variables
    int a, b, c, max;

    //Prompt for the user
    printf("Enter three numbers to check the greater one : ");
    scanf("%d %d %d", &a, &b, &c);

    //Calculate maximum number
    max = getMax(a, b, c);

    //Print the greater number
    printf("Greatest number is : %d.\n", max);

    return 0; 
} 

int getMax(int a, int b, int c)
{
    int temp = a;
    if (b > temp)
	temp = b;
    if (c > temp)
	temp = c;
    return temp;
}

