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

int main(void)
{
    //Variables Declarations
    int i, n, m, ch, pos;
    start = NULL;

    //Prompt for the user
    while (1)
    {
	printf("\n1. Create list");
	printf("\n2. Display list");
	printf("\n3. Add to Beginning");
	printf("\n4. Add to End");
	printf("\n5. Add at Position");
	printf("\n6. Exit");
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

	    case 6:	printf("\nExiting...\n");
			exit(1);
			break;
	    
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

