#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

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
    void inputDetails();
    void modifyDetails();
    void searchDetails();
    void deleteDetails();
    void viewAllBookDetail();
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
    int quit = 0, choice;

    while (!quit)
    {
        // system("clear");
        menu.mainMenu();
        cout << "Please enter your choice : " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            // system("clear");
            menu.studentMenu();
            cout << "Please enter your choice : " << endl;
            cin >> choice;
            Student s1;
            switch (choice)
            {
            case 1:
                s1.inputDetails();
                break;
            case 2:
                s1.modifyDetails();
                break;
            case 3:
                s1.searchDetails();
                break;
            case 4:
                s1.deleteDetails();
                break;
            case 5:
                s1.viewAllStudentDetail();
                break;
            case 6:
                break;
            default:
                cout << "Wrong Input recieved!" << endl;
            }
            break;
        }
        case 2:
        {
            // system("clear");
            menu.bookMenu();
            cout << "Please enter your choice : " << endl;
            cin >> choice;
            Book b1;
            switch (choice)
            {
            case 1:
                b1.inputDetails();
                break;
            case 2:
                b1.modifyDetails();
                break;
            case 3:
                b1.searchDetails();
                break;
            case 4:
                b1.deleteDetails();
                break;
            case 5:
                b1.viewAllBookDetail();
                break;
            case 6:
                break;
            default:
                cout << "Wrong Input recieved!" << endl;
            }
            break;
        }
        case 3:
            menu.issueBook();
            break;
        case 4:
            menu.returnBook();
            break;
        case 5:
            quit++;
            break;
        default:
            cout << "Please Enter correct input!" << endl;
            cin >> choice;
        }
    }

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


void Menu::issueBook()
{
    fstream sp, bp;
    sp.open("studentDatabase.dat", ios::in | ios::out | ios::ate | ios::binary);
    bp.open("bookDatabase.dat", ios::in | ios::out | ios::ate | ios::binary);
    bp.seekg(0, ios::beg);
    sp.seekg(0, ios::beg);

    int rollNo, flagS = 0, flagB = 0, position;
    string title;
    StudendData student;
    BookData book;

    cout << "Enter Student's roll no to issue book : ";
    cin >> rollNo;

    while (sp.read((char *)&student, sizeof(StudendData)))
    {
        if (student.rollNo == rollNo)
        {
            position = (-1) * sizeof(StudendData);
            sp.seekp(position, ios::cur);
            flagS++;
            break;
        }
    }

    if (flagS == 0)
    {
        cout << "Record not found!" << endl;
        cin.get();
        sp.close();
        bp.close();
        return;
    }

    cout << "Enter book title you want to issue : ";
    cin >> title;

    while (bp.read((char *)&title, sizeof(BookData)))
    {
        if (book.title == title)
        {
            position = (-1) * sizeof(BookData);
            bp.seekp(position, ios::cur);
            flagB++;
            break;
        }
    }

    if (flagB == 0)
    {
        cout << "Record not found!" << endl;
        cin.get();
        sp.close();
        bp.close();
    }

    if (student.status != 1 and book.status != 1)
    {
        student.bookTitle = title;
        student.status = 1;
        book.status = 1;
        book.issuedRollNo = student.rollNo;
        book.returnDate.setDate(book.issuedDate);
        sp.write((char *)&student, sizeof(StudendData));
        bp.write((char *)&book, sizeof(BookData));
        sp.close();
        bp.close();
    }
    else
    {
        if (student.status == 1)
        {
            cout << "Student's account is already full!" << endl;
            cin.get();
            sp.close();
            bp.close();
            return;
        }
        else
        {
            cout << "Book is already issued!" << endl;
            cin.get();
            sp.close();
            bp.close();
            return;
        }
    }
}

