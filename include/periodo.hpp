#ifndef PERIODO_HPP
#define PERIODO_HPP
#include "data.hpp"
#include <string>
#include <iostream>


class Periodo{
    private:
        Data inicio;
        Data fim;
    public: 
        Periodo();
        Periodo(Data inicio, Data fim);

        bool contem(Data data);

        Data getDataInicio();
        Data getDataFim();

        std::string getPeriodo();

        static Periodo cadastroPeriodo();
};

#endif