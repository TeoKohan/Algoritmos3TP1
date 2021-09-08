#ifndef BCKTRCK_NAIF_NPM
#define BCKTRCK_NAIF_NPM

#include <iostream>

#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

#include "../Utilidades/salida_consola.hpp"
#include "../Tipos/Tipos.h"
#include "greedy.h"

namespace backtracking_naif {
    int mayor_beneficio(const Locales& L, int M);
}

#endif
