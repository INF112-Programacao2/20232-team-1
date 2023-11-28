#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <vector>

class Cliente{
    protected:
        static int _nextId;
        int _id;
        std::string _nome;
        float _totalComprado;
    public:

        Cliente();
        Cliente(std::string nome);


        static Cliente* cadastrarCliente();

        static int nextId();
 
        void realizarCompra(float valor, std::vector<Cliente*> &clientes);
        void atualizarNivelCliente(std::vector<Cliente*> &clientes);

        int getID();

        virtual std::string getNome();

        float getTotalComprado();

        virtual float calculaDesconto(float valor);
};

#endif