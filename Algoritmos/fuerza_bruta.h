#ifndef BF_NPM
#define BF_NPM

#include <vector>
#include "../Tipos/Tipos.h"

namespace fuerza_bruta {

    int espacio(const std::vector<bool>& V);

    bool adyacentes(const std::vector<bool>& V);

    int mayor_beneficio(const Locales& L, int i, int M, std::vector<bool>& V);
}

#endif
