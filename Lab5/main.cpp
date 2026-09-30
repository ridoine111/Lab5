#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string foodName;
    char menuChoice;
    char size;
    int quantity;
    double unitPrice;
    char isMember;
    string cashierNotes;

    // gets the input from the user
    cout << "================ DRINK MENU ================\n";
    cout << left << setw(20) << "Drink"
        << setw(12) << "Small"
        << setw(12) << "Medium"
        << setw(12) << "Large" << endl;

    cout << left << setw(20) << "A. Apple Juice"
        << setw(12) << "2.50"
        << setw(12) << "3.50"
        << setw(12) << "4.50" << endl;

    cout << left << setw(20) << "B. Lemonade"
        << setw(12) << "2.00"
        << setw(12) << "3.00"
        << setw(12) << "4.00" << endl;

    cout << left << setw(20) << "C. Soda"
        << setw(12) << "1.50"
        << setw(12) << "2.50"
        << setw(12) << "3.50" << endl;

    cout << "\nSelect a drink (A, B, or C): ";
    cin >> menuChoice;

    cout << "Select a size (s, m, or l): ";
    cin >> size;

    if (menuChoice == 'A' || menuChoice == 'a') {
        foodName = "Apple Juice";
    }
    else if (menuChoice == 'B' || menuChoice == 'b') {
        foodName = "Lemonade";
    }
    else if (menuChoice == 'C' || menuChoice == 'c') {
        foodName = "Soda";
    }

    if (size == 's' || size == 'S') {
        if (menuChoice == 'A' || menuChoice == 'a')
            unitPrice = 2.50;
        else if (menuChoice == 'B' || menuChoice == 'b')
            unitPrice = 2.00;
        else if (menuChoice == 'C' || menuChoice == 'c')
            unitPrice = 1.50;
    }
    else if (size == 'm' || size == 'M') {
        if (menuChoice == 'A' || menuChoice == 'a')
            unitPrice = 3.50;
        else if (menuChoice == 'B' || menuChoice == 'b')
            unitPrice = 3.00;
        else if (menuChoice == 'C' || menuChoice == 'c')
            unitPrice = 2.50;
    }
    else if (size == 'l' || size == 'L') {
        if (menuChoice == 'A' || menuChoice == 'a')
            unitPrice = 4.50;
        else if (menuChoice == 'B' || menuChoice == 'b')
            unitPrice = 4.00;
        else if (menuChoice == 'C' || menuChoice == 'c')
            unitPrice = 3.50;
    }

    cout << "Enter the quantity: ";
    cin >> quantity;

    cout << "Is the customer a member? (y/n): ";
    cin >> isMember;

    // Clear leftover newline before getline()
    cin.ignore();

    cout << "Enter cashier notes: ";
    getline(cin, cashierNotes);

    // =========================
    // CALCULATIONS
    // =========================

    double subCost = quantity * unitPrice;

    double discount = (isMember == 'y' || isMember == 'Y')
        ? subCost * 0.10
        : 0.0;

    // Subtotal after member discount
    double taxableSubtotal = subCost - discount;

    // Sales taxes
    double arkansasTax = taxableSubtotal * 0.065;
    double faulknerTax = taxableSubtotal * 0.005;
    double conwayTax = taxableSubtotal * 0.02125;

    double totalTax = arkansasTax + faulknerTax + conwayTax;

    // Amount before tip
    double totalWithTax = taxableSubtotal + totalTax;

    // =========================
    // TIP MENU
    // =========================

    char tipChoice;
    double tipAmount = 0.0;

    double tip15 = totalWithTax * 0.15;
    double tip20 = totalWithTax * 0.20;
    double tip25 = totalWithTax * 0.25;

    cout << fixed << setprecision(2);

    cout << "\n=========== TIP MENU ===========\n";
    cout << left << setw(25) << "Tip Selection"
        << setw(15) << "Amount" << endl;

    cout << left << setw(25) << "A. 15%"
        << "$" << tip15 << endl;

    cout << left << setw(25) << "B. 20%"
        << "$" << tip20 << endl;

    cout << left << setw(25) << "C. 25%"
        << "$" << tip25 << endl;

    cout << left << setw(25) << "D. Other Amount"
        << endl;

    cout << "\nWhat tip do you choose? ";
    cin >> tipChoice;

    if (tipChoice == 'A' || tipChoice == 'a') {
        tipAmount = tip15;
    }
    else if (tipChoice == 'B' || tipChoice == 'b') {
        tipAmount = tip20;
    }
    else if (tipChoice == 'C' || tipChoice == 'c') {
        tipAmount = tip25;
    }
    else if (tipChoice == 'D' || tipChoice == 'd') {
        cout << "How much would you like to tip? $";
        cin >> tipAmount;
    }

    // Final total = subtotal after discount + taxes + tip
    double finalTotal = taxableSubtotal + totalTax + tipAmount;

    // =========================
    // RECEIPT
    // =========================

    cout << "\n=========== RECEIPT ===========\n";

    cout << left << setw(20) << "Food Item:"
        << setw(15) << foodName << endl;

    cout << left << setw(20) << "Size:"
        << setw(15) << size << endl;

    cout << left << setw(20) << "Quantity:"
        << setw(15) << quantity << endl;

    cout << left << setw(20) << "Unit Price:"
        << right << setw(10) << "$" << unitPrice << endl;

    cout << left << setw(20) << "Subtotal:"
        << right << setw(10) << "$" << subCost << endl;

    cout << left << setw(20) << "Discount:"
        << right << setw(10) << "$" << discount << endl;

    cout << left << setw(20) << "Taxable Subtotal:"
        << right << setw(10) << "$" << taxableSubtotal << endl;

    // =========================
    // SALES TAX TABLE
    // =========================

    cout << "\n============= SALES TAXES =============\n";

    cout << left << setw(25) << "Tax Name"
        << setw(12) << "Rate"
        << right << setw(15) << "Tax Amount" << endl;

    cout << left << setw(25) << "Arkansas State Tax"
        << setw(12) << "6.5%"
        << right << setw(15) << "$" << arkansasTax << endl;

    cout << left << setw(25) << "Faulkner County Tax"
        << setw(12) << "0.5%"
        << right << setw(15) << "$" << faulknerTax << endl;

    cout << left << setw(25) << "Conway Municipal Tax"
        << setw(12) << "2.125%"
        << right << setw(15) << "$" << conwayTax << endl;

    cout << left << setw(37) << "Total Tax:"
        << right << setw(15) << "$" << totalTax << endl;

    // =========================
    // TIP AND FINAL TOTAL
    // =========================

    cout << "\nTip:" << right << setw(29) << "$" << tipAmount << endl;

    cout << left << setw(20) << "Total Before Tip:"
        << right << setw(10) << "$" << totalWithTax << endl;

    cout << left << setw(20) << "TIP:"
        << right << setw(10) << "$" << tipAmount << endl;

    cout << "---------------------------------------\n";

    cout << left << setw(20) << "TOTAL:"
        << right << setw(10) << "$" << finalTotal << endl;

    cout << "\nCashier Notes:\n" << cashierNotes << endl;

    cout << "=======================================\n";

    // =========================
    // INVENTORY AUDIT TABLE
    // =========================

    cout << "\n====== INVENTORY AUDIT ======\n";

    cout << left << setw(15) << "Item Name"
        << setw(10) << "Qty"
        << setw(12) << "Unit Price"
        << setw(12) << "Subtotal"
        << endl;

    cout << left << setw(15) << foodName
        << setw(10) << quantity
        << setw(12) << unitPrice
        << setw(12) << subCost
        << endl;

    return 0;
}
