#include <vector>

namespace helper{
    /**
     *Calcula la raiz cuadrada de un numero, en caso de no ser entera,
     *devuelve el piso de la raiz
     *@param[in] n el valor al cual se le calcula su raiz.
     *    sqrt(24) = 4
     *    sqrt(25) = 5
     */
    int sqrt (int n) {
        int  i = 0;
        int  j = n ;
        while (j > i+1) {
            int k = (i+j)/2;
            if (k*k>n)
                j = k;
            else
                i = k;
        }
        return  i;
    }

    int maximo_valor_vector (const std::vector<int>& V) {
        int m = 0;
        for (int v : V)
            m = std::max(m, v);
        return m;
    }
}
