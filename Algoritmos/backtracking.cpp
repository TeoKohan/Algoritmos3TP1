#include "backtracking.h"

namespace backtracking {

    namespace {

        const int INFINITO = INT_MAX;

        int inf;
        std::vector<int> sup;

        std::vector<int> cota_superior (const Locales& L) {
            int n = L.size();
            int k = helper::sqrt(n);
            auto patrones = configuraciones::configuraciones_maximas(k);
            std::vector<int> A = {0};

            for (int i = 0; i < n; i += k) {
                std::vector<beneficio_contagio> bloque(L.begin()+i, L.begin()+std::min(i+k, n));
                int m = 0;
                for (auto p : patrones)
                    m = std::max(m, helper::producto_interno(bloque, p).beneficio);
                A.push_back(*(A.end()-1) + m);
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
            if (A.beneficio + *(sup.end()-1) - sup[i/helper::sqrt(L.size())] < inf)
                return -INFINITO;
            beneficio_contagio T(L[i].beneficio, -L[i].contagio);
            return std::max(L[i].beneficio + mayor_beneficio_R(L, i+2, A + T), mayor_beneficio_R(L, i+1, A));
        }
    }

    int mayor_beneficio(const Locales& L, int M) {
        inf = greedy::mayor_beneficio(L, M);
        sup = cota_superior(L);
        mayor_beneficio_R(L, 0, {0, M});
        return inf;
    }
}
