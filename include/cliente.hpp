#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <vector>
#include "venda.hpp"

class Cliente{
    protected:
        static int _nextId;
        int _id;
        std::string _nome;
        float _totalComprado;
        std::vector<Venda*> _compras;
    public:

        Cliente();
        Cliente(std::string nome);

        Cliente* getClienteById(int id, std::vector<Cliente*> &clientes);


        static Cliente* cadastrarCliente();

        static int nextId();
 
        void realizarCompra(Venda* venda, std::vector<Cliente*> &clientes);
        void atualizarNivelCliente(std::vector<Cliente*> &clientes);

        int getID();

        virtual std::string getNome();

        float getTotalComprado();

        virtual float calculaDesconto(float valor);

        void relatorioClientes(std::vector<Cliente*> &clientes);
};

#endif