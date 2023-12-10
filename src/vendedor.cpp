#include "../include/vendedor.hpp"


int Vendedor::_nextId = 0;

int Vendedor::nextId(){
    return _nextId++;
}

int Vendedor::getID(){
    return _id;
}

std::string Vendedor::getNome(){
    return _nome;
}


void Vendedor::relatorioVendedores(std::vector<Vendedor*> &todosVendedores){
    int i = 0;
    while( i < 21){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
    std::cout << std::setw(6) << "Id" << std::setw(15) << "Nome" << std::endl;
    for(Vendedor* vendedor : todosVendedores){
        std::cout << std::setw(6) << vendedor->getID() << std::setw(15) << vendedor->getNome() << std::endl;
    }
    i = 0;
    while( i < 21){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
}

void Vendedor::realizarVenda(Venda* venda){
    _totalVendido += venda->getValor();
    _vendas.push_back(venda);
}

Vendedor* Vendedor::getVendedorById(int id, std::vector<Vendedor*> &todosVendedores){
    for(Vendedor* vendedor : todosVendedores){
        if(vendedor->getID() == id)
            return vendedor;
    }
    return nullptr;
}

float Vendedor::calcularComissao(float valor){
    return valor * 0.02;
}

