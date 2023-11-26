#include "../include/cliente.hpp"
#include "../include/clienteprata.hpp"

int Cliente::_nextId = 0;

Cliente::Cliente(std::string nome):
    _id(nextId()), _nome(nome), _totalComprado(0) {
        insertCliente(this);
    };

int Cliente::nextId(){
    return _nextId++;
}

Cliente* Cliente::getClienteById(int id){
    for(int i = 0; i < clientes.size(); i++){
        if(clientes[i]->getID() == id)
            return clientes[i];
    }
    return nullptr;
}

void Cliente::insertCliente(Cliente* cliente){
    if(cliente != nullptr){
        clientes.push_back(cliente);
    }
    throw std::invalid_argument("Cliente inválido!");
}

void Cliente::realizarCompra(float valor){
    _totalComprado += valor;
    atualizarNivelCliente();
}

void Cliente::atualizarNivelCliente(){
    if(_totalComprado >= 1000){
        ClientePrata* cliente = dynamic_cast<ClientePrata*>(this);
        clientes[this->_id] = cliente;
        // Atualiza o vetor clientes com o novo objeto ClientePrata
        for (int i = 0; i < clientes.size(); i++) {
            if (clientes[i] == this) {
                clientes[i] = cliente;
                break;
            }
        }
        delete this; // Libera a memória do objeto Cliente antigo
    }
    
}