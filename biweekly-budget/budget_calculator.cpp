#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Expense {
public:
    std::string category;
    double amount;

    Expense(std::string cat, double amt) : category(cat), amount(amt) {}
};

class BudgetCalculator {
private:
    double income;
    std::vector<Expense> expenses;

public:
    BudgetCalculator() : income(0) {}

    void setIncome() {
        std::cout << "Enter your biweekly income: $";
        std::cin >> income;
        while (income <= 0) {
            std::cout << "Please enter a valid income amount: $";
            std::cin >> income;
        }
    }

    void addExpense() {
        std::string category;
        double amount;
        
        std::cout << "Enter expense category: ";
        std::cin.ignore();  // To clear the input buffer
        std::getline(std::cin, category);

        std::cout << "Enter expense amount: $";
        std::cin >> amount;
        while (amount <= 0) {
            std::cout << "Please enter a valid amount: $";
            std::cin >> amount;
        }

        // Add expense to the list
        expenses.push_back(Expense(category, amount));
    }

    void displayExpenses() {
        std::cout << "\nList of expenses:\n";
        for (const auto& expense : expenses) {
            std::cout << "Category: " << expense.category << " | Amount: $" << expense.amount << "\n";
        }
    }

    double calculateRemaining() {
        double totalExpenses = 0;
        for (const auto& expense : expenses) {
            totalExpenses += expense.amount;
        }

        double remainingFunds = income - totalExpenses;
        return remainingFunds;
    }

    void displayRemainingFunds() {
        double remaining = calculateRemaining();
        std::cout << "\nRemaining Funds: $" << std::fixed << std::setprecision(2) << remaining << "\n";
    }
};

int main() {
    BudgetCalculator budget;

    // Step 1: Set income
    budget.setIncome();

    int choice;
    do {
        std::cout << "\n--- Biweekly Budget Calculator ---\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. View Expenses\n";
        std::cout << "3. Calculate Remaining Funds\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                budget.addExpense();
                break;
            case 2:
                budget.displayExpenses();
                break;
            case 3:
                budget.displayRemainingFunds();
                break;
            case 4:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
