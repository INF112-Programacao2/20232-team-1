#ifndef PERIODO_HPP
#define PERIODO_HPP
#include "data.hpp"


class Periodo{
    private:
        Data inicio;
        Data fim;
    public: 
        Periodo();
        Periodo(Data inicio, Data fim);
        Data getDataInicio();
        Data getDataFim();
};

#endif