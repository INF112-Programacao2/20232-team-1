#include "../include/periodo.hpp"

Periodo::Periodo(){
    this->inicio = Data();
    this->fim = Data();
}

Periodo::Periodo(Data inicio, Data fim){
    this->inicio = inicio;
    this->fim = fim;
}

Data Periodo::getDataFim(){
    return this->fim;
}

Data Periodo::getDataInicio(){
    return this->inicio;
}