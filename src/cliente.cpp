#include "../include/cliente.hpp"
#include "../include/clienteprata.hpp"
#include "../include/clienteouro.hpp"
#include <iostream>

int Cliente::_nextId = 0;

Cliente::Cliente(std::string nome):
    _id(nextId()), _nome(nome), _totalComprado(0) { };


Cliente::Cliente(){}

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
    std::string nome;
    std::cout << "Nome: ";
    std::cin >> nome;
    return new Cliente(nome);
}


void Cliente::realizarCompra(Venda* venda, std::vector<Cliente*> &clientes){

    _totalComprado += venda->getValor();
    _compras.push_back(venda);
    atualizarNivelCliente(clientes);
}

void Cliente::atualizarNivelCliente(std::vector<Cliente*> &clientes){
    if(_totalComprado >= 5000){
        ClienteOuro* clienteOuro = new ClienteOuro(this); // Create a new ClienteOuro object using the data from the existing Cliente object
        // Atualiza o vetor clientes com o novo objeto ClienteOuro
        for (int i = 0; i < clientes.size(); i++) {
            if (clientes[i] == this) {
                clientes[i] = clienteOuro;
                break;
            }
        }
        delete this; // Libera a memória do objeto Cliente antigo
    } else if(_totalComprado >= 1000){
        ClientePrata* clientePrata = new ClientePrata(this);
        // Atualiza o vetor clientes com o novo objeto ClientePrata
        for (int i = 0; i < clientes.size(); i++) {
            if (clientes[i] == this) {
                clientes[i] = clientePrata;
                break;
            }
        }
        delete this; // Libera a memória do objeto Cliente antigo
    }
    
    
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