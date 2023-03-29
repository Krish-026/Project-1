#include "..\Header File\display.hpp"


void Display(vector<string> &s, int i)
{
    system("cls");
    int sz = s.size();
    string ss = "\t\t\t\t";
    for (int j = 0; j < sz; ++j)
    {
        if (j == 0)
        {
            cout << s[j] << endl;
            continue;
        }
        if (j == i)
        {
            cout << ss << ">" << s[j] << endl;
        }
        else
            cout << ss << s[j] << endl;
    }
}

int Display1() // To use arrow keys in the menu
{
    int input = 0, pointer = 1;
    vector<string> s;
    s.push_back("\n\n\t\t**********   WELCOME TO SIMPLE BOOKS LIBRARY SYSTEM  **********\n\n");
    s.push_back(" 1. Add new Books");
    s.push_back(" 2. Add new Members");
    s.push_back(" 3. Issue Book to a Member");
    s.push_back(" 4. Return Book from a Member");
    s.push_back(" 5. List all Books in the System");
    s.push_back(" 6. List all Members in the System");
    s.push_back(" 7. Edit Book");
    s.push_back(" 8. Edit Member");
    s.push_back(" 9. Enquire Book");
    s.push_back(" 10. Enquire Member");
    s.push_back(" 11. EXIT");
    Display(s, pointer);
    while (true)
    {
        input = getch();
        if (input == 72) // input code for UP Arrow key
        {
            pointer--;
        }
        else if (input == 80) // input code for DOWN Arrow key
        {
            pointer++;
        }
        else if (input == 13) // input code for Enter key
        {
            return pointer;
        }
        else
        {
            continue;
        }

        if (pointer <= 0) // To keep the value of i between 1 and 11
        {
            pointer = 11;
        }
        else if (pointer > 11)
        {
            pointer = 0;
        }
        else;

        if (pointer >= 1 and pointer <= 11)
        {
            Display(s, pointer);
        }
    }
}