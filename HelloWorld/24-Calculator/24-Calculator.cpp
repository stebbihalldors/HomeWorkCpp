#include <iostream>
#include <functional>

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

class Calculator{
private:
    int number1;
    int number2;

public:
    Calculator()
    {
        number1 = 0;
        number2 = 0;
        a = Operation::Add;
    }

    ~Calculator()
    {
        printf("Deleted things");
    }

    void SetNumber(int a) {
        if (number1 != 0)
            number1 = (number1 * 10)+a;
        else
            number1 = a;
    }
    Operation a;
    int GetNumber() {
        switch (a) {
        case Operation::Add:
            return number1 + number2;
        case Operation::Subtract:
            return number2 - number1;
            break;
        default:
            break;
        }
    }

    void SetOperation(Operation a)
    {
        number2 = GetNumber();
        number1 = 0;
        this->a = a;
    }

    void Clear()
    {
        number1 = 0;
        number2 = 0;
        a = Operation::Add;
    }
};

int main()
{
    Calculator calculator;
    calculator.SetNumber(5);
    calculator.SetOperation(Operation::Add);
    calculator.SetNumber(3);
    calculator.SetOperation(Operation::Subtract);
    calculator.SetNumber(2);
    printf("%d\n", calculator.GetNumber());

    calculator.Clear();
    calculator.SetNumber(5);
    calculator.SetOperation(Operation::Subtract);
    calculator.SetNumber(3);
    printf("%d\n", calculator.GetNumber());

    calculator.Clear();
    calculator.SetNumber(5);
    calculator.SetNumber(5);
    calculator.SetNumber(5);
    calculator.SetOperation(Operation::Subtract);
    calculator.SetNumber(3);
    calculator.SetNumber(3);
    calculator.SetNumber(3);
    printf("%d\n", calculator.GetNumber());

    calculator.Clear();
    calculator.SetNumber(5);
    printf("%d\n", calculator.GetNumber());

}
