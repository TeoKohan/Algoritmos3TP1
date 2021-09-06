#ifndef LOCAL
#define LOCAL

#include <iostream>
#include <algorithm>
#include <vector>

struct beneficio_contagio {
    public:
        int beneficio;
        int contagio;

        beneficio_contagio();
        beneficio_contagio(int beneficio, int contagio);

        bool operator < (const beneficio_contagio& rhs);
        beneficio_contagio& operator += (const beneficio_contagio& rhs);
        beneficio_contagio operator + (const beneficio_contagio& rhs);
        beneficio_contagio& operator -= (const beneficio_contagio& rhs);
        beneficio_contagio operator - (const beneficio_contagio& rhs);
        friend std::ostream& operator << (std::ostream& os, const beneficio_contagio& rhs);
};

bool operator < (const beneficio_contagio& lhs, const beneficio_contagio& rhs);
beneficio_contagio operator * (const beneficio_contagio& lhs, int rhs);

beneficio_contagio operator * (const std::vector<beneficio_contagio>& a, const std::vector<bool>& b);
std::vector<beneficio_contagio> operator * (const std::vector<beneficio_contagio>& a, const std::vector<std::vector<bool>>& b);

typedef beneficio_contagio Local;
typedef std::vector<Local> Locales;

#endif
