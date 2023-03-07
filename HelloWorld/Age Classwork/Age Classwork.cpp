#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int age;
    int ans;
    //new c++ style with streaming operators
    cout << "What's your age?" << endl;
    while (!(cin >> age))
    {
        cin.clear();
        cin.ignore(1000000, '\n');
        cout << "That's not a valid input, try again." << endl;
    }
    cout << "Next year, you'll be " << age + 1 << " !" << std::endl;

    //c style
    AskAgain:
    printf("What's your age?\n");
    int result = scanf_s("%d", &ans);

    { // clear unparsed characters from the buffer
        char c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    if (result != 1) goto AskAgain;

    printf("Next year, you'll be %d", ans + 1);
}