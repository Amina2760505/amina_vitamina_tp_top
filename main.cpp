#include <iostream>
#include "Keeper.h"
#include "Poet.h"
#include "Novelist.h"
#include "Fantast.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Keeper keeper;
    int choice;

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Добавить Поэта" << endl;
        cout << "2. Добавить Романиста" << endl;
        cout << "3. Добавить Фантаста" << endl;
        cout << "4. Показать всех" << endl;
        cout << "5. Удалить по номеру" << endl;
        cout << "6. Сохранить в файл" << endl;
        cout << "7. Загрузить из файла" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        try {
            if (choice == 1) {
                char f[100], y[100], w[200];
                cout << "Введите ФИО: "; cin >> f;
                cout << "Годы жизни: "; cin >> y;
                cout << "Произведения: "; cin >> w;
                keeper.add(new Poet(f, y, w));
            }
            else if (choice == 2) {
                char f[100], y[100], w[200], b[200];
                cout << "Введите ФИО: "; cin >> f;
                cout << "Годы жизни: "; cin >> y;
                cout << "Произведения: "; cin >> w;
                cout << "Биография: "; cin >> b;
                keeper.add(new Novelist(f, y, w, b));
            }
            else if (choice == 3) {
                char f[100], w[200];
                int m;
                cout << "Введите ФИО: "; cin >> f;
                cout << "Произведения: "; cin >> w;
                cout << "Сняты фильмы? (1-да, 0-нет): "; cin >> m;
                keeper.add(new Fantast(f, w, m == 1));
            }
            else if (choice == 4) {
                keeper.printAll();
            }
            else if (choice == 5) {
                int idx;
                cout << "Номер для удаления: "; cin >> idx;
                keeper.remove(idx - 1); // минус 1, так как нумерация с 1
            }
            else if (choice == 6) {
                keeper.saveToFile("data.txt");
                cout << "Сохранено!" << endl;
            }
            else if (choice == 7) {
                keeper.loadFromFile("data.txt");
                cout << "Загружено!" << endl;
            }
        } 
        catch (const char* msg) {
            cout << "ОШИБКА: " << msg << endl;
        }

    } while (choice != 0);

    return 0;
}