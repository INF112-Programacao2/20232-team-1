#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Periodo;

class Data {
    private:
        int dia, mes, ano;
    public:
        Data();
        Data(int d, int m, int a);
        //bool in(Periodo periodo);
        std::string getData();
        static Data cadastrarData();
        bool dataValida() const;
        bool operator==(const Data& outraData) const;
        bool operator!=(const Data& outraData) const;
        bool operator<(const Data& outraData) const;
        bool operator>(const Data& outraData) const;
        bool operator<=(const Data& outraData) const;
        bool operator>=(const Data& outraData) const;
};

#endif