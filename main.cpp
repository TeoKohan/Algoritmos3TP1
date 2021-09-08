#include <iostream>
#include <fstream>
#include <chrono>

#include "Tipos/Tipos.h"
#include "Utilidades/salida_consola.hpp"
#include "Utilidades/generador.h"

#include "Algoritmos/fuerza_bruta.h"
#include "Algoritmos/backtracking.h"

std::ostream& operator << (std::ostream& os, const Problema& p) {
    os << "Problema [";
    for (auto i = p.second.begin(); i != p.second.end(); ++i)
        os << " " << *i;
    os << " ]" << " contagio: " << p.first;
    return os;
}

int resolver_fb(Locales L, int M, bool log = true) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<bool> V(L.size());
    int res = fuerza_bruta::mayor_beneficio(L, 0, M, V);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    int duration_int = duration.count();

    std::cout << "la duracion de FB  es " << duration_int << " con un resultado de " << res << std::endl;
    return res;
}

int resolver_bck(Locales L, int M, bool log = true) {
    auto start = std::chrono::high_resolution_clock::now();
    int res = backtracking::mayor_beneficio(L, M);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    int duration_int = duration.count();

    std::cout << "la duracion de BCK es " << duration_int << " con un resultado de " << res << std::endl;
    return res;
}

int main() {

    //std::cout

    Locales PROB = { {27, 31}, {21, 10}, {22, 25}, {16, 20}, {14, 26}, {2, 1}, {24, 28}, {6, 0}, {25, 34}, {25, 26}, {22, 12}, {22, 16}, {12, 17}, {19, 6}, {21, 26}, {6, 17}, {25, 18}, {24, 20}, {26, 10}, {30, 14} };
    int PROB_M = 75;

    int n = 5;
    float mean = 20;
    float sd = 10;
    float diff = 1;
    auto P = generador::generar_problemas(n, 1000, mean, sd, diff);

    for (auto p : P) {
        int M = p.first;
        auto L = p.second;
        std::cout << p << std::endl;
        int fb = resolver_fb(L, M);
        int bck = resolver_bck(L, M);
        if (fb != bck)
            std::cin >> fb;
        std::cout << std::endl;
    }

    /*
    int M = 45;

    Locales L = {
        {50, 10}, {25, 10}, {10, 20}, {20, 30}, {15, 20}, {50, 10},
        {10, 20}, {60, 20}, {19, 7}, {23, 91}, {81, 7}, {50, 10},
        {25, 10}, {10, 20}, {20, 30}, {15, 20}, {50, 10}, {10, 20},
        {60, 20}, {19, 7}, {23, 91}, {81, 7}, {19, 7}, {23, 91},
        {23, 91}, {81, 7}, {19, 7}, {23, 91}
        };
    int n = L.size();

    std::cout << backtracking::cota_superior(L, 0, n, M) << std::endl;

    std::vector<bool> V(n);

    int fb;
    std::chrono::milliseconds suma;
    int samples = 1;
    for (int i = 0; i < samples; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        fb = fuerza_bruta::mayor_beneficio(L, 0, M, V);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
        suma += duration;
        std::cout << 'o';
    }
    std::cout << std::endl;
    suma /= samples;
    std::cout << "la duracion promedio de FB es " << suma.count() << " con un resultado de " << fb << std::endl;

    int bcktrck;
    suma = std::chrono::milliseconds(0);
    for (int i = 0; i < samples; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        bcktrck = backtracking::mayor_beneficio(L, n, M);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
        suma += duration;
        std::cout << 'o';
    }
    std::cout << std::endl;
    suma /= samples;
    std::cout << "la duracion promedio de BCKTRCK es " << suma.count() << " con un resultado de " << bcktrck << std::endl;


    auto cotas_golosas = backtracking::cota_inferior(L, 0, n, M);
    //std::cout << cotas_golosas << std::endl;
    */
    return 0;
}
