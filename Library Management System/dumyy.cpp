#include<bits/stdc++.h>
using namespace std;
void Display(vector<string>&s, int i){
    system("cls");
    int sz = s.size();
    for(int j = 0; j < sz; ++j){
        if(j == i){
            cout << ">" << s[j];
        }
        else
            cout << s[j] ;
    }
}

int main(){
    int i = 1;
    vector<string>s;
    s.push_back("\n\n\t\t**********   WELCOME TO SIMPLE BOOKS LIBRARY SYSTEM  **********\n\n");
    s.push_back("\n\t\t\t\t Add new Books");
    s.push_back("\n\t\t\t\t Add new Members");
    s.push_back("\n\t\t\t\t Issue Book to a Member");
    s.push_back("\n\t\t\t\t Return Book from a Member");
    s.push_back("\n\t\t\t\t List all Books in the System");
    s.push_back("\n\t\t\t\t List all Members in the System");
    s.push_back("\n\t\t\t\t Edit Book");
    s.push_back("\n\t\t\t\t Edit Member");
    s.push_back("\n\t\t\t\t Enquire Book");
    s.push_back("\n\t\t\t\t Enquire Member");
    s.push_back("\n\t\t\t\t Quit from this System");
    Display(s, i-1);
    return 0;
}