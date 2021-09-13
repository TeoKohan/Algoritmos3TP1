#include "experimentos.h"

namespace experimentos {
    bool bck_podas (int n) {

        std::ofstream bckpodas;
        bckpodas.open ("Output/bck_podas.csv");
        long long int t;
        int res;
        bckpodas << "n, t ambas podas, t sin factibilidad, t sin optimalidad" << std::endl;
        for (int longitud = 1; longitud <= n; ++longitud) {

            auto P = generador::generar_problema(longitud, 50, 5, 2, 364184);
            bckpodas << longitud;

            int samples = 5;
            long long int t_sum = 0;
            for (int i = 0; i < samples; ++i) {
                solver::resolver_bck(P, res, t);
                t_sum += t;
            }
            std::cout << "con ambas " << res << " ";
            bckpodas << ", " << t_sum / samples;
            t_sum = 0;
            for (int i = 0; i < samples; ++i) {
                solver::resolver_bck_sin_factibilidad(P, res, t);
                t_sum += t;
            }
            std::cout << "sin facti " << res << " ";
            bckpodas << ", " << t_sum / samples;
            t_sum = 0;
            for (int i = 0; i < samples; ++i) {
                solver::resolver_bck_sin_optimalidad(P, res, t);
                t_sum += t;
            }
            std::cout << "sin opti " << res << std::endl;
            bckpodas << ", " << t_sum / samples;
            bckpodas << std::endl;
        }
        bckpodas.close();
        return true;
    }
}
