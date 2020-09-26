/******************************************************************

** Program: Chapter 11 Main.cpp
** Description: Use data structures

** Course: CMSC226

** Professor: Greg Grinigory

** Student: Arman Khan

** Due Date: 11/3/19
******************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include <fstream>
#pragma warning(disable : 4996)

//#include "mainmenu.h"

using namespace std;
fstream bookFile;

//size of array
const int n = 20;
const int stringlength = 51;

//Create structure declaration
class BookData {
protected:
	char bookTitle[51] = { 0 };
	char isbn[14] = { 0 };
	char author[31] = { 0 };
	char publisher[31] = { 0 };


public:
	void setTitle(string* newTitle, int subscript);
	void setISBN(string* ISBN, int subscript);
	void setAuthor(string* Author, int subscript);
	void setPub(string* publisher, int subscript);
	bool bookMatch(char x[]);

	char* getTitle() {
		return this->bookTitle;
	}
	char* getISBN() {
		return this->isbn;
	}
	char* getAuthor() {
		return this->author;
	}
	char* getPub() {
		return this->publisher;
	}
};

class InventoryBook :public BookData {
private:
	char dateAdded[11] = { 0 };
	int qtyOnHand[1] = { 0 };
	double wholesale[1] = { 0.0 };
	double retail[1] = { 0.0 };

public:
	void setDateAdded(string* newDate, int subscript);
	void setQty(int qty, int subscript);
	void setWholesale(double wholeSalePrice, int subscript);
	void setRetail(double retailPrice, int subscript);
	int isEmpty(int subscript);
	void removeBook(int subscript);

	char* getDateAdded() {
		return dateAdded;
	}
	int getQty() {
		return qtyOnHand[0];
	}
	double getWholesale() {
		return wholesale[0];
	}
	double getRetail() {
		return retail[0];
	}
};

class SoldBook :public InventoryBook {
private:
	static double taxRate;
	static double total;

public:
	int qtySold;
	double tax;
	double subtotal;

	//setters
	double setTax() {
		taxRate = 0.06;
		tax = taxRate * subtotal;
	}

	double setSubtotal() {
		subtotal = qtySold * getRetail();
	}

	double setTotal() {
		total = subtotal + tax;
	}

	//getters
	double getSubTotal() {
		return subtotal;
	}

	double getTax() {
		return tax;
	}

	double getTotal() {
		return total;
	}
};

//GLobal book array
InventoryBook bookInfo[n];

void bookObjectArray(string book, char arr[], int l) {
	int counter = 0;
	for (int col = 0; col < l; col++) {
		if (counter == book.size()) {
			arr[counter] = '\0';

		}
		if (counter < book.size()) {
			arr[counter] = book.at(counter);
			counter++;
		}
		else
			break;
	}
}

char YearAdded[n][stringlength] = { "2013/03/05", "2009/01/01","2002/12/26","2005/06/13","1998/01/01","2005/01/01" }; //Display in YYYY-MM-DD to sort easier in selection sort algorithm


void strUpper(char* str) {
	while (*str != 0) {
		*str = toupper(*str);
		str++;
	}
}


//Add following functions to program
void BookData::setTitle(string* newTitle, int subscript) {
	string title = *newTitle;
	bookObjectArray(title, bookInfo[subscript].bookTitle, 51);
}

void BookData::setISBN(string* isbn1, int subscript) {
	string ISBN = *isbn1;
	bookObjectArray(ISBN, bookInfo[subscript].isbn, 14);
}

void BookData::setAuthor(string* Author, int subscript) {
	string author = *Author;
	bookObjectArray(author, bookInfo[subscript].author, 31);
}

void BookData::setPub(string* publisher, int subscript) {
	string pub = *publisher;
	bookObjectArray(pub, bookInfo[subscript].publisher, 31);
}

void InventoryBook::setDateAdded(string* newDate, int subscript) {
	string dateAdded = *newDate;
	bookObjectArray(dateAdded, bookInfo[subscript].dateAdded, 11);
}

void InventoryBook::setQty(int qty, int subscript) {
	bookInfo[subscript].qtyOnHand[0] = qty;
}

void InventoryBook::setWholesale(double wholeSalePrice, int subscript) {
	bookInfo[subscript].wholesale[0] = wholeSalePrice;
}

void InventoryBook::setRetail(double retailPrice, int subscript) {
	bookInfo[subscript].retail[0] = retailPrice;
}

int InventoryBook::isEmpty(int subscript) {
	if (bookTitle[0] == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void InventoryBook::removeBook(int subscript) {
	bookInfo[subscript].bookTitle[0] = 0;
	bookInfo[subscript].isbn[0] = 0;
}

//***********************BOOK INFO***************************************
int bookinfo(char isbnNumber[14], char newTitle[51], char newAuthor[31], char publisher[31], char date[11], int qty, double wholesale, double retail)
{

	cout << "              Serendipity Booksellers " << endl;
	cout << "                  Book Information\n" << endl;
	cout << "ISBN: " << isbnNumber << endl;
	cout << "Title " << newTitle << endl;
	cout << "Author: " << newAuthor << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Date Added: " << date << endl;
	cout << "Quantity-On-Hand: " << qty << endl;
	cout << "Wholesale cost: $" << setprecision(2) << fixed << wholesale << endl;
	cout << "Retail Price: $" << setprecision(2) << fixed << retail << endl;

	return 0;
}

bool BookData::bookMatch(char x[51]) {

	int i = 0;
	int YesOrNo;

	for (i; i < n; i++) {
		if (strstr(bookInfo[i].getTitle(), x)) {

			cout << "Is this the book you were looking for? " << bookInfo[i].getTitle() << endl;
			do {
				cout << "Type 1 for Yes and 2 for No. " << endl;
				cin >> YesOrNo;
				if (YesOrNo != 1 && YesOrNo != 2) {
					cout << "Please enter a valid character." << endl;
				}
			} while (YesOrNo > 2 || YesOrNo < 1);

			if (YesOrNo == 1) {
				bookinfo(bookInfo[i].getISBN(), bookInfo[i].getTitle(), bookInfo[i].getAuthor(), bookInfo[i].getPub(), bookInfo[i].getDateAdded(),
					bookInfo[i].getQty(), bookInfo[i].getWholesale(), bookInfo[i].getRetail());
				return true;
				break;
			}
			else {
				return false;
			}
		}
	}
}

//reports menu functions
void repListing() {

	cout << "\t\t    Serendipity Booksellers " << endl;
	cout << "\t\tYou selected Inventory Listing.\n\n" << endl;
	cout << "__________________________________________________________________" << endl;

	for (int i = 0; i < n; i++) {
		if (bookInfo[i].isEmpty(i) != 1) {
			cout << "Books title: " << bookInfo[i].getTitle() << endl;
			cout << "ISBN number: " << bookInfo[i].getISBN() << endl;
			cout << "Author's name: " << bookInfo[i].getAuthor() << endl;
			cout << "Publisher " << bookInfo[i].getPub() << endl;
			cout << "Date Added: " << bookInfo[i].getDateAdded() << endl;
			cout << "Amount in stock: " << bookInfo[i].getQty() << endl;
			cout << "Wholesale cost: " << setprecision(2) << fixed << bookInfo[i].getWholesale() << endl;
			cout << "Retail price: " << setprecision(2) << fixed << bookInfo[i].getRetail() << endl;
			cout << "__________________________________________________________________" << endl;
		}
	}

	cout << "\n\nPress a key to continue..." << endl;
	cin.ignore();
	cin.get();
}

void repWholesale() {
	double invenTotalCost = 0;
	cout << "You selected Inventory Wholesale Value." << endl;
	cout << "__________________________________________________________________" << endl;

	for (int i = 0; i < n; i++) {
		if (bookInfo[i].isEmpty(i) != 1) {
			cout << "\nBooks title: " << bookInfo[i].getTitle() << endl;
			cout << "ISBN number: " << bookInfo[i].getISBN() << endl;
			cout << "Date Added: " << bookInfo[i].getDateAdded() << endl;
			cout << "Amount in stock: " << bookInfo[i].getQty() << endl;
			cout << "Wholesale cost: " << setprecision(2) << fixed << bookInfo[i].getWholesale() << endl;
			cout << "__________________________________________________________________" << endl;
			invenTotalCost += (bookInfo[i].getQty() * bookInfo[i].getWholesale());
		}
	}

	cout << "\nTotal inventory wholesale cost: $" << setprecision(2) << fixed << invenTotalCost << endl;
	cout << endl;

}

void repRetail() {
	cout << "You selected Inventory Retail Value." << endl;

	double retailTotalCost = 0;
	cout << "__________________________________________________________________" << endl;

	for (int i = 0; i < n; i++) {
		if (bookInfo[i].isEmpty(i) != 1) {
			cout << "\nBooks title: " << bookInfo[i].getTitle() << endl;
			cout << "ISBN number: " << bookInfo[i].getISBN() << endl;
			cout << "Amount in stock: " << bookInfo[i].getQty() << endl;
			cout << "Retail cost: " << setprecision(2) << fixed << bookInfo[i].getRetail() << endl;
			cout << "__________________________________________________________________" << endl;
			retailTotalCost += (bookInfo[i].getQty() * bookInfo[i].getRetail());
		}
	}

	cout << "\nTotal inventory retail value of inventory: $" << setprecision(2) << fixed << retailTotalCost << endl;
	cout << endl;
}

void repQty() {

	int* MaxQty;
	int* temp;
	int maxIndex;


	int originalArrID[n];
	int* ArrID[n];
	int* qtyPtr[n];

	for (int x = 0; x < n; x++) {
		originalArrID[x] = x;
		ArrID[x] = &originalArrID[x];
		int temporary = bookInfo[x].getQty();
		qtyPtr[x] = &temporary;
	}


	cout << "You selected Listing By Quantity." << endl;
	cout << "__________________________________________________________________" << endl;

	//Selection Sort Algorithm
	for (int index = 0; index < n - 1; index++) {
		maxIndex = index;
		MaxQty = qtyPtr[index];
		temp = ArrID[index];

		for (int i = index + 1; i < n; i++) {
			if (*(qtyPtr[i]) > * MaxQty) {
				MaxQty = qtyPtr[i];
				temp = ArrID[i];
				maxIndex = i;
			}
		}

		qtyPtr[maxIndex] = qtyPtr[index];
		ArrID[maxIndex] = ArrID[index];
		qtyPtr[index] = MaxQty;
		ArrID[index] = temp;
	}

	//sorted output displayed
	for (int k = 0; k < n; k++) {
		if (bookInfo[*(ArrID[k])].isEmpty(k) != 1) {
			cout << "\nBooks title: " << bookInfo[*(ArrID[k])].getTitle() << endl;
			cout << "ISBN number: " << bookInfo[*(ArrID[k])].getISBN() << endl;
			cout << "Amount in stock: " << *qtyPtr[k] << endl;
			cout << "__________________________________________________________________" << endl;

		}
	}

	cout << "\n\nPress a key to continue..." << endl;
	cin.ignore();
	cin.get();

}

void repCost() {
	cout << "You selected Listing By Cost" << endl;

	double* MaxCost;
	int* temp;
	int maxIndex;

	int originalArrID[n];
	int* ArrID[n];
	double* costPtr[n];

	for (int x = 0; x < n; x++) {
		originalArrID[x] = x;
		ArrID[x] = &originalArrID[x];
		//costPtr[x] = &bookInfo[x].getWholesale();
	}


	cout << "You selected Listing By Cost." << endl;
	cout << "__________________________________________________________________" << endl;

	//Selection Sort Algorithm
	for (int index = 0; index < n - 1; index++) {
		maxIndex = index;
		MaxCost = costPtr[index];
		temp = ArrID[index];

		for (int i = index + 1; i < n; i++) {
			if (*(costPtr[i]) > * MaxCost) {
				MaxCost = costPtr[i];
				temp = ArrID[i];
				maxIndex = i;
			}
		}

		costPtr[maxIndex] = costPtr[index];
		ArrID[maxIndex] = ArrID[index];
		costPtr[index] = MaxCost;
		ArrID[index] = temp;
	}

	for (int k = 0; k < n; k++) {
		if (bookInfo[*(ArrID[k])].isEmpty(k) != 1) {
			cout << "\nBooks title: " << bookInfo[*(ArrID[k])].getTitle() << endl;
			cout << "ISBN number: " << bookInfo[*(ArrID[k])].getISBN() << endl;
			cout << "Greatest unit cost: " << setprecision(2) << fixed << *costPtr[k] << endl;
			cout << "__________________________________________________________________" << endl;

		}
	}

	cout << "\n\nPress a key to continue..." << endl;
	cin.ignore();
	cin.get();
}

void repAge() {

	int id[n];
	int* ArrID[n];
	char* datePtr[n][stringlength];
	int* temp;
	int maxIndex;
	char* MaxDate;


	for (int i = 0; i < n; i++) {
		id[i] = i;
		ArrID[i] = &id[i];
		strcpy(*datePtr[i], YearAdded[i]);
	}

	for (int index = 0; index < n - 1; index++) {
		maxIndex = index;
		MaxDate = *datePtr[index];
		temp = ArrID[index];

		for (int i = index + 1; i < n; i++) {
			if (*(datePtr[i]) > MaxDate) {
				MaxDate = *datePtr[i];
				temp = ArrID[i];
				maxIndex = i;
			}
		}

		strcpy(*datePtr[maxIndex], *datePtr[index]);
		ArrID[maxIndex] = ArrID[index];
		*datePtr[index] = MaxDate;
		ArrID[index] = temp;
	}

	cout << "\t\t    Serendipity Booksellers " << endl;
	cout << "\t\tYou selected Listing By Age.\n\n" << endl;
	cout << "__________________________________________________________________" << endl;

	for (int k = 0; k < n; k++) {
		if (bookInfo[*(ArrID[k])].isEmpty(k) != 1) {
			cout << "\nBooks title: " << bookInfo[*(ArrID[k])].getTitle() << endl;
			cout << "ISBN number: " << bookInfo[*(ArrID[k])].getISBN() << endl;
			cout << "Date added (YYYY-MM-DD): " << YearAdded[*ArrID[k]] << endl; //Date format change for easier sorting using selection sort algorithm
			cout << "__________________________________________________________________" << endl;

		}
	}
}


//inv menu functions

void addBook() {

	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int qty;
	double wholesale;
	double retail;
	BookData book;
	InventoryBook inv;
	int bookIndex = -1;

	for (int i = 0; i < n; i++) {
		if (inv.isEmpty(i)) {
			bookIndex = i;
		}
	}

	if (bookIndex != -1) {

		cin.ignore(10000, '\n');
		cout << endl << "\nPlease enter the new book title you would like to add." << endl;
		getline(cin, bookTitle);
		bookInfo[bookIndex].setTitle(&bookTitle, bookIndex);


		cout << "Please enter the books ISBN number:" << endl;
		getline(cin, isbn);
		bookInfo[bookIndex].setISBN(&isbn, bookIndex);

		cout << "Enter the Author's name." << endl;
		getline(cin, author);
		bookInfo[bookIndex].setAuthor(&author, bookIndex);


		cout << "Enter the publishers name." << endl;
		getline(cin, publisher);
		bookInfo[bookIndex].setPub(&publisher, bookIndex);


		cout << "When was the book added to the inventory (MM-DD-YYYY) ?" << endl;
		getline(cin, dateAdded);
		bookInfo[bookIndex].setDateAdded(&dateAdded, bookIndex);


		cout << "How many books are being added?" << endl;
		cin >> qty;
		bookInfo[bookIndex].setQty(qty, bookIndex);

		cout << "Enter the wholesale cost of a single book." << endl;
		cin >> wholesale;
		bookInfo[bookIndex].setWholesale(wholesale, bookIndex);


		cout << "Enter the retail price of a single book." << endl;
		cin >> retail;
		bookInfo[bookIndex].setRetail(retail, bookIndex);

		return;

	}
	else {
		cout << "No more books can be added." << endl;
	}


}

void lookUpBook() {

	int i = 0;
	int YesOrNo;
	char bookTitleSearch[51];

	cout << "\nWhat is the title of the book you are looking up?" << endl;
	cin.ignore();
	cin.getline(bookTitleSearch, 51);

	BookData match;

	match.bookMatch(bookTitleSearch);

	//strUpper(bookTitleSearch);
	if (i > (n - 1))
		cout << "The book you are looking for is not in the inventory." << endl;
}


void editBook() {
	char bookTitleUser[stringlength];
	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int qty;
	double wholesale;
	double retail;
	int YesOrNo;
	int i;
	bool flag = false;

	cout << "\nWhat is the title of the book you want to edit?" << endl;
	cin.ignore();
	cin.getline(bookTitleUser, stringlength);


	BookData match;

	//match.bookMatch(bookTitleUser);


	for (i = 0; i < n; i++) {
		if (strstr(bookInfo[i].getTitle(), bookTitleUser)) {

			if (match.bookMatch(bookTitleUser) == true) {

				int choice;
				cout << "What field do you want to edit? Please select a number. " << endl;
				cout << "1. Title:" << endl;
				cout << "2. ISBN: " << endl;
				cout << "3. Author: " << endl;
				cout << "4. Publisher:" << endl;
				cout << "5. Date Added: " << endl;
				cout << "6. Quantity-On-Hand: " << endl;
				cout << "7. Wholesale cost: " << endl;
				cout << "8. Retail Price: " << endl;
				cout << "Enter your choice: " << endl;
				cin >> choice;

				while (choice > 8 || choice < 1) {
					cout << "Please enter a valid choice:" << endl;
					cin >> choice;
				}

				switch (choice) {
				case 1: cin.ignore();
					cout << "Please enter the new book title you would like to add." << endl;
					getline(cin, bookTitle);
					bookInfo[i].setTitle(&bookTitle, i);
					break;
				case 2: cout << "Please enter the books new ISBN number:" << endl;
					getline(cin, isbn);
					bookInfo[i].setISBN(&isbn, i);
					break;
				case 3: cout << "Enter the Author's name." << endl;
					getline(cin, author);
					bookInfo[i].setAuthor(&author, i);
					break;
				case 4: cout << "Enter the publishers name." << endl;
					getline(cin, publisher);
					bookInfo[i].setPub(&publisher, i);
					break;
				case 5: cout << "When was the book added to the inventory (MM-DD-YYYY) ?" << endl;
					getline(cin, dateAdded);
					bookInfo[i].setDateAdded(&dateAdded, i);
					break;
				case 6: cout << "How many books are in inventory?" << endl;
					cin >> qty;
					bookInfo[i].setQty(qty, i);
					break;
				case 7: cout << "Enter the wholesale cost of a single book." << endl;
					cin >> wholesale;
					bookInfo[i].setWholesale(wholesale, i);
					break;
				case 8:
					cout << "Enter the retail price of a single book." << endl;
					cin >> retail;
					bookInfo[i].setRetail(retail, i);
					break;
				}

				cout << "Value has been updated." << endl;
				break;
			}
		}
	}

	// User chooses which field to edit for given book
	if (match.bookMatch(bookTitleUser) == false) {
		cout << "The book is not in the inventory." << endl;
	}
}

void deleteBook() {
	int i = 0;
	int YesOrNo;
	bool flag = false;
	char bookTitleSearch[stringlength];
	cout << "\nWhat is the book that you would like to delete?" << endl;
	cin.ignore();
	cin.getline(bookTitleSearch, stringlength);

	BookData Book;

	if (Book.bookMatch(bookTitleSearch) == true) {
		bookInfo[i].removeBook(i);

		cout << "\nBook information has been deleted" << endl;
		return;

	}
	else if (Book.bookMatch(bookTitleSearch) == false) {
		cout << "The book is not in the inventory." << endl;
	}

}


//******************************INV MENU*************************/

