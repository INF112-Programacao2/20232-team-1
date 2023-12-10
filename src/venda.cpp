#include "../include/venda.hpp"

Venda::Venda(std::vector<Produto*> produtos, Cliente* cliente, Vendedor* vendedor, Data data, float _totalSemDesconto){
    _produtos = produtos;
    _cliente = cliente;
    _vendedor = vendedor;
    _data = data;
    _totalSemDesconto = _totalSemDesconto;
    _totalComDesconto = _totalSemDesconto - _cliente->calculaDesconto(_totalSemDesconto);
}

Venda* Venda::cadastrarVenda(std::vector<Produto*> &todosProdutos, std::vector<Cliente*> &todosClientes, std::vector<Vendedor*> &todosVendedores){
    std::vector<Produto*> _produtos;
    Cliente* cliente = nullptr;
    Vendedor* vendedor = nullptr;
    Data data;
    data = data.dataHoje();
    int idCliente;
    int idVendedor;
    
    std::cout << "Cliente:" << std::endl;
    cliente->relatorioClientes(todosClientes);
    while(cliente == nullptr){
        std:: cout << std::endl << "Digite o id do cliente: ";
        std::cin >> idCliente;
            
        cliente = cliente->getClienteById(idCliente, todosClientes);
        if(cliente == nullptr){
            std::cout << "Id inexistente!" << std::endl;
        }
        
    }
    std::cout << "Vendedor:" << std::endl;
    vendedor->relatorioVendedores(todosVendedores);
    while (vendedor == nullptr){
        std:: cout << std::endl << "Digite o id do vendedor: ";
        std::cin >> idVendedor;
        
        vendedor = vendedor->getVendedorById(idVendedor, todosVendedores);
        if(vendedor == nullptr){
            std::cout << "Id inexistente!" << std::endl;
        }
        
    }


    int menuSelect = -1;
    
    
    while(menuSelect < 3){
        Produto* produto = nullptr;
        int idProduto;
        std::cout << "1 - Inserir produto" << std::endl;
        std::cout << "2 - Visualizar carrinho" << std::endl;
        std::cout << "3 - Finalizar compra" << std::endl;
        std::cout << "4 - Cancelar" << std::endl;
        std::cout << "Opção: ";
        std::cin >> menuSelect;
        switch(menuSelect){
            case 1:
                produto->relatorioProdutos(todosProdutos, data);
                while(produto == nullptr){
                    std::cout << "Id do produto a ser adicionado: ";
                    std::cin >> idProduto;
                    produto = produto->getProdutoById(idProduto, todosProdutos);
                    if(produto == nullptr){
                        std::cout << "Id inexistente!" << std::endl;
                    }
                }
                _produtos.push_back(produto);
                calcularPrecoTotal(_produtos, data, cliente);
                break;
            case 2:
                produto->relatorioProdutos(_produtos, data);
                std::cout << "Total sem desconto: " << _totalSemDesconto << std::endl;
                std::cout << "Total com desconto: " << _totalComDesconto << std::endl;
                break;
            case 3:
                return new Venda(_produtos, cliente, vendedor, data, _totalSemDesconto);
                break;
            case 4:
                break;
        }
    }


}


void Venda::calcularPrecoTotal(std::vector<Produto*> &carrinho, Data data, Cliente* cliente){
    _totalSemDesconto = 0;
    
    for(Produto* produto : carrinho){
        _totalSemDesconto += produto->getPreco(data);
    }

    _totalComDesconto = _totalSemDesconto - cliente->calculaDesconto(_totalSemDesconto);
}

float Venda::getValor(){
    return _totalComDesconto;
}

