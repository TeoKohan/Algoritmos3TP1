#include "local.h"

beneficio_contagio::beneficio_contagio() {
    this->beneficio = 0;
    this->contagio = 0;
}

beneficio_contagio::beneficio_contagio(int beneficio, int contagio) {
    this->beneficio = beneficio;
    this->contagio = contagio;
}

bool beneficio_contagio :: operator < (const beneficio_contagio& rhs) {
    if (this->beneficio < rhs.beneficio)
        return true;
    else if (this->beneficio == rhs.beneficio && this->contagio > rhs.contagio)
        return true;
    return false;
}

bool operator < (const beneficio_contagio& lhs, const beneficio_contagio& rhs) {
    return lhs < rhs;
}

beneficio_contagio& beneficio_contagio :: operator += (const beneficio_contagio& rhs) {
    this->beneficio += rhs.beneficio;
    this->contagio += rhs.contagio;
    return *this;
}

beneficio_contagio beneficio_contagio :: operator + (const beneficio_contagio& rhs) {
    beneficio_contagio res = {this->beneficio + rhs.beneficio, this->contagio + rhs.contagio};
    return res;
}

beneficio_contagio& beneficio_contagio :: operator -= (const beneficio_contagio& rhs) {
    this->beneficio -= rhs.beneficio;
    this->contagio -= rhs.contagio;
    return *this;
}

beneficio_contagio beneficio_contagio :: operator - (const beneficio_contagio& rhs) {
    beneficio_contagio res = {this->beneficio - rhs.beneficio, this->contagio - rhs.contagio};
    return res;
}

beneficio_contagio operator * (const beneficio_contagio& lhs, int rhs) {
    beneficio_contagio res = {lhs.beneficio * rhs, lhs.contagio * rhs};
    return res;
}

std::ostream& operator << (std::ostream& os, const beneficio_contagio& rhs) {
    os << '(' << "b: " << rhs.beneficio << ", c: " << rhs.contagio << ')';
    return os;
}

/*
beneficio_contagio::beneficio_contagio operator * (const vector<beneficio_contagio>& a, const vector<bool>& b) {
    beneficio_contagio s = {0, 0};
    for (int i = 0; i < a.size(); ++i)
        s += a[i] * b[i];
    return s;
}

beneficio_contagio::vector<beneficio_contagio> operator * (const vector<beneficio_contagio>& a, const vector<vector<bool>>& b) {
    vector<beneficio_contagio>  s;
    for (int i = 0; i < a.size(); ++i)
        s.push_back(a * b[i]);
    return s;
}*/
