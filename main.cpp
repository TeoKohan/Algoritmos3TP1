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

int main() {

    int n = 25;
    float mean = 10;
    float sd = 10;
    float diff = 2;
    auto P = generador::generar_problemas(n, 100, mean, sd, diff);

    /*
    std::vector<Local> malo {
        {26, 2}, {7, 2}, {11, 4}, {1, 19}, {29, 21}
    };
    int M_malo = 23;

    std::cout << malo << "   " << M_malo << std::endl;

    std::vector<bool> V_malo(malo.size());
    std::cout << fuerza_bruta::mayor_beneficio(malo, 0, M_malo, V_malo) << std::endl;
    std::cout << backtracking::mayor_beneficio(malo, n, M_malo) << std::endl;
    int a;
    std::cin >> a;*/



    int fb;
    int fb_r;
    int bck;
    int bck_r;

    for (auto p : P) {
        int M = p.first;
        auto L = p.second;

        auto start = std::chrono::high_resolution_clock::now();
        std::vector<bool> V(L.size());
        fb_r = fuerza_bruta::mayor_beneficio(L, 0, M, V);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
        fb = duration.count();
        auto start_b = std::chrono::high_resolution_clock::now();
        bck_r = backtracking::mayor_beneficio(L, n, M);
        auto stop_b = std::chrono::high_resolution_clock::now();
        auto duration_b = std::chrono::duration_cast<std::chrono::milliseconds>(stop_b-start_b);
        bck = duration_b.count();

        std::cout << p << std::endl;
        std::cout << "la duracion de FB es " << fb << " con un resultado de " << fb_r << std::endl;
        std::cout << "la duracion de BCK es " << bck << " con un resultado de " << bck_r << std::endl;
        std::cout << std::endl << std::endl;
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
