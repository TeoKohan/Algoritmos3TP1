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
#include "greedy.h"

namespace backtracking {
    namespace {
        int default_blocksize(int n) {
            return std::max(2, helper::sqrt(n));
        }
    }
    int mayor_beneficio(const Locales& L, int M, std::function<int(int)> = default_blocksize);
}

#endif
