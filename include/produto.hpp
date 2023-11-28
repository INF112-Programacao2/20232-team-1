#ifndef PRODUTO_HPP
#define PRODUTO_HPP


#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "periodo.hpp"
#include "data.hpp"

class Produto{
    private:
        static int _nextId;
        int _id;
        std::string _nome;
        float _preco;
        float _estoque;
        Periodo _periodoPromocao;
        float _percentualDesconto;
    public:
        Produto(std::string nome, float preco, float estoque);
        static int nextId();
        static Produto* cadastrarProduto();

        void setPeriodoPromocao(Periodo periodoPromocao);
        std::string getPeriodoPromocao();
        void cadastrarPromocao();

        void setDesconto(float valor);

        int getID();

        void setNome(std::string nome);
        std::string getNome();

        void setPreco(float preco);
        float getPreco(Data dataCompra);

        float getEstoque();
        void diminuirEstoque(float qnt);
};

class EstoqueInsuficienteException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
};


#endif