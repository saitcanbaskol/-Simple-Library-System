#include <iostream>
#include <cstddef>
#include<string>
#include "Book.h"
using namespace std;
/*
Saitcan Baskol
21803589
SEC02
*/

Book::Book()
{
    bookId = 0;
    bookName = "Default";
    bookYear = 0;
    status = true;
}
Book::Book(int id,string title,int year)
{
     setBookId(id);
     setBookName(title);
     setBookYear(year);
     status = true;
}
Book::~Book(){}
int Book::getBookId()
{
    return bookId;
}
string Book::getBookName()
{
    return bookName;
}
int Book::getBookYear()
{
    return bookYear;
}
bool Book::getStatus()
{
    return status;
}
void Book::setBookId(int id)
{
    bookId = id;
}
void Book::setBookName(string title)
{
    bookName = title;
}
void Book::setBookYear(int year)
{
    bookYear = year;
}
void Book::setStatus(bool taken)
{
    status = taken;
}
