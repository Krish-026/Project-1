#include "..\Header File\class_member.hpp"

Member::Member()
{
    member_Code = 0;
}

void Member::newMember()
{
    system("cls");
    int tempMc;
    do
    {
        WIDTH(25);
        CL << "\n\tEnter Member Code : ";
        cin >> tempMc;
        member_Code = tempMc;
        if (memberCodeAvailable(tempMc) == 1)
        {
            cout << "\n\tMember code Taken : " << tempMc;
            tempMc = -1;
            cout << "\n\tUse another code" << endl;
        }

    } while (tempMc == -1);
    member_Code = tempMc;
    WIDTH(25);
    CL << "\n\tEnter Member Name : ";
    cin.ignore();
    cin.getline(member_Name, 50);
    WIDTH(25);
    CL << "\n\tEnter Member Phone : ";
    cin.ignore(0, '\n');
    cin.getline(member_Phone, 11);
    WIDTH(25);
    CL << "\n\tEnter Member Address : ";
    cin.ignore(0, '\n');
    cin.getline(member_Address, 50);
    storeMember();
}

void Member::memberData()
{
    cout << "\n\n\t\t********** Member Details **********\n";
    WIDTH(25);
    CL << "\n\tMember code    : " << member_Code;
    WIDTH(25);
    CL << "\n\tMember Name    : " << member_Name;
    WIDTH(25);
    cout << left << "\n\tMember Phone   : " << member_Phone;
    WIDTH(25);
    CL << "\n\tMember Address : " << member_Address;
    cout << "\n\n";
}

void Member::memberList()
{
    system("cls");
    ifstream file;
    file.open("Mdat", ios::in | ios::binary);
    file.seekg(0);
    if (!file)
    {
        WIDTH(25);
        CL << "\n\tNo Member are Stored";
        WIDTH(25);
        PRESS;
        getch();
    }
    else
    {
        file.READ;
        while (!file.eof())
        {
            memberData();
            file.READ;
        }
        file.close();
        WIDTH(25);
        PRESS;
        getch();
    }
}

void Member::storeMember()
{
    system("cls");
    if (member_Code == 0)
    {
        WIDTH(25);
        CL << "\n\tBook has no data";
        WIDTH(25);
        PRESS;
        getch();
    }
    else
    {
        ofstream file;
        file.open("Mdat", ios::app | ios::binary);
        file.WRITE;
        file.close();
        WIDTH(25);
        CL << "\n\tMember Added Successfully.";
        WIDTH(25);
        PRESS;
        getch();
    }
}

