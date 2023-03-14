#include <iostream>

enum Operation {
    Add = 5,
};

class Calculator{
private:
    int number;


public:
    Calculator()
    {
        number = 0;
    }

    Calculator(int a)
    {
        number = a;
    }

    ~Calculator()
    {
        printf("Deleted things");
    }

    void SetNumber(int a) {
        number = a;
    }

    int GetNumber() {
        return number;
    }

    void SetOperation(Operation a)
    {
        switch (a) {
        case 0:
            //save a plus :?
            break;
        default:
            break;
        }
    }
    
};

int main()
{
    Calculator calculator;
    calculator.SetNumber(5);
    Operation::Add;
    calculator.GetNumber();
}
