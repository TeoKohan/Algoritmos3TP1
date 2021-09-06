#include "generador.h"

namespace generador {

    Problema generar_problema(int n, float densidad, float varianza, float dificultad, int seed) {
        std::mt19937 gen{seed};

        // values near the mean are the most likely
        // standard deviation affects the dispersion of generated values from the mean
        std::normal_distribution<> beneficio{densidad, varianza};
        std::normal_distribution<> costo{densidad, varianza};
        std::normal_distribution<> M{densidad * n / (dificultad*dificultad), varianza};

        std::vector<Local> L;

        for (int i = 0; i < n; ++i)
            L.push_back({std::abs(beneficio(gen)), std::abs(costo(gen))});

        return {std::abs(M(gen)), L};
    }

    std::vector<Problema> generar_problemas (int n, int N, float densidad, float varianza, float dificultad) {
        std::random_device rd{};
        std::uniform_int_distribution<int> seed(0, 1024);
        std::vector<Problema>  P(N);
        for (int i = 0; i < N; ++i)
            P[i] = generar_problema(n, densidad, varianza, dificultad, seed(rd));
        return P;
    }
}
