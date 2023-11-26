#ifndef PRODUTO_HPP
#define PRODUTO_HPP


#include <iostream>
#include <stdexcept>
#include "periodo.hpp"

class Produto{
    private:
        int _id;
        std::string _nome;
        double _preco;
        float _estoque;
        Periodo _periodoPromocao;
    public:
        Produto(int id, std::string nome, double preco, float estoque);

        int getID();

        void setNome(std::string nome);
        std::string getNome();

        void setPreco(double preco);
        double getPreco();

        float getEstoque();
        void diminuirEstoque(float qnt);
};

class EstoqueInsuficienteException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
};


#endif