#include "backtracking.h"

namespace backtracking {

    namespace {

        /*
        std::vector<int> cota_superior (const Locales& L, int i, int j) {
            int n = j-i;
            int k = helper::sqrt(n);
            auto patrones = configuraciones::configuraciones_maximas(k);
            std::vector<int> A;
            for (int r = i; r < j; r += k) {
                std::vector<beneficio_contagio> candidatos;
                std::vector<beneficio_contagio> bloque(L.begin()+i+r, L.begin()+std::min(i+r+k, j));
                for (auto p : patrones)
                    candidatos.push_back(helper::producto_interno(bloque, p));
                auto m = *std::max_element(candidatos.begin(), candidatos.end());
                A.push_back(m.beneficio);
            }
            for (int r = 0; r < A.size(); ++r)
                A[r] += (r > 0 ? A[r-1] : 0);
            A.insert(A.begin(), 0);
            return A;
        }*/

        std::vector<int> cota_superior (const Locales& L) {
            int n = L.size();
            int k = helper::sqrt(n);
            auto patrones = configuraciones::configuraciones_maximas(k);
            std::vector<int> A;

            for (int i = 0; i < n; i += k) {
                std::vector<beneficio_contagio> candidatos;
                std::vector<beneficio_contagio> bloque(L.begin()+i, L.begin()+std::min(i+k, n));
                int m = 0;
                for (auto p : patrones)
                    m = std::max(m, helper::producto_interno(bloque, p).beneficio);
                A.push_back(m);
            }
            for (int i = 0; i < A.size(); ++i)
                A[i] += (i > 0 ? A[i-1] : 0);
            A.insert(A.begin(), 0);
            return A;
        }

        int sub_mayor_beneficio (const Locales& L, int i, int j) {
        if (i >= j)
            return 0;
        int B0 = sub_mayor_beneficio(L, i+1, j);
        int B1 = L[i].beneficio + sub_mayor_beneficio(L, i+2, j);
        return std::max(B0, B1);
        }

        std::vector<int> cota_superior_2 (const Locales& L, int k) {
            int n = L.size();
            k = std::max(k, n);

            std::vector<int> A;
            for (int i = 0; i < n; i += k)
                A.push_back(sub_mayor_beneficio(L, i, std::min(i+k, n)) );



            for (int i = 0; i < A.size(); ++i)
                A[i] += (i > 0 ? A[i-1] : 0);
            A.insert(A.begin(), 0);
            return A;
        }

        int inf;
        std::vector<int> sup;


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

    int mayor_beneficio(const Locales& L, int M, bool cota, int k) {
        inf = greedy::mayor_beneficio(L, M);
        if (cota)
            sup = cota_superior_2(L, k);
        else
            sup = cota_superior(L);
        mayor_beneficio_R(L, 0, {0, M});
        return inf;
    }
}
