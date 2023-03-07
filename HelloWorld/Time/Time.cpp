#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int secs = 0;
    
    printf("How many Seconds have passed?\n");
    scanf_s("%d", &secs);
    int minutes = secs / 60;
    secs -= minutes * 60;
    int hours = minutes / 60;
    minutes -= hours * 60;
    printf("%02d:%02d:%02d", hours, minutes, secs);
}
