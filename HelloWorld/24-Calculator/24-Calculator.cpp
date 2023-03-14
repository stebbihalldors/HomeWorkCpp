#include <iostream>
#include <functional>

enum Operation {
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
    }

    /*Calculator(int a, int b)
    {
        number1 = a;
        number2 = b;
    }*/

    ~Calculator()
    {
        printf("Deleted things");
    }

    void SetNumber(int a) {
        if (number1 == 0)
            number1 = a;
        else
            number2 = a;
    }

    int GetNumber() {
        return op(number1,number2);
    }

    void SetOperation(Operation a)
    {
        switch (a) {
        case 0:
            //std::function<int(int, int)> op = std::plus<int>();
            op = std::plus<int>();
            break;
        case 1:
            op = std::minus<int>();
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
{/*
    Calculator calc(2, 5);
    printf("%d\n", calc.GetNumber());
    */
    Calculator calculator;
    calculator.SetNumber(5);
    calculator.SetOperation(Operation::Add);
    calculator.SetNumber(3);
    printf("%d\n", calculator.GetNumber());

    calculator.Clear();
    calculator.SetNumber(5);
    calculator.SetOperation(Operation::Subtract);
    calculator.SetNumber(3);
    printf("%d\n", calculator.GetNumber());

}
