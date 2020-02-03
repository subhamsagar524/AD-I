//Program to implement the selection sort using user defined function

#include<stdio.h>
#include<stdlib.h>

void selection(int a[], int x);

#define MAX_SIZE 100
int main(void)
{
    //Input Variables
    int a[MAX_SIZE], n, i, u, l;

    //Prompt for the user
    printf("Enter the numbers of elements : ");
    scanf("%d", &n);
    printf("Enter the upper and lower bound for generating Random integers : ");
    scanf("%d %d", &u, &l);

    //Renerating random Integers
    for (i = 0; i < n; i++)
	a[i] = (rand() % (u - l + 1)) + l;

    //Display the random numbers to the user
    printf("\nThe random numbers generated are : ");
    for (i = 0; i < n; i++)
	printf("%d ", a[i]);

    //Sort the array
    selection(a, n);
    
    //Print the sorted array
    printf("\nThe sorted array is : ");
    for (i = 0; i < n; i++)
	printf("%d ", a[i]);

    return 0;
}
    
void selection(int a[], int x)
{
    int i, j, temp;

    for (i = 0; i < x-1; i++)
	for (j = i+1; j < x; j++)
	    if (a[j] < a[i])
	    {
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	    }
}
