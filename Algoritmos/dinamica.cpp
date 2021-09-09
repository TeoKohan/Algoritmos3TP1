#include "dinamica.h"

namespace dinamica {

    const int BOTTOM = -1;
    const int INFINITO = INT_MAX;

    namespace {

        int mayor_beneficio_R(const Locales& L, std::vector<std::vector<int>>& D, int n, int M) {
            if (M < 0)
                return -INFINITO;
            if (n < 0)
                return 0;
            if (D[n][M] == BOTTOM)
                D[n][M] = std::max(L[n].beneficio + mayor_beneficio_R(L, D, n-2, M-L[n].contagio), mayor_beneficio_R(L, D, n-1, M));

            return D[n][M];
        }
    }

    int mayor_beneficio (const Locales& L, int M) {
        int n = L.size();
        std::vector<std::vector<int>> D(n+1, std::vector<int>(M+1, BOTTOM));
        return mayor_beneficio_R(L, D, n-1, M);
    }
}
