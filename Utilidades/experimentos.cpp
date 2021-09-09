#include "experimentos.h"

namespace experimentos {

    namespace {

    void resolver_dp(Problema& P, int& res, int& tiempo) {
        auto start = std::chrono::high_resolution_clock::now();
        res = dinamica::mayor_beneficio(P.second, P.first);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
        tiempo = duration.count();

        return;
    }

    }

    bool peor_caso_dp(int n) {
        std::ofstream dp_p;
        dp_p.open ("Output/dp_peor_caso.csv");
        int res, t, porcentaje = 0;
        dp_p << "n, tiempo" << std::endl;
        for (int i = 1; i <= n; ++i) {
            auto P = generador::dp_peor_caso(i);
            resolver_dp(P, res, t);
            dp_p << i << ", " << t << std::endl;
            if (i*100/n > porcentaje) {
                porcentaje = i*100/n;
                std::cout << porcentaje << '%';
            }
        }
        dp_p.close();
        return true;
    }

    bool mejor_caso_dp(int n) {
        std::ofstream dp_p;
        dp_p.open ("Output/dp_peor_caso.csv");
        int res, t, porcentaje = 0;
        dp_p << "n, tiempo" << std::endl;
        for (int i = 1; i <= n; ++i) {
            auto P = generador::dp_peor_caso(i);
            resolver_dp(P, res, t);
            dp_p << i << ", " << t << std::endl;
            if (i*100/n > porcentaje) {
                porcentaje = i*100/n;
                std::cout << porcentaje << '%';
            }
        }
        dp_p.close();
        return true;
    }
}
