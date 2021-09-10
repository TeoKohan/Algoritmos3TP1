#include "solver.h"

namespace solver {

    void resolver_bf(Problema& P, int& res, long long int& tiempo) {
        auto start = std::chrono::steady_clock::now();
        std::vector<bool> V(P.second.size());
        res = fuerza_bruta::mayor_beneficio(P.second, 0, P.first, V);
        auto stop = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
        tiempo = duration.count();

        return;
    }

    void resolver_bck_n(Problema& P, int& res, long long int& tiempo) {
        auto start = std::chrono::steady_clock::now();
        res = backtracking_naif::mayor_beneficio(P.second, P.first);
        auto stop = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
        tiempo = duration.count();

        return;
    }

    void resolver_bck(Problema& P, int& res, long long int& tiempo, std::function<int(int)> block_size) {
        auto start = std::chrono::steady_clock::now();
        res = backtracking::mayor_beneficio(P.second, P.first, block_size);
        auto stop = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
        tiempo = duration.count();

        return;
    }


    void resolver_dp(Problema& P, int& res, long long int& tiempo) {
        auto start = std::chrono::steady_clock::now();
        res = dinamica::mayor_beneficio(P.second, P.first);
        auto stop = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);
        tiempo = duration.count();

        return;
    }
}
