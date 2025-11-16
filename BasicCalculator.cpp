//1st C++ Project: Basic Calculator (BaCa)

#include <iostream>
using namespace std;

void showMenu();
void spacing1();

void getNumbers(float &num1, float &num2);
void handleInput();
float multiply(float num1, float num2);
float divide(float num1, float num2);
float add(float num1, float num2);
float subtract(float num1, float num2);

int main() {
    int selection;
    float num1, num2, result;

    while (true){
        showMenu();
        spacing1();

        cout << "Select an operation: ";
        while (!(cin >> selection)) {
        handleInput();
        }

        cout << endl;

        if (selection == 5) {
            cout << "\033[34m Exiting program...\033[0m";
            spacing1();
            break;
        } else if ( selection < 1 || selection > 5) {
            cout << "\033[31m Invalid selection. Please try again!\033[0m";
            spacing1();
            continue;
        }
    
        // Get user numbers only once

        getNumbers(num1, num2);

        switch (selection){
            case 1:
                result = multiply(num1, num2);
                cout << endl;
                cout << "\033[32m" << num1 << " * " << num2 << " = " << result << "\033[0m";
                spacing1();
                break;

            case 2:
                result = divide(num1, num2);
                cout << endl;
                cout << "\033[32m" << num1 << " / " << num2 << " = " << result << "\033[0m";
                spacing1();
                break;

            case 3:
                result = add(num1, num2);
                cout << endl;
                cout << "\033[32m" << num1 << " + " << num2 << " = " << result << "\033[0m";
                spacing1();
                break;
                
            case 4:
                result = subtract(num1, num2);
                cout << endl;
                cout << "\033[32m" << num1 << " - " << num2 << " = " << result << "\033[0m";
                spacing1();
                break;

            //lacks type proofing

            default:
                return 0;
                break;
        }

    }
    return 0;
}

//FUNCTION DEFINITION

void showMenu() {
    cout << "****** Basic Calculator ******" << endl;
    cout << "[1] Multiply" << endl;
    cout << "[2] Divide" << endl;
    cout << "[3] Add" << endl;
    cout << "[4] Subtract" << endl;
    cout << "[5] Exit";
}

void spacing1 () {
    cout << endl << endl;
}

void getNumbers(float &num1, float &num2) {
    cout << "Enter first number: ";
    while (!(cin >> num1)) {
        handleInput();
    }

    // cin >> num1;
    cout << "Enter second number: ";
    while (!(cin >> num2)) {
        handleInput();
    }
}

void handleInput() {
    cout << "\033[31m Invalid input! \033[0m";
    cout << "Please enter a number: ";
    cin.clear();
    cin.ignore(1000, '\n');
}

float multiply(float num1, float num2) { return  num1 * num2; }
float divide( float num1, float num2) { 
    if (num2 == 0) {
        cout << "\033[31m Error! Division by zero is not allowed.\033[03m" << endl;
        return 0;
    }
    return num1 / num2; }
float add(float num1, float num2) { return num1 + num2; }
float subtract(float num1, float num2) { return num1 - num2; }