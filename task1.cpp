#include <iostream>
#include <limits>
#include <string>
using namespace std;

double getNumber(const string& prompt) {
    double n;
    while (true) {
        cout << prompt;
        if (cin >> n) return n;
        cout << "Invalid input. Enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    char again;
    cout << "=== Simple Calculator ===\n";
    do {
        double a = getNumber("Enter first number: ");
        double b = getNumber("Enter second number: ");
        char op;
        cout << "Operations: + - * /\nChoose operation: ";
        cin >> op;

        switch (op) {
            case '+': cout << "Result: " << a + b << "\n"; break;
            case '-': cout << "Result: " << a - b << "\n"; break;
            case '*': cout << "Result: " << a * b << "\n"; break;
            case '/':
                if (b == 0) cout << "Error: Cannot divide by zero.\n";
                else cout << "Result: " << a / b << "\n";
                break;
            default: cout << "Invalid operation.\n";
        }

        cout << "Calculate again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "Goodbye!\n";
    return 0;
}
