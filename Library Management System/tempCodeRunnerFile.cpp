void searchDetailsb()
// {
//     system("cls");
//     cout << "******** Search ********" << endl;
//     file.open("book.dat", ios::binary | ios::in);

//     string title;
//     int flag = 0;

//     cout << "Enter book title to remove : ";
//     cin >> title;

//     while (file.read((char *)&bk, sizeof(Book)))
//     {
//         if (title == bk.book.title)
//         {
//             bk.showDetails();
//             flag = 1;
//             break;
//         }
//     }

//     file.close();

//     if (flag == 1)
//         cout << "Record Found" << endl;
//     else
//         cout << "Record not found" << endl;

//     cin.get();
//     return;
// }