#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

struct User {
    int id = 0;
    string first_name, last_name, phone_number, email, address;
};

string readLine () {
    string input = "";
    getline(cin, input);
    return input;
}

char getChar() {
    char sign;
    string input = "";

    while(true) {
        input = readLine();

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "This is not a single character. Try again. " << endl;
    }
    return sign;
}

int getInt() {
    int number = 0;
    string input = "";

    while(true) {
        input = readLine();

        stringstream myStream(input);
        if (myStream >> number) break;

        cout << "THis is not a number. Try again." << endl;
    }
    return number;
}

void load_user_file (vector <User> &users) {
    fstream file;

    file.open("Address_Book.txt", ios::out);

    if (file.good()) {

        for (unsigned int i = 0; i < users.size(); i++) {
            file << users[i].id << "|";
            file << users[i].first_name << "|";
            file << users[i].last_name << "|";
            file << users[i].phone_number << "|";
            file << users[i].email << "|";
            file << users[i].address << "|" << endl;
        }
    }
    file.close();
}

void add_user(vector <User> &users) {

    User new_user;

    cout << "Enter first name: ";
    new_user.first_name = readLine();
    cout << "Enter last name: ";
    new_user.last_name = readLine();
    cout << "Enter phone number: ";
    new_user.phone_number = readLine();
    cout << "Enter e-mail: ";
    new_user.email = readLine();
    cout << "Enter address: ";
    new_user.address = readLine();
    new_user.id = users.empty() ? 1 : users.back().id + 1;
    users.push_back(new_user);

    cout << "User added" << endl;

    load_user_file(users);
}

void search_by_first_name (vector <User> &users) {

    string searched_first_name;
    cout << "Enter first name to search: ";
    searched_first_name = readLine();

    for (unsigned int i = 0; i < users.size(); i++) {
        if (users[i].first_name == searched_first_name) {
            cout << "ID:            " << users[i].id << "." << endl;
            cout << "First Name:    " << users[i].first_name << endl;
            cout << "Last Name:     " << users[i].last_name << endl;
            cout << "Phone Number:  " << users[i].phone_number << endl;
            cout << "E-mail:        " << users[i].email << endl;
            cout << "Address:       " << users[i].address << endl;
            cout << endl;
        } else {
            cout << "No users of this first name. Try again." << endl;
            break;
        }
    }
    system("pause");
}

void search_by_last_name (vector <User> &users) {
    string searched_last_name;
    cout << "Enter last name to search: ";
    searched_last_name = readLine();

    for (unsigned int i = 0; i < users.size(); i++) {
        if (users[i].last_name == searched_last_name) {
            cout << "ID:            " << users[i].id << "." << endl;
            cout << "First Name:    " << users[i].first_name << endl;
            cout << "Last Name:     " << users[i].last_name << endl;
            cout << "Phone Number:  " << users[i].phone_number << endl;
            cout << "E-mail:        " << users[i].email << endl;
            cout << "Address:       " << users[i].address << endl;
            cout << endl;
        } else {
            cout << "No users of this last name. Try again." << endl;
            break;
        }
    }
    system("pause");
}

void display_users_book(vector <User> &users) {

    if (!users.empty()) {
        for (unsigned int i = 0; i < users.size(); i++) {
            cout << "ID:            " << users[i].id << "." << endl;
            cout << "First Name:    " << users[i].first_name << endl;
            cout << "Last Name:     " << users[i].last_name << endl;
            cout << "Phone Number:  " << users[i].phone_number << endl;
            cout << "E-mail:        " << users[i].email << endl;
            cout << "Address:       " << users[i].address << endl;

        }
        cout << endl;
    } else {
        cout << "Address Book is empty." << endl;
    }
    system("pause");

}

void display_users_file(vector <User> &users) {

    User this_User;

    string data_user{};
    fstream file;
    file.open("Address_Book.txt", ios::in);

    if (!file.good()) {
        cout << "File corrupted. Try again. " << endl;
        system("pause");
        return;
    }
    while (getline(file, data_user)) {
        string special_data_user;
        int number_of_user = 1;
        for (size_t i{}; i < data_user.length(); i++) {
            if (data_user[i] != '|') {
                special_data_user += data_user[i];
            } else {

                switch (number_of_user) {
                case 1:
                    this_User.id = atoi(special_data_user.c_str());
                    break;
                case 2:
                    this_User.first_name = special_data_user;
                    break;
                case 3:
                    this_User.last_name = special_data_user;
                    break;
                case 4:
                    this_User.phone_number = special_data_user;
                    break;
                case 5:
                    this_User.email = special_data_user;
                    break;
                case 6:
                    this_User.address = special_data_user;
                    break;
                }
                special_data_user = "";
                number_of_user++;
            }
        }
        users.push_back(this_User);
    }
    file.close();
}

