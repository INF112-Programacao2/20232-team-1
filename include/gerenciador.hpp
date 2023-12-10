#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include "cliente.hpp"
#include "produto.hpp"
#include "venda.hpp"
#include <vector>


class IdInexistente : public std::exception{
    virtual const char* what() const noexcept override;
};

class Gerenciador{
    
        
    public:

        ~Gerenciador();
        std::vector<Cliente*> clientes;
        std::vector<Produto*> produtos;
        std::vector<Venda*> vendas;

        void inserirProduto(Produto* produto);  
        void inserirCliente(Cliente* cliente);

        void removerCliente(int id);
        void removerProduto(int id);

        Cliente* getClienteById(int id);
        Produto* getProdutoById(int id);
        Venda* getVendaById(int id);
};


#endif