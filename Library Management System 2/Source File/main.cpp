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
using namespace std;

int main()
{
    system("color A"); // To change the color of the console
    int n, ans, ans1, ans2, temp, count1, Tbookid;
    do
    {
        system("CLS"); // Clear screen
        n = Display1();
        switch (n)
        {
        case 1 : B.Newbook();
                    break;
        // case 2 : M.Newmember();
        //             break;
        // case 3 : system("CLS");
        //          cout.width(30); cout<< left <<"\n\tEnter Member code :";
        //          cin>>temp;
        //          ans=M.Membercodeavailable(temp);
        //          if(ans==1)
        //          {
        //                 cout.width(30); cout<< left <<"\n\tEnter book id for issue :";
        //                 cin>>Tbookid;
        //                 ans2=B.Bookidavailable(Tbookid);
        //                 if(ans2==1)
        //                 {
        //                     M.issue(temp,Tbookid);
        //                     break;
        //                 }
        //                 else
        //                 {
        //                     cout.width(30); cout<< left <<"\n\tWrong book id";
        //                     cout.width(25); cout<< left <<"\n\n\tPress Any Key to go to main Menu.";
        //                     getch();
        //                     break;
        //                 }
        //          }
        //          else
        //             {
        //             cout.width(30); cout<< left <<"\n\tWrong Member code";
        //             cout.width(25); cout<< left <<"\n\n\tPress Any Key to go to main Menu.";
        //             getch();
        //             }
        //             break;
        // case 4 : system("CLS");
        //          cout.width(30); cout<< left <<"\n\tEnter Member code :";
        //          cin>>temp;
        //          ans=M.Membercodeavailable(temp);
        //          if(ans==1)
        //          {       M.Bookissuedlist(temp);
        //                 cout.width(30); cout<< left <<"\n\tEnter book id you want to return :";
        //                 cin>>ans1;
        //                 ans2=B.Bookidavailable(ans1);
        //                 if(ans2==1)
        //                 {
        //                     M.returnbook(temp,ans1);
        //                     break;
        //                 }
        //                 else
        //                 {
        //                     cout.width(30); cout<< left <<"\n\tWrong book id";
        //                     cout.width(25); cout<< left <<"\n\n\tPress Any Key to go to main Menu.";
        //                     getch();
        //                     break;
        //                 }
        //          }
        //          else
        //             {
        //             cout.width(30); cout<< left <<"\n\tWrong Member code";
        //             cout.width(25); cout<< left <<"\n\n\tPress Any Key to go to main Menu.";
        //             getch();
        //             }
        //          break;
        case 5 : B.BookList();
                    break;
        // case 6 : M.Memberlist();
        //             break;
        // case 7 : system("CLS");
        //          cout.width(25); cout<< left <<"\n\tEnter book id : ";
        //          cin>>ans;
        //          ans1=B.Bookidavailable(ans);
        //          if(ans1==1)
        //          B.Edit_Book(ans);
        //          else {cout.width(30); cout<< left <<"\n\tYou Entered wrong book id ";}
        //          cout.width(25); cout<< left <<"\n\n\tPress Any Key to go to main Menu.";
        //          getch();
        //          break;
        // case 8 : system("CLS");
        //          cout.width(25); cout<< left <<"\n\tEnter Member Code : ";
        //          cin>>ans;
        //          ans1 = M.Membercodeavailable(ans);
        //          if(ans1 == 1)
        //          { M.Edit_Member(ans); }
        //          else {cout.width(30); cout<< left <<"\n\tYou Entered wrong member code ";}
        //          cout.width(25); cout<< left <<"\n\n\tPress Any Key to go to main Menu.";
        //          getch();
        //          break;
        // case 9 : B.EnqureBook();
        //          cout.width(25); cout<< left <<"\n\n\tPress Any Key to go to main Menu.";
        //          getch();
        //          break;
        // case 10 : M.EnqureMember();
        //           cout.width(25); cout<< left <<"\n\n\tPress Any Key to go to main Menu.";
        //           getch();
        //           break;
        case 11:
            system("CLS");
            cout << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl;
            cout << "\n\n\t\t\t\t\t\t  ****EXIT****" << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl;
            break;
        default:
            cout << "\n\n\t\t\t\tInvalid Choice!" << endl;
        }
    } while (n != 11);
    getch();
    return 0;
}

