//store structure type in an array and display the second element

#include<stdio.h>

//Defining Structure
struct student
{
    int roll, age;
    char name[30];
    float marks[3];
};

int main(void)
{
    //Input Variables
    struct student s[5];

    //Processing Variable
    int i, j;

    //prompt the user for input
    printf("Enter details for 5 students...");

    for (i = 0; i < 5; i++)
    {
	printf("\nEnter details for student with roll %d ...", i+1);
        s[i].roll = i+1;
        printf("\nEnter the Name       : ");
        scanf("%s", s[i].name);
        printf("\nEnter the Age        : ");
        scanf("%d", &s[i].age);
        printf("\nEnter three  Marks   : ");
        for (j = 0; j < 3; j++)
            scanf("%f", &s[i].marks[j]);
	printf("\n");
    }

    //Display roll no 2
    i = 1;
    printf("\nDisplay the details of roll no 2...");
    printf("\nName    : %s\n", s[i].name);
    printf("\nAge     : %d\n", s[i].age);
    printf("\nMarks   : ");
    for (i = 0; i < 3; i++)
        printf("%.2f ", s[i].marks[i]);
    printf("\n");

    return 0;
}