void invMenu()
{
	int choice;

	do {
		//Inventory Menu
		cout << "\nSerendipity Booksellers" << endl;
		cout << "  Inventory Database   \n" << endl;
		cout << "1. Look up a book" << endl;
		cout << "2. Add a book " << endl;
		cout << "3. Edit a book's record" << endl;
		cout << "4. Delete a book" << endl;
		cout << "5. Return to the Main Menu \n" << endl;
		cout << "Enter Your Choice: " << endl;
		cin >> choice;

		//Choice validation
		while (choice > 5 || choice < 1) {
			cout << "Please enter a number in the range 1 - 5." << endl;
			cin >> choice;
		}

		switch (choice) {
		case 1: lookUpBook();
			break;
		case 2: addBook();
			break;
		case 3: editBook();
			break;
		case 4: deleteBook();
			break;
		case 5: cout << "\nYou selected item 5" << endl;
			break;
		}

	} while (choice != 5);

}

/************************CASHIER***********************************/
void cashier()
{
	//Declare all variables in the beginning
	string ISBN;
	string date;
	string newBookTitle;
	float bookPrice = 0;
	int quantityOfBooks = 0;
	float SubTotal;
	float Tax;
	int YesOrNo = 1;
	int NumTitlePur;

	char BookTitle[n][stringlength];
	char isbnNumber[n][stringlength];
	char DateOfTrans[stringlength];
	int quantityBook;
	double costPerBook;
	double subTotal;

	double tempTotal = 0;
	double grandTotal = 0;

	int count = 0;
	int positiveQty;
	BookData book;


	while (YesOrNo == 1) {
		//Ask user Questions
		cout << "Welcome to Seredipity Booksellers, please enter the following information." << endl;
		cout << "What is today's date? Please enter in MM/DD/YY form: " << endl;
		cin.ignore();
		cin.getline(DateOfTrans, stringlength);  // Enter date of transaction in array at index 0
		cout << "How many titles would you like to purchase?" << endl;
		cin >> NumTitlePur;
		cin.ignore();

		SoldBook* bookSold;
		try {
			bookSold = new SoldBook[NumTitlePur]; //Dynamic array allocation
		}
		catch (exception & e) {
			cout << "Memory fail. Exiting program.";
			exit(0);
		}

		cout << "What is the book's ISBN: " << endl;
		getline(cin, ISBN); // Enter isbn in array at index 0

		for (int i = 0; i < n; i++) {

			if (bookInfo[i].getISBN() == ISBN) {
				cout << "The title of the book is:  " << bookInfo[i].getTitle() << endl;
				cout << setprecision(2) << fixed << "Retail Price: " << bookInfo[i].getRetail() << endl;

				costPerBook = bookInfo[i].getRetail();
				strcpy_s(BookTitle[count], bookInfo[i].getTitle());

				positiveQty = bookInfo[i].getQty();

				if (positiveQty == 0) {
					throw "ERROR: There are no more books available for purchase. \n";
					return;
				}

				cout << "How many copies would you like to buy: " << endl;
				cin >> quantityBook;

				while (quantityBook < 1 || quantityBook > positiveQty) {

					if (quantityBook < 1) {
						cout << "Enter a valid quanity." << endl;
					}
					else {
						cout << "There is not enough in inventory for this. " << endl;
					}

					cout << "How many books would you like to buy: " << endl;
					cin >> quantityBook;
				}

				bookInfo[i].setQty(bookInfo[i].getQty() - quantityBook, i);
				count++;

				cout << "\nDo you have another title you would like to add? Press 1 for YES and 2 for NO" << endl;
				cin.ignore();
				cin >> YesOrNo;

				//Choice validation loop
				while (YesOrNo > 2 || YesOrNo < 1) {
					cout << "Please enter either 1 for YES or 2 for No:" << endl;
					cin >> YesOrNo;
				}

				if (YesOrNo == 2) {
					break;
				}

			}
			else if (i == (n - 1)) {
				cout << "The ISBN number is not in the system. " << endl;
			}
		}


		if (count > 0)
		{
			//Cost Calculations
			SubTotal = (double)quantityOfBooks * (double)bookPrice;
			//Tax = SubTotal * (0.06);
			//PriceTotal = Tax + SubTotal;

			//Transaction Display
			cout << "\n\nSerendipity Booksellers\n" << endl;
			cout << "Date: " << date << "\n" << endl;
			cout << "Qty    ISBN            Title              Price       Total " << endl;
			cout << "---------------------------------------------------------------  " << endl;

			for (int i = 0; i < count; i++) {
				subTotal = quantityBook * costPerBook;
				Tax = subTotal * (.06);
				tempTotal += subTotal;
				grandTotal = (Tax + tempTotal);


				cout << quantityBook << "     " << ISBN << "      " << BookTitle[i] << "        $" << setprecision(2) << fixed << setw(6) << costPerBook << "          $" << setprecision(2) << fixed << setw(6) << subTotal << "\n\n" << endl;
			}
			cout << "Subtotal                                                 $" << tempTotal << endl;
			cout << "Tax                                                      $" << right << Tax << endl;
			cout << "Total                                                    $" << grandTotal << endl;
			cout << "\n\nThank You for Shopping at Serendipity!" << endl;
			cout << "\nDo you have another transaction? Press 1 for YES and 2 for NO" << endl;
			cin >> YesOrNo;

			//Choice validation loop
			while (YesOrNo > 2 || YesOrNo < 1) {
				cout << "Please enter either 1 for YES or 2 for No:" << endl;
				cin >> YesOrNo;
			}

		}

	}
	return;
}



