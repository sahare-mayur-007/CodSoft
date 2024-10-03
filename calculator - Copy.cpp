#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Enter the 1st nu: ";
    cin >> num1;

    cout << "Enter the op (+, -, *, /): ";
    cin >> operation;

    cout << "Enter the 2nd nu: ";
    cin >> num2;

    switch (operation) {
        case '+':
            cout << "Res: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Res: " << num1 - num2 << endl;
            break;
        case '*':
            std::cout << "Res: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Res: " << num1 / num2 << endl;
            } else {
                cout << "Error: Div by zero!" << endl;
            }
            break;
        default:
            cout << "Error: Invalid op!" << endl;
    }

    return 0;
}