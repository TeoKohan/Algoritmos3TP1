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
#include "Experimentos/bck_podas.h"
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

    uint n;
    uint M;

    std::ifstream input("Input/Ejemplo.in");
    std::string s;

    input >> n;
    input >> M;
    Locales L(n);
    for (int i = 0; i < n; ++i) {
        int b, c;
        input >> b;
        input >> c;
        Local l(b, c);
        L[i] = l;
    }
    Problema P(M, L);

    int res;
    long long int t;

    solver::resolver_bf(P, res, t);
    std::cout << "El tiempo de fuerza bruta es " << t << " con un resultado de " << res << std::endl;
    solver::resolver_bck(P, res, t);
    std::cout << "El tiempo de backtracking es " << t << " con un resultado de " << res << std::endl;
    solver::resolver_dp(P, res, t);
    std::cout << "El tiempo de dinamica es " << t << " con un resultado de " << res << std::endl;


    //experimentos::peor_caso_dp(4000);
    //experimentos::longitud_bloque_baja_var(100);
    //experimentos::longitud_bloque_alta_var(100);
    //experimentos::fb_var_baja(30);
    //experimentos::fb_var_alta(30);
    //experimentos::bck_vs_dp(1000);
    //experimentos::dp_vs_bck(100);
    experimentos::bck_podas(50);

    return 0;
}
