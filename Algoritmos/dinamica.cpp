#include "dinamica.h"

namespace dinamica {

    const int BOTTOM = -1;

    namespace {

        int mayor_beneficio_R(const Locales& L, int i, int M) {
            return 0;
        }

    }


    int mayor_beneficio (const Locales& L, int M) {
        int n = L.size();
        int O[n][M];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < M; ++i)
                O[i][j] = BOTTOM;

        mayor_beneficio_R(L, n, M);
    }
}
