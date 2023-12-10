#include "../include/periodo.hpp"

Periodo::Periodo(){
    this->inicio = Data();
    this->fim = Data();
}

Periodo::Periodo(Data inicio, Data fim){
    this->inicio = inicio;
    this->fim = fim;
}

std::string Periodo::getPeriodo(){

    return this->inicio.getData() + " " + this->fim.getData();
}

bool Periodo::contem(Data data){
    return (data >= this->inicio && data <= this->fim);
}

Periodo Periodo::cadastroPeriodo(){
    std::cout << "Inicio do Periodo de Promoção:\n";
    Data inicio = Data::cadastrarData();
    std::cout << "Fim do Periodo de Promoção:\n";
    Data fim = Data::cadastrarData();
    return Periodo(inicio, fim);
}

Data Periodo::getDataFim(){
    return this->fim;
}

Data Periodo::getDataInicio(){
    return this->inicio;
}