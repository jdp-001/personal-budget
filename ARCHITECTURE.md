# Project Architecture

## 1. Purpose
A console-based personal budget application that allows registered users to record incomes and expenses and display balance summaries for the current month, previous month, or a custom period.

Data is persisted in XML files using the CMarkup library.

The project follows mentor requirements and strict architectural separation between UI, business logic and persistence.

---

## 2. Global assumptions

- Language: C++
- Data storage: XML (CMarkup)
- User date format (UI): yyyy-mm-dd
- Internal date format: int YYYYMMDD
- Allowed date range: 2000-01-01 to last day of current month
- Amount input: decimal with dot; comma is converted to dot
- Sorting: operations sorted ascending by date
- Code / commits / branches: English
- Discussions: Polish

---

## 3. Modules overview

### Application entry
- `main.cpp`
  - Owns main loop
  - Delegates control to `BudgetMainApp`

---

### UI / Control layer
- `BudgetMainApp`
  - Controls program flow after login
  - Delegates business logic to managers
  - Does not perform calculations

---

### Input helpers
- `Utils`
  - readLine()
  - getCharacter()
  - Safe console input handling

---

### User management
- `UserManager`
  - registration
  - login (3 attempts)
  - logout
  - password change
  - holds vector<User> in memory

- `UserFile`
  - loads users.xml
  - appends new user
  - rewrites file when password changes

- `User` (struct)
  - id
  - firstName
  - lastName
  - login
  - password

---

### Budget management
- `BudgetManager`
  - add income
  - add expense
  - load operations for logged user
  - calculate balance for:
    - current month
    - previous month
    - custom period
  - sort operations by date

---

### Domain model
- `Operation`
  - id
  - userId
  - date (int YYYYMMDD)
  - item
  - amount (double)

- `Type` (enum)
  - INCOME
  - EXPENSE

---

### Persistence of operations
- `OperationFile`
  - addOperationToFile()
  - loadOperationsFromFile()
  - getLastOperationId() (private)
  - uses CMarkup
  - separate files:
    - incomes.xml
    - expenses.xml

---

### Date handling
- `DateMethods`
  - validate date format
  - leap year handling
  - month length
  - convert yyyy-mm-dd ↔ YYYYMMDD
  - provide:
    - current date
    - first day of current month
    - previous month boundaries

---

### Planned (UML-aligned but not yet implemented)

- `CashMethods`
  - amount validation
  - comma-to-dot conversion
  - numeric validation before conversion to double

- `File` (base class)
  - potential common abstraction for UserFile and OperationFile
  - not yet introduced (current implementation uses concrete classes only)

---

## 4. Helpers philosophy

Helper classes:
- are stateless
- contain reusable logic
- do not store application state
- do not perform business decisions

---

## 5. Separation of concerns

UI layer:
- displays menus
- collects raw input
- delegates to managers

Managers:
- perform business logic
- operate on domain objects
- do not directly parse console input

Persistence layer:
- performs XML I/O
- contains no business decisions

Domain model:
- contains only data
- no UI or XML logic

---

## 6. Persistence format

- users.xml:
  - userId
  - login
  - password
  - firstName
  - lastName

- incomes.xml:
  - Id
  - UserId
  - Date
  - Item
  - Amount

- expenses.xml:
  - Id
  - UserId
  - Date
  - Item
  - Amount

---

## 7. Authentication flow

- users.xml loaded once at startup
- vector<User> stored in memory
- login validated in memory
- password change rewrites full users.xml
- after successful login:
  - BudgetManager created with loggedUserId
- after logout:
  - BudgetManager destroyed

---

## 8. Git rules

- No direct commits to master
- Master updated only via merge commits
- One branch = one coherent functional area
- 1 commit = 1 closed functional level
- Keep history clean

---

## 9. Development process rules

- Architecture updated before or together with code
- No implementation without agreed structure
- Small incremental steps
- Avoid architectural drift
- Avoid adding classes not defined in architecture

---

## 10. Current state (after merge to master)

Implemented:
- User registration + login
- Password change
- OperationFile complete
- DateMethods complete
- BudgetManager skeleton

Remaining:
- BudgetManager:
  - loading operations into vectors
  - addIncome / addExpense
  - balance calculations

Planned:
- CashMethods
- Optional File base class

---

## 11. Mentor requirements (verbatim)

- Date stored as int YYYYMMDD
- User enters yyyy-mm-dd, validated then converted
- Sorting based on int YYYYMMDD
- README required after publishing