#include "experimentos.h"

namespace experimentos {
    bool fb_var_baja (int n) {
        std::ofstream fbvbaja;
        fbvbaja.open ("Output/fb_var_baja.csv");
        long long int t;
        int res;
        fbvbaja << "n";
        for (int i = 1; i <= n; ++i)
            fbvbaja << ", " << i;
        fbvbaja << std::endl;
        for (int longitud = 1; longitud <= n; ++longitud) {
            fbvbaja << longitud;
            auto P = generador::generar_problema(longitud, 50, 1, 1, 731642);

            int samples = 1;
            for (int bloque = 1; bloque <= longitud; ++bloque) {
                    long long int t_sum = 0;
                    for (int i = 0; i < samples; ++i) {
                        solver::resolver_bck(P, res, t, [bloque](int n) {
                            return bloque;
                        }
                        );
                        t_sum += t;
                    }
                    fbvbaja << ", " << t_sum / samples;
            }
            fbvbaja << std::endl;
        }
        fbvbaja.close();
        return true;
    }
}