//************************REPORTS*****************************************
void reports()
{
	int choice;

	//Use do while loop since program has to execute at least once first. 
	do {
		//Reports Menu screen
		cout << "  Serendipity Booksellers" << endl;
		cout << "         Reports\n" << endl;
		cout << "1. Inventory Listing" << endl;
		cout << "2. Inventory Wholesale Value" << endl;
		cout << "3. Inventory Retail Value" << endl;
		cout << "4. Listing by Quantity" << endl;
		cout << "5. Listing by Cost" << endl;
		cout << "6. Listing by Age" << endl;
		cout << "7. Return to Main Menu\n" << endl;

		cout << "Enter Your Choice: " << endl;
		cin >> choice;

		//choice validation
		while (choice > 7 || choice < 1) {
			cout << "Please enter a number in the range 1 - 7." << endl;
			cin >> choice;
		}

		//call functions using switch
		switch (choice) {
		case 1: repListing();
			break;
		case 2: repWholesale();
			break;
		case 3: repRetail();
			break;
		case 4: repQty();
			break;
		case 5: repCost();
			break;
		case 6: repAge();
			break;
		case 7: cout << "\nYou selected item 7" << endl;
			break;
		}
	} while (choice != 7);
}

int main()
{
	int choice;

	try
	{
		bookFile.open("database.txt", ios::in);
		if (bookFile.fail())
		{
			string errString = "ERROR: File does not exist. Creating new book database file. \n";
			throw errString;
		}
		else
		{
			bookFile.close();
		}
	}
	catch (string error)
	{
		cout << error << endl;
		bookFile.open("database.txt", ios::out);
		bookFile.close();
		bookFile.clear();
	}

	cout << "No books in inventory. Please add a book." << endl;
	addBook();
	//reports menu functions
	try {
		do {
			//Menu screen output
			cout << "Serendipity Booksellers" << endl;
			cout << "        Main Menu       \n" << endl;
			cout << "1. Cashier Module" << endl;
			cout << "2. Inventory Database Module" << endl;
			cout << "3. Report Module" << endl;
			cout << "4. Exit\n\n" << endl;
			cout << "Enter Your Choice: " << endl;
			cin >> choice;

			//input validation for choices
			while (choice > 4 || choice < 1) {
				cout << "Please enter a number in the range 1 - 4." << endl;
				cout << "Enter Your Choice: " << endl;
				cin >> choice;
			}

			//calls functions after choice was selected
			switch (choice) {
			case 1: cashier();
				break;
			case 2: invMenu();
				break;
			case 3: reports();
				break;
			case 4: cout << "You selected to exit the program." << endl;
				break;

			}
		} while (choice != 4);
	}
	catch (bad_alloc) {
		cout << "ERROR: Insufficient memory to allocate.";
		return 0;
	}
}
