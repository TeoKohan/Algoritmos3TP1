#ifndef COUT_NPM
#define COUT_NPM

#include <ostream>
#include <set>
#include <vector>
#include "../Tipos/Tipos.h"

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (auto i = v.begin(); i != v.end(); ++i)
        os << " " << *i;
    os << " ]";
    return os;
}

template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& v) {
    os << "[";
    for (auto i = v.begin(); i != v.end(); ++i)
        os << " " << *i;
    os << " ]";
    return os;
}

std::ostream& operator << (std::ostream& os, const Local& local) {
    os << '(' << "b: " << local.beneficio << ", c: " << local.contagio << ')';
    return os;
}

#endif
