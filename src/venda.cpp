#include "../include/venda.hpp"

int Venda::_nextId = 0;

Venda::Venda(std::vector<std::pair<Produto*, float>> carrinho, Cliente* cliente, Vendedor* vendedor, Data data, float _totalSemDesconto){
    _id = nextId();
    _carrinho = carrinho;
    _cliente = cliente;
    _vendedor = vendedor;
    _data = data;
    _totalSemDesconto = _totalSemDesconto;
    _totalComDesconto = _totalSemDesconto - _cliente->calculaDesconto(_totalSemDesconto);
}

Venda::Venda(){
    _totalSemDesconto = 0;
}

Venda::Venda(int id, Cliente* cliente, Vendedor* vendedor, int dia, int mes, int ano, float totalSemDesconto){
    _id = id;
    if(_id >= _nextId){
        _nextId = _id + 1;
    }
    _cliente = cliente;
    _vendedor = vendedor;
    _data = Data(dia, mes, ano);
    _totalSemDesconto = totalSemDesconto;
    _totalComDesconto = _totalSemDesconto - _cliente->calculaDesconto(_totalSemDesconto);
}

int Venda::getId(){
    return _id;
}

Venda* Venda::cadastrarVenda(std::vector<Produto*> &todosProdutos, std::vector<Cliente*> &todosClientes, std::vector<Vendedor*> &todosVendedores){
    std::vector<std::pair<Produto*, float>> _produtos;
    Cliente* cliente = nullptr;
    Vendedor* vendedor = nullptr;
    Data data;
    data = data.dataHoje();
    int idCliente;
    int idVendedor;
    
    std::cout << "Cliente:" << std::endl;
    Cliente::relatorioClientes(todosClientes);
    while(cliente == nullptr){
        std:: cout << std::endl << "Digite o id do cliente: ";
        std::cin >> idCliente;
            
        cliente = Cliente::getClienteById(idCliente, todosClientes);
        if(cliente == nullptr){
            std::cout << "Id inexistente!" << std::endl;
        }
        
    }
    std::cout << "Vendedor:" << std::endl;
    Vendedor::relatorioVendedores(todosVendedores);
    while (vendedor == nullptr){
        std:: cout << std::endl << "Digite o id do vendedor: ";
        std::cin >> idVendedor;
        
        vendedor = Vendedor::getVendedorById(idVendedor, todosVendedores);
        if(vendedor == nullptr){
            std::cout << "Id inexistente!" << std::endl;
        }
        
    }


    int menuSelect = -1;
    
    
    while(menuSelect < 3){
        std::pair<Produto*, float> produto;
        produto.first = nullptr;
        int idProduto;
        std::cout << "1 - Inserir produto" << std::endl;
        std::cout << "2 - Visualizar carrinho" << std::endl;
        std::cout << "3 - Finalizar compra" << std::endl;
        std::cout << "4 - Cancelar" << std::endl;
        std::cout << "Opção: ";
        std::cin >> menuSelect;
        switch(menuSelect){
            case 1:
                Produto::relatorioProdutos(todosProdutos, data);
                while(produto.first == nullptr){
                    std::cout << "Id do produto a ser adicionado: ";
                    std::cin >> idProduto;
                    produto.first = Produto::getProdutoById(idProduto, todosProdutos);
                    if(produto.first == nullptr){
                        std::cout << "Id inexistente!" << std::endl;
                    }
                }
                std::cout << "Quantidade: ";
                std::cin >> produto.second;
                _produtos.push_back(produto);
                calcularPrecoTotal(_produtos, data, cliente);
                break;
            case 2:
                
                Produto::relatorioProdutos(_produtos, data);
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

int Venda::nextId(){
    return _nextId++;
}


void Venda::calcularPrecoTotal(std::vector<std::pair<Produto*, float>> &carrinho, Data &data, Cliente* cliente){
    _totalSemDesconto = 0;
    
    for(std::pair<Produto*, float> produto : carrinho){
        _totalSemDesconto += produto.first->getPreco(data) * produto.second;
    }

    _totalComDesconto = _totalSemDesconto - cliente->calculaDesconto(_totalSemDesconto);
}

float Venda::getValor(){
    return _totalComDesconto;
}

Cliente* Venda::getCliente(){
    return _cliente;
}

Vendedor* Venda::getVendedor(){
    return _vendedor;
}

std::string Venda::getData(){
    return _data.getData();
}

std::vector<std::pair<Produto*, float>> Venda::getCarrinho(){
    return _carrinho;
}



void relatorioVendas(std::vector<Venda*> &vendas){
    int i = 0;
    while( i < 51){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
    std::cout << std::setw(6) << "Id" << std::setw(15) << "Cliente" << std::setw(15) << "Vendedor" << std::setw(15) << "Total Comprado" << std::endl;
    for(Venda* venda : vendas){
        std::cout << std::setw(6) << venda->getId() << std::setw(15) << venda->getCliente()->getNome() << std::setw(15) << venda->getVendedor() << std::setw(15) << venda->getValor() << std::endl;
    }
    i = 0;
    while( i < 51){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
}