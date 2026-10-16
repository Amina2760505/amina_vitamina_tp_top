#ifndef POET_H
#define POET_H
#include "Base.h"

class Poet : public Base {
private:
    char* fio;
    char* years;
    char* works;

public:
    Poet();
    Poet(const char* f, const char* y, const char* w);
    Poet(const Poet& other); // Конструктор копирования
    ~Poet(); // Деструктор

    void print() const override;
    void save(ostream& out) const override;
    void load(istream& in) override;
    int getType() const override { return 1; } // 1 - Поэт

    // Сеттеры и геттеры (просто для галочки)
    void setFio(const char* f);
    char* getFio() const;
};

#endif