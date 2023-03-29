#ifndef CLASS_BOOK_HPP
#define CLASS_BOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#define Bdat AllBook.dat
#define READ read((char *)this, sizeof(*this))
#define WRITE write((char *)this, sizeof(*this))
using namespace std;

class Book
{

private:
    int Book_id;
    char Book_Name[50];
    char Author_Name[50];
    float Book_price;
    int Number_of_Books_Available;
    int Member_Code[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int ans = 0;
    int temp;

public:
    Book();
    void Newbook();
    int BookIdAvailable(int);
    void storeBook();
    void bookData();
    void BookList();
    void Edit_Book(int);
    int getMemberCode(int, int);
    int returnedBook(int, int);
    void EnqureBook();
    void memberIssuedList(int);
}B;

#endif