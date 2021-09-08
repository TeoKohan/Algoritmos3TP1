#include "backtracking_naif.h"

namespace backtracking_naif {

    int inf;
    int c;

    namespace {
        int cota_inferior (const Locales& L, int i, int j, int M) {
            std::vector<std::pair<int, Local>> L_prima(j-i);

            int k;
            for (k = i; k < j; ++k)
                L_prima[k] = {k, L[k]};

            std::sort(L_prima.begin(), L_prima.end(),
                [](const std::pair<int, Local>& a, const std::pair<int, Local>& b) {
                    if ((float)a.second.beneficio/a.second.contagio > (float)b.second.beneficio/b.second.contagio)
                        return true;
                    return false;
                }
            );

            beneficio_contagio s = {0, 0};

            std::set<int> usados;

            k = i;
            while (k < j) {
                if (s.contagio + L_prima[k].second.contagio <= M && !usados.count(L_prima[k].first-1) && !usados.count(L_prima[k].first+1)) {
                    s += L_prima[k].second;
                    usados.insert(L_prima[k].first);
                }
                k++;
            }

            return s.beneficio;
        }

        int cota_superior (const Locales& L, int i) {
            int S = 0;
            for (; i < L.size(); ++i)
                S += L[i].beneficio;
            return S;
        }

        int mayor_beneficio_R(const Locales& L, int i, beneficio_contagio A) {
            c++;
            if (A.contagio < 0)
                return -INFINITO;
            if (inf < A.beneficio)
                    inf = A.beneficio;
            if (i >= L.size())
                return 0;
            if (A.beneficio + cota_superior(L, i) < inf)
                return -INFINITO;
            beneficio_contagio T(L[i].beneficio, -L[i].contagio);
            return std::max(L[i].beneficio + mayor_beneficio_R(L, i+2, A+T), mayor_beneficio_R(L, i+1, A));
        }
    }

    int mayor_beneficio(const Locales& L, int M) {
        inf = greedy::mayor_beneficio(L, M);
        c = 0;
        mayor_beneficio_R(L, 0, {0, M});
        //std::cout << "llamados N: " << c << std::endl;
        return inf;
    }
}
