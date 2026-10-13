#include "Fantast.h"

Fantast::Fantast() {
    fio = new char[1]; fio[0] = '\0';
    works = new char[1]; works[0] = '\0';
    hasMovie = false;
}

Fantast::Fantast(const char* f, const char* w, bool m) {
    fio = new char[strlen(f) + 1]; strcpy(fio, f);
    works = new char[strlen(w) + 1]; strcpy(works, w);
    hasMovie = m;
}

Fantast::Fantast(const Fantast& other) {
    fio = new char[strlen(other.fio) + 1]; strcpy(fio, other.fio);
    works = new char[strlen(other.works) + 1]; strcpy(works, other.works);
    hasMovie = other.hasMovie;
}

Fantast::~Fantast() {
    delete[] fio;
    delete[] works;
}

void Fantast::print() const {
    cout << "[Фантаст] ФИО: " << fio << " | Книги: " << works << " | Фильмы сняты: " << (hasMovie ? "Да" : "Нет") << endl;
}

void Fantast::save(ostream& out) const {
    out << getType() << endl << fio << endl << works << endl << hasMovie << endl;
}

void Fantast::load(istream& in) {
    char buf[1000];
    in >> ws; in.getline(buf, 1000); delete[] fio; fio = new char[strlen(buf) + 1]; strcpy(fio, buf);
    in.getline(buf, 1000); delete[] works; works = new char[strlen(buf) + 1]; strcpy(works, buf);
    in >> hasMovie;
}