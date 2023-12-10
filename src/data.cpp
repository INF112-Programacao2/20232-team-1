#include "../include/data.hpp"

Data::Data(){
    this->ano = 2000;
    this->mes = 1;
    this->dia = 1;
}


Data::Data(int d, int m, int a) : dia(d), mes(m), ano(a){
    if(!dataValida()){
        throw std::invalid_argument("Data inválida.");
    }
}

//bool Data::in(Periodo periodo){
//    if(*this >= periodo.getDataInicio() && *this <= periodo.getDataFim()){
//        return true;
//    }
//    return false;
//}

int Data::getDia(){
    return this->dia;
}

int Data::getMes(){
    return this->mes;
}

int Data::getAno(){
    return this->ano;
}


Data Data::dataHoje(){
    // Get current time
    std::time_t current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // Convert current time to struct tm
    std::tm* time_info = std::localtime(&current_time);

    // Extract day, month, and year as integers
    int day = time_info->tm_mday;
    int month = time_info->tm_mon + 1; // tm_mon is zero-based
    int year = time_info->tm_year + 1900; // tm_year is years since 1900

    return Data(day, month, year);
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
    return std::to_string(dia) + " " + std::to_string(mes) + " " + std::to_string(ano);
}

Data Data::cadastrarData(){
    int d, m, a;
    std::cout << "Data(DD MM AAAA): ";
    std::cin >> d >> m >> a;
    return Data(d, m, a);
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