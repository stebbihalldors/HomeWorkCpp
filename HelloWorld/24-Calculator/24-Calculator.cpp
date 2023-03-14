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
    std::function<int(int, int)> op;

public:
    Calculator()
    {
        number1 = 0;
        number2 = 0;
        op = std::plus<int>();
    }

    ~Calculator()
    {
        printf("Deleted things");
    }

    void SetNumber(int a) {
        if (number1 != 0)
            number1 = (number1 * 10)+a;
        else if (number1 == 0)
            number1 = a;
    }

    int GetNumber() {
        return op(number2, number1); 
    }

    void SetOperation(Operation a)
    {

        number2 = op(number1, number2);
        number1 = 0;
        switch (a) {
        case Operation::Add:
            op = std::plus<int>();
            break;
        case Operation::Subtract:
            op = std::minus<int>();
            break;
        default:
            break;
        }
    }

    void Clear()
    {
        number1 = 0;
        number2 = 0;
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

}
