#ifndef KEEPER_H
#define KEEPER_H
#include "Base.h"

class Keeper {
private:
    Base** items; // Массив указателей на базовый класс
    int count;

public:
    Keeper();
    ~Keeper();

    void add(Base* obj);
    void remove(int index);
    void printAll() const;
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
    int getCount() const { return count; }
};

#endif