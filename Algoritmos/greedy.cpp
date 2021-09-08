#include "greedy.h"

namespace greedy {
    int mayor_beneficio (const Locales& L, int M) {
        int n = L.size();
        std::vector<std::pair<int, Local>> L_prima(n);

        int k;
        for (k = 0; k < n; ++k)
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

        k = 0;
        while (k < n) {
            if (s.contagio + L_prima[k].second.contagio <= M && !usados.count(L_prima[k].first-1) && !usados.count(L_prima[k].first+1)) {
                s += L_prima[k].second;
                usados.insert(L_prima[k].first);
            }
            k++;
        }

        return s.beneficio;
    }
}
