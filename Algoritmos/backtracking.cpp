#include "backtracking.h"

namespace backtracking {

    beneficio_contagio cota_inferior (const Locales& L, int i, int j, int M) {
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

        beneficio_contagio inf = {0, 0};

        std::set<int> usados;

        k = i;
        while (k < j) {
            if (inf.contagio + L_prima[k].second.contagio <= M && !usados.count(L_prima[k].first-1) && !usados.count(L_prima[k].first+1)) {
                inf += L_prima[k].second;
                usados.insert(L_prima[k].first);
            }
            k++;
        }

        return inf;
    }

    beneficio_contagio cota_superior (const Locales& L, int i, int j, int M, std::vector<std::set<std::vector<bool>>>& tablas) {

    }

    int mayor_beneficio(const Locales& L, int n, int M) {
        auto tablas = configuraciones::llenar_tablas(n);


        return 0;
    }

    int mayor_beneficio_n(const Locales& L, int i, int j, int M, beneficio_contagio inf, beneficio_contagio sup) {
        if (M < 0)
            return -INFINITO;
        if (i >= j)
            return 0;
        return std::max(L[j].beneficio + mayor_beneficio(L, i+2, M-L[i].contagio), mayor_beneficio(L, i+1, M));
    }
}
