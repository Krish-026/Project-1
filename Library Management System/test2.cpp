#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Data{
    private:
    string name;
    public:
    Data();
    Data(const Data &temp);
    void input();
    void output();
};

Data::Data (){
    name = "";
}

Data::Data(const Data &temp){
    name = temp.name;
}

void Data::input(){
    cout << "Enter Name : ";
    cin >> name;
}

void Data::output(){
    cout << name << endl;
}

int main(){
    fstream op, cl;
    op.open("data.dat", ios::out| ios::app);
    cl.open("data.dat", ios::in);
    Data ob, ob2;
    ob.input();
    op.write((char*)&ob, sizeof(Data));
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

