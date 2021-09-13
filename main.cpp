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

#include "Experimentos/fb_var_baja.h"
#include "Experimentos/fb_var_alta.h"
#include "Experimentos/bck_vs_dp.h"
#include "Experimentos/dp_vs_bck.h"
#include "Experimentos/longitud_bloque_baja_var.h"
#include "Experimentos/longitud_bloque_alta_var.h"

std::ostream& operator << (std::ostream& os, const Problema& p) {
    os << "Problema [";
    for (auto i = p.second.begin(); i != p.second.end(); ++i)
        os << " " << *i;
    os << " ]" << " contagio: " << p.first;
    return os;
}

int main() {

//    fstream input;
//	input.open("my_file", ios::out);
//	if (!input) {
//		cout << "File not created!";
//	}
//	else {
//		cout << "File created successfully!";
//		input.close();
//	}
//	return 0;

    //resolver_fb(PROB, PROB_M);
    //resolver_bck(PROB, PROB_M);
    //resolver_bck_n(PROB, PROB_M);
    //resolver_dp(PROB, PROB_M);

    int n = 100;
    float mean = 1;
    float sd = 0;
    float diff = 0.001;

    auto P = generador::generar_problemas(n, 1000, mean, sd, diff);

    //experimentos::peor_caso_dp(4000);
    //experimentos::longitud_bloque_baja_var(100);
    //experimentos::longitud_bloque_alta_var(100);
    //experimentos::fb_var_baja(30);
    //experimentos::fb_var_alta(30);
    experimentos::bck_vs_dp(1000);
    experimentos::dp_vs_bck(100);

    int r;
    long long int t;

    for (auto p : P) {
        int M = p.first;
        auto L = p.second;
        //std::cout << p << std::endl;
        //int fb = resolver_fb(L, M, true);
        //int greed = resolver_greedy(L, M, true);
        Problema Prob(M, L);
        solver::resolver_bck(Prob, r, t);
        //int bck_n = resolver_bck_n(L, M, true);
        //int dp = resolver_dp(L, M, true);
        std::cout << std::endl;
    }

    return 0;
}
