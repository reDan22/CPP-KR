#include <iostream>
#include <string>

struct Account {
    std::string username;
    std::string password;
};

Account accounts[50]; 
int numAccounts = 0;    

void addAccount() {
    std::cout << "Enter username: ";
    std::cin >> accounts[numAccounts].username;
    std::cout << "Enter password: ";
    std::cin >> accounts[numAccounts].password;
    numAccounts++;
    std::cout << "Account created." << std::endl;
}

void deleteAccount() {
    std::string username;
    std::cout << "Enter username of an account to delete: ";
    std::cin >> username;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].username == username) {
            for (int j = i; j < numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            numAccounts--;
            std::cout << "Account deleted." << std::endl;
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}

void changeAccount() {
    std::string username;
    std::cout << "Enter username of an account to change: ";
    std::cin >> username;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].username == username) {
            std::cout << "Enter new username: ";
            std::cin >> accounts[i].username;
            std::cout << "Enter new password: ";
            std::cin >> accounts[i].password;
            std::cout << "Account updated successfully." << std::endl;
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}

void displayAccounts() {
    for (int i = 0; i < numAccounts; i++) {
        std::cout << "Username: " << accounts[i].username << ", Password: " << accounts[i].password << std::endl;
    }
}

int main() {
    void (*functionPtrArr[])(void) = { addAccount, deleteAccount, changeAccount, displayAccounts };

    while (true) {
        std::cout << "Type number 1-4 to select an option:" << std::endl;
        std::cout << "1. Create new account" << std::endl;
        std::cout << "2. Delete account" << std::endl;
        std::cout << "3. Change account settings" << std::endl;
        std::cout << "4. Display all accounts" << std::endl;
        int choice;
        std::cin >> choice;
        if (choice < 1 || choice > 4) {
            std::cout << "Invalid choice. Try again." << std::endl;
            continue;
        }
        (*functionPtrArr[choice - 1])();
    }

    return 0;
}