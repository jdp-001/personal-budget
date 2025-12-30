# Project Architecture

## 1. Purpose
A console-based personal budget application that allows registered users to record incomes and expenses and display balance summaries for the current month, previous month, or a custom period. Data is persisted in XML files.

---

## 2. Global assumptions
- Language: C++
- Data storage: XML files using CMarkup library
- Date input/output format: yyyy-mm-dd (string in UI)
- Internal date representation: int YYYYMMDD (for sorting and comparisons)
- Allowed date range: from 2000-01-01 to the last day of the current month
- Amount input: decimal with dot; if user enters comma, convert comma to dot
- Sorting: operations must be sortable by date (ascending, oldest first)
- Code/comments/commit messages/branch names: English
- Our discussions and mentor materials: Polish

---

## 3. Modules overview
The application is split into the following modules (based on the UML and mentor reference):

- Application entry / loop (main.cpp)
  Owns the main loop and delegates control to BudgetMainApp based on user choice.

- UI (Menus)
  Responsible only for displaying menu options/titles (no business logic).

- Input helpers (Utils)
  Provides safe console input helpers (e.g., readLine, getCharacter) and basic input validation.

- User management (UserManager + UserFile + User struct)
  Registration, login/logout, password change and persistence of users in users.xml.

- Budget management (BudgetMainApp + BudgetManager)
  BudgetMainApp orchestrates user flow and delegates budget operations to BudgetManager.
  BudgetManager handles adding operations and showing balances for current month, previous month, and custom period.

- Domain model (Operation + Type enum)
  Operation represents a single income/expense entry; Type distinguishes INCOME vs EXPENSE.

- Date & amount validation (DateMethods + CashMethods)
  DateMethods validates and converts dates (UI string yyyy-mm-dd <-> internal int YYYYMMDD) and provides period boundaries.
  CashMethods validates amount input (including comma-to-dot handling).

- Persistence of operations (OperationFile + File base class)
  OperationFile loads/saves operations (incomes.xml / expenses.xml) for a given user using XML (CMarkup).

---

## 4. Helpers
Helper classes contain stateless, reusable logic shared across the application.
They do not store application state and do not perform business decisions.

- Utils
  Provides basic console input helpers (e.g., reading full lines, single characters)
  and simple input validation used by menus and managers.

- DateMethods
  Responsible for all date-related logic:
  - validating user input dates (yyyy-mm-dd)
  - handling special input for current date
  - converting dates between string format and internal int format (YYYYMMDD)
  - calculating date boundaries (current month, previous month)
  - leap year handling

- CashMethods
  Validates monetary input:
  - accepts decimal values
  - converts comma to dot if needed
  - ensures correct numeric format before conversion to double

---

## 5. Domain model
The domain model represents core business data without UI or persistence logic.

- Operation
  Represents a single financial entry (income or expense).
  Fields include:
  - id
  - userId
  - date (int YYYYMMDD)
  - item (description)
  - amount (double)

- Type (enum)
  Distinguishes the kind of operation:
  - INCOME
  - EXPENSE

---

## 6. Managers / Application logic
Managers coordinate application logic and operate on domain objects.
They do not handle direct user input parsing or low-level persistence details.

- BudgetMainApp
  Acts as the main application controller.
  Orchestrates user flow after login and delegates business operations to managers.
  Does not perform calculations itself.

- BudgetManager
  Handles core budget logic:
  - adding incomes and expenses
  - loading operations for the logged-in user
  - calculating balances for:
    - current month
    - previous month
    - custom date range
  - sorting operations by date (ascending)

- UserManager
  Responsible for user-related logic:
  - user registration
  - login and logout
  - password change
  - cooperation with persistence layer for users

---

## 7. Persistence
- users.xml: userId, login, password, name, surname
- incomes.xml: incomeId, userId, date, item, amount
- expenses.xml: expenseId, userId, date, item, amount
- XML library: CMarkup

---

## 8. UI / Control flow
The UI layer is console-based and responsible only for interaction and flow control.
It does not contain business logic or persistence logic.

- Main menu
  Allows the user to:
  - register a new account
  - log in to an existing account
  - exit the application

- User menu (after login)
  Allows the logged-in user to:
  - add income
  - add expense
  - display balance for the current month
  - display balance for the previous month
  - display balance for a custom date range
  - change password
  - log out

- Input flow
  - user input is read as strings
  - validation and conversion are delegated to helper classes
  - UI forwards validated data to managers

---

## 9. Rules & conventions
### Git conventions
- Commit messages: English
- Branch names: English
- Keep history clean (avoid unnecessary merges)
- Commit in small, logical steps

### Code conventions
- Source code: English
- Comments: English

### Architecture & implementation rules
- Application logic must be separated from UI and persistence layers.
- main.cpp should only contain the main loop and delegate control to BudgetMainApp.
- Managers must not perform direct console input parsing.
- Helper classes must be stateless and reusable.

### Date handling rules
- User-facing date format is yyyy-mm-dd.
- Internal date representation is int YYYYMMDD.
- Date validation must include:
  - correct format
  - valid day/month/year
  - leap year handling
  - allowed range (2000-01-01 to last day of current month)
- Date comparisons and sorting are based on int YYYYMMDD.

### Persistence rules
- XML is the only persistence format.
- All XML operations are implemented using CMarkup.
- File access logic must be isolated from business logic.

### Development process rules
- Architecture must be updated before or together with code changes.
- No implementation starts without agreed architecture (UML + ARCHITECTURE.md).
- README.md is required after publishing the project to GitHub.

---

## 10. Open questions / decisions
- (TODO) Decide when to add README.md (mentor requires README after publishing to GitHub)
- (TODO) Decide whether to include a short "Mentor requirements (verbatim)" section here or keep it in a separate file

### Mentor requirements (verbatim)
- Date should be stored as int YYYYMMDD to simplify sorting and comparing.
- User enters date as yyyy-mm-dd; validate; then convert to YYYYMMDD (with leading zeros) and store as int.
- After publishing on GitHub, add README describing the application.