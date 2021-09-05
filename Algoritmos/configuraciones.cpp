#include <set>
#include <vector>
#include "configuraciones.h"

namespace configuraciones {

    namespace {
        void configuraciones(int i, std::vector<bool>& V, std::set<std::vector<bool>>& T) {
            if (i < 0) {
                if (!fuerza_bruta::adyacentes(V) && fuerza_bruta::espacio(V) == V.size())
                    T.insert(V);
                return;
            }
            if (i+1 < V.size() || V[i+1] || V[i+2]) {
                V[i] = false;
                configuraciones(i-1, V, T);
            }
            if (i < V.size() || !V[i+1]) {
                V[i] = true;
                configuraciones(i-1, V, T);
            }
            return;
        }
    }

    std::vector<std::set<std::vector<bool>>> llenar_tablas(int n) {
        int k = helper::sqrt(n);
        std::vector<std::set<std::vector<bool>>> T(k+1, {{false}});
        for (int i = 1; i <= k; ++i)
            T[i] = configuraciones::configuraciones_maximas(i);
        return T;
    }

    std::set<std::vector<bool>> configuraciones_maximas(int n) {
        if (n == 1)
            return {{1}};
        std::vector<bool> V (n, false);
        std::set<std::vector<bool>> T;
        configuraciones(n, V, T);
        return T;
    }
}