void Member::edit_Member(int temp)
{
    fstream file;
    int flag = 0;
    file.open("Mdat", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.READ;
    while (!file.eof())
    {
        if (temp == member_Code)
        {
            memberData();
            WIDTH(25);
            CL << "\n\tEnter Member Name : ";
            cin.ignore();
            cin.getline(member_Name, 50);
            WIDTH(25);
            CL << "\n\tEnter Member Phone : ";
            cin.ignore(0, '\n');
            cin.getline(0, 11);
            WIDTH(25);
            CL << "\n\tEnter Member Address : ";
            cin.ignore(0, '\n');
            cin.getline(0, 50);
            file.seekp(file.tellp() - sizeof(*this));
            file.WRITE;
            flag = 1;
            WIDTH(25);
            PRESS;
            getch();
            break;
        }
        file.READ;
    }
    file.close();
    if (flag == 0)
    {
        WIDTH(25);
        CL << "\n\t No such Member Exist!!!!";
        PRESS;
        getch();
    }
}

void Member::issueDate()
{
    date.setDate();
}

void Member::issue(int temp, int bookId)
{
    int flag = 0, ans1 = 0;
    fstream file;
    file.open("Mdat", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.READ;
    while (!file.eof())
    {
        if (member_Code == temp)
        {
            bool ch = true;
            int count = 0;
            for (int i = 0; i < 5; ++i)
            {
                if (book_Code[i] == 0)
                { // Member can issue only 5 books
                    ++count;
                    ans1 = getMemberCode(member_Code, bookId); // Cheack if Book is Available or not
                    if (ans1 == 1)
                    {
                        ch = false;
                        flag = 1;
                        book_Code[i] = bookId;
                        issueDate();
                        break;
                    }
                }
            }
            if (count == 5 or ch) // Not Eligible // Some issue
            {
                WIDTH(25);
                CL << "\n\tYou already have issued 5 books.";
                PRESS;
                getch();
                flag = 0;
                break;
            }
            file.seekp(file.tellp() - sizeof(*this));
            file.WRITE;
        }
        file.READ;
    }
    file.close();
    if (flag == 1)
    {
        WIDTH(25);
        CL << "\n\tBook Issued!!!!!";
        WIDTH(25);
        PRESS;
        getch();
    }
    else
    {
        WIDTH(25);
        CL << "\n\tBook not Issued";
        WIDTH(25);
        PRESS;
        getch();
    }
}

int Member::memberCodeAvailable(int temp)
{
    int flag = 0;
    ifstream file;
    file.open("Mdat", ios::in | ios::binary);
    if (!file)
    {
        // File had not data
        return 0;
    }
    file.READ;
    while (!file.eof())
    {
        if (temp == member_Code)
        {
            flag = 1;
            break;
        }
        file.READ;
    }
    file.close();
    return flag;
}

void Member::returnBook(int temp, int bookId)
{
    system("cls");
    int flag = 0, ans1;
    fstream file;
    file.open("Mdat", ios::in | ios::out | ios::binary);
    file.seekg(0);
    file.READ;
    while (!file.eof())
    {
        if (member_Code == temp)
        {
            bool ch = true;
            for (int i = 0; i < 5; ++i)
            {
                if (book_Code[i] == bookId)
                {
                    ch = false;
                    ans1 = returnedBook(member_Code, bookId);
                    book_Code[i] = 0;
                    flag = 1;
                }
            }
            if (ch) // Member didn't issued a book
            {
                WIDTH(25);
                CL << "\n\tThis member isn't issued a book" << endl;
            }
            else // Member issued a book. Update it
            {
                file.seekp(file.tellp() - sizeof((*this)));
                file.WRITE;
            }
            break;
        }
        file.READ;
    }
    file.close();
    if (flag == 0)
    {
        WIDTH(25);
        CL << "\n\tNo Book is Returned";
        WIDTH(25);
        PRESS;
        getch();
    }
    else
    {
        WIDTH(25);
        CL << "\n\tBook is Returned !!!!!";
        WIDTH(25);
        PRESS;
        getch();
    }
}

void Member::showDate()
{
    date.displayDate();
}

void Member::bookIssuedList(int tempMcode)
{
    ifstream file;
    int i;
    file.open("Mdat", ios::in | ios::binary);
    if (!file)
    {
        WIDTH(25);
        CL << "\n\tNo Member data is stored";
        WIDTH(25);
        PRESS;
        getch();
        return;
    }

    file.READ;
    while (!file.eof())
    {
        if (tempMcode == member_Code)
        {
            bool ch = true;
            for (int i = 0; i < 5; ++i)
            {
                if (book_Code[i] != 0)
                {
                    ch = false;
                    WIDTH(25);
                    CL << "\n\tBook Issued " << book_Code[i] << " on ";
                    showDate();
                    getch();
                }
            }
            if (ch) // No Book Issued"
            {
                WIDTH(25);
                CL << "\n\tNo Book is Issued" << endl;
            }
            break;
        }
        file.READ;
    }
    file.close();
}

void Member::enquireMember()
{
    system("cls");
    int tempMcode;
    WIDTH(25);
    CL << "\n\tEnter Member Code you want to enquire : ";
    cin >> tempMcode;
    if (memberCodeAvailable(tempMcode) == 1)
    {
        ifstream file;
        file.open("Mdat", ios::in | ios::binary);
        if (!file)
        {
            WIDTH(25);
            CL << "\n\tNo Member are stored";
            WIDTH(25);
            PRESS;
            getch();
            return;
        }
        file.READ;
        while (!file.eof())
        {
            if (tempMcode = member_Code)
            {
                memberData();
                bookIssuedList(tempMcode);
                break;
            }
            file.READ;
        }
        file.close();
        WIDTH(25);
        PRESS;
        getch();
    }
}
