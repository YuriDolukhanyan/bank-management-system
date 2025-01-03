#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include <random>

int total_saving_accounts = 0;
int total_current_accounts = 0;

long long generateUniqueBankID() {
    std::random_device rd;  // Seed for random number generator
    std::mt19937 gen(rd()); // Mersenne Twister RNG
    std::uniform_int_distribution<long long> dist(100000000000, 999999999999);

    long long id = dist(gen);;

    return id;
}

class Account
{
public:
    std::string accountHolderName;
    std::string jointAccountHolderName;
    long long accountNumber;
    long long balance;
    std::string accountType;
    std::string pin;

    // Constructor for single-holder account
    Account(std::string holderName, int initialBalance, std::string type, std::string pinCode)
    {
        accountNumber = generateUniqueBankID();
        accountHolderName = holderName;
        jointAccountHolderName = "No Joint Holder in this account";
        balance = initialBalance;
        accountType = type;
        pin = pinCode;
    }

    // Constructor for joint-holder account
    Account(std::string holderName, std::string jointHolderName, int initialBalance, std::string type, std::string pinCode)
    {
        accountNumber = generateUniqueBankID();
        accountHolderName = holderName;
        jointAccountHolderName = jointHolderName;
        balance = initialBalance;
        accountType = type;
        pin = pinCode;
    }
};

std::vector<Account> accounts;

bool validatePin(const std::string& pin)
{
    if (pin.length() != 4 || !isdigit(pin[0]) || !isdigit(pin[1]) || !isdigit(pin[2]) || !isdigit(pin[3]))
    {
        std::cout << "Invalid PIN! Please enter a 4-digit numeric PIN.\n";
        return false;
    }
    return true;
}

void displayAccountDetails(long long accountNumber)
{
    for (const auto& acc : accounts)
    {
        if (acc.accountNumber == accountNumber)
        {
            std::cout << "\nAccount Number: " << acc.accountNumber;
            std::cout << "\nAccount Holder Name: " << acc.accountHolderName;
            std::cout << "\nJoint Holder Name: " << acc.jointAccountHolderName;
            std::cout << "\nBalance: " << acc.balance;
            std::cout << "\nAccount Type: " << acc.accountType << "\n";
            return;
        }
    }
    std::cout << "Account not found with the given Account Number.\n";
}

void displayAllAccounts()
{
    if (accounts.empty())
    {
        std::cout << "No accounts available.\n";
        return;
    }

    std::cout << "\nAll Accounts:\n";
    std::cout << "-----------------------------------------------\n";
    for (const auto& acc : accounts)
    {
        std::cout << "Account Number: " << acc.accountNumber << "\n";
        std::cout << "Account Holder Name: " << acc.accountHolderName << "\n";
        std::cout << "Joint Holder Name: " << acc.jointAccountHolderName << "\n";
        std::cout << "Balance: " << acc.balance << "\n";
        std::cout << "Account Type: " << acc.accountType << "\n";
        std::cout << "-----------------------------------------------\n";
    }
}

bool createAccount()
{
    system("cls");
    std::string holderName;
    std::cout << "\nENTER YOUR DETAILS HERE:\n";
    std::cout << "Name of Account Holder: ";
    std::cin.ignore();
    std::getline(std::cin, holderName);

    std::string jointHolderName = "No Joint Holder in this account";
    std::cout << "\nDo you want a joint holder account? Type YES/NO: ";
    std::string choice; std::cin >> choice;
    for (char& c : choice)
        c = std::toupper(static_cast<unsigned char>(c));
    while (choice != "YES" && choice != "NO")
    {
        std::cout << "Invalid choice. Please type YES or NO: ";
        std::cin >> choice;
        for (char& c : choice)
            c = std::toupper(static_cast<unsigned char>(c));
    }
    if (choice == "YES")
    {
        std::cout << "Enter the name of Joint Holder: ";
        std::cin.ignore();
        std::getline(std::cin, jointHolderName);
    }

    std::string pin;
    do
    {
        std::cout << "\nEnter a 4-digit numeric PIN: ";
        std::cin >> pin;
    } while (!validatePin(pin));

    int accountChoice;
    std::string accountType;
    do
    {
        std::cout << "\nChoose the type of account:\n1 - Savings Account\n2 - Current Account\nEnter your choice: ";
        std::cin >> accountChoice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            accountChoice = 0;
        }
        if (accountChoice == 1)
            accountType = "Savings";
        else if (accountChoice == 2)
            accountType = "Current";
        else
            std::cout << "Invalid choice. Please try again.\n";
    } while (accountChoice != 1 && accountChoice != 2);

    long long initialBalance;
    do
    {
        std::cout << "\nEnter the initial balance: ";
        std::cin >> initialBalance;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            initialBalance = -1;
        }
        if (accountType == "Current" && initialBalance < 10000)
        {
            std::cout << "Minimum required balance for Current Account is 10,000.\n";
        }
    } while (accountType == "Current" && initialBalance < 10000);

    if (choice == "YES")
    {
        accounts.emplace_back(holderName, jointHolderName, initialBalance, accountType, pin);
    } else
    {
        accounts.emplace_back(holderName, initialBalance, accountType, pin);
    }

    if (accountType == "Savings")
        total_saving_accounts++;
    else
        total_current_accounts++;

    std::cout << "\nAccount created successfully!\n";
    displayAccountDetails(accounts.back().accountNumber);

    return true;
}

void adminMenu()
{
    int adminChoice;
    do
    {
        system("cls");
        std::cout << "\t\t|-----------------------------------------------|\n";
        std::cout << "\t\t|            ADMIN MENU                          |\n";
        std::cout << "\t\t|-----------------------------------------------|\n";
        std::cout << "\t\t|     1) View All Accounts                      |\n";
        std::cout << "\t\t|     2) Total Savings and Current Accounts     |\n";
        std::cout << "\t\t|     3) Back to Main Menu                      |\n";
        std::cout << "\t\t|-----------------------------------------------|\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> adminChoice;

        switch (adminChoice)
        {
        case 1:
            displayAllAccounts();
            break;
        case 2:
            std::cout << "\nTotal Savings Accounts: " << total_saving_accounts;
            std::cout << "\nTotal Current Accounts: " << total_current_accounts << "\n";
            break;
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    } while (true);
}

void displayMenu()
{
    int choice;
    do
    {
        system("cls");
        std::cout << "\t\t|-----------------------------------------------|\n";
        std::cout << "\t\t|     WELCOME TO THE BANKING SYSTEM             |\n";
        std::cout << "\t\t|-----------------------------------------------|\n";
        std::cout << "\t\t|     1) Create a New Account                   |\n";
        std::cout << "\t\t|     2) Admin Menu                             |\n";
        std::cout << "\t\t|     3) Exit                                   |\n";
        std::cout << "\t\t|-----------------------------------------------|\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid option [1, 2, or 3].\n";
            std::cout << "\nPress Enter to continue...";
            std::cin.get();
            continue;
        }

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            adminMenu();
            break;
        case 3:
            std::cout << "Exiting the system. Thank you!\n";
            exit(0);
        default:
            std::cout << "Invalid choice. Please enter [1, 2, or 3].\n";
            break;
        }
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    } while (true);
}

int main()
{
    displayMenu();
    return 0;
}
