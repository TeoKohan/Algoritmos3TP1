#include "configuraciones.h"

namespace configuraciones {

    namespace {
        /**
         *Devuelve el conjunto de vectores booleanos maximales para un cierto numero, esto es
         *vectores que:
         *1) cumplen la propiedad de no tener valores adyacentes
         *2) dado un vector de naturales del mismo tamaño su producto interno puede maximizar la sumatoria del vector resultante
         *@param[in] i la longitud de los vectores a buscar
         *@param[in] V una instancia de un vector de booleanos de longitud i
         *@param[out] T el conjunto de estos vectores
         *    configuraciones(3, V, T) = {{true, false, true}, {false, true, false}}
         *    configuraciones(5, V, T) = {{true, false, true, false, true}, {true, false, false, true, false},
         *                                {false, true, false, true, false}, {false, true, false, false, true}}
         */
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
        int k = std::max(helper::sqrt(n), MAX_TABLA);
        std::vector<std::set<std::vector<bool>>> T(k, {{false}});
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
