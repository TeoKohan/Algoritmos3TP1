#include "backtracking.h"
#include <cmath>
namespace backtracking {

    namespace {

        const int INFINITO = INT_MAX;

        int inf;
        std::vector<int> sup;

        std::vector<int> cota_superior (const Locales& L, int largo_bloque) {

            int n = L.size();
            int k = largo_bloque;
            auto patrones = configuraciones::configuraciones_maximas(k);
            std::vector<int> A(n+1, 0);
            for (int i = n; i >= 0; --i) {
                int m = 0;
                for (auto p : patrones)
                    m = std::max(m, helper::producto_interno(L, i, std::min(i+k, n), p).beneficio);
                A[i] = m + (i+k >= n ? 0 : A[i+k]);
            }
            return A;
        }

        int mayor_beneficio_R(const Locales& L, int i, beneficio_contagio A) {
            if (A.contagio < 0)
                return -INFINITO;
            if (inf < A.beneficio)
                    inf = A.beneficio;
            if (i >= L.size())
                    return 0;
            if (A.beneficio + sup[i] <= inf)
                return -INFINITO;
            beneficio_contagio T(L[i].beneficio, -L[i].contagio);
            return std::max(L[i].beneficio + mayor_beneficio_R(L, i+2, A + T), mayor_beneficio_R(L, i+1, A));
        }
    }

    int mayor_beneficio(const Locales& L, int M, std::function<int(int)> largo_bloque) {
        inf = greedy::mayor_beneficio(L, M);
        sup = cota_superior(L, largo_bloque(L.size()));
        mayor_beneficio_R(L, 0, {0, M});
        return inf;
    }
}
