#include "Keeper.h"
#include "Poet.h"
#include "Novelist.h"
#include "Fantast.h"
#include <fstream>

Keeper::Keeper() {
    items = nullptr;
    count = 0;
}

Keeper::~Keeper() {
    for (int i = 0; i < count; i++) {
        delete items[i];
    }
    delete[] items;
}

void Keeper::add(Base* obj) {
    Base** newArr = new Base*[count + 1];
    for (int i = 0; i < count; i++) {
        newArr[i] = items[i];
    }
    newArr[count] = obj;
    delete[] items;
    items = newArr;
    count++;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= count) {
        throw "Неверный индекс для удаления!"; // исключение
    }
    delete items[index];
    for (int i = index; i < count - 1; i++) {
        items[i] = items[i + 1];
    }
    count--;
}

void Keeper::printAll() const {
    if (count == 0) {
        cout << "Список пуст!" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". ";
        items[i]->print();
    }
}

void Keeper::saveToFile(const char* filename) const {
    ofstream out(filename);
    if (!out) throw "Ошибка открытия файла для записи!";
    out << count << endl;
    for (int i = 0; i < count; i++) {
        items[i]->save(out);
    }
    out.close();
}

void Keeper::loadFromFile(const char* filename) {
    ifstream in(filename);
    if (!in) throw "Ошибка открытия файла для чтения!";
    
    // Очищаем старые данные
    for (int i = 0; i < count; i++) delete items[i];
    delete[] items;
    count = 0;
    items = nullptr;

    int newCount;
    in >> newCount;
    
    for (int i = 0; i < newCount; i++) {
        int type;
        in >> type;
        Base* obj = nullptr;
        if (type == 1) obj = new Poet();
        else if (type == 2) obj = new Novelist();
        else if (type == 3) obj = new Fantast();
        
        if (obj) {
            obj->load(in);
            add(obj);
        }
    }
    in.close();
}