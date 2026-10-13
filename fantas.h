#ifndef FANTAST_H
#define FANTAST_H
#include "Base.h"

class Fantast : public Base {
private:
    char* fio;
    char* works;
    bool hasMovie; // сняты ли фильмы

public:
    Fantast();
    Fantast(const char* f, const char* w, bool m);
    Fantast(const Fantast& other);
    ~Fantast();

    void print() const override;
    void save(ostream& out) const override;
    void load(istream& in) override;
    int getType() const override { return 3; } // 3 - Фантаст
};

#endif