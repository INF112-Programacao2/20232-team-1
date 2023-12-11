#include "../include/clienteprata.hpp"


ClientePrata::ClientePrata(Cliente* cliente){
    std::string nome = cliente->getNome();
    while(nome[0] == '*'){
        nome = nome.substr(1);
    }
    _id = cliente->getID();
    _nome = nome;
    _totalComprado = cliente->getTotalComprado();
}


float ClientePrata::calculaDesconto(float valor){
    if(valor > 500){
        return valor * 0.15;
    } else if (valor > 100){
        return valor * 0.1;
    } else {
        return valor * 0.05;
    }
}

std::string ClientePrata::getNome(){
    return "*" + _nome;
}
