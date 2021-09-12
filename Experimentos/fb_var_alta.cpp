#include "experimentos.h"

namespace experimentos {
    bool fb_var_alta (int n) {
        std::ofstream fbvalta;
        fbvalta.open ("Output/fb_var_alta.csv");
        long long int t;
        int res;
        for (int longitud = 1; longitud <= n; ++longitud) {
            fbvalta << longitud;
            auto P = generador::generar_problema(longitud, 50, 100, 2, 731642);

            int samples = 1;
            long long int t_sum = 0;
            for (int i = 0; i < samples; ++i) {
                solver::resolver_bf(P, res, t);
                t_sum += t;
            }
            fbvalta << ", " << t_sum / samples;
            fbvalta << std::endl;
        }
        fbvalta.close();
        return true;
    }
}
