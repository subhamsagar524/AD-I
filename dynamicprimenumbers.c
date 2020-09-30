// Subham Sagar Paira
// subhamsagarpaira.com

// This is a C program to store the prime numbers between
// two numbers input by the user.

// Prior to this we are not provided with any limitations, 
// so we don't know hoe many memory space should be reserved.
// Hence we are going to use dynamic memory allocation here.

#include <stdio.h>
#include <stdlib.h>

// Functions Prototype Declaration
int prime (int data);
void addnumber (int data);
void displayList ();


// Structure to store a number
struct node
{
    int info;
    struct node *link;
} *start;


// Main function
int main (void)
{
    // Prompt the user for the input...
    int l, h;
    start = NULL;
    printf("Enter the interval...\nLower : ");
    scanf("%d", &l);
    printf("Higher : ");
    scanf("%d", &h);

    // Run the loop and find the prime numbers
    int i;
    for (i = l; i <= h; i++)
	//Check if the number is prime or not
	if (prime(i))
	    //Store the data
	    addnumber(i);

    // Display the stored numbers
    printf("\nThe prime numbers between %d and %d (including) are : \n", l, h);
    displayList();
    printf("\n");

    return 0;
}


// Function to find if a number is prime or not
int prime (int data)
{
    int i, flag = 1;
    
    // If less than 1 or 2
    if (data <= 1 )
	return 0;
    if (data == 2)
	return 1;
    
    // Run the loop from 2 to n/2
    for (i = 2; i * i <= data; i++)
    {
	if (data % i == 0)
	{
	    flag = 0;
	    break;
	}
    }

    // Return the test result
    if (flag == 1)
	return 1;
    else
	return 0;
}


// Function to add a number(if prime) in the linked list
void addnumber (int data)
{
    struct node *temp, *q;
    temp = (struct node *)malloc (sizeof(struct node));
    temp -> info = data;
    temp -> link = NULL;

    if (start == NULL)
	start = temp;
    else
    {
    	q = start;
	while (q -> link != NULL)
	    q = q -> link;
	q -> link = temp;
    }
}


// Function to display the linked list
void displayList ()
{
    struct node *q;
    if (start == NULL)
	printf("\nLinked List is empty...");
    else
    {
	q = start;
	while (q != NULL)
	{
	    printf("%d\t", q -> info);
    	    q = q -> link;
   	}
    }
}
//end the program
