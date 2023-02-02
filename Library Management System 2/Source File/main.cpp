#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <stdlib.h>
// #include "display.hpp"
#include "display.cpp"
#include "class_book.cpp"
#include "class_member.cpp"
#include "class_date.cpp"
using namespace std;

int main()
{
    system("color F"); // To change the color of the console
    int n, ans, ans1, ans2, temp, count1, Tbookid;
    do
    {
        system("CLS"); // Clear screen
        n = Display1();
        switch (n)
        {
        case 1:
            B.Newbook();
            break;
        case 2:
            M.newMember();
            break;
        case 3:
            system("cls");
            WIDTH(25);
            CL << "\n\tEnter Member code :";
            cin >> temp;
            ans = M.memberCodeAvailable(temp);
            if (ans == 1)
            {
                WIDTH(30);
                CL << "\n\tEnter book id for issue :";
                cin >> Tbookid;
                ans2 = B.BookIdAvailable(Tbookid);
                if (ans2 == 1)
                {
                    M.issue(temp, Tbookid);
                    break;
                }
                else
                {
                    WIDTH(25);
                    CL << "\n\tWrong book id";
                    WIDTH(25);
                    PRESS;
                    getch();
                    break;
                }
            }
            else
            {
                WIDTH(25);
                CL << "\n\tWrong Member code";
                WIDTH(25);
                PRESS;
                getch();
            }
            break;
        case 4:
            system("cls");
            WIDTH(25);
            CL << "\n\tEnter Member code :";
            cin >> temp;
            ans = M.memberCodeAvailable(temp);
            if (ans == 1)
            {
                // M.bookIssuedList(temp);
                WIDTH(30);
                CL << "\n\tEnter book id you want to return :";
                cin >> ans1;
                ans2 = B.BookIdAvailable(ans1);
                if (ans2 == 1)
                {
                    M.returnBook(temp, ans1);
                    break;
                }
                else
                {
                    WIDTH(30);
                    cout << left << "\n\tWrong book id";
                    PRESS;
                    getch();
                    break;
                }
            }
            else
            {
                cout.width(30);
                cout << left << "\n\tWrong Member code";
                cout.width(25);
                PRESS;
                getch();
            }
            break;
        case 5:
            B.BookList();
            break;
        case 6:
            M.memberList();
            break;
        case 7:
            system("CLS");
            WIDTH(25);
            CL << "\n\tEnter book id : ";
            cin >> ans;
            ans1 = B.BookIdAvailable(ans);
            if (ans1 == 1)
                B.Edit_Book(ans);
            else
            {
                WIDTH(25);
                CL << "\n\tYou Entered wrong book id ";
            }
            WIDTH(25);
            PRESS;
            getch();
            break;
        case 8:
            system("cls");
            WIDTH(25);
            CL << "\n\tEnter Member Code : ";
            cin >> ans;
            ans1 = M.memberCodeAvailable(ans);
            if (ans1 == 1)
            {
                M.edit_Member(ans);
            }
            else
            {
                WIDTH(25);
                CL << "\n\tYou Entered wrong member code ";
            }
            WIDTH(25);
            PRESS;
            getch();
            break;
        case 9:
            B.EnqureBook();
            WIDTH(25);
            PRESS;
            getch();
            break;
        case 10:
            M.enquireMember();
            WIDTH(25);
            PRESS;
            getch();
            break;
        case 11:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ****EXIT****\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            break;
        default:
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tInvalid Choice!\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        }
    } while (n != 11);
    getch();
    return 0;
}
