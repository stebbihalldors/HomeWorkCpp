#include <iostream>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int four = 4;
	int five = 5;
	printf("This is four: %d, This is five: %d\n", four, five);
	Swap(four, five);
	// invoke swap function here passing pointers to five and four.
	printf("This used to be four: %d, This used to be five: %d", four, five);
	return 0;
}