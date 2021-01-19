#include<iostream>
#include<string>
#include "LibrarySystem.h"
#include <cstddef>
using namespace std;
/*
Saitcan Baskol
21803589
SEC02
*/
LibrarySystem::LibrarySystem()
{
    Size = 0;
    head = NULL;
    bookSize = 0;
    bookHead = NULL;
}
LibrarySystem::~LibrarySystem()
{
    while(!isEmpty())
    {
        removeNode(1);
    }
    while(!isBooksEmpty())
    {
        removeBookNode(1);
    }
}
void LibrarySystem::addStudent(const int studentId,const string studentName)
{
    bool notExist = true;
    int newLength;
    if(studentId > 0)
    {
        if(getLength() == 0)
        {
            Node* temp = new Node();
            temp->item = Student(studentId,studentName);
            temp->next = NULL;
            head = temp;
            newLength = getLength() + 1;
            Size = newLength;
            cout<<"Student:"<<studentId<<" Has been added"<<endl;
            return;

        }
        Node* cur = head;
        for(int i = 1; i <= getLength(); i++)
        {
            if(cur->item.getId() == studentId)
            {
                notExist = false;
            }
            cur = cur->next;
        }
        if(notExist)
        {

            Node* prev = findPointer(getLength());
            Node* temp = new Node();
            temp->item = Student(studentId,studentName);
            prev->next = temp;
            temp->next = NULL;

            Size++;
            cout<<"Student: "<<studentId <<" Has been added"<<endl;

        }
        else
        {
            cout<<"Student "<<studentId<<" already exists"<<endl;
        }

    }
}
bool LibrarySystem::isEmpty() const
{
    return Size == 0;
}
bool LibrarySystem::isBooksEmpty()const
{
    return bookSize == 0;
}
int LibrarySystem::getLength() const
{
    return Size;
}
int LibrarySystem::getLengthBooks() const
{
    return bookSize;
}
int LibrarySystem::findIndex(int studentId)
{
    Node* cur = head;
    for(int i = 1; i <= getLength();i++)//here
    {
        if(cur->item.getId() == studentId)
        {
            return i;
        }
        cur = cur->next;
    }


}
int LibrarySystem::findBookIndex(int bookId)
{
    allBooksNode* cur = bookHead;
    for(int i = 1; i <= getLengthBooks();i++)//here
    {
        if(cur->item.getBookId() == bookId)
        {
            return i;
        }
        cur = cur->next;
    }
}
LibrarySystem::Node* LibrarySystem::findPointer(int index) const
{
    Node* cur = head;
    for(int i = 1; i < index; i++)//here
    {
        cur = cur->next;
    }
    return cur;
}
LibrarySystem::allBooksNode* LibrarySystem::findBookPointer(int index) const
{
    allBooksNode* cur = bookHead;
    for(int i = 1; i < index; i++)
    {
        cur = cur->next;
    }
    return cur;
}
bool LibrarySystem::removeNode(int index)
{
    Node* cur;
    if ((index < 1) || (index > getLength()))
    {
       return false;
    }
    Size--;
    if(index == 1)
    {
        cur = head;
        head = head->next;
    }
    else
    {
        Node* prev = findPointer(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;
    return true;
}
bool LibrarySystem::removeBookNode(int index)
{
    allBooksNode* cur;
    if ((index < 1) || (index > getLengthBooks()))
    {
       return false;
    }
    bookSize--;
    if(index == 1)
    {
        cur = bookHead;
        bookHead = bookHead->next;
    }
    else
    {
        allBooksNode* prev = findBookPointer(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;
    return true;


}
void LibrarySystem::addBook(const int bookId,const string bookName,const int bookYear)
{
    bool notExist = true;
    int newLength;

        if(getLengthBooks() == 0)
        {
            allBooksNode* temp = new allBooksNode();
            temp->item = Book(bookId,bookName,bookYear);
            temp->next = NULL;
            bookHead = temp;
            newLength = getLengthBooks() + 1;
            bookSize = newLength;
            cout<<"Book:"<<bookId<<" Has been added"<<endl;
            return;

        }
        allBooksNode* cur = bookHead;
        for(int i = 1; i <= getLengthBooks(); i++)
        {
            if(cur->item.getBookId() == bookId)
            {
                notExist = false;
            }
            cur = cur->next;
        }
        if(notExist)
        {
            allBooksNode* prev = findBookPointer(getLengthBooks());
            allBooksNode* temp = new allBooksNode();
            temp->item = Book(bookId,bookName,bookYear);
            prev->next = temp;
            temp->next = NULL;
            bookSize++;
            cout<<"Book: "<<bookId <<" Has been added"<<endl;

        }
        else
        {
            cout<<"Book "<<bookId<<" already exists"<<endl;
        }


}
void LibrarySystem::checkoutBook(const int bookId,const int studentId)
{
    bool bookExist = false;
    bool studentExist = false;
    Node* cur = head;
    int stuIndex;
    int bookIndex;
    allBooksNode* curBook = bookHead;
    for(int i = 1; i <= getLengthBooks(); i++)
        {
            if(curBook->item.getBookId() == bookId)
            {
                if(curBook->item.getStatus() == true)
                {
                bookExist = true;
                bookIndex = i;
                }
                else
                {
                       cout<<"Book: "<<bookId<<" Has been checked out by another student "<<endl;
                       return;
                }


            }
            curBook = curBook->next;
        }
        if(bookExist)
        {
            for(int i = 1; i <= getLength(); i++)
            {
                if(cur->item.getId() == studentId)
                {
                    studentExist = true;
                    stuIndex = i;
                }
                cur = cur->next;
            }
        }
        else
        {
            cout<<"Book :"<<bookId<<" does not exist for checkout"<<endl;
        }
        if(bookExist == true && studentExist == true)
        {
            Node* stuTemp = findPointer(stuIndex);
            allBooksNode* bookTemp = findBookPointer(bookIndex);

            if(stuTemp->item.getLength() == 0)
            {
                Student::studentBookNode* temp = new Student::studentBookNode();
                temp->item = bookTemp->item;
                temp->next = NULL;
                stuTemp->item.stuhead = temp;
                stuTemp->item.studentBooks++;
                cout<<"Book: "<<bookId<<" Has been checked out by student: "<<studentId<<endl;
                bookTemp->item.setStatus(false);
                return;
            }
            else
            {

            Student::studentBookNode* prev = stuTemp->item.findPointer(stuTemp->item.getLength());
            Student::studentBookNode* temp = new Student::studentBookNode();
            temp->item = bookTemp->item;
            temp->next = NULL;
            prev->next = temp;
            stuTemp->item.studentBooks++;
            cout<<"Book: "<<bookId<<" Has been checked out by student: "<<studentId<<endl;
            bookTemp->item.setStatus(false);

            }

        }
        else
        {
            cout<<"Student: "<<studentId<<" does not exist for checkout"<<endl;
        }

}
void LibrarySystem::returnBook(const int bookId)
{
    bool bookExist = false;
    int bookIndex;
    int stuIndex;
    allBooksNode* curBook = bookHead;
    int counter = 1;
    for(int i = 1; i <= getLengthBooks();i++)
    {
        if(curBook->item.getBookId() == bookId)
        {
            if(curBook->item.getStatus() == false)
            {
                bookIndex = i;
                bookExist = true;
            }
        }
        curBook = curBook->next;
    }
    if(bookExist)
    {
        Student::studentBookNode* prev;
        curBook = findBookPointer(bookIndex);
        Student::studentBookNode* curSTN;

        for(Node* cur = head; cur != NULL;cur = cur->next)
        {

            for(Student::studentBookNode* temp = cur->item.stuhead; temp!= NULL;temp = temp->next)
            {

                 if(temp->item.getBookId() == bookId)
                {
                    if(cur->item.findIndex(bookId) == 1)
                    {
                        curSTN = cur->item.stuhead;
                        cur->item.stuhead = cur->item.stuhead->next;
                        cur->item.studentBooks--;
                        curSTN->next = NULL;
                        delete curSTN;
                        curSTN = NULL;
                         curBook->item.setStatus(true);
                    cout<<"Book: "<<bookId<<" Has been returned"<<endl;


                    }

                    else
                    {

                        prev = cur->item.findPointer(counter - 1);

                        curSTN = prev->next;

                        prev->next = curSTN->next;

                        cur->item.studentBooks--;

                         curSTN->next = NULL;

                        delete curSTN;
                        curSTN = NULL;
                         curBook->item.setStatus(true);
                    cout<<"Book: "<<bookId<<" Has been returned"<<endl;

                    }
                }
        counter++;

            }
            counter = 1;
        }
    }
    else
    {
        cout<<"Book "<<bookId<<" has not been checked out"<<endl;
    }



}
void LibrarySystem::showBook(const int bookId) const
{
    bool exist = false;
    int bookIndex;
    int studentIndex;
    Node* stu;
    allBooksNode* tmp;
    for(allBooksNode* cur = bookHead; cur!= NULL; cur = cur->next)
    {
        if(cur->item.getBookId() == bookId)
        {
        tmp = cur;
            exist = true;
        }
    }
    if(exist)
    {
        if(tmp->item.getStatus() == false)
        {
            for(Node* temp = head; temp!= NULL;temp = temp->next)
            {
                for(Student::studentBookNode* stuBook = temp->item.stuhead; stuBook!= NULL;stuBook = stuBook->next)
                {
                    if(stuBook->item.getBookId() == bookId)
                    {
                        stu = temp;
                    }
                }
            }
            cout<<"Book Id     Book name     Year     Status"<<endl;
            cout<<tmp->item.getBookId()<<"   "<<tmp->item.getBookName()<<"    "<<tmp->item.getBookYear()<<"    "<<"Checked out by student "<<stu->item.getName()<<endl;
        }
        else
        {
            cout<<"Book Id     Book name     Year     Status"<<endl;
            cout<<tmp->item.getBookId()<<"   "<<tmp->item.getBookName()<<"    "<<tmp->item.getBookYear()<<"    "<<"Not checked Out"<<endl;
        }


    }
    else
    {
        cout<<"Book does not exist"<<endl;
    }
}

void LibrarySystem::showAllBooks() const
{
    for(allBooksNode* cur = bookHead; cur!= NULL;cur = cur->next)
    {
        showBook(cur->item.getBookId());
    }
}
void LibrarySystem::showStudent(const int studentId) const
{
    bool exist = false;
    Node* stuPtr;
    for(Node* cur = head; cur != NULL; cur = cur->next)
    {

        if(cur->item.getId() == studentId)
        {
            exist = true;
            stuPtr = cur;
        }
    }
    if(exist)
    {
        if(stuPtr->item.getLength() == 0)
        {
            cout<<"Student id:"<<stuPtr->item.getId()<<" Student name "<<stuPtr->item.getName()<<endl;
            cout<<"Student "<<stuPtr->item.getId()<<" has no books"<<endl;
        }
        else
        {

            cout<<"Student id:"<<stuPtr->item.getId()<<" Student name "<<stuPtr->item.getName()<<endl;
            cout<<"Student "<<stuPtr->item.getId()<<" has checked out following books"<<endl;
            cout<<"Book id     Book name          Year"<<endl;
            for(Student::studentBookNode* stubookptr = stuPtr->item.stuhead;stubookptr != NULL;stubookptr = stubookptr->next )
            {
                cout<<stubookptr->item.getBookId()<<"    "<<stubookptr->item.getBookName()<<"     "<<stubookptr->item.getBookYear()<<endl;
            }

        }
    }
    else
    {
        cout<< "Student "<<studentId<<" does not exists"<<endl;
    }

}
void LibrarySystem::deleteBook(const int bookId)
{
    bool exist = false;
    int index;
    int counter = 1;
    allBooksNode* prev;
    allBooksNode* curr;
    for(allBooksNode*cur = bookHead; cur!= NULL; cur = cur->next)
    {

        if(cur->item.getBookId() == bookId)
        {
            exist = true;
            index = counter;
        }
        counter++;
    }
    if(exist)
    {
        bookSize--;
        if(index == 1)
        {
            returnBook(bookId);
            curr = bookHead;
            bookHead = bookHead->next;
            cout<<"Book "<<bookId<<" has been deleted"<<endl;
        }
        else
        {
            returnBook(bookId);
            prev = findBookPointer(index - 1);
            curr = prev->next;
            prev->next = curr->next;
            cout<<"Book "<<bookId<<" has been deleted"<<endl;

        }
        curr->next = NULL;
        delete curr;
        curr = NULL;


    }
    else
    {
        cout<<"Book "<<bookId<< " does not exists"<<endl;
    }
}
void LibrarySystem::deleteStudent(const int studentId)
{
    bool exist = false;
    int index;
    int counter = 1;

    for(Node* cur = head; cur != NULL; cur = cur->next)
    {
        if(cur->item.getId() == studentId)
        {
            exist = true;
            index = counter;
        }
        counter++;
    }
    if(exist)
    {
        Node* cur;
        Node* prev;

        Size--;
        Node* curr = findPointer(index);
        Student::studentBookNode* st = curr->item.stuhead;
         while(st!=NULL)
            {
                Student::studentBookNode* tm = st->next;
                returnBook(st->item.getBookId());
                st = tm;
            }

        if(index == 1)
        {

           cur = head;
           head = head->next;
           cout<<"Student "<<studentId<<" has been deleted"<<endl;

        }
        else
        {

            prev = findPointer(index - 1);
            cur = prev->next;
            prev->next = cur->next;
            cout<<"Student "<<studentId<<" has been deleted"<<endl;
        }
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }

    else
    {
        cout<<"Student "<<studentId<<" does not exists"<<endl;
    }
}



