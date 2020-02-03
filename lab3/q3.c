//calculate the distance between two points

#include<stdio.h>
#include<math.h>

//Defining point variable
struct point
{
    double x, y, z;
};

double getDistance(struct point a, struct point b);

int main(void)
{
    struct point a, b;
    double distance;

    //Prompt user for two points
    printf("Enter the three values of first point (x, y, z)  : ");
    scanf("%lf %lf %lf", &a.x, &a.y, &a.z);
    printf("Enter the three values of second point (x, y, z) : ");
    scanf("%lf %lf %lf", &b.x, &b.y, &b.z);

    //Get the distance
    distance = getDistance(a, b);

    //Display the distance
    printf("\nDistance : %.2f\n", distance);

    return 0;
}

double getDistance(struct point a, struct point b)
{
    return(sqrt((b.x - a.x) + (b.y - a.y) + (b.z - a.z)));
}
