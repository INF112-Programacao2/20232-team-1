#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include "cliente.hpp"
#include "produto.hpp"
#include "venda.hpp"
#include "vendedor.hpp"
#include <vector>
#include <fstream>


class IdInexistente : public std::exception{
    virtual const char* what() const noexcept override;
};

class Gerenciador{
    
        
    public:

        ~Gerenciador();
        std::vector<Cliente*> clientes;
        std::vector<Produto*> produtos;
        std::vector<Vendedor*> vendedores;
        std::vector<Venda*> vendas;

        void inserirProduto(Produto* produto);  
        void inserirCliente(Cliente* cliente);
        void inserirVenda(Venda* venda);
        void inserirVendedor(Vendedor* vendedor);

        void removerCliente(int id);
        void removerProduto(int id);
        void removerVendedor(int id);
        void removerVenda(int id);

        Cliente* getClienteById(int id);
        Produto* getProdutoById(int id);
        Venda* getVendaById(int id);

        void carregarRegistros();
        void salvarRegistros();

        void realizarVenda(int id, Cliente* cliente, Vendedor* vendedor, int dia, int mes, int ano, float totalSemDesconto);

        void criarMenu();
        void menuClientes();
        void menuProdutos();
        void menuVendedores();
        void menuVendas();

        void menuProdutosRelatorios();
        void menuProdutosCadastrar();
        void menuProdutosRemover();

        void menuClientesCadastrar();
        void menuClientesRemover();
        void menuClientesRelatorios();
        
        void menuVendedoresCadastrar();
        void menuVendedoresRemover();
        void menuVendedoresRelatorios();

        void menuVendasCadastrar();
        void menuVendasRemover();
        void menuVendasRelatorios();

        void fecharPrograma();
};


#endif