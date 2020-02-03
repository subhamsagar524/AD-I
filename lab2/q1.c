//program to find the average of n numbers randomly generated using functions

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int getAvg(int arr[], int x);

int main(void)
{
    //Input variables
    int a[MAX_SIZE], i, n, l, u, avg;

    //Prompt for the user
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter the upper bound and lower bound for generating Random Integers : ");
    scanf("%d %d", &u, &l);

    //Renerating random Integers
    for (i = 0; i < n; i++)
	a[i] = (rand() % (u - l + 1)) + l;

    //Display the random numbers to the user
    printf("\nThe random numbers generated are : ");
    for (i = 0; i < n; i++)
	printf("%d ", a[i]);

    //Get the average
    avg = getAvg(a, n);

    //Print the average
    printf("\nAverage : %d\n", avg);

    return 0;

}

int getAvg(int arr[], int x)
{
    int i, res = 0;
    for (i = 0; i < x; i++)
	res += arr[i];
    res /= x;
    return res;
}
