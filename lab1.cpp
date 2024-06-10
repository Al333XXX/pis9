#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

struct Participant {
    string club;
    string city;
    string coach;
    string date;
    double budget;
    int points;
    int place;
};
//fgfhgj//
void inputClub(Participant& club) {
    cout << "Название клуба: ";
    cin.ignore();
    getline(cin, club.club);
    cout << "Год: ";
    getline(cin, club.city);
    cout << "ФИО тренера: ";
    getline(cin, club.coach);
    cout << "Дата основания клуба: ";
    getline(cin, club.date);
    cout << "Бюджет команды в руб.: ";
    cin >> club.budget;
    cout << "Текущее количество очков: ";
    cin >> club.points;
    cout << "Текущее место в чемпионате: ";
    cin >> club.place;
}

void printBestClub(const string& bestClub) {
    cout << "Клуб с самым высоким отношением очков к бюджету: " << bestClub << endl;
}

void printClubsInCity(const vector<Participant>& clubs, const string& selectedCity) {
    cout << "Клубы из города " << selectedCity << ":" << endl;
    for (const Participant& club : clubs) {
        if (club.city == selectedCity) {
            cout << club.club << endl;
        }
    }
}
Participant club;
int main() {
    int n;
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Participant> clubs;

    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Добавить клуб" << endl;
        cout << "2. Найти клуб с лучшим отношением очков к бюджету" << endl;
        cout << "3. Найти клубы по городу" << endl;
        cout << "4. Выход" << endl;

        int choice;
        cout << "Введите номер действия: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Добавление клуба:" << endl;
            inputClub(club);
            clubs.push_back(club);
            break;
        case 2:
            if (clubs.empty()) {
                cout << "Список клубов пуст. Добавьте клубы сначала." << endl;
            }
            else {
                double maxRatio = -1.0;
                string bestClub;

                for (const Participant& club : clubs) {
                    double ratio = static_cast<double>(club.points) / club.budget;
                    if (ratio > maxRatio) {
                        maxRatio = ratio;
                        bestClub = club.club;
                    }
                }

                printBestClub(bestClub);
            }
            break;
        case 3:
            if (clubs.empty()) {
                cout << "Список клубов пуст. Добавьте клубы сначала." << endl;
            }
            else {
                string selectedCity;
                cout << "Введите город для поиска клубов: ";
                cin.ignore();
                getline(cin, selectedCity);
                printClubsInCity(clubs, selectedCity);
            }
            break;
        case 4:
            return 0;
        default:
            cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
            break;
        }
    }

    return 0;
}
