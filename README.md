# PersonalBudget

PersonalBudget is a console application written in C++ that allows users to manage a personal budget by recording incomes and expenses and generating balance summaries for selected time periods.

The project was created as part of an object-oriented programming course and focuses on clean architecture, XML persistence and financial data processing.

## Features

The application allows users to:

- register a new account
- log in using login and password (3 attempts)
- change password
- add incomes
- add expenses
- display balance for:
  - current month
  - previous month
  - custom period

During balance display the application:

- shows incomes first
- then expenses
- sorts operations by date
- displays:
  - total incomes
  - total expenses
  - balance difference

## Technologies

- C++
- Object-Oriented Programming
- XML data storage
- CMarkup library

## Project structure

Main components of the application:

- BudgetMainApp – controls application flow and menus  
- UserManager – handles user registration, login, logout and password changes  
- BudgetManager – manages financial operations and balance calculations  
- UserFile – handles persistence of user data in `users.xml`  
- OperationFile – handles persistence of financial operations in XML files  
- DateMethods – provides date validation and date conversion utilities  

## Data storage

Application data is stored in three XML files:

users.xml  
incomes.xml  
expenses.xml  

Each operation stores:

- id
- userId
- date (stored internally as `YYYYMMDD`)
- item
- amount

## How to run

1. Clone the repository

git clone https://github.com/jdp-001/personal-budget.git

2. Open the project in Code::Blocks

3. Build the project

4. Run the application

## Author

Jarosław Doliński

## Status

Educational project created as part of the *Przyszły Programista* course.