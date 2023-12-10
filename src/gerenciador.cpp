#include "../include/gerenciador.hpp"

Gerenciador::~Gerenciador(){
    for(int i = 0; i < clientes.size(); i++){
        delete clientes[i];
    }
    for(int i = 0; i < produtos.size(); i++){
        delete produtos[i];
    }
}

const char* IdInexistente::what() const noexcept {
    return "ID inexistente";
}



Cliente* Gerenciador::getClienteById(int id){
    for(int i = 0; i < clientes.size(); i++){
        if(clientes[i]->getID() == id)
            return clientes[i];
    }
    throw IdInexistente();
}


Produto* Gerenciador::getProdutoById(int id){
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i]->getID() == id)
            return produtos[i];
    }
    throw IdInexistente();
}
void Gerenciador::inserirCliente(Cliente* cliente){
    // Verifica se o cliente é inválido
    if(cliente == nullptr) {
        throw std::invalid_argument("Cliente inválido!");
    }

    // Adiciona o cliente à lista
    clientes.push_back(cliente);
}

void Gerenciador::inserirProduto(Produto* produto){
    // Verifica se o cliente é inválido
    if(produto == nullptr) {
        throw std::invalid_argument("Produto inválido!");
    }

    // Adiciona o cliente à lista
    produtos.push_back(produto);
}