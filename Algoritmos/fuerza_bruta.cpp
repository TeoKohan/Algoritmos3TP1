#include "fuerza_bruta.h"

namespace fuerza_bruta {

    int espacio(const std::vector<bool>& V) {
        int i = 0;
        while (i < V.size() && ((i > 0 && V[i-1]) || V[i] || (i+1 < V.size() && V[i+1])))
            i++;
        return i;
    }

    bool adyacentes(const std::vector<bool>& V) {
        int i = 0;
        while (i < V.size() && !(V[i++] && (i == V.size() || V[i])));
        return i < V.size();
    }

    int mayor_beneficio(const Locales& L, int i, int M, std::vector<bool>& V) {
        if (i >= L.size())
            return (M < 0 || adyacentes(V)) ? -INFINITO : 0;
        V[i] = false;
        int B0 = mayor_beneficio(L, i+1, M, V);
        V[i] = true;
        int B1 = L[i].beneficio + mayor_beneficio(L, i+1, M-L[i].contagio, V);
        return std::max(B0, B1);
    }
}
