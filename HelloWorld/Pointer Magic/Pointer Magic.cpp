
#include <iostream>

struct Book {
	int numberOfPages;
};

void StealHalfTheBook(Book* book) {
	book->numberOfPages /= 2;
	printf("Pages of Book after stealing:%d\n", book->numberOfPages); // 100
}

int main() {
	Book book;
	book.numberOfPages = 200;
	printf("Pages of main-Book before stealing:%d\n", book.numberOfPages); // 200
	StealHalfTheBook(&book);
	printf("Pages of main-Book after stealing:%d\n", book.numberOfPages); // 200
}