void Menu::returnBook()
{
    fstream sp, bp;
    sp.open("studentDatabase.dat", ios::in | ios::out | ios::ate | ios::binary);
    bp.open("bookDatabase.dat", ios::in | ios::out | ios::ate | ios::binary);
    bp.seekg(0, ios::beg);
    sp.seekg(0, ios::beg);

    int rollNo, flagS = 0, flagB = 0, position;
    string title;
    StudendData student;
    BookData book;

    cout << "Enter Student's roll no to return book : ";
    cin >> rollNo;

    while (sp.read((char *)&student, sizeof(StudendData)))
    {
        if (student.rollNo == rollNo)
        {
            position = (-1) * sizeof(StudendData);
            sp.seekp(position, ios::cur);
            flagS++;
            break;
        }
    }

    if (flagS == 0)
    {
        cout << "Record not found!" << endl;
        cin.get();
        sp.close();
        bp.close();
        return;
    }

    while (bp.read((char *)&title, sizeof(BookData)))
    {
        if (book.title == title)
        {
            position = (-1) * sizeof(BookData);
            bp.seekp(position, ios::cur);
            flagB++;
            break;
        }
    }

    if (flagB == 0)
    {
        cout << "Record not found!" << endl;
        cin.get();
        sp.close();
        bp.close();
    }

    if (student.status != 1 and book.status != 1)
    {
        student.status = 0;
        book.status = 0;
        book.issuedRollNo = -1;
        book.returnDate.setDate(book.issuedDate);
        sp.write((char *)&student, sizeof(StudendData));
        bp.write((char *)&book, sizeof(BookData));
        sp.close();
        bp.close();
    }
    else
    {
        if (student.status == 0)
        {
            cout << "Student's account is already full!" << endl;
            cin.get();
            sp.close();
            bp.close();
            return;
        }
        else
        {
            cout << "Book is already issued!" << endl;
            cin.get();
            sp.close();
            bp.close();
            return;
        }
    }
}


