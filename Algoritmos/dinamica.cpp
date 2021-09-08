#include "dinamica.h"

namespace dinamica {

    const int BOTTOM = -1;

    namespace {

        int mayor_beneficio_R(const Locales& L, std::vector<std::vector<int>>& O, int n, int M) {
            if (M < 0)
                return -INFINITO;
            if (n < 0)
                return 0;
            if (O[n][M] == BOTTOM) {
                O[n][M] = std::max(L[n].beneficio + mayor_beneficio_R(L, O, n-2, M-L[n].contagio), mayor_beneficio_R(L, O, n-1, M));
            }
            return O[n][M];
        }

    }


    int mayor_beneficio (const Locales& L, int M) {
        int n = L.size();
        std::vector<std::vector<int>> O(n+1, std::vector<int>(M+1, BOTTOM));
        return mayor_beneficio_R(L, O, n-1, M);
    }
}
