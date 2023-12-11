#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <vector>
//#include "venda.hpp"
#include <iomanip>
#include <limits>

class Cliente{
    protected:
        static int _nextId;
        int _id;
        std::string _nome;
        float _totalComprado;
        //std::vector<Venda*> _compras;
    public:
        virtual ~Cliente();
        Cliente();
        Cliente(std::string nome);
        Cliente(int id, std::string nome);

        static Cliente* getClienteById(int id, std::vector<Cliente*> &clientes);


        static Cliente* cadastrarCliente();

        static int nextId();
 
        Cliente* realizarCompra(float valor, std::vector<Cliente*> &clientes);
        Cliente* atualizarNivelCliente(std::vector<Cliente*> &clientes);

        int getID();

        virtual std::string getNome();

        float getTotalComprado();

        virtual float calculaDesconto(float valor);

        static void relatorioClientes(std::vector<Cliente*> &clientes);
};

#endif