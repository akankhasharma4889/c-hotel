#include <iostream>
#include <string>
#include <iomanip>
#include<stdlib.h>
#include<windows.h>

using namespace std;

// Function prototypes
void login();
void choicePage();
void roomBilling();
void food();
void displayMenu();
void gameChoice(int choice); // Fixed: Added parameter
void displaygame(); // Added function prototype
void exitProgram();

bool isLoggedIn = false;

void login() {
    string username, password;
    const string correctUsername = "akku";
    const string correctPassword = "1234";

    cout << "\t\t\t***************** Welcome to Radison Hotel******************\n\n" << endl;
    cout << "\t\t\t\t\t Please login  yourself and  continue.\n\n" << endl;

    cout << "\t\t\t\t\t\t enter your Username: ";
    cin >> username;

    cout << "\t\t\t\t\t\t enter your Password: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        cout << "\t\t\t\t\t\t Login successfully...\n\n\n" << endl;
        isLoggedIn = true;
    } else {
        cout << "\t\t\t\t\t\tIncorrect username or password.\n\n\n" << endl;
    }
    cout << "\t\t\t\t\t\tplease wait for 2s...\n\n\n";
    Sleep(5000);
    system("CLS");
}

void choicePage() {
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                roomBilling();
                break;
            case 2:
                food();
                break;
            case 3:    
                displaygame(); // Fixed: Call displaygame() instead of gameChoice()
                break;
            case 4:
                cout << "Exiting the system." << endl;
                exitProgram();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (true);
}

void displayMenu() {
    cout << "\t\t\t\t------ Hotel Billing System ------\n\n\n" << endl;
    cout << "1. Room Billing" << endl;
    cout << "2. Food" << endl;
    cout << "3. Play" << endl;
    cout << "4. Exit" << endl;
    cout << "\t\t\t\t---------------------------------\n\n\n" << endl;
}

void roomBilling() {
    int nights;
    double pricePerNight = 1000.00;
    double totalAmount;

    cout << "Enter number of nights stayed: ";
    cin >> nights;

    totalAmount = pricePerNight * nights;

    cout << fixed << setprecision(2);
    cout << "Room rate per night: " << pricePerNight << endl;
    cout << "Number of nights: " << nights << endl;
    cout << "Total amount to pay: " << totalAmount << endl;

    cout << "\nWould you like to continue with payment?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int paymentChoice;
    cout << "Enter choice: ";
    cin >> paymentChoice;

    if (paymentChoice == 1) {
        cout << "Payment successful! Thank you for staying with us." << endl;
    } else {
        cout << "You have opted not to proceed with payment. Exiting the system." << endl;
        exitProgram();
    }
}

void food() {
    int plate;
    double order = 500.00; // Example price per plate
    double totalAmount;

    cout << "Enter number of plates: ";
    cin >> plate;
    totalAmount = order * plate;

    cout << fixed << setprecision(2);
    cout << "Ordered food: " << order << endl;
    cout << "Number of plates: " << plate << endl;
    cout << "Total amount to pay: " << totalAmount << endl;

    cout << "\nWould you like to continue with payment?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int paymentChoice;
    cout << "Enter choice: ";
    cin >> paymentChoice;

    if (paymentChoice == 1) {
        cout << "Payment successful! Thank you." << endl;
    } else {
        cout << "You have opted not to proceed with payment." << endl;
        exitProgram();
    }
}

void gameChoice(int choice) { // Fixed: Accepts an integer parameter
    switch(choice) {
        case 1:
            cout << "You have chosen ludo game" << endl;
            break;
        case 2:
            cout << "You have chosen quiz game" << endl;
            break;
        case 3:
            cout << "You have chosen chess game" << endl;
            break;
        case 4:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
    }
}

void displaygame() {
    int choice;

    do {
        cout << "\n==== Which game do you want to play ====" << endl;
        cout << "1. Play Ludo Game?" << endl;
        cout << "2. Play Quiz Game?" << endl;
        cout << "3. Play Chess Game?" << endl;
        cout << "4. Exit Game" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        gameChoice(choice);

    } while (choice != 4);     
}

void exitProgram() {
    cout << "Thank you for visiting Radison hotel. Good day!" << endl;
    exit(0); 
}

int main() {
    cout << "\t\t\t****************************************************************\n\n\n";
    cout << "\t\t\t-------------------- Welcome to the login page -------------------\n\n\n";
    
    login();
    
    if (isLoggedIn) {
        choicePage();
    } else {
        cout << "Login failed! Exiting program." << endl;
    }
    
    return 0;
}
