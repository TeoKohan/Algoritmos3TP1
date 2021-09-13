#include "experimentos.h"

namespace experimentos {
    bool dp_vs_bck (int n) {

        int longitud = 1;

        std::ofstream bckvsdp;
        bckvsdp.open ("Output/dp_vs_bck.csv");
        long long int t;
        int res;
        for (int longitud = 1; longitud <= n; ++longitud) {

            auto P = generador::bck_vs_dp_caso(longitud, longitud*25);
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
