#include<iostream>
using namespace std;
#include <string>
#include <cstddef>
#include "Student.h"
/*
Saitcan Baskol
21803589
SEC02
*/

class LibrarySystem
{
public:
    LibrarySystem();
    ~LibrarySystem();
    void addStudent(const int studentId, const string studentName);
    void addBook(const int bookId, const string bookName, const int bookYear);
    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);
    void showBook(const int bookId) const;
    void showAllBooks() const;
    void showStudent(const int studentId) const;
    void deleteBook(const int bookId);
    void deleteStudent(const int studentId);
    bool isEmpty() const;
    bool isBooksEmpty() const;
    bool removeNode(int index);
    bool removeBookNode(int index);

    int findBookIndex(int bookId);
    int findIndex(int studentId);
    int getLengthBooks() const;
    int getLength() const;

private:
    struct Node
    {
        Student item;
        Node* next;
    };
    Node* head;
    int Size;
    Node* findPointer(int index) const;
    struct allBooksNode
    {
        Book item;
        allBooksNode* next;
    };
    allBooksNode* bookHead;
    int bookSize;
    allBooksNode* findBookPointer(int index) const;
};

