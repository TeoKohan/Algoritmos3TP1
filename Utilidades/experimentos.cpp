#include "experimentos.h"

namespace experimentos {

    namespace {

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

    void resolver_bck(Problema& P, int& res, long long int& tiempo, int B) {
        auto start = std::chrono::steady_clock::now();
        res = backtracking::mayor_beneficio(P.second, P.first, B);
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

    bool complejidad_bf (int n) {
        std::ofstream bf;
        bf.open ("Output/complejidad_fb.csv");
        long long int t;
        int res, porcentaje = 0;
        bf << "n, tiempo_fb, tiempo_esperado" << std::endl;
        for (int i = 1; i <= n; ++i) {
            auto P = generador::uniforme(i, i);
            long long int t_sum = 0;
            int samples = std::max(1, (int)(std::pow(2, 20) / std::pow(2, i)));
            for (int j = 0; j < samples; ++j) {
                resolver_bf(P, res, t);
                t_sum += t / samples;
            }
            bf << i << ", " << t_sum << std::endl;
            if (i*100/n > porcentaje) {
                porcentaje = i*100/n;
                std::cout << porcentaje << '%';
            }
        }
        bf.close();
        return true;
    }

    bool caso_medio_bck (int n) {
        std::ofstream bck;
        bck.open ("Output/bck_tam_bloque.csv");
        long long int t;
        int res, porcentaje = 0;
        bck << "n, tiempo_bck" << std::endl;
        for (int i = 1; i <= n; ++i) {
            auto P = generador::uniforme(i);
            bck << i;
            for (int j = 1; j <= i; ++j) {
                resolver_bck(P, res, t, j);
                bck << ", " << t;
            }
            bck << std::endl;
            std::cout << " bck: " << res << "  -  dp: " << dinamica::mayor_beneficio(P.second, P.first) << std::endl;
            if (i*100/n > porcentaje) {
                porcentaje = i*100/n;
                std::cout << porcentaje << '%' << "   ";
            }
        }
        bck.close();
        return true;
    }

    bool peor_caso_bck (int n) {
        std::ofstream bck;
        bck.open ("Output/peor_caso_bck.csv");
        long long int t;
        int res, porcentaje = 0;
        bck << "n, tiempo_bck" << std::endl;
        for (int i = 2; i <= n; ++i) {
            auto P = generador::uniforme(i, 0);
            long long int t_sum = 0;
            int samples = std::max(2, (int)(std::pow(2, 20) / std::pow(2, i)));

            for (int j = 0; j < samples; ++j) {
                resolver_bck(P, res, t, 0);
                t_sum += t / samples;
            }
            bck << i << ", " << t_sum << std::endl;
            if (i*100/n > porcentaje) {
                porcentaje = i*100/n;
                std::cout << porcentaje << '%';
            }
        }
        bck.close();
        return true;
    }

    bool peor_caso_dp(int n) {
        std::ofstream dp_p;
        dp_p.open ("Output/dp_peor_caso.csv");
        int res, porcentaje = 0;
        long long int t;
        dp_p << "n, tiempo" << std::endl;
        for (int i = 1; i <= n; ++i) {
            auto P = generador::uniforme(i);
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
