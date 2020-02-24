//Linked List implementation

#include<stdio.h>
#include<stdlib.h>

//Declaration of the node data type
struct node
{
    int info;
    struct node *link;
}*start;

int count = 0;

//Declarations of prototypes
void createList (int data);
void displayList();
void addBeg(int data);
void addEnd (int data);
void addAtPos(int data, int pos);
void deleteBeg();
void deleteEnd();
void deleteAtPos(int pos);
void searchElement(int element);

int main(void)
{
    //Variables Declarations
    int i, n, m, ch, pos;
    start = NULL;

    //Prompt for the user
    while (1)
    {
	printf("\n\n1.  Create list");
	printf("\n2.  Display list");
	printf("\n3.  Add to Beginning");
	printf("\n4.  Add to End");
	printf("\n5.  Add at Position");
	printf("\n6.  Delete at Beginning");
	printf("\n7.  Delete at End");
	printf("\n8.  Delete at Position");
	printf("\n9.  Search an Element");
	printf("\n10. Exit");
	printf("\nEnter Choiche : ");

	scanf("%d", &ch);

	switch(ch)
	{
	    case 1:	printf("\nEnter the number of nodes to be inserted : ");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
			    printf("\nEnter the data : ");
			    scanf("%d", &m);
			    createList(m);
			}
			break;
	    
	    case 2:	printf("\nLinked List : ");
			displayList();
			printf("\nNumber of items : %d", count);
			printf("\n");
			break;

	    case 3:	printf("\nEnter the data : ");
                        scanf("%d", &m);
                        addBeg(m);
			break;

	    case 4:     printf("\nEnter the data : ");
                        scanf("%d", &m);
                        addEnd(m);
                        break;

       	    case 5:     printf("\nEnter the data : ");
                        scanf("%d", &m);
			printf("\nEnter the position after which the node is to be inserted : ");
			scanf("%d", &pos);
                        addAtPos(m, pos);
                        break;

	    case 6:	deleteBeg();
			break;
	    
	    case 7:	deleteEnd();
			break;

	    case 8:	printf("\nEnter the position of the node is to be deleted : ");
                        scanf("%d", &pos);
			deleteAtPos(pos);
			break;
	    
	    case 9:	printf("\nEnter the element you want to search : ");
			scanf("%d", &pos);
			searchElement(pos);
			break;

	    case 10:	printf("Exiting...");
			exit(1);
	    
	    deafult:	printf("\nInvalid Option Try Again :( ");
	}
    }

    return 0;
}

//Function to create a linked list
void createList (int data)
{
    struct node *temp, *q;
    temp = (struct node *)malloc (sizeof(struct node));
    temp -> info = data;
    temp -> link = NULL;

    if (start == NULL)
    {
	start = temp;
	count++;
    }
    else
    {
	q = start;
	while (q -> link != NULL)
	    q = q -> link;
	q -> link = temp;
	count++;
    }
}

//Function to display a linked list
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

//Function to add a node at the beginning
void addBeg (int data)
{
    struct node *temp;
    temp = (struct node *)malloc (sizeof(struct node));
    temp -> info = data;
    temp -> link = start;
    start = temp;
    count++;
}

//Function  to add a node at the end
void addEnd (int data)
{
    struct node *temp, *q;
    temp = (struct node *)malloc (sizeof(struct node));
    temp -> info = data;
    temp -> link = NULL;
    q = start;
    while(q -> link != NULL)
	q = q -> link;
    q -> link = temp;
    count++;
}

//Function to add a node at any position
void addAtPos (int data, int pos)
{
    struct node *temp, *q, *next;
    int i;
    temp = (struct node *)malloc (sizeof(struct node));
    temp -> info = data;
    q = start;
    for (i = 1; i < pos; i++)
	q = q -> link;
    next = q -> link;
    q -> link = temp;
    temp -> link = next;
    count++;
}

//Function to delete a node at Beginning
void deleteBeg()
{
    if (start == NULL)
    {
	printf("\nLinked List is empty...");
	return;
    }
    else
    {
	struct node *temp;
	temp = start;
	start = temp -> link;
	printf("\nDeleted node is: %d", temp -> info);
	free(temp);
	if (start == NULL)
	    printf("\nLinked List is empty... Only one element deleted");
	count--;
    }
}

//Function to delete a node at End
void deleteEnd()
{
    if (start == NULL)
    {
        printf("\nLinked List is empty...");
        return;
    }
    else if (start -> link == NULL)
    {
	printf("\nDeleted node is: %d", start -> info);
	start = NULL;
	free(start);
	printf("Linked List is empty... Only one element deleted");
    }
    else
    {
        struct node *temp, *prev;
	int i;
        temp = start;
	while (temp -> link != NULL)
	{
	    prev = temp;
	    temp = temp -> link;
	}
	prev -> link = NULL;
        printf("\nDeleted node is: %d", temp -> info);
        free(temp);
        count--;
    }
}   

//Function to delete a node at a position
void deleteAtPos(int pos)
{
    if (start == NULL)
    {
        printf("\nLinked List is empty...");
        return;
    }
    else if (start -> link == NULL)
    {
	if (pos > 1)
	{
	    printf("\nLess number of nodes...");
	    return;
	}
        struct node *temp;
        temp = start;
	start = NULL;
        printf("\nDeleted node is: %d", temp -> info);
        free(temp);
        count--;
    }
    else
    {
	struct node *temp, *q;
	int i;
	q = start;
	for (i = 1; i < pos - 1; i++)
	    q = q -> link;
	if (q == NULL)
	{
	    printf("\nLess number of nodes...");
	    return;
	}
	temp = q -> link;
	q -> link = temp -> link;
	printf("\nDeleted node is: %d", temp -> info);
        free(temp);
        count--;
    }
}

//Function to search an element in the Linked List
void searchElement(int element)
{
    if (start == NULL)
	printf("\nLinked list is empty...");
    else
    {
        struct node *temp;
        temp = start;
	int count, flag;
	count = 1;
	flag = 0;
	while (temp != NULL)
	{
	    if (temp -> info == element)
	    {
		printf("\nItem found at position %d", count);
		count++;
		flag = 1;
	    }
	    temp = temp -> link;
	}
	if (flag == 0)
	    printf("\nItem doesn't exists in the list...");
    }
}
