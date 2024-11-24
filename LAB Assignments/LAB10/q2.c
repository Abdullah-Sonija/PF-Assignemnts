#include<stdio.h>
#include<math.h>

double distance(point p1, point p2);
void input(point *p);
int rectangular_boundary(point p, point bottom_left,point top_right);

typedef struct 
{
    float x,y;
} point;

int main()
{
    point p1, p2,rect_bottom_left,rect_top_right;
    //input points
    printf("Enter coordinates of the first point (x y): ");
    input(&p1);
    printf("Enter coordinates of the second point (x y): ");
    input(&p2);
    //input rectangular boundaries
    printf("Enter coordinates of the rectangle's bottom-left corner (x y): ");
    input(&rect_bottom_left);
    printf("Enter coordinates of the rectangle's top-right corner (x y): ");
    input(&rect_top_right);
    //calculating distance
    printf("The distance between the two points is: %.2f\n", distance(p1,p2));
    //checking rectangular boundary
    if(rectangular_boundary(p1,rect_bottom_left,rect_top_right))
    {
        printf("Point 1 lies within the rectangle.\n");
    }
    else
    {
        printf("Point 1 does not lie within the rectangle.");
    }
    if(rectangular_boundary(p2,rect_bottom_left,rect_top_right))
    {
        printf("Point 2 lies within the rectangle.\n");
    }
    else
    {
        printf("Point 2 does not lie within the rectangle.");
    }
    
    return 0;
}

void input(point *p)
{
    scanf("%f %f", &p->x,&p->y);
}

double distance(point p1, point p2)
{
    return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}
int rectangular_boundary(point p, point bottom_left,point top_right)
{
    return (p.x >= bottom_left.x && p.x <= top_right.x && p.y >= bottom_left.y && p.y <= top_right.y);
}
