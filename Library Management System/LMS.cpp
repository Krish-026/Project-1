#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void writeBook();
void displayallb();
void modifyDetailsb();
void deleteDetailsb();
void searchDetailsb();

fstream file, temp;

class Date
{
private:
    int dd, mm, yy;
    void rectifyDate();

public:
    // Constructor
    Date();
    Date(const Date &temp);
    void setDate();
    void setDate(Date temp);
    void showDate();
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

class BookData
{
public:
    string title, author, publisher;
    int status, issuedRollNo;
    float price;
    Date issuedDate;
    Date returnDate;
    BookData()
    {
        status = 0;
        issuedRollNo = -1;
    }
};

class Book
{
public:
    BookData book;
    void inputDetails();
    void showDetails();
    void modifyDetails();
    void searchDetails();
    void deleteDetails();
    void viewAllBookDetail();
} bk;

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

class Student
{
public:
    void inputDetails();
    void modifyDetails();
    void searchDetails();
    void deleteDetails();
    void viewAllStudentDetail();
};

int main()
{
    Menu menu;
    int ch1;
    do
    {
        system("cls");
        menu.mainMenu();
        cout << "\nPlease enter you choice : ";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
        {
            int ch2;
            do
            {
                system("cls");
                menu.studentMenu();
                cout << "\nPlease enter your choice : ";
                cin >> ch2;
                switch (ch2)
                {
                case 1:
                {
                    cout << "New Entry" << endl;
                    system("pause");
                    break;
                }
                case 2:
                {
                    cout << "Modify Entry" << endl;
                    system("pause");
                    break;
                }
                case 3:
                {
                    cout << "Search Entry" << endl;
                    system("pause");
                    break;
                }
                case 4:
                {
                    cout << "Delete Entry" << endl;
                    system("pause");
                    break;
                }
                case 5:
                {
                    cout << "View all student detail " << endl;
                    system("pause");
                    break;
                }
                case 6:
                {
                    cout << "######## Exit Successfull #######" << endl;
                    system("pause");
                    break;
                }
                
                default:
                {
                    cout << "####### Wrong Choice #######" << endl;
                    system("pause");
                    break;
                }
                }
            } while (ch2 != 6);
            break;
        }

        case 2:
        {
            int ch2;
            do
            {
                system("cls");
                menu.bookMenu();
                cout << "\nPlease enter your choice : ";
                cin >> ch2;
                switch (ch2)
                {
                case 1:
                {
                    cout << "******** New Entry ********" << endl;
                    writeBook();
                    system("pause");
                    break;
                }
                case 2:
                {
                    modifyDetailsb();
                    system("pause");
                    break;
                }
                case 3:
                {
                    cout << "Search Data" << endl;
                    searchDetailsb();
                    system("pause");
                    break;
                }
                case 4:
                {
                    deleteDetailsb();
                    system("pause");
                    break;
                }
                case 5:
                {
                    displayallb();
                    system("pause");
                    break;
                }
                case 6:
                {
                    cout << "######## Exit Successfull #######" << endl;
                    system("pause");
                    break;
                }
                case 7:
                {
                    file.open("book.dat", ios::in | ios::trunc);
                    file.close();
                    break;
                }
                default:
                {
                    cout << "####### Wrong Choice #######" << endl;
                    system("pause");
                    break;
                }
                }
            } while (ch2 != 6);
            break;
        }
        case 3:
        {
            cout << "IssueBook()" << endl;
            system("pause");
            // menu.issueBook();
            break;
        }
        case 4:
        {
            cout << "Return Book()" << endl;
            system("pause");
            // menu.returnBook();
            break;
        }

        case 5:
        {
            cout << "######## Exit Successfull #######" << endl;
            system("pause");
            break;
        }

        default:
        {
            cout << "####### Wrong Choice #######" << endl;
            system("pause");
            break;
        }
        }
    } while (ch1 != 5);

    return 0;
}

void Date::rectifyDate()
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
Date::Date()
{
    dd = 1, mm = 1, yy = 2023;
}

Date::Date(const Date &temp)
{
    dd = temp.dd;
    mm = temp.mm;
    yy = temp.yy;
}

