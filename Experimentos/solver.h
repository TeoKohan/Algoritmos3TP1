#ifndef SOLV_NPM
#define SOLV_NPM

#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>

#include "../Tipos/Tipos.h"
#include "../Utilidades/generador.h"

#include "../Algoritmos/fuerza_bruta.h"
#include "../Algoritmos/greedy.h"
#include "../Algoritmos/backtracking.h"
#include "../Algoritmos/backtracking_naif.h"
#include "../Algoritmos/dinamica.h"

namespace solver {
    void resolver_bf(Problema& P, int& res, long long int& tiempo);
    void resolver_bck_n(Problema& P, int& res, long long int& tiempo);
    void resolver_bck(Problema& P, int& res, long long int& tiempo, std::function<int(int)> block_size);
    void resolver_dp(Problema& P, int& res, long long int& tiempo);
}

#endif
