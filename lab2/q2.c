//Program to implement linear search using user defined function

#include<stdio.h>
#define MAX_SIZE 100

void search(int arr[], int x, int k);

int main(void)
{
    //Input Variables
    int a[100], n, i, key;

    //Prompt for the user
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter %d numbers : ", n);
    for (i = 0; i < n; i++)
	scanf("%d", &a[i]);

    //Display the input
    printf("\nThe elements are : ");
    for (i = 0; i < n; i++)
	printf("%d ", a[i]);

    //prompt for the user
    printf("\n\nEnter the element you want to search : ");
    scanf("%d", &key);

    //Search for the element
    search(a, n, key);

    return 0;
}

void search(int arr[], int x, int k)
{
    int i, flag = 0;
    for (i = 0; i < x; i++)
	if (arr[i] == k)
	{
	    printf("\nElement found at position : %d\n", (i + 1));
	    flag = 1;
	}
    if (flag == 0)
	printf("\nElement could not be found...\n");
}
