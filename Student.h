#include<iostream>
using namespace std;
#include <string>
#include <cstddef>
#include "Book.h"
/*
Saitcan Baskol
21803589
SEC02
*/
class Student
{
public:
    Student();
    Student(int id,string name);
    ~Student();
    Student(const Student& rightVal);
    //Student& operator=(const Student& rightVal);
    int getId();
    void setId(int id);
    string getName();
    void setName(string name);
    //studentBookNode methods
    bool isEmpty() const;
    int getLength() const;
    bool removeNode(int index);
    int findIndex(int studentId);
     struct studentBookNode
    {
        Book item;
        studentBookNode* next;
    };
    studentBookNode* stuhead;
    int studentBooks;
    studentBookNode* findPointer(int index);
private:
    int studentId;
    string studentName;

};
