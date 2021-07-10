#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

void login();
void signup();
void forgot();

int main()
{
    int choice;
    for (int i = 0; i < 50; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << endl;
    for (int j = 0; j < 13; j++)
    {
        cout << "*";
    }
    cout << " Welcome to Login Page ";
    for (int k = 0; k < 14; k++)
    {
        cout << "*";
    }
    cout << "\n1. Login" << endl;
    cout << "2. Sign up" << endl;
    cout << "3. Forgot password" << endl;
    cout << "4. Exit" << endl;
    for (int z = 0; z < 50; z++)
    {
        cout << "*";
    }
    cout << "\nEnter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "Thank you for using Login Page :)" << endl;
        break;
    default:
        cout << "Please select your choice from options 1-4" << endl;
        main();
    }


    return 0;
}

void signup()
{
    string Nuser, Npass;
    system("cls");
    cout << "\nEnter the Username : ";
    cin >> Nuser;
    cout << "\nEnter the Password : ";
    cin >> Npass;

    ofstream reg("database.txt", ios::app);
    reg << Nuser << ' ' << Npass << endl;

    cout << "\nCongrats! You are signed up successfully" << endl;
    cout << "Press any key to continue\n";
    cin.get();
    cin.get();
    system("cls");
    main();

}
void login()
{
    int x = 0;
    string Euser, Epass, u, p;
    system("cls");
    cout << "Enter your details" << endl;
    cout << "Username : ";
    cin >> Euser;
    cout << "\nPassword : ";
    cin >> Epass;

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == Euser && p == Epass)
        {
            x = 1;
            break;
        }
    }
    input.close();
    if (x == 1)
    {
        cout << "Welcome " << Euser << endl;
        cout << "Press any key to go back to Welcome page" << endl;
        cin.get();
        cin.get();
        system("cls");
        main();
    }
    else
    {
        cout << "Login error\n Please check your Username and Password" << endl;
        cout << "Press any key to continue" << endl;
        cin.get();
        cin.get();
        system("cls");
        main();
    }
}
void forgot()
{
    int y;
    system("cls");
    cout << "1. Recover Password" << endl;
    cout << "2. Go back to Welcome page" << endl;
    cout << "Choose an option : ";
    cin >> y;

    switch (y)
    {
    case 1:
    {
        int m = 0;
        string Ruser, Ru, Rp;
        cout << "Enter your Username : ";
        cin >> Ruser;

        ifstream searchru("database.txt");
        while (searchru >> Ru >> Rp)
        {
            if (Ru == Ruser)
            {
                m = 1;
                break;
            }
        }
        searchru.close();
        if (m == 1)
        {
            cout << "Your password has been recovered.\nYour password is : " << Rp << endl;
            cout << "Press any key to continue\n";
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "The Username entered is not registered" << endl;
            cout << "Press any key to continue\n";
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        break;
    }

    case 2:
    {
        main();
        break;
    }

    default:
        cout << "Please choose from the options 1 and 2\n Press a key to continue" << endl;
        cin.get();
        cin.get();
        system("cls");
        forgot();

    }
}
