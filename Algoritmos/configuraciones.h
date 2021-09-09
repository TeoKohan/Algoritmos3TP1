#ifndef CONF_NPM
#define CONF_NPM
#include <iostream>
#include <set>
#include <vector>
#include "../Tipos/tipos.h"
#include "../Utilidades/helper.h"
#include "../Algoritmos/fuerza_bruta.h"
#include "../Utilidades/salida_consola.hpp"

namespace configuraciones {
    std::vector<std::set<std::vector<bool>>> llenar_tablas(int n);
    std::set<std::vector<bool>> configuraciones_maximas(int n);
}

#endif
