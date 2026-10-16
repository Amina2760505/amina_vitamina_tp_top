#include "Poet.h"

Poet::Poet() {
    fio = new char[1]; fio[0] = '\0';
    years = new char[1]; years[0] = '\0';
    works = new char[1]; works[0] = '\0';
}

Poet::Poet(const char* f, const char* y, const char* w) {
    fio = new char[strlen(f) + 1];
    strcpy(fio, f);
    years = new char[strlen(y) + 1];
    strcpy(years, y);
    works = new char[strlen(w) + 1];
    strcpy(works, w);
}

Poet::Poet(const Poet& other) {
    fio = new char[strlen(other.fio) + 1];
    strcpy(fio, other.fio);
    years = new char[strlen(other.years) + 1];
    strcpy(years, other.years);
    works = new char[strlen(other.works) + 1];
    strcpy(works, other.works);
}

Poet::~Poet() {
    delete[] fio;
    delete[] years;
    delete[] works;
}

void Poet::print() const {
    cout << "[Поэт] ФИО: " << fio << " | Годы жизни: " << years << " | Произведения: " << works << endl;
}

void Poet::save(ostream& out) const {
    out << getType() << endl;
    out << fio << endl;
    out << years << endl;
    out << works << endl;
}

void Poet::load(istream& in) {
    char buf[1000];
    in >> ws; // пропускаем пробелы
    in.getline(buf, 1000);
    delete[] fio;
    fio = new char[strlen(buf) + 1]; strcpy(fio, buf);
    
    in.getline(buf, 1000);
    delete[] years;
    years = new char[strlen(buf) + 1]; strcpy(years, buf);
    
    in.getline(buf, 1000);
    delete[] works;
    works = new char[strlen(buf) + 1]; strcpy(works, buf);
}

void Poet::setFio(const char* f) {
    delete[] fio;
    fio = new char[strlen(f) + 1];
    strcpy(fio, f);
}

char* Poet::getFio() const {
    return fio;
}