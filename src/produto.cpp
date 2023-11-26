#include "../include/produto.hpp"

Produto::Produto(int id, std::string nome, double preco, float estoque) : 
        _id(id), _nome(nome), _preco(preco), _estoque(estoque) {};


void Produto::diminuirEstoque(float qnt){
    if(qnt > _estoque){
        throw EstoqueInsuficienteException();
    } else {
        _estoque -= qnt;
    }
    
}

const char* EstoqueInsuficienteException::what() const noexcept{
    return "Estoque insuficiente";
}