#include "../include/data.hpp"

Data::Data(){
    this->ano = 2023;
    this->mes = 1;
    this->dia = 1;
}


Data::Data(int d, int m, int a) : dia(d), mes(m), ano(a){
    if(!dataValida()){
        throw std::invalid_argument("Data inválida.");
    }
}

bool Data::in(Periodo periodo){
    if(*this >= periodo.getDataInicio() && *this <= periodo.getDataFim()){
        return true;
    }
    return false;
}

bool Data::dataValida() const {
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1) {
        return false;
    }

    // Verificar fevereiro (considerando anos bissextos)
    if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            return (dia <= 29);
        } else {
            return (dia <= 28);
        }
    }

    // Verificar meses com 30 dias
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return (dia <= 30);
    }

    // Verificar meses com 31 dias
    return (dia <= 31);
}

std::string Data::getData(){
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(ano);
}


// Métodos de comparação
bool Data::operator==(const Data& outraData) const {
    return (dia == outraData.dia && mes == outraData.mes && ano == outraData.ano);
}

bool Data::operator!=(const Data& outraData) const {
    return !(*this == outraData);
}

bool Data::operator<(const Data& outraData) const {
    if (ano < outraData.ano)
        return true;
    else if (ano == outraData.ano && mes < outraData.mes)
        return true;
    else if (ano == outraData.ano && mes == outraData.mes && dia < outraData.dia)
        return true;
    return false;
}

bool Data::operator>(const Data& outraData) const {
    return (!(*this == outraData) && !(*this < outraData));
}

bool Data::operator<=(const Data& outraData) const {
    return (*this < outraData || *this == outraData);
}

bool Data::operator>=(const Data& outraData) const {
    return (*this > outraData || *this == outraData);
}