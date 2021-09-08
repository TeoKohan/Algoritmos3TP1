#include "backtracking.h"

namespace backtracking {

    int c;
    int inf;
    std::vector<int> sup;

    namespace {
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

            return s;
        }

        std::vector<int> cota_superior (const Locales& L, int i, int j) {
            int n = j-i;
            int k = helper::sqrt(n);
            auto patrones = configuraciones::configuraciones_maximas(k);
            std::vector<int> A;
            for (int r = i; r < j; r += k) {
                std::vector<beneficio_contagio> candidatos;
                std::vector<beneficio_contagio> bloque(L.begin()+i+r, L.begin()+std::min(i+r+k, j));
                //std::cout << std::endl << "bloque :" << bloque << std::endl;
                for (auto p : patrones)
                    candidatos.push_back(helper::producto_interno(bloque, p));
                //std::cout << "el maximo de: " << candidatos << " es ";
                auto m = *std::max_element(candidatos.begin(), candidatos.end());
                //std::cout << m << std::endl;
                A.push_back(m.beneficio);
            }
            for (int r = 0; r < A.size(); ++r)
                A[r] += (r > 0 ? A[r-1] : 0);
            A.insert(A.begin(), 0);
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
        sup = cota_superior(L, 0, L.size());
        mayor_beneficio_R(L, 0, {0, M});
        return inf;
    }
}