void delete_user(vector <User> &users) {

    system("cls");
    if (users.size() == 0) {
        cout << "Address Book is empty." << endl;
        Sleep(1000);
        return;
    }
    int id_user_to_delete;
    cout << "ID user to delete: " << endl;
    id_user_to_delete = getInt();

    char choose;

    for (unsigned int i = 0; i < users.size(); i++) {
        if (id_user_to_delete == users[i].id) {
            cout << "Delete" << endl;
            cout << "ID: " << users[i].id << "." << endl;
            cout << "First Name: " << users[i].first_name << endl;
            cout << "Last Name: " << users[i].last_name << endl;
            cout << "Phone Number: " << users[i].phone_number << endl;
            cout << "E-mail: " << users[i].email << endl;
            cout << "Address: " << users[i].address << endl;
            cout << endl;
            cout << "Confirm delete user? Press <t> to confirm. " << endl;
            cin >> choose;
            if (choose == 't') {
                users.erase(users.begin() + i);
                cout << "Confirmation of delete user" << endl;
            } else {
                cout << "Wrong answer. Try again" << endl;
            }
        } else {
            cout << "Chosen ID has not been found" << endl;
        }
    }
    load_user_file(users);
}

void edit_user(vector <User> &users) {

    system("cls");
    if (users.size() == 0) {
        cout << "Address Book is empty." << endl;
        Sleep(1000);
        return;
    }
    int id_user_to_edit;
    char choose;

    cout << "ID user to edit" << endl;
    id_user_to_edit = getInt();

    string first_name, last_name, phone_number, email, address;

    cout << "EDITION PANEL" << endl;
    cout << "1. First Name" << endl;
    cout << "2. Last Name" << endl;
    cout << "3. Phone Number" << endl;
    cout << "4. Email" << endl;
    cout << "5. Address" << endl;
    cout << "Your Choice: " << endl;

    choose = getChar();

    switch (choose) {
    case '1':
        cout << "Set User First Name" << endl;
        first_name = getInt();
        for (unsigned int i = 0; i < users.size(); i++) {
            if (users[i].id == id_user_to_edit)
                users[i].first_name = first_name;
        }
        break;
    case '2':
        cout << "Set User Last Name" << endl;
        last_name = getInt();
        for (unsigned int i = 0; i < users.size(); i++) {
            if (users[i].id == id_user_to_edit)
                users[i].last_name = last_name;
        }
        break;
    case '3':
        cout << "Set User Phone Number" << endl;
        phone_number = getInt();
        for (unsigned int i = 0; i < users.size(); i++) {
            if (users[i].id == id_user_to_edit)
                users[i].phone_number = phone_number;
        }
        break;
    case '4':
        cout << "Set User E-mail" << endl;
        email = getInt();
        for (unsigned int i = 0; i < users.size(); i++) {
            if (users[i].id == id_user_to_edit)
                users[i].email = email;
        }
        break;
    case '5':
        cout << "Set User Address" << endl;
        address = getInt();
        for (unsigned int i = 0; i < users.size(); i++) {
            if (users[i].id == id_user_to_edit)
                users[i].address = address;
        }
        break;
    }
    load_user_file(users);

}

void show_menu() {
    system("cls");
    cout << "ADDRESS BOOK" << endl << endl;
    cout << "1. Add person" << endl;
    cout << "2. Search by first name" << endl;
    cout << "3. Search by last name" << endl;
    cout << "4. Display address book" << endl;
    cout << "5. Remove person" << endl;
    cout << "6. Edit person" << endl;
    cout << "9. End program" << endl;
    cout << "Your choice:" << endl;
    cout << endl;

}

bool fileExists (const string& fileName) {
    fstream file;
    file.open(fileName.c_str(), ios::in);
    if ( file.is_open() ) {
        file.close();
        return true;
    }
    file.close();
    return false;
}

int main() {

    char choose;
    vector <User> users;

    display_users_file(users);

    while (true) {
        show_menu();
        choose = getChar();

        switch (choose) {
        case '1':
            add_user(users);
            break;
        case '2':
            search_by_first_name(users);
            break;
        case '3':
            search_by_last_name(users);
            break;
        case '4':
            display_users_book(users);
            break;
        case '5':
            delete_user(users);
            break;
        case '6':
            edit_user(users);
            break;
        case '9':
            cout << "End of the program! "<< endl;
            exit(0);
        default:
            cout << "Wrong choice. Try again. " << endl;
        }
        system ("pause");
    }

    return 0;
}
