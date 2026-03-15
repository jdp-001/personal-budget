# Project Architecture

## 1. Purpose

PersonalBudget is a console-based C++ application for managing a personal budget.

The program allows registered users to:
- register and log in,
- change password,
- add incomes and expenses,
- display balance for:
  - current month,
  - previous month,
  - custom period.

Data is persisted in XML files using the CMarkup library.

---

## 2. Global assumptions

- Language: C++
- Data storage: XML (CMarkup)
- UI date format: `yyyy-mm-dd`
- Internal date format: `int YYYYMMDD`
- Allowed date range: from `2000-01-01` to the last day of the current month
- Amount input: decimal number; comma is converted to dot
- Operations are displayed sorted ascending by date
- Code / commits / branch names: English
- Discussion / analysis: Polish

---

## 3. Layers and responsibilities

### Application entry
- `main.cpp`
  - owns the main loop,
  - creates `BudgetMainApp`.

### UI / control layer
- `BudgetMainApp`
  - controls application flow,
  - displays menus,
  - delegates work to managers,
  - does not contain business calculations.

### User logic
- `UserManager`
  - user registration,
  - login,
  - logout,
  - password change,
  - stores `vector<User>` in memory,
  - creates user-related decisions and validations.

### Budget logic
- `BudgetManager`
  - adding incomes,
  - adding expenses,
  - loading operations for logged user,
  - calculating and displaying balances,
  - sorting operations by date,
  - using date range logic.

### Persistence layer
- `UserFile`
  - loads users from XML,
  - appends new user to XML,
  - saves full users list when needed.

- `OperationFile`
  - loads operations from XML,
  - appends operations to XML,
  - determines last operation id.

- `File`
  - base class for XML file handling,
  - stores common file data:
    - `FILE_NAME`
    - `lastId`
    - `xmlDoc`
  - provides shared XML-related mechanism (`checkRootNode()`).

### Helper classes
- `Utils`
  - safe console input handling,
  - `readLine()`,
  - `getCharacter()`.

- `DateMethods`
  - date validation,
  - leap year handling,
  - month length handling,
  - date conversion between string and integer formats,
  - current and previous month boundary calculations.

---

## 4. Domain model

### `User`
- `id`
- `firstName`
- `lastName`
- `login`
- `password`

### `Operation`
- `id`
- `userId`
- `date`
- `item`
- `amount`

### `Type`
- `INCOME`
- `EXPENSE`

---

## 5. Persistence format

### `users.xml`
Stores:
- `UserId`
- `FirstName`
- `LastName`
- `Login`
- `Password`

### `incomes.xml` / `expenses.xml`
Stores:
- `Id`
- `UserId`
- `Date`
- `Item`
- `Amount`

---

## 6. Main flow

### Authentication flow
- `users.xml` is loaded into memory,
- login is validated against `vector<User>`,
- after successful login, `BudgetManager` is created for the logged user,
- after logout, `BudgetManager` is destroyed.

### Budget flow
- user adds income or expense,
- operation is validated and converted,
- operation is appended to the proper XML file,
- balances are calculated from loaded operations for selected date range.

---

## 7. Separation of concerns

### UI layer
Responsible for:
- menus,
- communication with the user,
- collecting raw input.

### Managers
Responsible for:
- business decisions,
- application logic,
- using domain objects and helpers.

### Persistence layer
Responsible for:
- XML reading and writing,
- file structure handling,
- no business decisions.

### Domain objects
Responsible only for:
- storing data.

---

## 8. Git workflow

- No direct commits to `master`
- `master` updated through merges from feature/chore/fix branches
- One branch = one coherent change
- One commit = one closed logical step
- Keep history clean and readable

---

## 9. Current state

Implemented:
- user registration,
- login,
- password change,
- adding income,
- adding expense,
- current month balance,
- previous month balance,
- custom period balance,
- XML persistence,
- `File` base class introduced and used by file classes.

Not implemented as separate UML elements:
- `CashMethods` class
- `Utils::validateInput()`
- `UserFile::changePasswordInFile()`

These areas are currently handled in other parts of the program.

---

## 10. Mentor requirements reflected in the implementation

- Date stored internally as `int YYYYMMDD`
- User enters date as `yyyy-mm-dd`
- Input date is validated before conversion
- Sorting is based on integer date representation
- XML persistence implemented with CMarkup