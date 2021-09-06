#ifndef BCKTRCK_NPM
#define BCKTRCK_NPM

#include <iostream>

#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

#include "../Utilidades/salida_consola.hpp"
#include "../Tipos/Tipos.h"
#include "configuraciones.h"

namespace backtracking {

    std::vector<std::set<std::vector<bool>>> tablas(int n);
    beneficio_contagio cota_inferior (const Locales& L, int i, int j, int M);
    std::vector<beneficio_contagio> cota_superior (const Locales& L, int i, int j, int M);
    int mayor_beneficio(const Locales& L, int n, int M);
    int mayor_beneficio_R(const Locales& L, int i, int M, beneficio_contagio A);
}

#endif
