#ifndef BCKTRCK_NPM
#define BCKTRCK_NPM

#include <iostream>

#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

#include "../Tipos/Tipos.h"
#include "configuraciones.h"


const int MAX_TABLA = 10;

namespace backtracking {

    std::vector<std::set<std::vector<bool>>> tablas(int n);
    beneficio_contagio cota_golosa (const Locales& L, int i, int j, int M);
    int mayor_beneficio_n(const Locales& L, int i, int M);
}

#endif
