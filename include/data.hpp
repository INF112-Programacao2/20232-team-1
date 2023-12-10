#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <chrono>

class Periodo;

class Data {
    private:
    
        int dia, mes, ano;
    public:
        static Data dataHoje();
        Data();
        Data(int d, int m, int a);

        int getDia();
        int getMes();
        int getAno();

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