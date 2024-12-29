This C++ program implements a basic Library Management System using a Binary Search Tree (BST) to manage books, and an unordered map to manage issued books. It provides functionality for adding, searching, deleting, issuing, and returning books.

Features
Book Management:

Add books to the library.
Search books by ID.
Delete books from the library.
Display all books in the library in sorted order.
Book Issuing:

Issue a book to a user.
Return a book to the library.
Display the list of issued books.
File Structure
Library Management System: Main program with the implementation of classes for managing books and issued books.

Book Class: Represents the structure of a book with fields such as ID, title, author, and genre.

TreeNode Class: Represents a node in the binary search tree (BST) to store books and provide operations like insertion, deletion, and search.

BookBST Class: Manages the binary search tree, implementing functions to add, search, delete, and display books.

Library Class: Manages the overall operations of the library, including adding books, issuing/returning books, and displaying the status of the library.

