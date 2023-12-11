#include "../include/venda.hpp"

int Venda::_nextId = 0;

Venda::Venda(std::vector<std::pair<Produto*, float>> carrinho, Cliente* cliente, Vendedor* vendedor, Data data, std::vector<Cliente*> &todosClientes){
    _id = nextId();
    _carrinho = carrinho;
    //_cliente = cliente;
    _vendedor = vendedor;
    _data = data;
    for(std::pair<Produto*, float> item : _carrinho){
        item.first->diminuirEstoque(item.second);
    }
    _totalSemDesconto = calcularPrecoTotal(_carrinho, _data);
    _totalComDesconto = _totalSemDesconto - cliente->calculaDesconto(_totalSemDesconto);
    cliente = cliente->realizarCompra(_totalComDesconto, todosClientes);
    _vendedor->realizarVenda(_totalComDesconto);
    idCliente = cliente->getID();
}

Venda::Venda(){
    _totalSemDesconto = 0;
}






Venda::Venda(int id, Cliente* cliente, Vendedor* vendedor, int dia, int mes, int ano, float totalSemDesconto){
    _id = id;
    if(_id >= _nextId){
        _nextId = _id + 1;
    }
    //_cliente = cliente;
    _vendedor = vendedor;
    _data = Data(dia, mes, ano);
    _totalSemDesconto = totalSemDesconto;
    _totalComDesconto = _totalSemDesconto - cliente->calculaDesconto(_totalSemDesconto);
    idCliente = cliente->getID();
}

int Venda::getId(){
    return _id;
}

int Venda::getClienteId(){
    return idCliente;
}


Venda* Venda::cadastrarVenda(std::vector<Produto*> &todosProdutos, std::vector<Cliente*> &todosClientes, std::vector<Vendedor*> &todosVendedores){
    std::vector<std::pair<Produto*, float>> _carrinho;
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
                produto.second = 999999999;
                while(produto.second > produto.first->getEstoque()){
                    std::cout << "Quantidade: ";
                    std::cin >> produto.second;
                    if(produto.second > produto.first->getEstoque()){
                        std::cout << "Quantidade indisponível!" << std::endl;
                    }
                }
                _carrinho.push_back(produto);
                break;
            case 2:
                Produto::relatorioProdutos(_carrinho, data);
                std::cout << "Total sem desconto: " << calcularPrecoTotal(_carrinho, data) << std::endl;
                std::cout << "Total com desconto: " << calcularPrecoTotal(_carrinho, data) - cliente->calculaDesconto(calcularPrecoTotal(_carrinho, data)) << std::endl;
                break;
            case 3:
                return new Venda(_carrinho, cliente, vendedor, data, todosClientes);
                break;
            case 4:
                break;
        }
    }
    return nullptr;

}

int Venda::nextId(){
    return _nextId++;
}


float Venda::calcularPrecoTotal(std::vector<std::pair<Produto*, float>> &carrinho, Data &data){
    float totalSemDesconto = 0;
    
    for(std::pair<Produto*, float> produto : carrinho){
        totalSemDesconto += produto.first->getPreco(data) * produto.second;
    }

    return totalSemDesconto;
}

float Venda::getValor(){
    return _totalSemDesconto;
}

//Cliente* Venda::getCliente(){
//    return _cliente;
//}

Vendedor* Venda::getVendedor(){
    return _vendedor;
}

std::string Venda::getData(){
    return _data.getData();
}

std::vector<std::pair<Produto*, float>> Venda::getCarrinho(){
    return _carrinho;
}



void Venda::relatorioVendas(std::vector<Venda*> &vendas, std::vector<Cliente*> &clientes){
    int i = 0;
    while( i < 51){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
    std::cout << std::setw(6) << "Id" << std::setw(15) << "Cliente" << std::setw(15) << "Vendedor" << std::setw(15) << "Total Comprado" << std::endl;
    for(Venda* venda : vendas){
        std::cout << std::setw(6) << venda->getId() << std::setw(15) << Cliente::getClienteById(venda->getClienteId(), clientes)->getNome() << std::setw(15) << venda->getVendedor()->getNome() << std::setw(15) << venda->getValor() << std::endl;
    }
    i = 0;
    while( i < 51){
        std::cout << "-";
        i++;
    }
    std::cout << std::endl;
}