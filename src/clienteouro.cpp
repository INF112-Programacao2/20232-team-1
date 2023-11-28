#include "../include/clienteouro.hpp"

ClienteOuro::ClienteOuro(Cliente* cliente){
    _id = cliente->getID();
    _nome = cliente->getNome();
    _totalComprado = cliente->getTotalComprado();
}

ClienteOuro::ClienteOuro(ClientePrata* cliente){
    _id = cliente->getID();
    _nome = cliente->getNome();
    _totalComprado = cliente->getTotalComprado();
}


float ClienteOuro::calculaDesconto(float valor){
    if(valor > 1000){
        return valor * 0.20;
    } else if (valor > 150){
        return valor * 0.15;
    } else {
        return valor * 0.1;
    }
}

std::string ClienteOuro::getNome(){
    return "**" + _nome;
}