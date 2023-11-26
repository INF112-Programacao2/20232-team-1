#include <iostream>
#include "periodo.hpp"

class Data{
    private:
        int dia, mes, ano;
    public:
        Data();
        Data(int d, int m, int a);

        bool in(Periodo periodo);
        std::string getData();
        bool dataValida() const;
        bool operator==(const Data& outraData) const;
        bool operator!=(const Data& outraData) const;
        bool operator<(const Data& outraData) const;
        bool operator>(const Data& outraData) const;
        bool operator<=(const Data& outraData) const;
        bool operator>=(const Data& outraData) const;

};

