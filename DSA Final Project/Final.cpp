#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


struct Book {
    int id;
    string title;
    string author;
    string genre;
};


class Library {
private:
    vector<Book> books;                    
    unordered_map<int, string> issuedBooks; 

public:
    void addBook(int id, string title, string author, string genre) {
        books.push_back({id, title, author, genre});
        cout << "Book added successfully.\n";
    }

    
    void searchBook(int id) {
        for (const auto& book : books) {
            if (book.id == id) {
                cout << "Book Found: ID: " << book.id << ", Title: " << book.title
                     << ", Author: " << book.author << ", Genre: " << book.genre << endl;
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Delete a book by ID
    void deleteBook(int id) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].id == id) {
                books.erase(books.begin() + i);
                cout << "Book deleted successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Display all books
    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        cout << "Books in the Library:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title
                 << ", Author: " << book.author << ", Genre: " << book.genre << endl;
        }
    }

    // Issue a book
    void issueBook(int id, string user) {
        for (const auto& book : books) {
            if (book.id == id) {
                if (issuedBooks.find(id) == issuedBooks.end()) {
                    issuedBooks[id] = user;
                    cout << "Book ID " << id << " issued to " << user << ".\n";
                } else {
                    cout << "Book is already issued.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Return a book
    void returnBook(int id) {
        if (issuedBooks.erase(id)) {
            cout << "Book ID " << id << " returned successfully.\n";
        } else {
            cout << "Book ID " << id << " was not issued.\n";
        }
    }

    // Display issued books
    void displayIssuedBooks() {
        if (issuedBooks.empty()) {
            cout << "No books are issued.\n";
            return;
        }
        cout << "Issued Books:\n";
        for (const auto& pair : issuedBooks) {
            cout << "Book ID: " << pair.first << ", Issued to: " << pair.second << endl;
        }
    }
};

// Main function
int main() {
    Library library;
    int choice, id;
    string title, author, genre, user;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Delete Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Display Issued Books\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(); // To consume the newline character
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Genre: ";
            getline(cin, genre);
            library.addBook(id, title, author, genre);
            break;

        case 2:
            cout << "Enter Book ID to search: ";
            cin >> id;
            library.searchBook(id);
            break;

        case 3:
            cout << "Enter Book ID to delete: ";
            cin >> id;
            library.deleteBook(id);
            break;

        case 4:
            library.displayAllBooks();
            break;

        case 5:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            cin.ignore();
            cout << "Enter User Name: ";
            getline(cin, user);
            library.issueBook(id, user);
            break;

        case 6:
            cout << "Enter Book ID to return: ";
            cin >> id;
            library.returnBook(id);
            break;

        case 7:
            library.displayIssuedBooks();
            break;

        case 8:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
