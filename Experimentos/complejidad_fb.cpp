#include "experimentos.h"

namespace experimentos {

    bool peor_caso_dp(int n) {
        std::ofstream dp_p;
        dp_p.open ("Output/dp_peor_caso.csv");
        int res, porcentaje = 0;
        long long int t;
        dp_p << "n, tiempo" << std::endl;
        for (int i = 1; i <= n; ++i) {
            auto P = generador::uniforme(i);
            solver::resolver_dp(P, res, t);
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
