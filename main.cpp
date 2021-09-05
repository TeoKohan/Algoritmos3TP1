#include <iostream>
#include <fstream>
#include <chrono>

#include "Tipos/Tipos.h"
#include "Utilidades/salida_consola.hpp"

#include "Algoritmos/fuerza_bruta.h"
#include "Algoritmos/backtracking.h"

int main() {
    int M = 45;

    Local D;
    beneficio_contagio C = {1, 2};

    Locales L = {{50, 10}, {25, 10}, {10, 20}, {20, 30}, {15, 20}, {50, 10}};

    std::vector<bool> A = {1, 0, 1, 1, 0, 1, 0, 1};
    std::vector<bool> B = {0, 1, 0, 1, 0, 1, 0, 0};

    int n = L.size();
    std::vector<bool> V(n);
    std::cout << fuerza_bruta::mayor_beneficio(L, n, M, V) << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    auto cotas_golosas = backtracking::cota_golosa(L, 0, n, M);
    std::cout << cotas_golosas << std::endl;

    return 0;
}
