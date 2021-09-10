#ifndef EXP_NPM
#define EXP_NPM

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>

#include "../Tipos/Tipos.h"
#include "generador.h"

#include "../Algoritmos/fuerza_bruta.h"
#include "../Algoritmos/greedy.h"
#include "../Algoritmos/backtracking.h"
#include "../Algoritmos/backtracking_naif.h"
#include "../Algoritmos/dinamica.h"

namespace experimentos {
    bool comparacion_bf_bck(int n);
    bool comparacion_bck_dp(int M);
    bool peor_caso_dp(int n);
    bool complejidad_bf(int n);
}

#endif
