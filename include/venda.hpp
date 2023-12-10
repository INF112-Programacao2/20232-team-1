#ifndef VENDA_HPP
#define VENDA_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include "produto.hpp"
#include "cliente.hpp"
#include "data.hpp"
#include "vendedor.hpp"


class Venda {
    private:
        std::vector<Produto*> _produtos;
        Cliente* _cliente;
        Vendedor* _vendedor;
        Data _data;
        float _totalSemDesconto;
        float _totalComDesconto;
    public:
        Venda(std::vector<Produto*> produtos, Cliente* cliente, Vendedor* vendedor, Data data, float totalSemDesconto);

        Venda* cadastrarVenda(std::vector<Produto*> &todosProdutos, std::vector<Cliente*> &todosClientes, std::vector<Vendedor*> &todosVendedores);

        void calcularPrecoTotal(std::vector<Produto*> &carrinho, Data data, Cliente* cliente);

        float getValor();
    
};


#endif