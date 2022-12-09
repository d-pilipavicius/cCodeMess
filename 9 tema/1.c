#include <stdio.h>
#include <math.h>

typedef struct Point
{
    double x, y;
}Point;

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

int main()
{
    getDistance(createPoint(2.0, -3.0),createPoint(-4.0, 5.0));
    return 0;
}

void printPoint(Point p)
{
    printf("(%f, %f)\n", p.x, p.y);
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
