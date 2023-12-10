#ifndef PRODUTO_HPP
#define PRODUTO_HPP


#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <iomanip>
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
        Produto(int id, std::string nome, float preco,float estoque, int diaInicio, int mesInicio, int anoInicio, int diaFim, int mesFim, int anoFim);



        static int nextId();
        static Produto* cadastrarProduto();

        void setPeriodoPromocao(Periodo periodoPromocao);
        std::string getPeriodoPromocao();
        void cadastrarPromocao();
        float getPrecoSemDesconto();

        void setDesconto(float valor);

        int getID();

        //void setNome(std::string nome);
        std::string getNome();

        //void setPreco(float preco);
        float getPreco(Data dataCompra);

        float getEstoque();
        void diminuirEstoque(float qnt);

        static Produto* getProdutoById(int id, std::vector<Produto*> &produtos);

        static void relatorioProdutos(std::vector<Produto*> &produtos, Data data);
        static void relatorioProdutos(std::vector<std::pair<Produto*, float>> &produtos, Data data);
};

class EstoqueInsuficienteException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
};


#endif