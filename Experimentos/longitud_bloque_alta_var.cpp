#include "longitud_bloque_baja_var.h"

namespace experimentos {

    bool longitud_bloque_alta_var (int n) {
        std::ofstream bck;
        bck.open ("Output/bck_longitud_bloque_alta_varianza.csv");
        long long int t;
        int res;
        bck << "n";
        for (int i = 1; i <= n; ++i)
            bck << ", " << i;
        bck << std::endl;
        for (int longitud = 1; longitud <= n; ++longitud) {
            bck << longitud;
            auto P = generador::generar_problema(longitud, 50, 50, 1, 731642);

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
                    bck << ", " << t_sum / samples;
            }
            bck << std::endl;
            std::cout << "longitud " << longitud << " bck: " << res << "  -  dp: " << dinamica::mayor_beneficio(P.second, P.first) << std::endl;
        }
        bck.close();
        return true;
    }
}
