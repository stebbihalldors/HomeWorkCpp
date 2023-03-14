#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    char* name = new char[100];
    _CrtDumpMemoryLeaks();
    return 0;
}