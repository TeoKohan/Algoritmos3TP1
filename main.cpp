#include <iostream>
#include <fstream>
#include <chrono>

#include "Tipos/Tipos.h"
#include "Utilidades/salida_consola.hpp"
#include "Utilidades/generador.h"

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

std::set<std::vector<bool>> resolver_max(int n, bool log = true) {
    auto start = std::chrono::high_resolution_clock::now();
    auto res = configuraciones::configuraciones_maximas(n);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    int duration_int = duration.count();

    if (log)
    std::cout << "la duracion de MAXIM es " << duration_int << " con un resultado de " << res.size() << std::endl;
    return res;
}

int resolver_fb(Locales L, int M, bool log = true) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<bool> V(L.size());
    int res = fuerza_bruta::mayor_beneficio(L, 0, M, V);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    int duration_int = duration.count();

    if (log)
    std::cout << "la duracion de FB    es " << duration_int << " con un resultado de " << res << std::endl;
    return res;
}

int resolver_greedy(Locales L, int M, bool log = true) {
    auto start = std::chrono::high_resolution_clock::now();
    int res = greedy::mayor_beneficio(L, M);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    int duration_int = duration.count();

    if (log)
    std::cout << "la duracion de GREED es " << duration_int << " con un resultado de " << res << std::endl;
    return res;
}

int resolver_bck(Locales L, int M, bool cota, int k, bool log = true) {
    auto start = std::chrono::high_resolution_clock::now();
    int res = backtracking::mayor_beneficio(L, M, cota, k);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    int duration_int = duration.count();

    if (log)
    std::cout << "la duracion de BCK   es " << duration_int << " con un resultado de " << res << std::endl;
    return res;
}

int resolver_bck_n(Locales L, int M, bool log = true) {
    auto start = std::chrono::high_resolution_clock::now();
    int res = backtracking_naif::mayor_beneficio(L, M);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    int duration_int = duration.count();

    if (log)
    std::cout << "la duracion de BCK_N es " << duration_int << " con un resultado de " << res << std::endl;
    return res;
}

int resolver_dp(Locales L, int M, bool log = true) {
    auto start = std::chrono::high_resolution_clock::now();
    int res = dinamica::mayor_beneficio(L, M);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    int duration_int = duration.count();

    if (log)
    std::cout << "la duracion de DP    es " << duration_int << " con un resultado de " << res << std::endl;
    return res;
}

int main() {

    Locales PROB = { {9, 56}, {34, 0}, {149, 46}, {69, 13}, {46, 54}, {2, 135}, {97, 227}, {132, 4}, {3, 21}, {12, 60}, {12, 24}, {72, 158}, {72, 3}, {65, 45}, {42, 18}, {80, 100}, {160, 175}, {45, 74}, {143, 96}, {98, 147}, {8, 187}, {154, 86}, {129, 82}, {156, 43}, {112, 4}, {3, 194}, {3, 58}, {54, 112}, {15, 28}, {41, 108}, {57, 42}, {17, 56}, {24, 7}, {32, 82}, {3, 42}, {15, 28}, {152, 73}, {130, 15}, {37, 21}, {85, 52}, {116, 59}, {222, 9}, {199, 139}, {27, 26}, {62, 20}, {36, 9}, {16, 55}, {2, 15}, {114, 100}, {85, 143} };

    int PROB_M = 928;

    //resolver_fb(PROB, PROB_M);
    //resolver_bck(PROB, PROB_M);
    //resolver_bck_n(PROB, PROB_M);
    //resolver_dp(PROB, PROB_M);

    int n = 30;
    float mean = 15;
    float sd = 10;
    float diff = 2;
    auto P = generador::generar_problemas(n, 1000, mean, sd, diff);

    for (auto p : P) {
        int M = p.first;
        auto L = p.second;
        std::cout << p << std::endl;
        //int fb = resolver_fb(L, M, true);
        //int greed = resolver_greedy(L, M, true);
        int bck1 = resolver_bck(L, M, true, 1, true);
        int bck2 = resolver_bck(L, M, true, 3, true);
        int bck3 = resolver_bck(L, M, true, 5, true);
        int bck4 = resolver_bck(L, M, false, 0, true);
        //int bck_n = resolver_bck_n(L, M, true);
        int dp = resolver_dp(L, M, true);
        std::cout << std::endl;
    }

    return 0;
}
