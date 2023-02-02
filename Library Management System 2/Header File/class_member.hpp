#ifndef CLASS_MEMBER_HPP
#define CLASS_MEMBER_HPP

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include "class_book.hpp"
#include "class_date.hpp"
#define Mdat AllMember.dat
#define READ read((char *)this, sizeof(*this))
#define WRITE write((char *)this, sizeof(*this))
#define WIDTH(a) cout.width(a)
#define CL cout << left
#define PRESS cout << left << "\n\n\tPress Any Key to go to main Menu."
using namespace std;

class Member : public Book
{
    int member_Code;
    char member_Name[50];
    char member_Phone[50];
    char member_Address[50];
    int book_Code[5] = {0, 0, 0, 0, 0};
    int DD[5], MM[5], YY[5];
    int ans;
    Date date;

public:
    Member();
    void newMember();
    int memberCodeAvailable(int);
    void storeMember();
    void memberData();
    void edit_Member(int);
    void memberList();
    void issue(int , int);
    void returnBook(int, int);
    void issueDate();
    void showDate();
    void bookIssuedList(int);
    void enquireMember();
} M;

#endif