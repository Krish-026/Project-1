#include "..\Header File\class_book.hpp"

Book::Book()
{
    Book_id = 0;
    Book_price = 0;
}

void Book::Newbook()
{
    system("cls");
    ans = 0;
    int tempBid;
    do
    {
        system("cls");
        cout.width(30);
        cout << left << "\n\tEnter Book id : ";
        cin >> tempBid;
        Book_id = tempBid;
        if (tempBid == 1001) // To move to main menu
            break;
        if (BookIdAvailable(tempBid) == 1)
        {
            tempBid = -1;
            cout << "\n\tBook Id Taken";
            cout << "\n\tUse another Id";
            cout << "\n\tEXIT : Press 1001 " << endl;
        }
    } while (tempBid == -1);
    if (Book_id == 1001)
        return;
    Book_id = tempBid;
    cout.width(30);
    cout << left << "\n\tEnter Book Name : ";
    cin.ignore();
    cin.getline(Book_Name, 50);
    cout.width(30);
    cout << left << "\n\tEnter Author Name : ";
    cin.ignore(0, '\n');
    cin.getline(Author_Name, 50);
    cout.width(30);
    cout << left << "\n\tEnter Book Price : ";
    cin >> Book_price;
    cout.width(30);
    cout << left << "\n\tEnter Books Available : ";
    cin >> Number_of_Books_Available;
    storeBook();
}

void Book::bookData() // to show all the data about the book
{
    cout.width(30);
    cout << left << "\n\tBook id : " << Book_id;
    cout.width(30);
    cout << left << "\n\tBook name : " << Book_Name;
    cout.width(30);
    cout << left << "\n\tAuthor Name : " << Author_Name;
    cout.width(30);
    cout << left << "\n\tBook price : " << Book_price;
    cout.width(30);
    cout << left << "\n\tBooks Available : " << Number_of_Books_Available << endl;
}

void Book::BookList()
{
    system("CLS");
    ifstream file;
    file.open("Bdat", ios::in | ios::binary);
    if (!file)
    {
        cout.width(25);
        cout << left << "\n\tNo Book are stored";
        cout.width(25);
        cout << left << "\n\n\tPress Any Key to go to main Menu.";
        getch();
    }
    else
    {
        file.READ; // Reading data from the file
        while (!file.eof())
        {
            bookData(); // displaying data
            file.READ;
        }
        file.close();
        cout.width(25);
        cout << left << "\n\n\tPress Any Key to go to main Menu.";
        getch();
    }
}

void Book::storeBook()
{
    if (Book_id == 0 and Book_price == 0)
    {
        cout.width(25);
        cout << left << "\n\tBook has no data";
        cout.width(25);
        cout << left << "\n\n\tPress Any key to go to main menu." << endl;
    }
    else
    {
        ofstream file;
        file.open("Bdat", ios::app | ios::binary | ios::out);
        file.write((char *)this, sizeof(*this));
        file.close();
        cout.width(25);
        cout << left << "\n\tBook Added Successfully";
        cout.width(25);
        cout << left << "\n\n\tPress Any key to go to main menu.";
        getch();
    }
}

