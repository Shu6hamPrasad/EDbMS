#include <bits/stdc++.h>
#include "continue.cpp"
using namespace std;
void UserIDinput();
void UserPasswordInput(string name, int index)
{
    vector<string> password;
    fstream p_file;
    p_file.open("password.x");
    if (p_file.is_open())
    {
        cout << "Hi "<< name << ", Enter your password: ";
        string passIn;
        cin >> passIn;
        string var;
        while (getline(p_file, var))
            password.push_back(var);
        if (password[index] == passIn){
            p_file.close();
            user(name);
        }
        else
        {
            cout << "Sorry, Wrong input, Do you want to try again? (y/n or Y/N): ";
            char i;
            cin >> i;
            if (i == 'y' || i == 'Y')
                UserIDinput();
            else
            {
                p_file.close();
                exit(0);
            }
        }
        p_file.close();
    }
    else
        cout << "404_FNF_PFILE" << endl;
}
void UserIDinput()
{
    fstream file;
    file.open("UserID.x");
    if (file.is_open())
    {
        vector<string> userID;
        vector<string>::iterator UIDvec;
        cout << "Enter your user ID: ";
        string input;
        cin >> input;
        string vecIN;
        int count = 0;
        string check;
        while (getline(file, vecIN))
            userID.push_back(vecIN);
        bool uidCheck = false;
        for (UIDvec = userID.begin(); UIDvec <= userID.end(); UIDvec++)
        {
            if (input == *UIDvec)
            {
                uidCheck = true;
                break;
            }
            count++;
        }
        if (uidCheck)
            UserPasswordInput(input, count);
        else
        {
            cout << "Sorry, Wrong input, Do you want to try again? (y/n or Y/N): ";
            char i;
            cin >> i;
            if (i == 'y' || i == 'Y')
                UserIDinput();
            else
            {
                file.close();
                exit(0);
            }
        }
        file.close();
    }
    else
        cout << "404_FNF_FILE" << endl;
}

int main()
{
    cout << "Welcome to EDbMS Version 0.0.1 [BETA_TESTING_1]" << endl;
    cout << "Please enter the required information:" << endl;
    UserIDinput();
    return 0;
}