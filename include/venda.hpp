#ifndef VENDA_HPP
#define VENDA_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <utility>
#include "produto.hpp"
#include "cliente.hpp"
#include "data.hpp"
#include "vendedor.hpp"


class Venda {
    private:
        static int _nextId;
        int _id;
        std::vector<std::pair<Produto*, float>> _carrinho;
        Cliente* _cliente;
        Vendedor* _vendedor;
        Data _data;
        float _totalSemDesconto;
        float _totalComDesconto;
    public:
        Venda();
        Venda(std::vector<std::pair<Produto*, float>>, Cliente* cliente, Vendedor* vendedor, Data data, std::vector<Cliente*> &todosClientes);

        Venda(int id, Cliente* cliente, Vendedor* vendedor, int dia, int mes, int ano, float totalSemDesconto);

        static int nextId();
        static Venda* cadastrarVenda(std::vector<Produto*> &todosProdutos, std::vector<Cliente*> &todosClientes, std::vector<Vendedor*> &todosVendedores);
        int getId();
        static float calcularPrecoTotal(std::vector<std::pair<Produto*, float>> &carrinho, Data &data);

        float getValor();

        static void relatorioVendas(std::vector<Venda*> &vendas);

        Cliente* getCliente();
        Vendedor* getVendedor();
        std::string getData();
        std::vector<std::pair<Produto*, float>> getCarrinho();

    
};


#endif