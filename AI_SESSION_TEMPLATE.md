Projekt: PersonalBudget (C++)
Branch: feature__user-login-from-xml
Ostatni commit: 61cc5ab – Add user registration with XML persistence

Co działa:

Odczyt users.xml do vector<User> przy starcie aplikacji

Rejestracja użytkownika:
- walidacja loginu (pusty + unikalność)
- zapis do users.xml (append)
- aktualizacja vectora w pamięci

Logowanie z weryfikacją hasła (3 próby)

Menu główne i menu użytkownika działają poprawnie

Utils::readLine() jako standard wejścia

Czego nie ma / co jest niedomknięte:

Zmiana hasła z aktualizacją users.xml (update)

Integracja UserManager z BudgetManager po zalogowaniu (przekazanie userId / tworzenie managera)

Budżet: dodawanie przychodów/wydatków + pliki incomes.xml/expenses.xml + bilanse

Aktualny cel sesji (1 zamknięty poziom funkcjonalny):
Domknąć zmianę hasła (walidacja + zapis aktualizacji do users.xml + test po restarcie).

Tryb pracy:

najpierw opis działania (jak tester)

potem zmiana

1 commit = 1 zamknięty poziom funkcjonalny

Odpowiadaj:

krótko

bez dygresji

OK / 1 poprawka