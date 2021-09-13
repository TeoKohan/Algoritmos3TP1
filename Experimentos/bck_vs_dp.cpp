#include "experimentos.h"

namespace experimentos {
    bool bck_vs_dp (int n) {

        int longitud = 35;

        std::ofstream bckvsdp;
        bckvsdp.open ("Output/bck_vs_dp.csv");
        long long int t;
        int res;
        for (int dificultad = 1; dificultad <= n; ++dificultad) {

            auto P = generador::bck_vs_dp_caso(longitud, dificultad*100);
            bckvsdp << P.first;

            int samples = 5;
            long long int t_sum = 0;
            for (int i = 0; i < samples; ++i) {
                solver::resolver_bck(P, res, t);
                t_sum += t;
            }
            bckvsdp << ", " << t_sum / samples;
            t_sum = 0;
            for (int i = 0; i < samples; ++i) {
                solver::resolver_dp(P, res, t);
                t_sum += t;
            }
            bckvsdp << ", " << t_sum / samples;
            bckvsdp << std::endl;
        }
        bckvsdp.close();
        return true;
    }
}
