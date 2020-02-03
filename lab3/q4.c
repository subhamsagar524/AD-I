//operations on complex numbers

#include<stdio.h>

struct complexnumber
{
    double a, b;
};

struct complexnumber add(struct complexnumber c1, struct complexnumber c2);
struct complexnumber sub(struct complexnumber c1, struct complexnumber c2);
struct complexnumber mul(struct complexnumber c1, struct complexnumber c2);

int main(void)
{
    //Input Variable
    struct complexnumber c1, c2;

    //Output Variable
    struct complexnumber result;

    //Prompt the user for two complex number
    printf("Enter the first complex number...");
    printf("\nEnter real and imaginary value : ");
    scanf("%lf %lf", &c1.a, &c1.b);
    printf("\n\nEnter the second complex numnber...");
    printf("\nEnter real and imaginary value : ");
    scanf("%lf %lf", &c2.a, &c2.b);

    //Addition
    result = add(c1, c2);
    printf("\nAddition : %.2f + %.2fi", result.a, result.b);

    //Substraction
    result = sub(c1, c2);
    printf("\nSubstraction : %.2f + %.2fi", result.a, result.b);

    //Multiplication
    result = mul(c1, c2);
    printf("\nMultiplication : %.2f + %.2fi\n", result.a, result.b);

    return 0;
}

struct complexnumber add(struct complexnumber c1, struct complexnumber c2)
{
    struct complexnumber r;
    r.a = c1.a + c2.a;
    r.b = c1.b + c2.b;
    return r;
}

struct complexnumber sub(struct complexnumber c1, struct complexnumber c2)
{
    struct complexnumber r;
    r.a = c1.a - c2.a;
    r.b = c1.b - c2.b;
    return r;
}

struct complexnumber mul(struct complexnumber c1, struct complexnumber c2)
{
    struct complexnumber r;
    r.a = c1.a * c2.a  -  c1.b * c2.b;
    r.b = c1.a + c2.b  +  c1.b + c2.a;
    return r;
}

