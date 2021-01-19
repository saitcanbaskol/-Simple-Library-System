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

Student::Student()
{
    stuhead = NULL;
    studentBooks = 0;
    studentId = 0;
    studentName = "DEFAULT";

}
Student::Student(int id,string name)
{
    stuhead = NULL;
    studentBooks = 0;
    setId(id);
    setName(name);
}
Student::~Student()
{
    while(!isEmpty())
    {
        removeNode(1);
    }
}
int Student::getId()
{
    return studentId;
}
void Student::setId(int id)
{
    studentId = id;
}
string Student::getName()
{
    return studentName;
}
void Student::setName(string nameP)
{
    studentName = nameP;
}
bool Student::isEmpty() const
{
    return studentBooks == 0;
}
int Student::getLength() const
{
    return studentBooks;
}
int Student::findIndex(int bookId)
{
    studentBookNode* cur = stuhead;
    for(int i = 1; i <= getLength();i++)
    {
        if(cur->item.getBookId() == bookId)
        {
            return i;
        }
        cur = cur->next;
    }


}
Student::studentBookNode* Student::findPointer(int index)
{
    studentBookNode* cur = stuhead;
    for(int i = 1; i < index; i++)
    {
        cur = cur->next;
    }
    return cur;
}
bool Student::removeNode(int index)
{
    studentBookNode* cur;
    if ((index < 1) || (index > getLength()))
    {
       return false;
    }
    studentBooks--;
    if(index == 1)
    {
        cur = stuhead;
        stuhead = stuhead->next;
    }
    else
    {
        studentBookNode* prev = findPointer(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;
    return true;
}


