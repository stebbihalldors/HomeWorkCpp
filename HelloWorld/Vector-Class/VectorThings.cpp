#include <cstdio>
#include "Vector3.h"

int main()
{
    Vector3 right{ 7, 14, 21 };
    right /= 7;
    right.Print();
    return 0;

    Vector3 vector1;
    vector1.Print();
    Vector3 vector2(1, 2, 3);
    vector2.Print();
    Vector3 v3(3, 2, 1);
    Vector3 test(v3 + vector2);
    test.Print();

    printf("Working on: \n");
    vector2.Print();
    v3.Print();
    test.Print();
    Vector3 test2(1.4404f, 2.505f, 5.6606);
    test2.Print();

    printf("\nWorking on: \n");
    Vector3 v1(1, 2, 3);
    Vector3 v2(3, 2, 1);

    Vector3 t1(-v1);
    Vector3 t2(-t1);

    Vector3 t3(1, 2, 3);
    Vector3 t4(1, 2, 3);

    if (t3 == t4)
        printf("jeij\n");
    else
        printf("boo\n");
    if (t3 != t4)
        printf("jeij\n");
    else
        printf("boo\n");
    if (v1 == t4)
        printf("jeij\n");

    v1.Print();
    v1 = v2;
    v1.Print();

    t4 = Vector3(5, 5, 5);

    printf("\n\n\nWorking on:\n");
    t3.Print();
    t4.Print();
    Vector3 t15 = t4 + t3;
    t15.Print();
    t4.Print();
    t4 += t3;
    t4.Print();


    
}
