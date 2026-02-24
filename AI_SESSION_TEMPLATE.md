Projekt: PersonalBudget (C++)
Branch: feature__user-login-from-xml
Ostatni commit: ed560c2 – Cleanup docs: remove deprecated guidelines, add workflow and AI template

Co działa:

Odczyt users.xml do vector<User> przy starcie aplikacji

Logowanie z weryfikacją hasła (3 próby)

Menu główne i menu użytkownika działają poprawnie

Utils::readLine() jako standard wejścia

Czego nie ma / co jest niedomknięte:

Rejestracja użytkownika z zapisem do users.xml

Zmiana hasła z aktualizacją pliku

Integracja UserManager z BudgetManager po zalogowaniu

Aktualny cel sesji (1 zamknięty poziom funkcjonalny):
Domknąć rejestrację użytkownika (walidacja loginu + zapis do users.xml + aktualizacja vectora w pamięci).

Tryb pracy:

najpierw opis działania (jak tester)

potem zmiana

1 commit = 1 zamknięty poziom funkcjonalny

Odpowiadaj:

krótko

bez dygresji

OK / 1 poprawka