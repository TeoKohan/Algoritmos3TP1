#ifndef GEN_NPM
#define GEN_NPM

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <stdlib.h>

#include "../Tipos/Tipos.h"

namespace generador {

    Problema generar_problema(int n, float densidad, float varianza, float dificultad, std::random_device rd);
    std::vector<Problema> generar_problemas (int n, int N, float densidad, float varianza, float dificultad);
    Problema creciente(int n, float p = 0.5);
    Problema uniforme(int n, int v = 1);
}

#endif
