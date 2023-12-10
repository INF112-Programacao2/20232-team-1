#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <vector>
#include <iostream>
#include <iomanip>
//#include "venda.hpp"

class Vendedor{
    protected:
        static int _nextId;
        int _id;
        std::string _nome;
        float _totalVendido;
        //std::vector<Venda*> _vendas;
    public:
        Vendedor(std::string nome);
        Vendedor(int id, std::string nome);

        static Vendedor* cadastrarVendedor();
        static Vendedor* getVendedorById(int idVendedor, std::vector<Vendedor*> &todosVendedores);
        static void relatorioVendedores(std::vector<Vendedor*> &todosVendedores);

        static int nextId();

        void realizarVenda(float valor);
        
        float getTotalVendido();

        int getID();

        std::string getNome();

        float calcularComissao(float valor);
};


#endif