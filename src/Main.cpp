#include <iostream>
using namespace std;

int main ()
{
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "admin" && userPassword == "1")
        {
            cout << "Welcome Admin!\n";
            break;
        }
        else if (userName == "individual" && userPassword == "2")
        {
            cout << "Welcome Individual!\n";
            break;
        }
        else if (userName == "cleaner" && userPassword == "3")
        {
            cout << "Welcome Cleaner!\n";
            break;
        }
        else if (userName == "logout" && userPassword == "0")
        {
            cout << "Logged Out \n";
            return 0;
        }

        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return 0;
    }
    cout << "Thank you for logging in.\n";
}