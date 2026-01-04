#include <iostream>
#include<conio.h>
#include <cstring>
#include <windows.h>
using namespace std;

struct Book{
    int id;
    char name[50];
    char author[50];
    float price;
    int stock;
};

struct Cart {
    int id;
    char name[50];
    float price;
    int quantity;
};


void pressEnterToContinue(){
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    system("cls");
} //this function will clear the screen after making the choice 

void showBooks(Book books[], int size) {
    cout << "\nAvailable Books:\n";
    cout << "ID\tName\t\tAuthor\t\tPrice\tStock\n";
    for (int i = 0; i < size; i++) {
        cout << books[i].id << "\t"
             << books[i].name << "\t\t"
             << books[i].author << "\t\t"
             << books[i].price << "\t"
             << books[i].stock <<endl;
    }
} //this function will display the books

void searchBook(Book books[], int size) {
    int option;
    cout << "\nSearch the book by:\n1. ID\n2. Name\nEnter option: ";
    cin >> option;

    if (option == 1) {
        int id;
        cout << "Enter the Book ID: ";
        cin >> id;
        for (int i = 0; i < size; i++) {
            if (books[i].id == id) {
                cout << "Book Found: " << books[i].name
                     << " | Price: " << books[i].price << endl;
                return;
            }
        }
        cout << "Sorry, Book not found.\n";
    }
    else if (option == 2) {
        char name[50];
        cout << "Enter Book Name: ";
        cin >> name;
        for (int i = 0; i < size; i++) {
            if (strcmp(books[i].name, name) == 0) {
                cout << "Book Found: " << books[i].name
                     << " | Price: " << books[i].price << endl;
                return;
            }
        }
        cout << "Sorry, Book not found.\n";
    }
}

void loadingBar() {
    system("cls");
    cout << "\n\n\n\t\tStarting Online Book Store...\n\n";

    cout << "\t\t[";

    for (int i = 0; i < 50; i++)
        cout << " ";

    cout << "] 0%";

    cout << "\r\t\t[";

    for (int i = 0; i <= 50; i++) {
        // progress bar
        cout << "\r\t\t[";

        for (int j = 0; j < i; j++)
            cout << "#";

        for (int j = i; j < 50; j++)
            cout << " ";

        cout << "] " << i * 2 << "%";
        Sleep(50);
    }
    system("color 0A");   // 0 = black background, A = green text
    system("cls"); //CHANGE COLOR TO GREEN AFTER LOADING
}


void addToCart(Book books[], Cart cart[], int &cartSize, int bookSize) {
    int id, qty;
    cout << "Enter Book ID to add to cart: ";
    cin >> id;

    for (int i = 0; i < bookSize; i++) {
        if (books[i].id == id) {
            cout << "Enter quantity: ";
            cin >> qty;

            if (qty <= books[i].stock) {
                cart[cartSize].id = books[i].id;
                strcpy(cart[cartSize].name, books[i].name);
                cart[cartSize].price = books[i].price;
                cart[cartSize].quantity = qty;

                books[i].stock -= qty;
                cartSize++;

                cout << "Book added to cart successfully.\n";
                return;
            } else {
                cout << "Not enough stock available.\n";
                return;
            }
        }
    }
    cout << "Invalid Book ID.\n";
}

void viewCart(Cart cart[], int cartSize) {
    if (cartSize == 0) {
        cout << "\nCart is empty.\n";
        return;
    }

    cout << "\nYour Cart:\n";
    cout << "ID\tName\t\tPrice\tQuantity\n";
    for (int i = 0; i < cartSize; i++) {
        cout << cart[i].id << "\t"
             << cart[i].name << "\t\t"
             << cart[i].price << "\t"
             << cart[i].quantity << endl;
    }
}

void removeFromCart(Cart cart[], int &cartSize) {
    int id;
    cout << "Enter Book ID to remove: ";
    cin >> id;

    for (int i = 0; i < cartSize; i++) {
        if (cart[i].id == id) {
            for (int j = i; j < cartSize - 1; j++) {
                cart[j] = cart[j + 1];
            }
            cartSize--;
            cout << "Book removed from cart.\n";
            return;
        }
    }
    cout << "Book not found in cart.\n";
}

float calculateBill(Cart cart[], int cartSize) {
    float total = 0;
    for (int i = 0; i < cartSize; i++) {
        total += cart[i].price * cart[i].quantity;
    }
    return total;
}

int main() {
	
	 loadingBar();
	
    Book books[5] = {
        {1, "PF", "Talha", 500, 10},
        {2, "English", "Maryam", 650, 8},
        {3, "DS", "Rehana", 800, 5},
        {4, "ICT", "Ahmed", 700, 6},
        {5, "OOP", "Wajiha", 750, 7}
    };

    Cart cart[10];
    int cartSize = 0;
    int option;

    do {
        cout << "\n========== Welcome to the ONLINE BOOK STORE ==========\n";
        cout << "Hey There, What you want us to do for you? \n"<<endl;
        cout << "========================================================="<<endl;
        cout << "1. View All Books"<<endl;
        cout << "2. Search Book"<<endl;
        cout << "3. Add Book to Cart"<<endl;
        cout << "4. View Cart"<<endl;
        cout << "5. Remove Book from Cart"<<endl;
        cout << "6. Checkout"<<endl;
        cout << "7. Exit \n"<<endl;
        cout << "Enter the option: ";
        cin >> option;

        switch (option) {
        case 1:
            showBooks(books, 5);
            pressEnterToContinue();
            break;

        case 2:
            searchBook(books, 5);
            pressEnterToContinue();
            break;

        case 3:
            addToCart(books, cart, cartSize, 5);
            pressEnterToContinue();
            break;

        case 4:
            viewCart(cart, cartSize);
            pressEnterToContinue();
            break;

        case 5:
            removeFromCart(cart, cartSize);
            pressEnterToContinue();
            break;

        case 6: {
            float total = calculateBill(cart, cartSize);
            cout << "\nTotal Bill: Rs. " << total << endl;
            cout << "Thank you for shopping!\n";
            cartSize = 0;
            pressEnterToContinue();
            break;
        }

        case 7:
            cout <<"Exiting program...\n";
            break;

        default:
            cout << "Please enter the valid option"<<endl;
            pressEnterToContinue();
        }
    } while (option != 7);
    return 0;
}
