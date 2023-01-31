#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Date
{
private:
    int dd, mm, yy;
    void rectifyDate()
    {
        if (dd > 30)
        {
            dd -= 30;
            ++mm;
        }
        if (mm > 12)
        {
            mm -= 12;
            ++yy;
        }
    }

public:
    // Constructor
    Date()
    {
        dd = 1, mm = 1, yy = 2023;
    }

    void setDate()
    {
        cout << "Enter Date : ";
        cin >> dd;
        cout << "Enter Month : ";
        cin >> mm;
        cout << "Enter Year : ";
        cin >> yy;
    }

    void setDate(Date temp)
    {
        dd = temp.dd + 15;
        mm = temp.mm;
        yy = temp.yy;
        rectifyDate();
    }

    void showDate()
    {
        cout << dd << "/" << mm << "/" << yy;
    }
};

class Menu
{
private:
public:
    void mainMenu();
    void studentMenu();
    void bookMenu();
    void issueBook();
    void returnBook();
};

void Menu::mainMenu()
{
    cout << "#################### Main Menu ####################" << endl
         << endl;
    cout << "1. Student Menu";
    cout << "2. Book Menu\n";
    cout << "3. Issue Book\n";
    cout << "4. Return Book\n";
    cout << "5. Exit\n";
}

void Menu::studentMenu()
{
    cout << "#################### Student Menu ####################" << endl
         << endl;
    cout << "1. New Entry\n";
    cout << "2. Modify Entry\n";
    cout << "3. Search Entry\n";
    cout << "4. Delete Entry\n";
    cout << "5. View Student Details\n";
    cout << "6. Go back to previous menu\n";
}

void Menu::bookMenu()
{
    cout << "#################### Book Menu ####################" << endl
         << endl;
    cout << "1. New Entry\n";
    cout << "2. Modify Entry\n";
    cout << "3. Search Entry\n";
    cout << "4. Delete Entry\n";
    cout << "5. View all books detail\n";
    cout << "6. Go back to previous menu\n";
}

class BookData
{
public:
    string title, author, publisher;
    int status, issuedRollNo;
    float price;
    Date issueDate;
    Date returnDate;
    BookData()
    {
        status = 0;
        issuedRollNo = -1;
    }
};

class StudendData
{
public:
    int rollNo;
    string name;
    string address;
    string branch;
    int status;
    string bookTitle;
    StudendData()
    {
        status = 0;
    }
};

class Book
{
public:
    void inputDetails();
    void modifyDetails();
    void searchDetails();
    void deleteDetails();
    void deleteDetails();
    void viewAllBookDetail();
};

void Book::inputDetails()
{
    fstream ofp;
    ofp.open("bookDatabase.dat", ios::out | ios::binary | ios ::app);

    if (!ofp)
    {
        cout << "Unable to open file" << endl;
        return;
    }

    BookData book;
    cout << " Enter book title : ";
    cin >> book.title;
    cout << " Enter author's name : ";
    cin >> book.author;
    cout << " Enter book publisher : ";
    cin >> book.publisher;
    cout << " Enter book price : ";
    cin >> book.price;

    ofp.write((char *)&book, sizeof(BookData));
    ofp.close();
}

void Book::modifyDetails()
{
    fstream file;
    file.open("bookDatabase.dat", ios::binary | ios::out | ios::ate);

    if (!file)
    {
        cout << "Unable to open file" << endl;
        return;
    }

    file.seekg(0, ios::beg);

    BookData book;
    string title;
    cout << "Enter book title to modify : ";
    cin >> title;
    while (file.read((char *)&book, sizeof(BookData)))
    {
        if (title == book.title)
        {
            int position = (-1) * sizeof(BookData);

            cout << "Enter new book title : ";
            cin >> book.title;
            cout << "Enter new author's name : ";
            cin >> book.author;
            cout << "Enter new book publisher : ";
            cin >> book.publisher;
            cout << "Enter new book prize : ";
            cin >> book.price;

            cout << "Record updated";
            cin.get();
            return;
        }
    }
    cout << "Book not found!";
    cin.get();
    return;
}

void Book::searchDetails()
{
    fstream file;
    file.open("bookDatabse.dat", ios::in | ios::binary);

    if (!file)
    {
        cout << "Unable to open file!" << endl;
        cin.get();
        return;
    }

    BookData book;
    string title;
    cout << "Enter book title to search : ";
    cin >> title;
    while (file.read((char *)&book, sizeof(BookData)))
    {
        if (title == book.title)
        {
            cout << "Book  title : " << book.title << endl;
            cout << "Book  author : " << book.author << endl;
            cout << "Book  publisher : " << book.publisher << endl;
            cout << "Book  price : " << book.price << endl;

            // book.issuedDate.
            if (book.status == 1)
            {
                cout << "Issued status : " << book.issuedRollNo << endl;
                cout << "Issued Date : " << book.issueDate.showDate() << endl;
                cout << "Return Date : " << book.returnDate.showDate() << endl;
            }
            else
            {
                cout << "Issued status : None" << endl;
            }
            cin.get();
            return;
        }
    }
    cout << "Book not found" << endl;
    cin.get();
    return;
}

void Book::deleteDetails()
{
    fstream file, temp;
    file.open("bookdatabse.dat", ios::binary | ios::in);
    temp.open("temp.dat", ios::binary | ios::out);

    string title;
    BookData book;
    int flag = 0;

    cout << "Enter book title to remove : ";
    cin >> title;

    while (file.read((char *)&book, sizeof(BookData)))
    {
        if (title == book.title)
        {
            flag++;
            continue;
        }
        temp.write((char *)&book, sizeof(BookData));
    }

    file.close();
    temp.close();
    remove("bookDatabase.dat");
    rename("temp.dat", "bookDatabse.dat");

    if (flag == 1)
        cout << "Record Deleted" << endl;
    else
        cout << "Record not found" << endl;

    cin.get();
    return;
}

void Book::viewAllBookDetail()
{
    fstream file;
    file.open("bookDatabse.dat", ios::in | ios::binary);

    BookData book;
    int choice = 1;
    while (choice and file.read((char *)&book, sizeof(BookData)))
    {
        system("clear");
        cout << "Book  title : " << book.title << endl;
        cout << "Book  author : " << book.author << endl;
        cout << "Book  publisher : " << book.publisher << endl;
        cout << "Book  price : " << book.price << endl;

        // book.issuedDate.
        if (book.status == 1)
        {
            cout << "Issued status : " << book.issuedRollNo << endl;
            cout << "Issued Date : " << book.issueDate.showDate() << endl;
            cout << "Return Date : " << book.returnDate.showDate() << endl;
        }
        else
        {
            cout << "Issued status : None" << endl;
        }
        cout << "Press 0 to exit or Press 1 to view the next";
        cin >> choice;
    }
    cin.get();
    return;
}