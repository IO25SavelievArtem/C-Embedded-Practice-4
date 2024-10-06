#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
	char *title;
	double price;
	unsigned int pages;
	char *language;
	double weight;
	unsigned int year;
	struct Book *next;
} Book;

Book* createBook(char *title, double price, int pages, char *language, double weight, int year) {
	Book *newBook = (Book*)malloc(sizeof(Book));
	newBook->title = title;
	newBook->price = price;
	newBook->pages = pages;
	newBook->language = language;
	newBook->weight = weight;
	newBook->year = year;
	newBook->next = NULL;
	return newBook;
}

void addBook(Book **head, char *title, double price, int pages, char *language, double weight, int year) {
	Book *newBook = createBook(title, price, pages, language, weight, year);
	if (*head == NULL) {
		*head = newBook;
	} else {
		Book *temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newBook;
	}
}

void printBooks(Book *head) {
	Book *temp = head;
	while (temp != NULL) {
		printf("Title: %s\n", temp->title);
		printf("Price: $%.2f\n", temp->price);
		printf("Number of pages: %d\n", temp->pages);
		printf("Language: %s\n", temp->language);
		printf("Weight: %.2f kg\n", temp->weight);
		printf("Publishment year: %d\n", temp->year);
		printf("------------------------\n");
		temp = temp->next;
	}
}

void deleteBooks(Book *head) {
	Book *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main() {
	Book *head = NULL;
	
	addBook(&head, "Harry Potter and the Philosopher's Stone", 7.99, 223, "Ukrainian", 0.26, 2002);
	addBook(&head, "Harry Potter and the Chamber of Secrets", 6.13, 251, "Ukrainian", 0.31, 2004);
	addBook(&head, "Harry Potter and the Prisoner of Azkaban", 6.99, 317, "Ukrainian", 0.35, 2006);
	addBook(&head, "Harry Potter and the Goblet of Fire", 6.59, 636, "Ukrainian", 0.62, 2008);
	addBook(&head, "Harry Potter and the Order of the Phoenix", 6.78, 766, "English", 0.68, 2003);
	addBook(&head, "Harry Potter and the Half-Blood Prince", 7.23, 607, "Spanish", 0.61, 2006);
	addBook(&head, "Harry Potter and the Deathly Hallows", 7.39, 607, "English", 0.61, 2007);
	
	printf("Harry Potter Book Series Information:\n");
	printf("------------------------\n");
	printBooks(head);
	
	deleteBooks(head);
	
	return 0;
}