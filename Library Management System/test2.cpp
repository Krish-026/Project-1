#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Data
{
private:
    string name;

public:
    Data();
    Data(const Data &temp);
    void input();
    void output();
};

Data::Data()
{
    name = "";
}

Data::Data(const Data &temp)
{
    name = temp.name;
}

void Data::input()
{
    cout << "Enter Name : ";
    cin >> name;
}

void Data::output()
{
    cout << name << endl;
}

int main()
{
    fstream op, cl;
    op.open("data.dat", ios::out | ios::app);
    cl.open("data.dat", ios::in);
    Data ob, ob2;
    ob.input();
    op.write((char *)&ob, sizeof(Data));
    op.close();

    cout << "Reading" << endl;
}

fstream file;

void searchDetailsb()
{
    system("cls");
    cout << "******** Search ********" << endl;
    file.open("book.dat", ios::in);

    string title;
    int flag = 0;

    cout << "Enter book title to remove : ";
    cin >> title;

    file.seekg(0, ios::beg);

    while (file.read((char *)&bk, sizeof(Book)))
    {
        if (title == bk.book.title)
        {
            bk.showDetails();
            flag = 1;
            break;
        }
    }

    file.close();

    if (flag == 1)
        cout << "Record Found" << endl;
    else
        cout << "Record not found" << endl;

    cin.get();
    return;
}

// void writeBook()
// {
//     char ch;
//     file.open("book.dat", ios::out | ios::app);
//     do
//     {
//         system("cls");
//         cout << "******** Enter Details **********" << endl;
//         bk.inputDetails();
//         file.write((char *)&bk, sizeof(Book));
//         cout << "\n\nDo you want to add more record...(y/n?) ";
//         cin >> ch;
//     } while (ch == 'y' || ch == 'Y');
//     file.close();
//     cin.get();
// }

// void displayallb()
// {
//     system("cls");
//     file.open("book.dat", ios::in); // read mode
//     if (!file)
//     {
//         cout << "File Could Not Be Open\n";
//         cin.get();
//         return;
//     }
//     while (file.read((char *)&bk, sizeof(Book)))
//     {
//         bk.showDetails();
//     }
//     file.close();
//     file.open("book.dat", ios::in | ios::trunc);
//     file.close();
//     cin.get();
// }

// void modifyDetailsb()
// {
//     file.open("book.dat", ios::out | ios::in);
//     system("cls");
//     cout << "******** Enter New Details **********" << endl;
//     if (!file)
//     {
//         cout << "Unable to open file" << endl;
//         return;
//     }

//     file.seekg(0, ios::beg);

//     string title;
//     cout << "Enter book title to modify : ";
//     cin >> title;
//     int flag = 1;
//     while (file.read((char *)&bk, sizeof(Book)))
//     {
//         if (title == bk.book.title)
//         {
//             flag = 0;
//             int position = (-1) * sizeof(Book);
//             bk.modifyDetails();
//             file.seekp(position, ios::cur); // back from current position
//             file.write((char *)&bk, sizeof(Book));
//             cout << "Record updated" << endl;
//             break;
//         }
//     }
//     if (flag)
//         cout << "Book not found!" << endl;
//     file.close();
//     cin.get();
//     cin.get();
//     return;
// }

// void deleteDetailsb()
// {
//     system("cls");
//     cout << "******** Delete Entry ********" << endl;
//     file.open("book.dat", ios::in | ios::out);
//     temp.open("temp.dat", ios::out);

//     string title;
//     int flag = 0;

//     cout << "Enter book title to remove : ";
//     cin >> title;

//     file.seekg(0, ios::beg);

//     while (file.read((char *)&bk, sizeof(Book)))
//     {
//         if (title == bk.book.title)
//         {
//             flag++;
//             continue;
//         }
//         temp.write((char *)&bk, sizeof(Book));
//     }

//     file.close();
//     temp.close();
//     remove("book.dat");
//     rename("temp.dat", "book.dat");

//     if (flag == 1)
//         cout << "Record Deleted" << endl;
//     else
//         cout << "Record not found" << endl;

//     cin.get();
// }


