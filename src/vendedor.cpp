#include "../include/vendedor.hpp"


int Vendedor::_nextId = 0;

int Vendedor::nextId(){
    return _nextId++;
}

Vendedor::Vendedor(std::string nome){
    _id = nextId();
    _nome = nome;
    _totalVendido = 0;
}

Vendedor::Vendedor(int id, std::string nome){
    _id = id;
    if(id >= _nextId)
        _nextId = id+1;
    _nome = nome;
    _totalVendido = 0;
}

int Vendedor::getID(){
    return _id;
}


Vendedor* Vendedor::cadastrarVendedor(){
    std::string nome;
    std::cout << "Nome: ";
    std::cin >> nome;
    return new Vendedor(nome);
}

std::string Vendedor::getNome(){
    return _nome;
}


void Vendedor::relatorioVendedores(std::vector<Vendedor*> &todosVendedores){
    int i = 0;
    while( i < 36){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
    std::cout << std::setw(6) << "Id" << std::setw(15) << "Nome" << std::setw(15) << "Total Vendido" << std::endl;
    for(Vendedor* vendedor : todosVendedores){
        std::cout << std::setw(6) << vendedor->getID() << std::setw(15) << vendedor->getNome() << std::setw(15) << vendedor->getTotalVendido() << std::endl;
    }
    i = 0;
    while( i < 36){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
}

float Vendedor::getTotalVendido(){
    return _totalVendido;
}

void Vendedor::realizarVenda(float valor){
    _totalVendido += valor;
    //_vendas.push_back(venda);
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

