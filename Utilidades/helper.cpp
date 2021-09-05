#include <vector>

namespace helper{
    int  sqrt (int n) {
        int  i = 0;
        int  j = n ;
        while  ( j>i +1) {
            int  k = ( i+j ) /2;
            if (k*k>n)
                j = k;
            else
                i = k ;
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
