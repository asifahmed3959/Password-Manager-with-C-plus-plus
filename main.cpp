#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

//global variables
string email, password;
void addPassword();
bool isChar(char);
bool isDigit(char);
bool checkEmail(string email);
bool checkPassword(const string& value);
void printPassword();

int main() {

    short int choice;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\tHello This is a password management application!";
    cout << "\n\n\t1. Save Password\n\t2. Print Password\n\t3. Exit\n\t> ";
    cin >> choice;

    switch(choice){
        case 1:
            addPassword();
            break;
        case 2:
            printPassword();
            break;
        default:
            cout << "\n\n\tInvalid Input !";
            cout << "\n\tPress Any Key To Continue..";
            getch();
            main();
    }

    return 0;
}

void printPassword() {
    // print passwords
    ifstream myFile("password.txt");

    while (myFile >> email  >> password){
            system("cls");
            cout << "\n\n\n\t\tEmail details..";
            cout << "\n\n\tEmail : " << email;
            cout << "\n\tPassword : " << password;
            break;
    }
}

void addPassword() {
//take input of email
//take input of password
    ofstream password_book("password.txt", ios::app);
    system("cls");
    cout << "\n\n\tEnter email address : ";
    cin >> email;
    cout << "\n\tEnter Password : ";
    cin >> password;

    if (password_book.is_open()){

    if (checkEmail(email)) {
        if (checkPassword(password)) {
            if (password_book.is_open()){
                password_book << email << " " << password << endl;
                cout << "\n\tPassword Saved Successfully !";
            }
            else {
                cout << "\n\tError Opening File !";
            }
        }
        else {
            cout << "\n\tPassword needs to be more secured";
        }
    }
    else {
        cout << "\n\tNot a valid Email";
    }

        password_book.close();
    }
    else{
        cout << "Problem with opening file";
    }
}

bool checkPassword(const string& value) {
    if (value.length() < 5){
        return false;
    }
        return true;
}

bool checkEmail(string email) {
    if (!isChar(email[0])){
        return false;
    }

    int At = -1, Dot = -1;

    for (int i = 0; i < email.length(); i++){
        if (email[i] == '@'){
            At = i;
        }
        else if (email[i] == '.'){
            Dot = i;
        }
    }

    if (At == -1 || Dot == -1)
        return false;

    if (At > Dot)
        return false;

    return Dot < (email.length() - 1);
}

bool isChar(char c){
    return (( c >= 'a' && c <= 'z' ) || (c>= 'A' && c <= 'Z'));
}

bool isDigit(const char c){
    return (c >= '0' && c <= '9');
}


