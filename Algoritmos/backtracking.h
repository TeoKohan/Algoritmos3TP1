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

namespace backtracking {

    std::vector<std::set<std::vector<bool>>> tablas(int n);
    beneficio_contagio cota_inferior (const Locales& L, int i, int j, int M);
    beneficio_contagio cota_superior (const Locales& L, int i, int j, int M);
    int mayor_beneficio_n(const Locales& L, int i, int M);
}

#endif
