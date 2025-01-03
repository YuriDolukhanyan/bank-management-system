# Bank Management System

## Overview
This is a simple Bank Management System built using C++. The system allows users to create bank accounts (both single and joint accounts), view account details, and interact with an admin menu to manage accounts. The system supports two types of accounts: **Savings Account** and **Current Account**.

## Features:
- **Account Creation**: Users can create single or joint bank accounts.
- **Account Types**: Supports both **Savings** and **Current** accounts.
- **PIN Validation**: Each account is secured with a 4-digit numeric PIN.
- **Admin Access**: Admins can view all accounts and check the total number of Savings and Current accounts.
- **Account Details**: Users can view details of their accounts such as balance, holder names, and account type.
- **Dynamic Input Validation**: The system ensures valid input is entered, including the balance and PIN.

## Requirements:
- A C++ compiler (e.g., g++, clang++).
- A terminal or command prompt for running the program.

## Usage:
### Menu Options: When you start the system, you'll be presented with a menu:
1. **Create a New Account**: Allows the user to create a new account by entering their details and choosing the account type (Savings or Current).
2. **Admin Menu**: For administrators to view all total number of Savings and Current accounts.
3. **Exit**: Exits the system.

### Account Creation:
- **Single-holder accounts**: Users can create an account with just their name and a 4-digit PIN.
- **Joint-holder accounts**: Users can opt to add a joint account holder.
- **Account Types**: Users can choose between a **Savings Account** or a **Current Account**. Current Accounts require a minimum initial balance of 10,000.

### Admin Menu:
- Admins can view all accounts created and see the total number of **Savings** and **Current** accounts.

### Input Validation:
- The system ensures that the **PIN** is 4 digits long. * For **Current Accounts**, the system checks that the initial balance is at least 10,000.

Example Usage:
- ### Creating an Account:
```bash
ENTER YOUR DETAILS HERE:
Name of Account Holder: John Doe
Do you want a joint holder account? Type YES/NO: NO
Enter a 4-digit numeric PIN: 1234
Choose the type of account:
1 - Savings Account
2 - Current Account
Enter your choice: 1
Enter the initial balance: 5000

Account created successfully!
Account Number: 123456789012
Account Holder Name: John Doe
Joint Holder Name: No Joint Holder in this account
Balance: 5000
Account Type: Savings
```

- ### Admin Menu less Copy code:
```bash
ADMIN MENU:
1) View All Accounts
2) Total Savings and Current Accounts
3) Back to Main Menu
```

- ### Viewing All Accounts yaml Copy code:
```bash
All Accounts:
-----------------------------------------------
Account Number: 123456789012
Account Holder Name: John Doe
Joint Holder Name: No Joint Holder in this account
Balance: 5000
Account Type: Savings
-----------------------------------------------
```

## Code Structure:
* **`bank_system.cpp`**: The main C++ file where the program logic resides. * The system initializes global variables to keep track of total savings and current accounts. * **`Account`** class defines the structure and behavior of bank accounts. * Functions for creating accounts, validating inputs, and displaying account details are provided.




