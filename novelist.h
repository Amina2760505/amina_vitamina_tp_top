#ifndef NOVELIST_H
#define NOVELIST_H
#include "Base.h"

class Novelist : public Base {
private:
    char* fio;
    char* years;
    char* works;
    char* bio;

public:
    Novelist();
    Novelist(const char* f, const char* y, const char* w, const char* b);
    Novelist(const Novelist& other);
    ~Novelist();

    void print() const override;
    void save(ostream& out) const override;
    void load(istream& in) override;
    int getType() const override { return 2; } // 2 - Романист
};

#endif