void Book::inputDetails()
{
    fstream ofp;
    ofp.open("bookDatabase.dat", ios::out | ios ::app);

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

    book.issuedDate.setDate();

    ofp.write((char*)&book, sizeof(BookData));
    ofp.close();

    fstream file;
    file.open("bookDatabase.dat", ios::in);
    int choice = 1;
    while (file.read((char*)&book, sizeof(BookData)))
    {
        // system("clear");
        cout << "ViewAllDetails Called" << endl;
        cout << "Book  title : " << book.title << endl;
        cout << "Book  author : " << book.author << endl;
        cout << "Book  publisher : " << book.publisher << endl;
        cout << "Book  price : " << book.price << endl;

        // book.issuedDate.
        if (book.status == 1)
        {
            cout << "Issued status : " << book.issuedRollNo << endl;
            cout << "Issued Date : ";
            book.issuedDate.showDate();
            cout << "Return Date : ";
            book.returnDate.showDate();
        }
        else
        {
            cout << "Issued status : None" << endl;
        }
        cout << "Press 0 to exit or Press 1 to view the next";
        cin >> choice;
    }
    file.close();
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
    file.open("bookDatabase.dat", ios::in | ios::binary);

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
                cout << "Issued Date : ";
                book.issuedDate.showDate();
                cout << "Return Date : ";
                book.returnDate.showDate();
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
    file.open("bookdatabase.dat", ios::binary | ios::in);
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
    rename("temp.dat", "bookDatabase.dat");

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
    cout << "ViewAllDetails Called" << endl;
    file.open("bookDatabase.dat", ios::in);

    BookData book;
    int choice = 1;
    while (choice and file.read((char *)&book, sizeof(BookData)))
    {
        // system("clear");
        cout << "ViewAllDetails Called" << endl;
        cout << "Book  title : " << book.title << endl;
        cout << "Book  author : " << book.author << endl;
        cout << "Book  publisher : " << book.publisher << endl;
        cout << "Book  price : " << book.price << endl;

        // book.issuedDate.
        if (book.status == 1)
        {
            cout << "Issued status : " << book.issuedRollNo << endl;
            cout << "Issued Date : ";
            book.issuedDate.showDate();
            cout << "Return Date : ";
            book.returnDate.showDate();
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

void Student::inputDetails()
{
    fstream ofp;
    ofp.open("studentDatabase.dat", ios::out | ios::app | ios::binary);

    if (!ofp)
    {
        cout << "Unable to open file" << endl;
        return;
    }

    StudendData student;

    cout << "Enter student's roll no. : ";
    cin >> student.rollNo;

    cout << "Enter student's name : ";
    cin >> student.name;

    cout << "Enter Student's address : ";
    cin >> student.address;

    cout << "Enter Student's branch : ";
    cin >> student.branch;

    cout << "Record added to database!";

    ofp.write((char *)&student, sizeof(StudendData));

    ofp.close();
}

void Student::modifyDetails()
{
    fstream fp;
    fp.open("studentDatabase.dat", ios::binary | ios::in | ios::out | ios::ate);

    if (!fp)
    {
        cout << "Unable to open file!" << endl;
        return;
    }

    fp.seekg(0, ios::beg);

    int roll;
    cout << "Enter student's roll no. to modify : ";
    cin >> roll;

    StudendData student;

    while (fp.read((char *)&student, sizeof(StudendData)))
    {
        if (roll == student.rollNo)
        {
            int position = (-1) * sizeof(StudendData);
            fp.seekp(position, ios::cur);

            cout << "Enter student's new roll no. : ";
            cin >> student.rollNo;
            cout << "Enter student's new name : ";
            cin >> student.name;
            cout << "Enter student's new address : ";
            cin >> student.address;
            cout << "Enter student's new branch : ";
            cin >> student.branch;

            fp.write((char *)&student, sizeof(StudendData));
            fp.close();

            cout << "Record Updated" << endl;
            cin.get();
            return;
        }
    }
    cout << "Roll Not found" << endl;
    cin.get();
    return;
}

void Student::searchDetails()
{
    fstream fp;
    fp.open("studentDatabase.dat", ios::binary | ios::in);

    if (!fp)
    {
        cout << "Unable to open file!" << endl;
        return;
    }

    int roll;
    cout << "Enter student's roll no. to search : ";
    cin >> roll;

    StudendData student;

    while (fp.read((char *)&student, sizeof(StudendData)))
    {
        if (roll == student.rollNo)
        {
            cout << "Record Found!" << endl;
            cout << "Student's name : " << student.name << endl;
            cout << "Student's roll no. " << student.rollNo << endl;
            cout << "Student's Branch : " << student.branch << endl;
            cout << "Student's Address : " << student.address << endl;
            if (student.status == 1)
            {
                cout << "Issued book name is : " << student.bookTitle << endl;
            }
            else
            {
                cout << "No book is issued for this roll no. " << endl;
            }
            cin.get();
            return;
        }
    }
    cout << "Roll Not found" << endl;
    cin.get();
    return;
}

void Student::viewAllStudentDetail()
{
    fstream fp;
    fp.open("studentDatabase.dat", ios::binary | ios::in);

    if (!fp)
    {
        cout << "Unable to open file!" << endl;
        return;
    }

    StudendData student;
    int choice = 1;
    while (choice and fp.read((char *)&student, sizeof(StudendData)))
    {
        // system("clear");
        cout << "Student's name : " << student.name << endl;
        cout << "Student's roll no. " << student.rollNo << endl;
        cout << "Student's Branch : " << student.branch << endl;
        cout << "Student's Address : " << student.address << endl;
        if (student.status == 1)
        {
            cout << "Issued book name is : " << student.bookTitle << endl;
        }
        else
        {
            cout << "No book is issued for this roll no. " << endl;
        }

        cout << "Press 1 to view next student detail or Press 0 to exit : ";
        cin.get();
        cin >> choice;
    }
    cin.get();
    return;
}

void Student::deleteDetails()
{
    fstream file;
    file.open("studentDatabase.dat", ios::in | ios::binary);
    fstream temp;
    file.open("temp.dat", ios::out | ios::binary);

    StudendData student;
    int roll, flag = 0;
    cout << "Enter roll no. to delete data : ";
    cin >> roll;

    while (file.read((char *)&student, sizeof(StudendData)))
    {
        if (student.rollNo == roll)
        {
            flag++;
            continue;
        }
        temp.write((char *)&student, sizeof(StudendData));
    }
    file.close();
    temp.close();

    remove("studenDatabase.dat");
    rename("temp.dat", "studentDatabase.dat");

    if (flag)
        cout << "Record Deleted" << endl;
    else
        cout << "Roll no not found" << endl;

    cin.get();
    return;
}



