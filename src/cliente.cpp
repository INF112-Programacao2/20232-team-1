#include "../include/cliente.hpp"
#include "../include/clienteprata.hpp"
#include "../include/clienteouro.hpp"
#include <iostream>

int Cliente::_nextId = 0;

Cliente::Cliente(std::string nome):
    _id(nextId()), _nome(nome), _totalComprado(0) { };


Cliente::Cliente(){}


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


void Cliente::realizarCompra(float valor, std::vector<Cliente*> &clientes){
    _totalComprado += valor;
    atualizarNivelCliente(clientes);
}

void Cliente::atualizarNivelCliente(std::vector<Cliente*> &clientes){
    if(_totalComprado >= 5000){
        ClienteOuro* clienteOuro = new ClienteOuro(this); // Create a new ClientePrata object using the data from the existing Cliente object
        // Atualiza o vetor clientes com o novo objeto ClientePrata
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