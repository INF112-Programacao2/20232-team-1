#include "../include/cliente.hpp"
#include "../include/clienteprata.hpp"
#include "../include/clienteouro.hpp"
#include <iostream>

int Cliente::_nextId = 0;

Cliente::Cliente(std::string nome):
    _id(nextId()), _nome(nome), _totalComprado(0) { };


Cliente::Cliente(){}

Cliente::~Cliente(){
    //delete this;
}

Cliente::Cliente(int id, std::string nome){
    _id = id;
    if(_id >= _nextId)
        _nextId = _id + 1;
    _nome = nome;
    _totalComprado = 0;
}


int Cliente::nextId(){
    return _nextId++;
}



int Cliente::getID(){
    return _id;
    
}

Cliente* Cliente::cadastrarCliente(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string nome;
    std::cout << "Nome: ";
    std::getline(std::cin, nome);
    return new Cliente(nome);
}


Cliente* Cliente::realizarCompra(float valor, std::vector<Cliente*> &clientes){

    _totalComprado += valor;
    //_compras.push_back(venda);
    return atualizarNivelCliente(clientes);
}

Cliente* Cliente::atualizarNivelCliente(std::vector<Cliente*> &clientes){
    if(_totalComprado >= 5000){
        ClienteOuro* clienteOuro = new ClienteOuro(this);
        // Atualiza o vetor clientes com o novo objeto ClienteOuro
        for (size_t i = 0; i < clientes.size(); i++) {
            if (clientes[i] == this) {
                
                clientes[i] = clienteOuro;
                break;
            }
        }
        delete this; // Libera a memória do objeto Cliente antigo
        return clienteOuro;
    } else if(_totalComprado >= 1000){
        ClientePrata* clientePrata = new ClientePrata(this);
        // Atualiza o vetor clientes com o novo objeto ClientePrata
        // Atualiza o vetor clientes com o novo objeto ClienteOuro
        for (size_t i = 0; i < clientes.size(); i++) {
            if (clientes[i] == this) {
                clientes[i] = clientePrata;
                break;
            }
        }
        delete this; // Libera a memória do objeto Cliente antigo
        return clientePrata;
    }
    return nullptr;
    
}

Cliente* Cliente::getClienteById(int id, std::vector<Cliente*> &clientes){
    for(Cliente* cliente : clientes){
        if(cliente->getID() == id)
            return cliente;
    }
    return nullptr;
}

void Cliente::relatorioClientes(std::vector<Cliente*> &clientes){
    int i = 0;
    while( i < 36){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
    std::cout << std::setw(6) << "Id" << std::setw(15) << "Nome" << std::setw(15) << "Total Comprado" << std::endl;
    for(Cliente* cliente : clientes){
        std::cout << std::setw(6) << cliente->getID() << std::setw(15) << cliente->getNome() << std::setw(15) << cliente->getTotalComprado() << std::endl;
    }
    i = 0;
    while( i < 36){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
}


std::string Cliente::getNome(){
    return _nome;
}

float Cliente::calculaDesconto(float valor){
    if(valor > 250){
        return valor * 0.1;
    } else {
        return 0;
    }
}

float Cliente::getTotalComprado(){
    return _totalComprado;
}