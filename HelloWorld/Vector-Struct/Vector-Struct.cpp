
#include <iostream>
#include <cstdio>

struct Vector2D {
    int x, y;
};

void Add(Vector2D,Vector2D);

int main()
{
    Vector2D vector1{5,3};
    Vector2D vector2{3,5};
    /*vector1.x = 5;
    vector1.y = 3;
    vector2.x = 3;
    vector2.y = 5;*/
    Add(vector1, vector2);
}

void Add(Vector2D a, Vector2D b)
{
    printf("Adding: Vector(%d,%d) and Vector(%d,%d)\n", a.x, a.y, b.x, b.y);
    printf("Result: Vector(%d,%d)",a.x + b.x,a.y+b.y);
}