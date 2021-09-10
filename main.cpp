#include <iostream>
#include <fstream>
#include <chrono>

#include "Tipos/Tipos.h"
#include "Utilidades/salida_consola.hpp"
#include "Utilidades/generador.h"
#include "Experimentos/longitud_bloque_baja_var.h"

#include "Algoritmos/fuerza_bruta.h"
#include "Algoritmos/greedy.h"
#include "Algoritmos/backtracking.h"
#include "Algoritmos/backtracking_naif.h"
#include "Algoritmos/dinamica.h"

std::ostream& operator << (std::ostream& os, const Problema& p) {
    os << "Problema [";
    for (auto i = p.second.begin(); i != p.second.end(); ++i)
        os << " " << *i;
    os << " ]" << " contagio: " << p.first;
    return os;
}

int main() {

    Locales PROB = { {9, 56}, {34, 0}, {149, 46}, {69, 13}, {46, 54}, {2, 135}, {97, 227}, {132, 4}, {3, 21}, {12, 60}, {12, 24}, {72, 158}, {72, 3}, {65, 45}, {42, 18}, {80, 100}, {160, 175}, {45, 74}, {143, 96}, {98, 147}, {8, 187}, {154, 86}, {129, 82}, {156, 43}, {112, 4}, {3, 194}, {3, 58}, {54, 112}, {15, 28}, {41, 108}, {57, 42}, {17, 56}, {24, 7}, {32, 82}, {3, 42}, {15, 28}, {152, 73}, {130, 15}, {37, 21}, {85, 52}, {116, 59}, {222, 9}, {199, 139}, {27, 26}, {62, 20}, {36, 9}, {16, 55}, {2, 15}, {114, 100}, {85, 143} };

    int PROB_M = 928;

    //resolver_fb(PROB, PROB_M);
    //resolver_bck(PROB, PROB_M);
    //resolver_bck_n(PROB, PROB_M);
    //resolver_dp(PROB, PROB_M);

    int n = 200;
    float mean = 50;
    float sd = 10;
    float diff = 1;

    auto P = generador::generar_problemas(n, 1000, mean, sd, diff);

    //experimentos::peor_caso_dp(4000);
    experimentos::longitud_bloque_baja_var(100);

    for (auto p : P) {
        int M = p.first;
        auto L = p.second;
        std::cout << p << std::endl;
        //int fb = resolver_fb(L, M, true);
        //int greed = resolver_greedy(L, M, true);
        //int bck = resolver_bck(L, M, false, 0, true);
        //int bck_n = resolver_bck_n(L, M, true);
        //int dp = resolver_dp(L, M, true);
        std::cout << std::endl;
    }

    return 0;
}
