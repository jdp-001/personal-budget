Projekt: PersonalBudget (C++)
Branch: feature__budget-manager-load-operations
Ostatni commit: bfada57 – Merge branch 'feature__user-login-from-xml'

Status (master = stable, merged):

Co działa:

- Rejestracja użytkownika:
  - walidacja loginu (pusty + unikalność)
  - zapis do users.xml (append)
  - aktualizacja vector<User> w pamięci

- Logowanie:
  - weryfikacja hasła (3 próby)
  - utrzymanie loggedUserId
  - tworzenie BudgetManager po poprawnym logowaniu
  - usuwanie BudgetManager przy wylogowaniu

- Zmiana hasła:
  - aktualizacja w vector<User>
  - pełny zapis users.xml (rewrite)

- OperationFile:
  - addOperationToFile (ID generation + XML append)
  - getLastOperationId (private)
  - loadOperationsFromFile (filter by loggedUserId)

- Struktura projektu zgodna z ARCHITECTURE.md

Czego nie ma / co jest niedomknięte:

- BudgetManager:
  - addIncome()
  - addExpense()
  - ładowanie operacji do wektorów w konstruktorze
  - bilans bieżącego miesiąca
  - bilans poprzedniego miesiąca
  - bilans okresu niestandardowego

- CashMethods (zgodnie z UML – brak implementacji)
- Klasa bazowa File (zgodnie z UML – brak implementacji / brak dziedziczenia)

Aktualny cel sesji (1 zamknięty poziom funkcjonalny):

BudgetManager loads incomes and expenses for logged user on construction

Tryb pracy:

- Najpierw opis działania (jak tester)
- Potem zmiana
- 1 commit = 1 zamknięty poziom funkcjonalny

Odpowiadaj:

- krótko
- bez dygresji
- OK / 1 poprawka