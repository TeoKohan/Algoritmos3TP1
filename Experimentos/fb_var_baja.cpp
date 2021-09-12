#include "experimentos.h"

namespace experimentos {
    bool fb_var_baja (int n) {
        std::ofstream fbvbaja;
        fbvbaja.open ("Output/fb_var_baja.csv");
        long long int t;
        int res;
        for (int longitud = 1; longitud <= n; ++longitud) {
            fbvbaja << longitud;
            auto P = generador::generar_problema(longitud, 50, 1, 2, 731642);

            int samples = 1;
            long long int t_sum = 0;
            for (int i = 0; i < samples; ++i) {
                solver::resolver_bf(P, res, t);
                t_sum += t;
            }
            fbvbaja << ", " << t_sum / samples;
            fbvbaja << std::endl;
        }
        fbvbaja.close();
        return true;
    }
}
