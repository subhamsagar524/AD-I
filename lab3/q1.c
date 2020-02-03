//store and print a structure

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
    struct student s;

    //Processing Variable
    int i;

    //prompt the user for input
    printf("Enter the Roll No    : ");
    scanf("%d", &s.roll);
    printf("Enter the Name       : ");
    scanf("%s", s.name);
    printf("Enter the Age        : ");
    scanf("%d", &s.age);
    printf("Enter three  Marks   : ");
    for (i = 0; i < 3; i++)
        scanf("%f", &s.marks[i]);

    //Display the input
    printf("\nStudent Details Entered are ...\n");
    printf("\nRoll No : %d\n", s.roll);
    printf("\nName    : %s\n", s.name);
    printf("\nAge     : %d\n", s.age);
    printf("\nMarks   : ");
    for (i = 0; i < 3; i++)
        printf("%.2f ", s.marks[i]);
    printf("\n");

    return 0;
}