void Book::Edit_Book(int tempBid) // Editing the book data
{
    fstream file;
    int flag = 0;
    file.open("Bdat", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.read((char *)this, sizeof(*this));
    while (!file.eof())
    {
        if (tempBid == Book_id)
        {
            bookData();
            cout.width(30);
            cout << left << "\n\tEnter Book name : ";
            cin.ignore();
            cin.getline(Book_Name, 50);
            cout.width(30);
            cout << left << "\n\tEnter Author Name : ";
            cin.ignore(0, '\n');
            cin.getline(Author_Name, 50);
            cout.width(30);
            cout << left << "\n\tEnter Book price : ";
            cin >> Book_price;
            cout.width(30);
            cout << left << "\n\tEnter Books Available : ";
            cin >> Number_of_Books_Available;
            file.seekp(file.tellp() - sizeof(*this)); // going to the front of the object to update
            file.write((char *)this, sizeof(*this));
            flag = 1;
            cout.width(30);
            cout << left << "\n\tEdit Successful.";
            break;
        }
        else
        {
            flag = 0;
        }
        file.read((char *)this, sizeof(*this));
    }
    file.close();
    if (flag == 0)
    {
        cout.width(30);
        cout << left << "\n\tNo such book is stored";
        cout.width(25);
        cout << left << "\n\n\tPress Any Key to go to main Menu.";
        getch();
    }
}

int Book::BookIdAvailable(int tempBid)
{
    int flag = 0;
    ifstream file;
    file.open("Bdat", ios::in | ios::binary);

    if (!file)
    {
        cout << "\n\tFile doesn't exit" << endl;
        return 0;
    }
    else
    {
        file.read((char *)this, sizeof(*this));
        while (!file.eof())
        {
            if (tempBid == Book_id)
            {
                cout << "BoodIdAvailable Called" << endl;
                flag = 1;
                break;
            }
            else{
                cout << "Check" << endl;
            }
            file.read((char *)this, sizeof(*this));
        }
        file.close();
    }
    if (flag == 1)
        return 1; // Book id is available
    else
        return 0; // Book id is not available
}

int Book::getMemberCode(int temp, int B_id)
{ // Member code who issued Book
    system("cls");
    fstream file;
    int flag = 0;
    file.open("Bdat", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.READ; // Read file
    while (!file.eof())
    {
        if (B_id == Book_id)
        {
            if (Number_of_Books_Available > 0) // If Book is in Library
            {
                for (int i = 0; i < 10; ++i)
                { // See if any member is eligible in Library
                    if (Member_Code[i] == 0)
                    {
                        --Number_of_Books_Available;
                        Member_Code[i] = temp;
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    cout.width(30);
                    cout << left << "\n\tThis Book is not available";
                    cout.width(25);
                    cout << left << "\n\n\tPress Any Key to go to main Menu.";
                    getch();
                    break;
                }
                file.seekp(file.tellp() - sizeof(*this));
                file.WRITE;
                flag = 1;
            }
            else // Book not Available in Library
            {
                cout.width(30);
                cout << left << "\n\tNo Book Are available to be issued";
                cout.width(25);
                cout << left << "\n\n\tPress Any Key to go to main Menu.";
                getch();
                break;
            }
        }
        file.READ;
    }
    file.close();
    if (flag == 0)
    {
        cout.width(30);
        cout << left << "\n\tNo such book is stored";
        cout.width(25);
        cout << left << "\n\n\tPress Any Key to go to main Menu.";
        return 0;
        getch();
    }
    else if (flag == 1) // Book Available
    {
        return 1;
    }
}

void Book::returnedBook(int tempMCode, int tempBid)
{
    system("cls");
    fstream file;
    int flag = 0, i;
    file.open("Bdat", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.READ;
    while (!file.eof())
    {
        if (tempBid == Book_id)
        {
            for (int i = 0; i < 10; ++i)
            {
                if (Member_Code[i] == tempMCode)
                {
                    Member_Code[i] = 0;
                    ++Number_of_Books_Available;
                }
            }
        }
        file.seekp(file.tellp() - sizeof(*this));
        flag = 1;
        break;
    }
    file.close();
    if (flag == 0)
    {
        cout.width(30);
        cout << left << "\n\tNo such book is stored";
        cout.width(25);
        cout << left << "\n\n\tPress Any Key to go to main Menu.";
        getch();
    }
    else
    {
        cout.width(30);
        cout << left << "\n\tBook Returned Successfully!!!!!";
        cout.width(25);
        cout << left << "\n\n\tPress Any Key to go to main Menu.";
    }
}

void Book::EnqureBook()
{
    system("cls");
    int tempBid;
    cout.width(25);
    cout << left << "\n\tEnter Book Id you to want to enquire : ";
    cin >> tempBid;
    if (BookIdAvailable(tempBid) == 1)
    {
        ifstream file;
        file.open("Bdat", ios::in | ios::binary);
        if (!file)
        {
            cout.width(25);
            cout << left << "\n\tNo Book are stored.";
            cout.width(25);
            cout << left << "\n\n\tPress Any Key to go to main Menu.";
            getch();
        }
        else
        {
            file.READ;
            while (!file.eof())
            {
                if (Book_id == tempBid)
                {
                    bookData();
                    memberIssuedList(tempBid);
                    break;
                }
                file.READ;
            }
            file.close();
            cout.width(25);
            cout << left << "\n\n\tPress Any key to go to main Menu.";
            getch();
        }
    }
}

void Book::memberIssuedList(int tempBid)
{
    ifstream file;
    file.open("Bdat", ios::in | ios::binary);
    if (!file)
    {
        cout.width(25);
        cout << left << "\n\tNo Book are stored";
        cout.width(25);
        cout << left << "\n\n\tPress Any Key to go to main Menu.";
        getch();
    }
    else
    {
        file.READ;
        while (!file.eof())
        {
            if (Book_id == tempBid)
            {
                for (int i = 0; i < 10; ++i)
                {
                    if (Member_Code[i] != 0)
                    {
                        cout << "\n\tBook issued by the Member id : " << Member_Code[i];
                    }
                }
                break;
            }
            file.READ;
        }
        file.close();
    }
}
