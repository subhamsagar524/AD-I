//Implement the quick sort algorithm uisng Lomato and Hoare Partitioning Method

#include<stdio.h>

//Declaration of prototypes
void quicksort(int a[], int p, int r);
int lomato_partition(int a[], int p, int r);
//int hoare_partition(int a[], int p, int r);

//Main function
int main(void)
{
    int n, i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    //Input the array
    int a[n];
    printf("\nEnter %d number of elements...", n);
    for (i = 0; i < n; i++)
    {
	printf("\nEnter data : ");
	scanf("%d", &a[i]);
    }

    //Display the array
    printf("\nArray is : ");
    for (i = 0; i < n; i++)
	printf(" %d", a[i]);

    //Calling the sort by Lomato method
    lomato_partition(a, 0, n-1);

    //Display the sorted array
    printf("\n\nSorted by lomato partitioning method...");
    printf("\nArray is : ");
    for (i = 0; i < n; i++)
        printf(" %d", a[i]);
    printf("\n");

    /*//Calling the sort by Hoare method
    hoare_partition();
    
    Display the sorted array
    printf("\n\nSorted by hoare partitioning method...");
    printf("\nArray is : ");
    for (i = 0; i < n; i++)
        printf(" %d", &a[i]);*/

    return 0;
}

void quicksort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
	q = lomato_partition(a, p, r);
	quicksort(a, p, q-1);
	quicksort(a, q+1, r);
    }
}

int lomato_partition(int a[], int p, int r)
{
    int x, i, j, temp;
    x = a[r];
    i = p - 1;
    for (j = p; j <= r; j++)
    {
	if (a[j] <= x)
	{
	    i++;
	    temp = a[i];
	    a[i] = a[j];
	    a[j] = temp;
	}
    }
    temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
    return i+1;
}
