#include <iostream>
#include <cstddef>
#include<string>
/*
Saitcan Baskol
21803589
SEC02
*/
using namespace std;

class Book
{
public:
    Book();
    Book(int id,string title,int year);
    ~Book();
    int getBookId();
    string getBookName();
    int getBookYear();
    bool getStatus();
    void setBookId(int id);
    void setBookName(string bookname);
    void setBookYear(int year);
    void setStatus(bool taken);


private:
    int bookId;
    string bookName;
    int bookYear;
    bool status;

};
