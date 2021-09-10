#include "helper.h"

namespace helper{
    /**
     *Calcula la raiz cuadrada de un numero, en caso de no ser entera,
     *devuelve el piso de la raiz
     *@param[in] n el valor al cual se le calcula su raiz.
     *    sqrt(24) = 4
     *    sqrt(25) = 5
     */
    int sqrt (int n) {
        if (n <= 1)
            return n;
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

    /**
     *Calcula el producto interno entre dos vectores
     *@param[in] n el valor al cual se le calcula su raiz.
     *    sqrt(24) = 4
     *    sqrt(25) = 5
     */
    beneficio_contagio producto_interno (const std::vector<beneficio_contagio>& lhs, const std::vector<bool>& rhs) {
        beneficio_contagio res = {0, 0};
        for (int i = 0; i < lhs.size(); ++i)
            res += lhs[i] * rhs[i];
        return res;
    }
}
