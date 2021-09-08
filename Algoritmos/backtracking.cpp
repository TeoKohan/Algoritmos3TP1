#include "backtracking.h"

namespace backtracking {

    beneficio_contagio inf;
    std::vector<beneficio_contagio> sup;

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

        std::vector<beneficio_contagio> cota_superior (const Locales& L, int i, int j) {
            int n = j-i;
            int k = helper::sqrt(n);
            auto patrones = configuraciones::configuraciones_maximas(k);
            std::vector<beneficio_contagio> A;
            for (int r = i; r < j; r += k) {
                std::vector<beneficio_contagio> candidatos;
                std::vector<beneficio_contagio> bloque(L.begin()+i+r, L.begin()+std::min(i+r+k, j));
                //std::cout << std::endl << "bloque :" << bloque << std::endl;
                for (auto p : patrones)
                    candidatos.push_back(helper::producto_interno(bloque, p));
                //std::cout << "el maximo de: " << candidatos << " es ";
                auto m = *std::max_element(candidatos.begin(), candidatos.end());
                //std::cout << m << std::endl;
                A.push_back(m);
            }
            for (int r = 0; r < A.size(); ++r)
                A[r] += (r > 0 ? A[r-1] : Local());
            A.insert(A.begin(), {0, 0});
            return A;
        }

        beneficio_contagio cota_superior_2 (const Locales& L, int i) {
            beneficio_contagio s = {0, 0};
            for (; i < L.size(); ++i)
                s += L[i];

            std::cout << s << "asignando" << std::endl;
            return s;
        }



        int mayor_beneficio_R(const Locales& L, int i, int M, beneficio_contagio A) {
            if (M < 0)
                return -INFINITO;
            if (inf < A)
                    inf = A;
            //std::cout << "en posicion " << i << " suma " << A << " + " << *(sup.end()-1) << " - " << sup[i/helper::sqrt(L.size())] << " < " << inf << std::endl;
            if (i >= L.size())
                return 0;
            if (A + *(sup.end()-1) - sup[i/helper::sqrt(L.size())] < inf)
                return -INFINITO;
            return std::max(L[i].beneficio + mayor_beneficio_R(L, i+2, M-L[i].contagio, A+L[i]), mayor_beneficio_R(L, i+1, M, A));
        }
    }

    int mayor_beneficio(const Locales& L, int M) {
        inf = cota_inferior(L, 0, L.size(), M);
        //std::cout << "cota inferior: " << inf << std::endl;
        sup = cota_superior(L, 0, L.size());
        //std::cout << "cota superior: " << sup << std::endl;
        mayor_beneficio_R(L, 0, M, {0, 0});
        return inf.beneficio;
    }
}
