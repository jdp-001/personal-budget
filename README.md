# PersonalBudget

Console personal budget application written in C++.

The program allows registered users to record incomes and expenses
and display balance summaries for selected periods.

## Features

- user registration
- user login
- password change
- add income
- add expense
- balance for current month
- balance for previous month
- balance for custom period

## Technologies

- C++
- XML persistence using CMarkup
- object-oriented design
- console interface

## Architecture

The project follows a layered architecture:

UI layer
- BudgetMainApp

Business logic
- UserManager
- BudgetManager

Persistence layer
- UserFile
- OperationFile
- File (base class)

Helpers
- DateMethods
- Utils

Detailed architecture description is available in `ARCHITECTURE.md`.

## Data storage

Application data is stored in XML files:

- users.xml
- incomes.xml
- expenses.xml

## Author

Project created as part of learning object-oriented programming in C++.