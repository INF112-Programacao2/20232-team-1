#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include "venda.hpp"

class Vendedor{
    protected:
        static int _nextId;
        int _id;
        std::string _nome;
        float _totalVendido;
        std::vector<Venda*> _vendas;
    public:
        Vendedor* getVendedorById(int idVendedor, std::vector<Vendedor*> &todosVendedores);
        void relatorioVendedores(std::vector<Vendedor*> &todosVendedores);

        static int nextId();

        void realizarVenda(Venda* venda);
        

        int getID();

        std::string getNome();

        float calcularComissao(float valor);
};


#endif