void Date::setDate()
{
    cout << "Enter Date : ";
    cin >> dd;
    cout << "Enter Month : ";
    cin >> mm;
    cout << "Enter Year : ";
    cin >> yy;
}

void Date::setDate(Date temp)
{
    dd = temp.dd + 15;
    mm = temp.mm;
    yy = temp.yy;
    rectifyDate();
}

void Date::showDate()
{
    cout << dd << "/" << mm << "/" << yy;
}

void Menu::mainMenu()
{
    cout << "#################### Main Menu ####################" << endl
         << endl;
    cout << "1. Student Menu\n";
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

void Book::inputDetails()
{
    cout << " Enter book title : ";
    cin >> book.title;
    cout << " Enter author's name : ";
    cin >> book.author;
    cout << " Enter book publisher : ";
    cin >> book.publisher;
    cout << " Enter book price : ";
    cin >> book.price;

    cin.get();
    // book.issuedDate.setDate();
}

void Book::showDetails()
{

    cout << "******* Details Called *******" << endl;
    cout << "Book  title : " << book.title << endl;
    cout << "Book  author : " << book.author << endl;
    cout << "Book  publisher : " << book.publisher << endl;
    cout << "Book  price : " << book.price << endl;
    cin.get();
}

void Book::modifyDetails()
{
    cout << "******* Enter New Details *******" << endl;
    cout << "Enter new book title : ";
    cin >> book.title;
    cout << "Enter new author's name : ";
    cin >> book.author;
    cout << "Enter new book publisher : ";
    cin >> book.publisher;
    cout << "Enter new book prize : ";
    cin >> book.price;
    cin.get();
}

void writeBook()
{
    char ch;
    file.open("book.dat", ios::out | ios::app);
    do
    {
        system("cls");
        cout << "******** Enter Details **********" << endl;
        bk.inputDetails();
        file.write((char *)&bk, sizeof(Book));
        cout << "\n\nDo you want to add more record...(y/n?) ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    file.close();
    cin.get();
}

void modifyDetailsb()
{
    file.open("book.dat", ios::out | ios::in);
    system("cls");
    cout << "******** Enter New Details **********" << endl;
    if (!file)
    {
        cout << "Unable to open file" << endl;
        return;
    }

    file.seekg(0, ios::beg);

    string title;
    cout << "Enter book title to modify : ";
    cin >> title;
    int flag = 1;
    while (file.read((char *)&bk, sizeof(Book)))
    {
        if (title == bk.book.title)
        {
            flag = 0;
            int position = (-1) * sizeof(Book);
            bk.modifyDetails();
            file.seekp(position, ios::cur); // back from current position
            file.write((char *)&bk, sizeof(Book));
            cout << "Record updated" << endl;
            break;
        }
    }
    if (flag)
        cout << "Book not found!" << endl;
    file.close();
    cin.get();
    cin.get();
    return;
}

void displayallb()
{
    system("cls");
    file.open("book.dat", ios::in); // read mode
    if (!file)
    {
        cout << "File Could Not Be Open\n";
        system("pause");
        return;
    }

    file.seekg(0, ios::beg); 

    while (file.read((char *)&bk, sizeof(Book)))
    {
        bk.showDetails();
    }
    file.close();
    cin.get();
}

void deleteDetailsb()
{
    system("cls");
    cout << "******** Delete Entry ********" << endl;
    file.open("book.dat", ios::in | ios::out);
    temp.open("temp.dat", ios::out);

    string title;
    int flag = 0;

    cout << "Enter book title to remove : ";
    cin >> title;

    file.seekg(0, ios::beg);

    while (file.read((char *)&bk, sizeof(Book)))
    {
        if (title == bk.book.title)
        {
            flag++;
            continue;
        }
        temp.write((char *)&bk, sizeof(Book));
    }

    file.close();
    temp.close();
    remove("book.dat");
    rename("temp.dat", "book.dat");

    if (flag == 1)
        cout << "Record Deleted" << endl;
    else
        cout << "Record not found" << endl;

    cin.get();
    return;
}






