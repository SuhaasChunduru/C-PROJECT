#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Class to represent the Library Management System
class LibraryManagementSystem {
private:
    vector<string> books;          // Vector to store available books
    vector<string> borrowedBooks; // Vector to store borrowed books

public:
    // Constructor to initialize the library with books
    LibraryManagementSystem() {
        books = {
            "C++ Primer", "Introduction to Algorithms", "Clean Code",
            "Artificial Intelligence: A Modern Approach", "Design Patterns",
            "The Pragmatic Programmer", "Cracking the Coding Interview",
            "Computer Networking", "Database System Concepts", "Operating System Concepts",
            "Harry Potter and the Sorcerer's Stone", "Harry Potter and the Chamber of Secrets",
            "Harry Potter and the Prisoner of Azkaban", "The Lord of the Rings",
            "The Hobbit", "Pride and Prejudice", "1984", "To Kill a Mockingbird",
            "The Catcher in the Rye", "The Great Gatsby"
        };
    }

    // Function to display all available books
    void displayBooks() {
        cout << "========= All Available Books =========\n";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << i + 1 << ". " << books[i] << endl;
        }
        if (books.empty()) {
            cout << "No books are currently available in the library.\n";
        }
        cout << "=======================================\n";
        if (!borrowedBooks.empty()) {
            cout << "Books Currently Borrowed:\n";
            for (size_t i = 0; i < borrowedBooks.size(); ++i) {
                cout << i + 1 << ". " << borrowedBooks[i] << endl;
            }
        }
        cout << "=======================================\n";
    }

    // Function to search for a book
    void searchBook() {
        cout << "Enter the title of the book you want to search for: ";
        string bookTitle;
        cin.ignore();
        getline(cin, bookTitle);

        // Check if the book is in the library
        auto it = find(books.begin(), books.end(), bookTitle);
        if (it != books.end()) {
            cout << "Book '" << bookTitle << "' is available in the library.\n";
        } else {
            cout << "Book '" << bookTitle << "' is not available in the library.\n";
        }
    }

    // Function to borrow a book
    void borrowBook() {
        cout << "Enter the title of the book you want to borrow: ";
        string bookTitle;
        cin.ignore();
        getline(cin, bookTitle);

        // Check if the book is in the library
        auto it = find(books.begin(), books.end(), bookTitle);
        if (it != books.end()) {
            cout << "Borrowing '" << bookTitle << "'...\n";
            borrowedBooks.push_back(bookTitle); // Add to borrowed books
            books.erase(it); // Remove from available books
            cout << "Successfully borrowed '" << bookTitle << "'.\n";
        } else {
            cout << "The book '" << bookTitle << "' is currently unavailable!\n";
        }
    }

    // Function to return a book
    void returnBook() {
        cout << "Enter the title of the book you want to return: ";
        string bookTitle;
        cin.ignore();
        getline(cin, bookTitle);

        // Check if the book is in the borrowed list
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), bookTitle);
        if (it != borrowedBooks.end()) {
            cout << "Returning '" << bookTitle << "'...\n";
            books.push_back(bookTitle); // Add back to available books
            borrowedBooks.erase(it);   // Remove from borrowed books
            cout << "Successfully returned '" << bookTitle << "'.\n";
        } else {
            cout << "The book '" << bookTitle << "' was not borrowed!\n";
        }
    }
};

int main() {
    LibraryManagementSystem lms;
    int choice;

    do {
        cout << "\n========= Library Management System =========\n";
        cout << "1. Display all books\n";
        cout << "2. Search for a book\n";
        cout << "3. Borrow a book\n";
        cout << "4. Return a book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lms.displayBooks();
            break;
        case 2:
            lms.searchBook();
            break;
        case 3:
            lms.borrowBook();
            break;
        case 4:
            lms.returnBook();
            break;
        case 5:
            cout << "Exiting the Library Management System. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
