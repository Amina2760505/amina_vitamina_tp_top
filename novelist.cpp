#include "Novelist.h"

Novelist::Novelist() {
    fio = new char[1]; fio[0] = '\0';
    years = new char[1]; years[0] = '\0';
    works = new char[1]; works[0] = '\0';
    bio = new char[1]; bio[0] = '\0';
}

Novelist::Novelist(const char* f, const char* y, const char* w, const char* b) {
    fio = new char[strlen(f) + 1]; strcpy(fio, f);
    years = new char[strlen(y) + 1]; strcpy(years, y);
    works = new char[strlen(w) + 1]; strcpy(works, w);
    bio = new char[strlen(b) + 1]; strcpy(bio, b);
}

Novelist::Novelist(const Novelist& other) {
    fio = new char[strlen(other.fio) + 1]; strcpy(fio, other.fio);
    years = new char[strlen(other.years) + 1]; strcpy(years, other.years);
    works = new char[strlen(other.works) + 1]; strcpy(works, other.works);
    bio = new char[strlen(other.bio) + 1]; strcpy(bio, other.bio);
}

Novelist::~Novelist() {
    delete[] fio;
    delete[] years;
    delete[] works;
    delete[] bio;
}

void Novelist::print() const {
    cout << "[Романист] ФИО: " << fio << " | Годы: " << years << " | Книги: " << works << " | Био: " << bio << endl;
}

void Novelist::save(ostream& out) const {
    out << getType() << endl << fio << endl << years << endl << works << endl << bio << endl;
}

void Novelist::load(istream& in) {
    char buf[1000];
    in >> ws; in.getline(buf, 1000); delete[] fio; fio = new char[strlen(buf) + 1]; strcpy(fio, buf);
    in.getline(buf, 1000); delete[] years; years = new char[strlen(buf) + 1]; strcpy(years, buf);
    in.getline(buf, 1000); delete[] works; works = new char[strlen(buf) + 1]; strcpy(works, buf);
    in.getline(buf, 1000); delete[] bio; bio = new char[strlen(buf) + 1]; strcpy(bio, buf);
}