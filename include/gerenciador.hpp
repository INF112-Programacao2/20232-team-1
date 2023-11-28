#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include "cliente.hpp"
#include "produto.hpp"
#include <vector>


class Gerenciador{
    
        
    public:
        ~Gerenciador();
        std::vector<Cliente*> clientes;
        std::vector<Produto*> produtos;

        void inserirProduto(Produto* produto);  
        void inserirCliente(Cliente* cliente);

        void removerCliente(int id);
        void removerProduto(int id);

        Cliente* getClienteById(int id);
        Produto* getProdutoById(int id);
};


#endif